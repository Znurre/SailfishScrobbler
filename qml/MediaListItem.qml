import QtQuick 2.0
import Sailfish.Silica 1.0

ListItem
{
	id: mediaListItem

	property string title
	property string subtitle
	property bool playing

	Column
	{
		anchors
		{
			left: parent.left;
			leftMargin: Theme.paddingMedium * 2
			top: parent.top
			topMargin: Theme.paddingSmall
			right: parent.right
			rightMargin: Theme.paddingLarge
		}

		Label
		{
			width: parent.width
			text: mediaListItem.title
			truncationMode: TruncationMode.Fade
			color: highlighted || playing ? Theme.highlightColor : Theme.primaryColor

			font
			{
				family: Theme.fontFamilyHeading
				pixelSize: Theme.fontSizeMedium
			}
		}

		Label
		{
			width: parent.width
			text: mediaListItem.subtitle
			truncationMode: TruncationMode.Fade
			opacity: 0.6
			color: highlighted || playing ? Theme.highlightColor : Theme.primaryColor

			font
			{
				family: Theme.fontFamily
				pixelSize: Theme.fontSizeExtraSmall
			}
		}
	}
}
