#ifndef SCROBBLERPAGEVIEWMODEL_H
#define SCROBBLERPAGEVIEWMODEL_H

#include <QObject>

class Track;

class ScrobblerPageViewModel : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString url READ url NOTIFY urlChanged)
	Q_PROPERTY(QList<QObject *> history READ history NOTIFY historyChanged)

	Q_PROPERTY(bool hasScrobbleHistory READ hasScrobbleHistory NOTIFY hasScrobbleHistoryChanged)
	Q_PROPERTY(bool isNowPlaying READ isNowPlaying NOTIFY isNowPlayingChanged)

	public:
		ScrobblerPageViewModel();
		~ScrobblerPageViewModel();

		QString url() const;
		QList<QObject *> history() const;

		bool hasScrobbleHistory() const;
		bool isNowPlaying() const;

	private:
		QList<Track *> m_history;
		QString m_url;

	public slots:
		void currentSongChanged(const QString &artist, const QString &title);
		void stoppedPlaying();
		void selectPlayer();
		void love();

	signals:
		void urlChanged();
		void historyChanged();
		void hasScrobbleHistoryChanged();
		void isNowPlayingChanged();
};

#endif // SCROBBLERPAGEVIEWMODEL_H
