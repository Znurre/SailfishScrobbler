#ifndef CONNECTPAGEVIEWMODEL_H
#define CONNECTPAGEVIEWMODEL_H

#include <QObject>

class MainPageViewModel;

class ConnectPageViewModel : public QObject
{
	Q_OBJECT

	public:
		ConnectPageViewModel();

	public slots:
		void accepted(MainPageViewModel *model);

	private:
		QString createToken();

		QString m_token;
};

#endif // CONNECTPAGEVIEWMODEL_H
