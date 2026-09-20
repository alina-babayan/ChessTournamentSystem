import QtQuick
import QtQuick.Controls
import ChessTournament

TextField {
    id: control
    implicitHeight: 38
    font.family: Theme.sansFamily
    font.pixelSize: 14
    color: Theme.walnut
    placeholderTextColor: Theme.walnutMuted
    selectByMouse: true
    leftPadding: Theme.spaceS
    rightPadding: Theme.spaceS

    background: Rectangle {
        radius: Theme.radiusSmall
        color: Theme.ivory
        border.width: 1
        border.color: control.activeFocus ? Theme.verdigris : Theme.hairline
    }
}
