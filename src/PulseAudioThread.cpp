#include <pulse/pulseaudio.h>

#include "PulseAudioThread.h"

PulseAudioThread::PulseAudioThread()
	: m_application("jolla-mediaplayer")
	, m_ready(false)
{

}

void PulseAudioThread::contextStateCallback(pa_context *context, void *data)
{
	if(pa_context_get_state(context) == PA_CONTEXT_READY)
	{
		State *state = (State *)data;
		PulseAudioThread *instance = state->instance;
		instance->m_ready = true;
	}
}

void PulseAudioThread::sinkInputInfoCallback(pa_context *, const pa_sink_input_info *info, int last, void *data)
{
	State *state = (State *)data;
	PulseAudioThread *instance = state->instance;

	if(!last)
	{
		pa_proplist *properties = info->proplist;

		if(properties)
		{
			const QString application = pa_proplist_gets(properties, PA_PROP_APPLICATION_NAME);

			if(application == instance->m_application)
			{
				const QString artist = pa_proplist_gets(properties, PA_PROP_MEDIA_ARTIST);
				const QString title = pa_proplist_gets(properties, PA_PROP_MEDIA_TITLE);

				const bool isChanged =
					artist != instance->m_artist ||
					title != instance->m_title;

				if(isChanged)
				{
					instance->m_artist = artist;
					instance->m_title = title;

					const bool isValid =
						!artist.isEmpty() &&
						!title.isEmpty();

					if(isValid)
					{
						emit instance->currentSongChanged(artist, title);
					}
				}

				instance->m_valid = true;
			}
		}
	}
	else
	{
		if(!instance->m_valid)
		{
			emit instance->stoppedPlaying();
		}

		instance->m_valid = false;
	}
}

void PulseAudioThread::timerCallback(pa_mainloop_api *api, pa_time_event *event, const timeval *, void *data)
{
	State *state = (State *)data;
	PulseAudioThread *instance = state->instance;

	if(instance->m_ready)
	{
		pa_context_get_sink_input_info_list(state->context, &PulseAudioThread::sinkInputInfoCallback, state);
	}

	timeval time;

	pa_gettimeofday(&time);
	pa_timeval_add(&time, INTERVAL);

	api->time_restart(event, &time);
}

void PulseAudioThread::run()
{
	pa_mainloop *mainLoop = pa_mainloop_new();
	pa_mainloop_api *api = pa_mainloop_get_api(mainLoop);
	pa_context *context = pa_context_new(api, 0);

	timeval time;

	pa_gettimeofday(&time);
	pa_timeval_add(&time, INTERVAL);

	State state = { this, context };

	api->time_new(api, &time, &PulseAudioThread::timerCallback, &state);

	pa_context_set_state_callback(context, &PulseAudioThread::contextStateCallback, &state);
	pa_context_connect(context, 0, PA_CONTEXT_NOFLAGS, 0);

	pa_mainloop_run(mainLoop, 0);
}
