#include <QDebug>

#include "Scrobbler.h"
#include "Track.h"

Track::Track(const QString &artist, const QString &title, const bool nowPlaying, const unsigned int timestamp)
	: m_artist(artist)
	, m_title(title)
	, m_nowPlaying(nowPlaying)
	, m_submitted(false)
	, m_discarded(nowPlaying)
	, m_timestamp(timestamp)
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

bool Track::isDiscarded() const
{
	return m_discarded;
}

QString Track::artist() const
{
	return m_artist;
}

QString Track::title() const
{
	return m_title;
}

QString Track::timestamp() const
{
	return QString::number(m_timestamp);
}

QString Track::header() const
{
	if(!m_nowPlaying)
	{
		const QDateTime date = QDateTime::fromTime_t(m_timestamp);
		const QDateTime now = QDateTime::currentDateTime();

		if(date.daysTo(now) > 0)
		{
			return date.toString("yyyy-MM-dd");
		}

		return "Today";

	}
	else
	{
		return "Playing";
	}
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
			m_discarded = false;
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
