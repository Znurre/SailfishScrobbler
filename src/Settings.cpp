#include <QDebug>

#include "Settings.h"
#include "Track.h"

QString Settings::sessionKey() const
{
	const QVariant &variant = value("key");
	const QString &key = variant.toString();

	return key;
}

void Settings::setSessionKey(const QString &key)
{
	setValue("key", key);
}

