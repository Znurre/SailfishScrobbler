#include <QCoreApplication>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

#include "NetworkObject.h"

NetworkObject::NetworkObject()
{
	connect(this, &QNetworkAccessManager::finished, this, &NetworkObject::reply);
}

QNetworkReply *NetworkObject::getBlocking(const QString &url, const int timeout)
{
	QNetworkRequest request(url);
	QNetworkReply *reply = get(request);

	return waitForReply(reply, timeout);
}

QNetworkReply *NetworkObject::postBlocking(const QString &url, const QByteArray &data, const int timeout)
{
	QNetworkRequest request(url);
	QNetworkReply *reply = post(request, data);

	return waitForReply(reply, timeout);
}

QNetworkReply *NetworkObject::waitForReply(QNetworkReply *reply, const int timeout)
{
	int elapsed = 0;

	for(; m_reply != reply; QCoreApplication::processEvents(QEventLoop::AllEvents, 100))
	{
		if(timeout > -1)
		{
			if((elapsed += 10) >= timeout)
			{
				return 0;
			}
		}
	}

	return reply;
}

void NetworkObject::reply(QNetworkReply *reply)
{
	m_reply = reply;
}
