#ifndef SCROBBLERVIEWMODEL_H
#define SCROBBLERVIEWMODEL_H

#include <QObject>

class PulseAudioThread;

class ScrobblerViewModel : public QObject
{
	Q_OBJECT

	public:
		ScrobblerViewModel();

	private:
		PulseAudioThread *m_thread;

	signals:
		void currentSongChanged(const QString &artist, const QString &title);
		void stoppedPlaying();
};

#endif // SCROBBLERVIEWMODEL_H
