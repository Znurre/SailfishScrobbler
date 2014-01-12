#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

class Track;

class Settings : public QSettings
{
	public:
		QString sessionKey() const;
		void setSessionKey(const QString &key);
};

#endif // SETTINGS_H
