import QtQuick 2.0
import Sailfish.Silica 1.0
import AvoidPointer 1.0

CoverBackground
{
	CoverPageViewModel
	{
		id: model
	}

	Connections
	{
		target: scrobbler
		onCurrentSongChanged: model.currentSongChanged(artist, title)
		onStoppedPlaying: model.stoppedPlaying()
	}

	Column
	{
		x: Theme.paddingMedium
		y: Theme.paddingMedium
		anchors.margins: Theme.paddingMedium
		anchors.verticalCenter: parent.verticalCenter
		anchors.verticalCenterOffset: -Theme.itemSizeMedium / 2
		spacing: Theme.paddingSmall
		visible: model.isValid
		width: parent.width - 2 * Theme.paddingMedium

		Label
		{
			text: model.artist
			width: parent.width
			horizontalAlignment: Text.AlignHCenter
			color: Theme.highlightColor
			elide: Text.ElideRight
			font.pixelSize: Theme.fontSizeLarge
			lineHeightMode: Text.FixedHeight
			lineHeight: Theme.itemSizeMedium / 2
		}

		Label
		{
			text: model.title
			width: parent.width
			horizontalAlignment: Text.AlignHCenter
			maximumLineCount: 3
			wrapMode: Text.WordWrap
			elide: Text.ElideRight
			font.pixelSize: Theme.fontSizeLarge
			lineHeightMode: Text.FixedHeight
			lineHeight: Theme.itemSizeMedium / 2
		}
	}

	CoverPlaceholder
	{
		visible: !model.isValid
		text: "Nothing playing"
	}

	CoverActionList
	{
		id: coverAction
		enabled: model.isValid

		CoverAction
		{
			iconSource: Qt.resolvedUrl("../../icon-cover-heart.png")
			onTriggered: model.love()
		}
	}
}


