#include <QtQuick>

#include <sailfishapp.h>

#include "PulseAudioModel.h"
#include "MainPageViewModel.h"
#include "PageStackAdapter.h"
#include "ScrobblerPageViewModel.h"
#include "ScrobblerViewModel.h"
#include "CoverPageViewModel.h"
#include "ConnectPageViewModel.h"

int main(int argc, char **argv)
{
	qmlRegisterType<PulseAudioModel>("harbour.audioscrobbler", 1, 0, "PulseAudioModel");
	qmlRegisterType<MainPageViewModel>("harbour.audioscrobbler", 1, 0, "MainPageViewModel");
	qmlRegisterType<ScrobblerPageViewModel>("harbour.audioscrobbler", 1, 0, "ScrobblerPageViewModel");
	qmlRegisterType<PageStackAdapter>("harbour.audioscrobbler", 1, 0, "PageStackAdapter");
	qmlRegisterType<ScrobblerViewModel>("harbour.audioscrobbler", 1, 0, "ScrobblerViewModel");
	qmlRegisterType<CoverPageViewModel>("harbour.audioscrobbler", 1, 0, "CoverPageViewModel");
	qmlRegisterType<ConnectPageViewModel>("harbour.audioscrobbler", 1, 0, "ConnectPageViewModel");

	QGuiApplication *application = SailfishApp::application(argc, argv);
	application->setOrganizationName("harbour-audioscrobbler");
	application->setApplicationName("settings");

	return SailfishApp::main(argc, argv);
}
