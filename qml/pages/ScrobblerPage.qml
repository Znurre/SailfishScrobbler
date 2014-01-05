import QtQuick 2.0
import Sailfish.Silica 1.0
import Sailfish.Media 1.0
import AvoidPointer 1.0

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
			text: "Love"
			onClicked: model.love()
			enabled: model.isNowPlaying
		}
	}

	SilicaListView
	{
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
			title: "Audioscrobbler"
		}

		ViewPlaceholder
		{
			text: "Nothing to show yet.\nStart listening to some music!"
			enabled: !model.hasScrobbleHistory;
		}
	}
}
