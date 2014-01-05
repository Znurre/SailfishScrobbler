#ifndef PULSEAUDIOTHREAD_H
#define PULSEAUDIOTHREAD_H

#include <QThread>
#include <QStringList>

struct pa_context;
struct pa_sink_input_info;
struct pa_mainloop_api;
struct pa_time_event;

class PulseAudioThread;

struct State
{
	PulseAudioThread *instance;
	pa_context *context;
};

const int INTERVAL = 1000 * 1000;

class PulseAudioThread : public QThread
{
	Q_OBJECT

	public:
		PulseAudioThread();

	private:
		void run();

		static void contextStateCallback(pa_context *context, void *data);
		static void sinkInputInfoCallback(pa_context *, const pa_sink_input_info *info, int last, void *data);
		static void timerCallback(pa_mainloop_api *api, pa_time_event *event, const struct timeval *, void *data);

		QString m_application;
		QString m_artist;
		QString m_title;

		bool m_ready;
		bool m_valid;

	signals:
		void currentSongChanged(const QString &artist, const QString &title);
		void stoppedPlaying();
};

#endif // PULSEAUDIOTHREAD_H
