import QtQuick
import ChessTournament

Rectangle {
    id: pill
    property string text: ""
    property color tint: Theme.walnutMuted

    implicitWidth: label.implicitWidth + Theme.spaceM * 2
    implicitHeight: label.implicitHeight + Theme.spaceXS * 2
    radius: height / 2
    color: Qt.rgba(tint.r, tint.g, tint.b, 0.14)
    border.width: 1
    border.color: Qt.rgba(tint.r, tint.g, tint.b, 0.4)

    Text {
        id: label
        anchors.centerIn: parent
        text: pill.text
        font.family: Theme.sansFamily
        font.pixelSize: 12
        font.weight: Font.DemiBold
        color: Qt.darker(tint, 1.3)
    }
}
