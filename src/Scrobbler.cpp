#include <QDateTime>

#include "AudioscrobblerAdapter.h"
#include "NetworkObject.h"
#include "Scrobbler.h"
#include "Settings.h"
#include "StatusParser.h"
#include "Track.h"

void Scrobbler::nowPlaying(Track *track)
{
	m_adapter.post(m_networkObject
		, as::api_key = APIKEY
		, as::artist = track->artist()
		, as::method = "track.updateNowPlaying"
		, as::sk = m_settings.sessionKey()
		, as::track = track->title());
}

void Scrobbler::submit(Track *track)
{
//	m_cache << track;

//	for(Track *track : m_cache)
//	{
//		const QDomDocument &response =
		m_adapter.post(m_networkObject
			, as::api_key = APIKEY
			, as::artist0 = track->artist()
			, as::method = "track.scrobble"
			, as::sk = m_settings.sessionKey()
			, as::timestamp0 = track->timestamp()
			, as::track0 = track->title());

//		const StatusParser parser(response);
//		const Status status = parser.status();

//		if(status.isValid())
//		{
//			m_cache.removeAll(track);
//		}
//	}
}

void Scrobbler::love(Track *track)
{
	m_adapter.post(m_networkObject
		, as::api_key = APIKEY
		, as::artist = track->artist()
		, as::method = "track.love"
		, as::sk = m_settings.sessionKey()
		, as::track = track->title());
}
