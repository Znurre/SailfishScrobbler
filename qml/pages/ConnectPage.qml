import QtQuick 2.0
import QtWebKit 3.0
import Sailfish.Silica 1.0
import harbour.audioscrobbler 1.0

Dialog
{
	onAccepted: model.accepted(main)

	ConnectPageViewModel
	{
		id: model
	}

	Column
	{
		spacing: 10
		anchors.fill: parent

		DialogHeader
		{
			title: "Connect"
			acceptText: "Done"
		}

		Label
		{
			text: "A browser window has been launched where you need to login and authorize this application.\n\n" +
				"Once you are done you can proceed from this page."
			width: parent.width - (Theme.paddingLarge * 2)
			wrapMode: Text.Wrap
			x: Theme.paddingLarge
		}
	}
}
