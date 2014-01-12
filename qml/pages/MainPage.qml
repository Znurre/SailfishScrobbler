import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.audioscrobbler 1.0

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
			enabled: !main.isConfigured
		}

		SilicaListView
		{
			anchors.fill: parent
			visible: main.isConfigured
			model: model.history
			delegate: Loader
			{
				source: modelData.isNowPlaying ?
					Qt.resolvedUrl("../NowPlayingItemTemplate.qml") :
					Qt.resolvedUrl("../HistoryItemTemplate.qml")
			}

			section
			{
				property: "modelData.isNowPlaying"
				delegate: Loader
				{
					anchors
					{
						left: parent.left
						right: parent.right
					}

					source: section == "true" ?
						Qt.resolvedUrl("../NowPlayingHeaderTemplate.qml") :
						Qt.resolvedUrl("../HistoryHeaderTemplate.qml")
				}
			}

			ViewPlaceholder
			{
				text: "Nothing to show yet.\nStart listening to some music!"
				enabled: !model.hasScrobbleHistory;
			}
		}
	}
}
