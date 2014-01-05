#include "AudioscrobblerAdapter.h"
#include "Settings.h"

#ifndef SCROBBLER_H
#define SCROBBLER_H

class Track;

class Scrobbler
{
	public:
		void nowPlaying(Track *track);
		void submit(Track *track);
		void love(Track *track);

	private:
		Settings m_settings;
		NetworkObject m_networkObject;
		AudioscrobblerAdapter m_adapter;
		
		QList<Track *> m_cache;
};

#endif // SCROBBLER_H
