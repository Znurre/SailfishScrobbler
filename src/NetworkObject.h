#ifndef NETWORKOBJECT_H
#define NETWORKOBJECT_H

#include <QNetworkAccessManager>

class NetworkObject : public QNetworkAccessManager
{
	Q_OBJECT

	public:
		NetworkObject();

		QNetworkReply *getBlocking(const QString &url, const int timeout = -1);
		QNetworkReply *postBlocking(const QString &url, const QByteArray &data, const int timeout = -1);

	private:
		QNetworkReply *waitForReply(QNetworkReply *reply, const int timeout);

		QNetworkReply *m_reply;

	private slots:
		void reply(QNetworkReply *reply);
};

#endif // NETWORKOBJECT_H
