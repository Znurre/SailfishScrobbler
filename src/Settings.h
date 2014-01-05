#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

class Track;

class Settings : public QSettings
{
	public:
		QString sessionKey() const;
		void setSessionKey(const QString &key);

		QList<Track *> history();
		void setHistory(QList<Track *> history);

	private:
		QString stringValue(const QString &key) const;
};

#endif // SETTINGS_H
