#ifndef TRACK_H
#define TRACK_H

#include <QDateTime>
#include <QObject>

#include "TimeProvider.h"

const unsigned int MIN_LENGTH = 30;
const unsigned int MAX_LENGTH = 240;

class Track : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString artist READ artist NOTIFY artistChanged)
	Q_PROPERTY(QString title READ title NOTIFY titleChanged)
	Q_PROPERTY(QString header READ header NOTIFY headerChanged)

	Q_PROPERTY(bool isNowPlaying READ isNowPlaying NOTIFY isNowPlayingChanged)

	public:
		Track(const QString &artist
			, const QString &title
			, const bool nowPlaying
			, const unsigned int timestamp = TIME_NOW);

		bool isNowPlaying() const;
		bool isDiscarded() const;

		QString artist() const;
		QString title() const;
		QString timestamp() const;
		QString header() const;

		void submit();
		void markAsPlayed();
		void love();

	private:
		void timerEvent(QTimerEvent *event);

		QString m_artist;
		QString m_title;

		bool m_nowPlaying;
		bool m_submitted;
		bool m_discarded;

		unsigned int m_timestamp;
		unsigned int m_timerId;

	signals:
		void artistChanged();
		void titleChanged();
		void headerChanged();
		void isNowPlayingChanged();
};

Q_DECLARE_METATYPE(Track *)

#endif // TRACK_H
