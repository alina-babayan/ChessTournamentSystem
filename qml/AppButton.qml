import QtQuick
import QtQuick.Controls
import ChessTournament

Button {
    id: control
    property bool primary: true

    implicitHeight: 38
    padding: 0
    leftPadding: Theme.spaceM
    rightPadding: Theme.spaceM

    contentItem: Text {
        text: control.text
        font.family: Theme.sansFamily
        font.pixelSize: 14
        font.weight: Font.DemiBold
        color: control.primary ? Theme.ivory : Theme.walnut
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    background: Rectangle {
        radius: Theme.radiusSmall
        color: control.primary
               ? (control.pressed ? Qt.darker(Theme.verdigris, 1.15)
                                   : (control.hovered ? Qt.darker(Theme.verdigris, 1.05) : Theme.verdigris))
               : (control.pressed ? Theme.hairline : "transparent")
        border.width: control.primary ? 0 : 1
        border.color: Theme.hairline
    }
}
