#include <QDebug>
#include <QMetaMethod>
#include <QQuickItem>
#include <QQmlContext>

#include "PageStackAdapter.h"

PageStackAdapter::PageStackAdapter()
	 : m_pageStack(0)
{

}

QString PageStackAdapter::url() const
{
	return m_url;
}

void PageStackAdapter::setUrl(const QString &url)
{
	m_url = url;

	if(m_pageStack)
	{
		if(url != QString::null)
		{
			QQmlContext *context = qmlContext(this);
			QQmlEngine *engine = qmlEngine(this);

			QUrl resolvedUrl = context->resolvedUrl(url);
			QQmlComponent component(engine, resolvedUrl);
			QObject *item = component.create(context);

			QMetaObject::invokeMethod(m_pageStack, "_push"
				, Q_ARG(QVariant, QVariant::fromValue(item))
				, Q_ARG(QVariant, QVariant())
				, Q_ARG(QVariant, QVariant()));
		}
	}
}

QObject *PageStackAdapter::pageStack() const
{
	return m_pageStack;
}

void PageStackAdapter::setPageStack(QObject *pageStack)
{
	m_pageStack = pageStack;
}
