#include <QDebug>

#include "StatusParser.h"

StatusParser::StatusParser(const QDomDocument &document)
	: m_document(document)
{

}

Status StatusParser::status() const
{
	const QDomElement &root = m_document.firstChildElement("lfm");
	const QString &status = root.attribute("status");

	if(status != "ok")
	{
		qDebug() << m_document.toString(4);
	}
	else
	{
		return -1;
	}

	return 0;
}
