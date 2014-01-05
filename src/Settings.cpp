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

QList<Track *> Settings::history()
{
	QList<Track *> tracks;

	const int size = beginReadArray("history");

	for(int i = 0; i < size && i < 20; i++)
	{
		setArrayIndex(i);

		const QString &artist = stringValue("artist");
		const QString &title = stringValue("title");

		tracks << new Track(artist, title, false);
	}

	endArray();

	return tracks;
}

void Settings::setHistory(QList<Track *> history)
{
	beginWriteArray("history");

	for(int i = 0; i < history.size(); i++)
	{
		const Track *track = history[i];
		const QString &artist = track->artist();
		const QString &title = track->title();

		setArrayIndex(i);
		setValue("artist", artist);
		setValue("title", title);
	}

	endArray();
}

QString Settings::stringValue(const QString &key) const
{
	const QVariant &variant = value(key);
	const QString &string = variant.toString();

	return string;
}
