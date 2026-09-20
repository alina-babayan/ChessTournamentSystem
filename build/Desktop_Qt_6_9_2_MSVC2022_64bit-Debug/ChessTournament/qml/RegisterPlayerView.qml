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
            text: "Roster"
            font.family: Theme.serifFamily
            font.pixelSize: 28
            font.weight: Font.DemiBold
            color: Theme.walnut
        }
        Text {
            text: "Register participants before pairing the first round."
            font.family: Theme.sansFamily
            font.pixelSize: 14
            color: Theme.walnutMuted
        }

        SectionCard {
            title: "Register a participant"
            Layout.fillWidth: true

            RowLayout {
                Layout.fillWidth: true
                spacing: Theme.spaceM

                AppTextField { id: nameField; placeholderText: "Full name"; Layout.fillWidth: true }
                AppTextField {
                    id: ratingField
                    placeholderText: "Rating"
                    validator: IntValidator { bottom: 0; top: 3500 }
                    Layout.preferredWidth: 100
                }
                AppTextField { id: fedField; placeholderText: "Federation"; Layout.preferredWidth: 120 }
                AppButton {
                    text: "Register"
                    onClicked: {
                        var ok = TournamentManager.registerPlayer(
                            nameField.text, parseInt(ratingField.text || "0"), fedField.text)
                        if (ok) {
                            errorLabel.text = ""
                            nameField.clear(); ratingField.clear(); fedField.clear()
                        } else {
                            errorLabel.text = "Registration failed: name cannot be empty."
                        }
                    }
                }
            }

            Text {
                id: errorLabel
                Layout.fillWidth: true
                font.family: Theme.sansFamily
                font.pixelSize: 13
                color: Theme.crimson
            }
        }

        SectionCard {
            title: "Registered players"
            Layout.fillWidth: true

            RowLayout {
                Layout.fillWidth: true
                Text { text: "#"; Layout.preferredWidth: 32; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
                Text { text: "Name"; Layout.fillWidth: true; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
                Text { text: "Rating"; Layout.preferredWidth: 80; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
                Text { text: "Federation"; Layout.preferredWidth: 100; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
            }
            Rectangle { Layout.fillWidth: true; height: 1; color: Theme.hairline }

            Repeater {
                model: TournamentManager.players
                delegate: Rectangle {
                    Layout.fillWidth: true
                    height: 40
                    radius: Theme.radiusSmall
                    color: index % 2 ? Qt.rgba(0, 0, 0, 0.02) : "transparent"

                    RowLayout {
                        anchors.fill: parent
                        anchors.leftMargin: Theme.spaceS
                        anchors.rightMargin: Theme.spaceS

                        Text { text: index + 1; Layout.preferredWidth: 32; font.family: Theme.monoFamily; font.pixelSize: 13; color: Theme.walnutMuted }
                        Text { text: name; Layout.fillWidth: true; font.family: Theme.sansFamily; font.pixelSize: 14; color: Theme.walnut }
                        Text { text: rating; Layout.preferredWidth: 80; font.family: Theme.monoFamily; font.pixelSize: 13; color: Theme.walnut }
                        Text { text: federation; Layout.preferredWidth: 100; font.family: Theme.sansFamily; font.pixelSize: 13; color: Theme.walnutMuted }
                    }
                }
            }
        }
    }
}
