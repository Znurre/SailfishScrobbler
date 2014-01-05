#ifndef WELCOMEPAGEVIEWMODEL_H
#define WELCOMEPAGEVIEWMODEL_H

#include <QObject>

class MainPageViewModel;
class PageStackAdapter;

class WelcomePageViewModel : public QObject
{
	Q_OBJECT

	Q_PROPERTY(int index READ index WRITE setIndex NOTIFY indexChanged)

	public:
		WelcomePageViewModel();

		int index() const;
		void setIndex(const int index);

	private:
		int m_index;

	signals:
		void indexChanged();
};

#endif // WELCOMEPAGEVIEWMODEL_H
