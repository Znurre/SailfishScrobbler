#include "ScrobblerViewModel.h"
#include "PulseAudioThread.h"

ScrobblerViewModel::ScrobblerViewModel()
{
	m_thread = new PulseAudioThread();
	m_thread->connect(m_thread, &PulseAudioThread::currentSongChanged, this, &ScrobblerViewModel::currentSongChanged);
	m_thread->connect(m_thread, &PulseAudioThread::stoppedPlaying, this, &ScrobblerViewModel::stoppedPlaying);
	m_thread->start();
}
