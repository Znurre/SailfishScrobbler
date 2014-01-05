#ifndef STATUSPARSER_H
#define STATUSPARSER_H

#include <QDomDocument>

#include "Status.h"

class StatusParser
{
	public:
		StatusParser(const QDomDocument &document);

		Status status() const;

	private:
		QDomDocument m_document;
};

#endif // STATUSPARSER_H
