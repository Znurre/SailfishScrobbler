#ifndef PULSEAUDIOMODEL_H
#define PULSEAUDIOMODEL_H

#include <QStringList>
#include <QObject>

class PulseAudioThread;

class PulseAudioModel : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString artist READ artist NOTIFY artistChanged)
	Q_PROPERTY(QString title READ title NOTIFY titleChanged)
	Q_PROPERTY(QString url READ url NOTIFY urlChanged)

	public:
		PulseAudioModel();

		QString artist() const;
		QString title() const;
		QString url() const;

	private:
		PulseAudioThread *m_thread;

		QString m_artist;
		QString m_title;
		QString m_url;

	public slots:
		void selectPlayer();

	private slots:
		void currentSongChanged(const QString &artist, const QString &title);

	signals:
		void artistChanged();
		void titleChanged();
		void urlChanged();
};

#endif // PULSEAUDIOMODEL_H
