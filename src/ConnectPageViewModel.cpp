#include <QDebug>
#include <QDesktopServices>

#include "ConnectPageViewModel.h"
#include "Settings.h"
#include "QStringEx.h"
#include "NetworkObject.h"
#include "AudioscrobblerAdapter.h"
#include "MainPageViewModel.h"

ConnectPageViewModel::ConnectPageViewModel()
{
	m_token = createToken();

	QString url = QStringEx::format("http://www.last.fm/api/auth/?api_key=%1&token=%2", APIKEY, m_token);
	QDesktopServices::openUrl(url);
}

void ConnectPageViewModel::accepted(MainPageViewModel *model)
{
	NetworkObject networkObject;
	AudioscrobblerAdapter adapter;

	QString sessionKey = adapter
		.get(networkObject
			, as::api_key = APIKEY
			, as::method = "auth.getSession"
			, as::token = m_token)
		.namedItem("lfm")
		.namedItem("session")
		.firstChildElement("key")
		.text();

	bool isValid = !sessionKey.isEmpty();

	if(isValid)
	{
		qDebug() << sessionKey;

		Settings settings;
		settings.setSessionKey(sessionKey);
		settings.sync();

		emit model->isConfiguredChanged();
	}
	else
	{
		qDebug() << "Authorization failed";
	}
}

QString ConnectPageViewModel::createToken()
{
	NetworkObject networkObject;
	AudioscrobblerAdapter adapter;

	return adapter
		.get(networkObject
			, as::api_key = APIKEY
			, as::method = "auth.getToken")
		.namedItem("lfm")
		.firstChildElement("token")
		.text();
}
