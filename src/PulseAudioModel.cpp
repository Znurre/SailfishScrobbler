#include "PulseAudioModel.h"
#include "PulseAudioThread.h"
#include "Settings.h"

PulseAudioModel::PulseAudioModel()
{
	m_thread = new PulseAudioThread();
	m_thread->connect(m_thread, &PulseAudioThread::currentSongChanged, this, &PulseAudioModel::currentSongChanged);
	m_thread->start();
}

QString PulseAudioModel::artist() const
{
	return m_artist;
}

QString PulseAudioModel::title() const
{
	return m_title;
}

QString PulseAudioModel::url() const
{
	return m_url;
}

void PulseAudioModel::selectPlayer()
{
	m_url = "PlayerSelectionPage.qml";

	emit urlChanged();
}

void PulseAudioModel::currentSongChanged(const QString &artist, const QString &title)
{
	m_artist = artist;
	m_title = title;

	emit artistChanged();
	emit titleChanged();
}
