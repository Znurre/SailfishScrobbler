#ifndef COVERPAGEVIEWMODEL_H
#define COVERPAGEVIEWMODEL_H

#include <QObject>

class CoverPageViewModel : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString artist READ artist NOTIFY artistChanged)
	Q_PROPERTY(QString title READ title NOTIFY titleChanged)

	Q_PROPERTY(bool isValid READ isValid NOTIFY isValidChanged)

	public:
		CoverPageViewModel();

		QString artist() const;
		QString title() const;

		bool isValid() const;

	public slots:
		void currentSongChanged(const QString &artist, const QString &title);
		void stoppedPlaying();
		void love();

	private:
		QString m_artist;
		QString m_title;

		bool m_isPlaying;

	signals:
		void artistChanged();
		void titleChanged();
		void isValidChanged();
};

#endif // COVERPAGEVIEWMODEL_H
