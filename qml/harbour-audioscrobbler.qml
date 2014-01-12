import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.audioscrobbler 1.0

import "pages"

ApplicationWindow
{
	id: window
	cover: Qt.resolvedUrl("cover/CoverPage.qml")
	allowedOrientations: Orientation.Portrait
	initialPage: Component
	{
		MainPage
		{

		}
	}

	MainPageViewModel
	{
		id: main
	}

	ScrobblerViewModel
	{
		id: scrobbler
	}
}
