#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>

#include "PulseAudioModel.h"
#include "MainPageViewModel.h"
#include "WelcomePageViewModel.h"
#include "PageStackAdapter.h"
#include "ScrobblerPageViewModel.h"
#include "ScrobblerViewModel.h"
#include "CoverPageViewModel.h"
#include "ConnectPageViewModel.h"

int main(int argc, char **argv)
{
	qmlRegisterType<PulseAudioModel>("AvoidPointer", 1, 0, "PulseAudioModel");
	qmlRegisterType<MainPageViewModel>("AvoidPointer", 1, 0, "MainPageViewModel");
	qmlRegisterType<WelcomePageViewModel>("AvoidPointer", 1, 0, "WelcomePageViewModel");
	qmlRegisterType<ScrobblerPageViewModel>("AvoidPointer", 1, 0, "ScrobblerPageViewModel");
	qmlRegisterType<PageStackAdapter>("AvoidPointer", 1, 0, "PageStackAdapter");
	qmlRegisterType<ScrobblerViewModel>("AvoidPointer", 1, 0, "ScrobblerViewModel");
	qmlRegisterType<CoverPageViewModel>("AvoidPointer", 1, 0, "CoverPageViewModel");
	qmlRegisterType<ConnectPageViewModel>("AvoidPointer", 1, 0, "ConnectPageViewModel");

	QGuiApplication *application = SailfishApp::application(argc, argv);
	application->setOrganizationName("AvoidPointer");
	application->setApplicationName("Audioscrobbler");

	return SailfishApp::main(argc, argv);
}
