#include <QDebug>

#include "Scrobbler.h"
#include "Track.h"
#include "TimeProvider.h"

Track::Track(const QString &artist, const QString &title, const bool nowPlaying)
	: m_artist(artist)
	, m_title(title)
	, m_nowPlaying(nowPlaying)
	, m_submitted(false)
	, m_timestamp(TIME_NOW)
{
	if(m_nowPlaying)
	{
		m_timerId = startTimer(1000);
	}
}

bool Track::isNowPlaying() const
{
	return m_nowPlaying;
}

QString Track::artist() const
{
	return m_artist;
}

QString Track::title() const
{
	return m_title;
}

QString Track::timestamp()
{
	return QString::number(m_timestamp);
}

void Track::submit()
{
	if(!m_submitted)
	{
		if(TIME_NOW - m_timestamp >= MIN_LENGTH)
		{
			Scrobbler scrobbler;
			scrobbler.submit(this);

			m_submitted = true;
		}
	}
}

void Track::markAsPlayed()
{
	m_nowPlaying = false;

	emit isNowPlayingChanged();
}

void Track::love()
{
	Scrobbler scrobbler;
	scrobbler.love(this);
}

void Track::timerEvent(QTimerEvent *)
{
	if(TIME_NOW - m_timestamp >= MAX_LENGTH)
	{
		submit();
		killTimer(m_timerId);
	}
}
