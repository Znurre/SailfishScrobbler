import QtQuick 2.0
import Sailfish.Silica 1.0
import Sailfish.Media 1.0
import AvoidPointer 1.0

Page
{
	SilicaFlickable
	{
		anchors.fill: parent

		Connections
		{
			target: scrobbler
			onCurrentSongChanged: model.currentSongChanged(artist, title)
			onStoppedPlaying: model.stoppedPlaying()
		}

		ScrobblerPageViewModel
		{
			id: model
		}

		PullDownMenu
		{
			MenuItem
			{
				text: "Connect"
				onClicked: pageStack.push("ConnectPage.qml")
				visible: !main.isConfigured
			}

			MenuItem
			{
				text: "Love"
				visible: main.isConfigured
				onClicked: model.love()
				enabled: model.isNowPlaying
			}
		}

		ViewPlaceholder
		{
			text: "Welcome to the Sailfish Scrobbler.\n\nPlease connect your last.fm account to enable scrobbling."
			visible: !main.isConfigured
			enabled: true
		}

		SilicaListView
		{
			visible: main.isConfigured
			anchors.fill: parent
			model: model.history
			delegate: MediaListItem
			{
				title: modelData.title
				subtitle: modelData.artist
				highlighted: modelData.isNowPlaying
			}

			header: PageHeader
			{
				title: "Tracks"
			}

			ViewPlaceholder
			{
				text: "Nothing to show yet.\nStart listening to some music!"
				enabled: !model.hasScrobbleHistory;
			}
		}
	}
}
