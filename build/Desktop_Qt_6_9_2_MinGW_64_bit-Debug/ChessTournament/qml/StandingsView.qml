import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import ChessTournament

Flickable {
    id: root
    contentWidth: width
    contentHeight: content.implicitHeight + Theme.spaceXL * 2
    clip: true

    ColumnLayout {
        id: content
        x: Theme.spaceXL
        y: Theme.spaceXL
        width: parent.width - Theme.spaceXL * 2
        spacing: Theme.spaceL

        Text {
            text: "Standings"
            font.family: Theme.serifFamily
            font.pixelSize: 28
            font.weight: Font.DemiBold
            color: Theme.walnut
        }
        Text {
            text: "Updated automatically as matches finish."
            font.family: Theme.sansFamily
            font.pixelSize: 14
            color: Theme.walnutMuted
        }

        SectionCard {
            title: "Crosstable"
            Layout.fillWidth: true

            RowLayout {
                Layout.fillWidth: true
                Text { text: "Rank"; Layout.preferredWidth: 48; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
                Text { text: "Player"; Layout.fillWidth: true; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
                Text { text: "Played"; Layout.preferredWidth: 64; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
                Text { text: "W"; Layout.preferredWidth: 32; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
                Text { text: "D"; Layout.preferredWidth: 32; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
                Text { text: "L"; Layout.preferredWidth: 32; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
                Text { text: "Points"; Layout.preferredWidth: 72; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
            }
            Rectangle { Layout.fillWidth: true; height: 1; color: Theme.hairline }

            Repeater {
                model: TournamentManager.standings
                delegate: Rectangle {
                    Layout.fillWidth: true
                    height: 40
                    color: index % 2 ? Qt.rgba(0, 0, 0, 0.02) : "transparent"

                    Rectangle {
                        visible: index < 3
                        width: 3
                        height: parent.height - 10
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        color: index === 0 ? Theme.gold : Theme.walnutMuted
                        radius: 2
                    }

                    RowLayout {
                        anchors.fill: parent
                        anchors.leftMargin: Theme.spaceS
                        anchors.rightMargin: Theme.spaceS

                        Text { text: index + 1; Layout.preferredWidth: 48; font.family: Theme.monoFamily; font.pixelSize: 13; color: Theme.walnutMuted }
                        Text { text: name; Layout.fillWidth: true; font.family: Theme.sansFamily; font.pixelSize: 14; color: Theme.walnut }
                        Text { text: played; Layout.preferredWidth: 64; font.family: Theme.monoFamily; font.pixelSize: 13; color: Theme.walnut }
                        Text { text: wins; Layout.preferredWidth: 32; font.family: Theme.monoFamily; font.pixelSize: 13; color: Theme.verdigris }
                        Text { text: draws; Layout.preferredWidth: 32; font.family: Theme.monoFamily; font.pixelSize: 13; color: Theme.gold }
                        Text { text: losses; Layout.preferredWidth: 32; font.family: Theme.monoFamily; font.pixelSize: 13; color: Theme.crimson }
                        Text { text: points; Layout.preferredWidth: 72; font.family: Theme.serifFamily; font.pixelSize: 16; font.weight: Font.DemiBold; color: Theme.walnut }
                    }
                }
            }
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: Theme.spaceM

            AppButton {
                text: "Export standings (CSV)"
                onClicked: {
                    var ok = Exporter.exportStandingsCsv(TournamentManager.standings, "standings.csv")
                    exportLabel.text = ok ? "Exported to standings.csv" : "Export failed."
                }
            }
            Text {
                id: exportLabel
                font.family: Theme.sansFamily
                font.pixelSize: 13
                color: Theme.walnutMuted
            }
        }
    }
}
