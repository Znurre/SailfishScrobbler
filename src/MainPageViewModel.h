#ifndef MAINPAGEVIEWMODEL_H
#define MAINPAGEVIEWMODEL_H

#include <QObject>
#include <QUrl>

class MainPageViewModel : public QObject
{
	Q_OBJECT

	Q_PROPERTY(bool isConfigured READ isConfigured NOTIFY isConfiguredChanged)

	public:
		bool isConfigured() const;

	signals:
		void isConfiguredChanged();
};

#endif // MAINPAGEVIEWMODEL_H
