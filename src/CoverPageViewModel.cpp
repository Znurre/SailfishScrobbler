#include "CoverPageViewModel.h"
#include "Scrobbler.h"
#include "Track.h"

CoverPageViewModel::CoverPageViewModel()
	: m_isPlaying(false)
{

}

QString CoverPageViewModel::artist() const
{
	return m_artist;
}

QString CoverPageViewModel::title() const
{
	return m_title;
}

bool CoverPageViewModel::isValid() const
{
	Settings settings;

	return m_isPlaying && !settings
		.sessionKey()
		.isEmpty();
}

void CoverPageViewModel::currentSongChanged(const QString &artist, const QString &title)
{
	m_artist = artist;
	m_title = title;
	m_isPlaying = true;

	emit artistChanged();
	emit titleChanged();
	emit isValidChanged();
}

void CoverPageViewModel::stoppedPlaying()
{
	m_isPlaying = false;

	emit isValidChanged();
}

void CoverPageViewModel::love()
{
	Track track(m_artist, m_title, false);

	Scrobbler scrobbler;
	scrobbler.love(&track);
}
