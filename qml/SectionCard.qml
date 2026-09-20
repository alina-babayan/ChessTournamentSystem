import QtQuick
import QtQuick.Layouts
import ChessTournament

Rectangle {
    id: card
    property string title: ""
    default property alias content: contentColumn.data

    implicitWidth: mainLayout.implicitWidth + Theme.spaceL * 2
    implicitHeight: mainLayout.implicitHeight + Theme.spaceL * 2
    clip: true

    color: Theme.parchment
    radius: Theme.radiusMedium
    border.width: 1
    border.color: Theme.hairline

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.margins: Theme.spaceL
        spacing: Theme.spaceM

        Text {
            text: card.title
            visible: card.title.length > 0
            font.family: Theme.serifFamily
            font.pixelSize: 20
            font.weight: Font.DemiBold
            color: Theme.walnut
            Layout.fillWidth: true
        }
        Rectangle {
            visible: card.title.length > 0
            Layout.fillWidth: true
            height: 1
            color: Theme.hairline
        }
        ColumnLayout {
            id: contentColumn
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: Theme.spaceM
        }
    }
}
