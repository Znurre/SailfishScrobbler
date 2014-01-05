import QtQuick 2.0
import Sailfish.Silica 1.0
import AvoidPointer 1.0

SilicaFlickable
{
	anchors.fill: parent

	WelcomePageViewModel
	{
		id: model
		index: pageStack.depth
	}

	PullDownMenu
	{
		MenuItem
		{
			text: "Connect"
			onClicked: pageStack.push("ConnectDialog.qml")
		}
	}

	PageHeader
	{
		title: "Welcome"
	}

	ViewPlaceholder
	{
		text: "Welcome to the Sailfish Scrobbler.\n\nPlease connect your last.fm account to enable scrobbling."
		enabled: true
	}
}


