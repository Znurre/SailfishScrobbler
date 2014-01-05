#include <QDebug>
#include <QDir>
#include <QQuickItem>
#include <QQmlContext>

#include "MainPageViewModel.h"
#include "PageStackAdapter.h"
#include "Settings.h"

bool MainPageViewModel::isConfigured() const
{
	const Settings settings;
	const QString &key = settings.sessionKey();

	return !key.isEmpty();
}
