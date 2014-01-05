#include <QDebug>
#include <QDesktopServices>
#include <QDomDocument>
#include <QProcess>
#include <QUrl>

#include "AudioscrobblerAdapter.h"
#include "PageStackAdapter.h"
#include "NetworkObject.h"
#include "Settings.h"
#include "WelcomePageViewModel.h"
#include "MainPageViewModel.h"
#include "QStringEx.h"
#include "Key.h"

WelcomePageViewModel::WelcomePageViewModel()
	: m_index(-1)
{

}

int WelcomePageViewModel::index() const
{
	return m_index;
}

void WelcomePageViewModel::setIndex(const int index)
{
	if(m_index == 2 && index == 1)
	{

	}

	m_index = index;

	qDebug() << index;
}
