#include <QStringList>
#include <QDebug>

#include "ScrobblerPageViewModel.h"
#include "PulseAudioThread.h"
#include "Settings.h"
#include "Track.h"
#include "AudioscrobblerAdapter.h"
#include "Scrobbler.h"

ScrobblerPageViewModel::ScrobblerPageViewModel()
{
	Settings settings;

	m_history = settings.history();
}

ScrobblerPageViewModel::~ScrobblerPageViewModel()
{
	Settings settings;
	settings.setHistory(m_history);
	settings.sync();
}

QString ScrobblerPageViewModel::url() const
{
	return m_url;
}

QList<QObject *> ScrobblerPageViewModel::history() const
{
	QList<QObject *> result;

	for(int i = 0; i < m_history.count() && i < 20; i++)
	{
		result << m_history[i];
	}

	return result;
}

bool ScrobblerPageViewModel::hasScrobbleHistory() const
{
	return !m_history.isEmpty();
}

bool ScrobblerPageViewModel::isNowPlaying() const
{
	Track *current = m_history.value(0);

	return current && current->isNowPlaying();
}

void ScrobblerPageViewModel::currentSongChanged(const QString &artist, const QString &title)
{
	Track *current = m_history.value(0);
	Track *track = new Track(artist, title, true);

	if(current)
	{
		current->markAsPlayed();
		current->submit();
	}

	m_history.prepend(track);

	Scrobbler scrobbler;
	scrobbler.nowPlaying(track);

	emit historyChanged();
	emit hasScrobbleHistoryChanged();
	emit isNowPlayingChanged();
}

void ScrobblerPageViewModel::stoppedPlaying()
{
	Track *current = m_history.value(0);

	if(current)
	{
		current->markAsPlayed();

		emit historyChanged();
		emit isNowPlayingChanged();
	}
}

void ScrobblerPageViewModel::selectPlayer()
{
	m_url = "PlayerSelectionPage.qml";

	emit urlChanged();
}

void ScrobblerPageViewModel::love()
{
	Track *current = m_history.first();
	current->love();
}
