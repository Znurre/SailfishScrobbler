#ifndef PAGESTACKADAPTER_H
#define PAGESTACKADAPTER_H

#include <QObject>
#include <QString>

class PageStackAdapter : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)
	Q_PROPERTY(QObject *pageStack READ pageStack WRITE setPageStack NOTIFY pageStackChanged)

	public:
		PageStackAdapter();

		QString url() const;
		void setUrl(const QString &url);

		QObject *pageStack() const;
		void setPageStack(QObject *pageStack);

	private:
		QString m_url;
		QObject *m_pageStack;

	signals:
		void urlChanged();
		void pageStackChanged();
};

#endif // PAGESTACKADAPTER_H
