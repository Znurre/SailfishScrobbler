#ifndef AUDIOSCROBBLERADAPTER_H
#define AUDIOSCROBBLERADAPTER_H

#include <QDomDocument>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "NetworkObject.h"
#include "UrlBuilder.h"
#include "SignatureBuilder.h"
#include "Key.h"

const QByteArray APIKEY = "086633358dc877dfd9c47a2812b06bc4";
const QByteArray SECRET = "02194139392e43fb7d89753185caeeb5";

class AudioscrobblerAdapter
{
	public:
		template<class ...TArguments>
		QDomDocument get(NetworkObject &networkObject, TArguments ...arguments)
		{
			QList<as::KeyValue> list = { arguments... };

			UrlBuilder urlBuilder("http://ws.audioscrobbler.com/2.0/");
			urlBuilder.setParameters(list);

			SignatureBuilder signatureBuilder(SECRET);
			signatureBuilder.setParameters(list);

			QString url = urlBuilder.url(signatureBuilder);
			QNetworkReply *reply = networkObject.getBlocking(url);

			QDomDocument document;
			document.setContent(reply);

			return document;
		}

		template<class ...TArguments>
		QDomDocument post(NetworkObject &networkObject, TArguments ...arguments)
		{
			QList<as::KeyValue> list = { arguments... };

			QueryBuilder queryBuilder;
			queryBuilder.setParameters(list);

			SignatureBuilder signatureBuilder(SECRET);
			signatureBuilder.setParameters(list);

			QByteArray query = queryBuilder
				.build(signatureBuilder)
				.toUtf8();

			QNetworkReply *reply = networkObject.postBlocking("http://ws.audioscrobbler.com/2.0/", query);

			QDomDocument document;
			document.setContent(reply);

			return document;
		}
};

#endif // AUDIOSCROBBLERADAPTER_H
