import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import ChessTournament

ApplicationWindow {
    id: root
    width: 1080
    height: 680
    visible: true
    title: "Chess Tournament System"
    color: Theme.ivory

    property int currentSection: 0

    RowLayout {
        anchors.fill: parent
        spacing: 0

        // Navigation rail — the one bold element in the design.
        Rectangle {
            width: 224
            Layout.preferredWidth: 224
            Layout.fillHeight: true
            color: Theme.walnut
            clip: true

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Theme.spaceL
                spacing: Theme.spaceXL

                RowLayout {
                    spacing: Theme.spaceS
                    Text { text: "♟"; font.pixelSize: 24; color: Theme.gold }
                    Text {
                        text: "Chess Tournament"
                        font.family: Theme.serifFamily
                        font.pixelSize: 18
                        font.weight: Font.DemiBold
                        color: Theme.ivory
                        wrapMode: Text.WordWrap
                        Layout.fillWidth: true
                    }
                }

                ColumnLayout {
                    spacing: Theme.spaceXS
                    Layout.topMargin: Theme.spaceM

                    Repeater {
                        model: [
                            { glyph: "♟", label: "Roster" },
                            { glyph: "♞", label: "Match" },
                            { glyph: "♛", label: "Standings" }
                        ]
                        delegate: Rectangle {
                            Layout.fillWidth: true
                            height: 44
                            radius: Theme.radiusSmall
                            color: root.currentSection === index ? Qt.rgba(1, 1, 1, 0.08) : "transparent"

                            Rectangle {
                                visible: root.currentSection === index
                                width: 3
                                height: parent.height - 12
                                anchors.left: parent.left
                                anchors.verticalCenter: parent.verticalCenter
                                color: Theme.gold
                                radius: 2
                            }

                            RowLayout {
                                anchors.fill: parent
                                anchors.leftMargin: Theme.spaceM
                                anchors.rightMargin: Theme.spaceM
                                spacing: Theme.spaceS

                                Text {
                                    text: modelData.glyph
                                    font.pixelSize: 16
                                    color: root.currentSection === index ? Theme.gold : Theme.ivory
                                }
                                Text {
                                    text: modelData.label
                                    font.family: Theme.sansFamily
                                    font.pixelSize: 14
                                    color: Theme.ivory
                                    opacity: root.currentSection === index ? 1.0 : 0.75
                                }
                            }

                            MouseArea {
                                anchors.fill: parent
                                cursorShape: Qt.PointingHandCursor
                                onClicked: root.currentSection = index
                            }
                        }
                    }
                }

                Item { Layout.fillHeight: true }

                Text {
                    text: "Tournament Administration"
                    font.family: Theme.sansFamily
                    font.pixelSize: 11
                    color: Qt.rgba(1, 1, 1, 0.45)
                    wrapMode: Text.WordWrap
                    Layout.fillWidth: true
                }
            }
        }

        StackLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            currentIndex: root.currentSection

            RegisterPlayerView {}
            MatchView {}
            StandingsView {}
        }
    }
}
