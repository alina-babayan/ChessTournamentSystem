import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import ChessTournament

Flickable {
    id: root
    contentWidth: width
    contentHeight: content.implicitHeight + Theme.spaceXL * 2
    clip: true

    property var match: TournamentManager.activeMatch

    function parseDateTime(text) {
        var m = text.match(/^(\d{4})-(\d{2})-(\d{2})[ T](\d{2}):(\d{2})(?::(\d{2}))?$/)
        if (!m) return null
        var d = new Date(parseInt(m[1]), parseInt(m[2]) - 1, parseInt(m[3]),
                          parseInt(m[4]), parseInt(m[5]), m[6] ? parseInt(m[6]) : 0)
        return isNaN(d.getTime()) ? null : d
    }

    function fillNow(field) {
        field.text = Qt.formatDateTime(new Date(), "yyyy-MM-dd HH:mm:ss")
    }

    Connections {
        target: TournamentManager
        function onActiveMatchChanged() {
            root.match = TournamentManager.activeMatch
            fillNow(startTimeField)
            fillNow(endTimeField)
        }
    }
    Connections {
        target: root.match
        function onErrorOccurred(message) { errorLabel.text = message }
        function onStatusChanged() { errorLabel.text = "" }
    }

    ColumnLayout {
        id: content
        x: Theme.spaceXL
        y: Theme.spaceXL
        width: parent.width - Theme.spaceXL * 2
        spacing: Theme.spaceL

        Text {
            text: "Match"
            font.family: Theme.serifFamily
            font.pixelSize: 28
            font.weight: Font.DemiBold
            color: Theme.walnut
        }
        Text {
            text: "Pair two registered players, then track the game move by move."
            font.family: Theme.sansFamily
            font.pixelSize: 14
            color: Theme.walnutMuted
        }

        SectionCard {
            title: "Pairing"
            Layout.fillWidth: true

            RowLayout {
                Layout.fillWidth: true
                spacing: Theme.spaceM

                ColumnLayout {
                    spacing: 2
                    Text { text: "Player 1 ID"; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
                    SpinBox { id: p1Id; from: 1; to: 9999 }
                }
                ColumnLayout {
                    spacing: 2
                    Text { text: "Player 2 ID"; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
                    SpinBox { id: p2Id; from: 1; to: 9999 }
                }
                Item { Layout.fillWidth: true }
                AppButton {
                    text: "Create match"
                    onClicked: {
                        var ok = TournamentManager.createMatch(p1Id.value, p2Id.value)
                        errorLabel.text = ok ? "" : "Could not create match: check that both player IDs are registered and distinct."
                    }
                }
            }

            RowLayout {
                visible: root.match !== null
                Layout.fillWidth: true
                spacing: Theme.spaceM

                ColumnLayout {
                    spacing: 2
                    Text { text: "Start time (yyyy-MM-dd HH:mm:ss)"; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
                    AppTextField { id: startTimeField; Layout.preferredWidth: 220; placeholderText: "yyyy-MM-dd HH:mm:ss" }
                }
                AppButton { text: "Now"; primary: false; onClicked: root.fillNow(startTimeField) }
                Item { Layout.fillWidth: true }
                AppButton {
                    text: "Start match"
                    enabled: root.match !== null
                    onClicked: {
                        var dt = root.parseDateTime(startTimeField.text)
                        if (!dt) {
                            errorLabel.text = "Enter the start time as yyyy-MM-dd HH:mm (seconds optional)."
                            return
                        }
                        root.match.start(dt)
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
            visible: root.match !== null
            title: "Board"
            Layout.fillWidth: true

            RowLayout {
                Layout.fillWidth: true
                spacing: Theme.spaceL

                ColumnLayout {
                    spacing: 2
                    Layout.fillWidth: true
                    Text { text: "White"; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
                    Text {
                        text: root.match ? root.match.whitePlayer.name : ""
                        font.family: Theme.serifFamily
                        font.pixelSize: 18
                        color: Theme.walnut
                    }
                }
                Text { text: "vs"; font.family: Theme.serifFamily; font.italic: true; font.pixelSize: 16; color: Theme.walnutMuted }
                ColumnLayout {
                    spacing: 2
                    Layout.fillWidth: true
                    Text { text: "Black"; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
                    Text {
                        text: root.match ? root.match.blackPlayer.name : ""
                        font.family: Theme.serifFamily
                        font.pixelSize: 18
                        color: Theme.walnut
                    }
                }

                StatusPill {
                    text: !root.match ? ""
                          : root.match.status === ChessEnums.Scheduled ? "Scheduled"
                          : root.match.status === ChessEnums.InProgress ? "In progress"
                          : "Finished"
                    tint: !root.match ? Theme.walnutMuted
                          : root.match.status === ChessEnums.InProgress ? Theme.verdigris
                          : root.match.status === ChessEnums.Finished ? Theme.gold
                          : Theme.walnutMuted
                }
            }

            ColumnLayout {
                spacing: 2
                Text {
                    visible: root.match !== null && root.match.status !== ChessEnums.Scheduled
                    text: root.match ? "Started " + Qt.formatDateTime(root.match.startTimestamp, "yyyy-MM-dd HH:mm") : ""
                    font.family: Theme.sansFamily
                    font.pixelSize: 12
                    color: Theme.walnutMuted
                }
                Text {
                    visible: root.match !== null && root.match.status === ChessEnums.Finished
                    text: root.match ? "Ended " + Qt.formatDateTime(root.match.endTimestamp, "yyyy-MM-dd HH:mm") : ""
                    font.family: Theme.sansFamily
                    font.pixelSize: 12
                    color: Theme.walnutMuted
                }
            }
        }

        SectionCard {
            visible: root.match !== null
            title: "Record a move"
            Layout.fillWidth: true

            RowLayout {
                Layout.fillWidth: true
                spacing: Theme.spaceM

                AppTextField { id: fromField; placeholderText: "from, e.g. e2"; Layout.preferredWidth: 130 }
                AppTextField { id: toField; placeholderText: "to, e.g. e4"; Layout.preferredWidth: 130 }
                AppTextField { id: pieceField; placeholderText: "piece, e.g. P"; Layout.preferredWidth: 130 }
                CheckBox {
                    id: captureBox
                    text: "Capture"
                    contentItem: Text {
                        text: captureBox.text
                        font.family: Theme.sansFamily
                        font.pixelSize: 13
                        color: Theme.walnut
                        leftPadding: captureBox.indicator.width + 6
                        verticalAlignment: Text.AlignVCenter
                    }
                }
                AppButton {
                    text: "Record move"
                    onClicked: {
                        root.match.recordMove(fromField.text, toField.text, pieceField.text, captureBox.checked)
                        fromField.clear(); toField.clear(); pieceField.clear(); captureBox.checked = false
                    }
                }
            }
        }

        SectionCard {
            visible: root.match !== null && root.match.moveModel.rowCount() > 0
            title: "Scoresheet"
            Layout.fillWidth: true

            RowLayout {
                Layout.fillWidth: true
                Text { text: "No."; Layout.preferredWidth: 40; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
                Text { text: "Side"; Layout.preferredWidth: 60; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
                Text { text: "Move"; Layout.fillWidth: true; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
            }
            Rectangle { Layout.fillWidth: true; height: 1; color: Theme.hairline }

            Repeater {
                model: root.match ? root.match.moveModel : null
                delegate: Rectangle {
                    Layout.fillWidth: true
                    height: 32
                    color: mover === "White" ? "transparent" : Qt.rgba(0, 0, 0, 0.02)

                    RowLayout {
                        anchors.fill: parent
                        Text { text: moveNumber; Layout.preferredWidth: 40; font.family: Theme.monoFamily; font.pixelSize: 13; color: Theme.walnutMuted }
                        Text { text: mover; Layout.preferredWidth: 60; font.family: Theme.sansFamily; font.pixelSize: 13; color: Theme.walnut }
                        Text {
                            text: from + " \u2192 " + to + "  " + piece + (isCapture ? " \u00d7" : "")
                            Layout.fillWidth: true
                            font.family: Theme.monoFamily
                            font.pixelSize: 13
                            color: Theme.walnut
                        }
                    }
                }
            }
        }

        SectionCard {
            visible: root.match !== null
            title: "Result"
            Layout.fillWidth: true

            RowLayout {
                Layout.fillWidth: true
                spacing: Theme.spaceM

                ColumnLayout {
                    spacing: 2
                    Text { text: "End time (yyyy-MM-dd HH:mm:ss)"; font.family: Theme.sansFamily; font.pixelSize: 12; color: Theme.walnutMuted }
                    AppTextField { id: endTimeField; Layout.preferredWidth: 220; placeholderText: "yyyy-MM-dd HH:mm:ss" }
                }
                AppButton { text: "Now"; primary: false; onClicked: root.fillNow(endTimeField) }
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: Theme.spaceM

                AppButton {
                    text: "White wins"
                    onClicked: {
                        var dt = root.parseDateTime(endTimeField.text)
                        if (!dt) { errorLabel.text = "Enter the end time as yyyy-MM-dd HH:mm (seconds optional)."; return }
                        root.match.finish(ChessEnums.WhiteWins, dt)
                    }
                }
                AppButton {
                    text: "Black wins"
                    onClicked: {
                        var dt = root.parseDateTime(endTimeField.text)
                        if (!dt) { errorLabel.text = "Enter the end time as yyyy-MM-dd HH:mm (seconds optional)."; return }
                        root.match.finish(ChessEnums.BlackWins, dt)
                    }
                }
                AppButton {
                    text: "Draw"
                    primary: false
                    onClicked: {
                        var dt = root.parseDateTime(endTimeField.text)
                        if (!dt) { errorLabel.text = "Enter the end time as yyyy-MM-dd HH:mm (seconds optional)."; return }
                        root.match.finish(ChessEnums.Draw, dt)
                    }
                }
                Item { Layout.fillWidth: true }
                AppButton {
                    text: "Export position"
                    primary: false
                    enabled: root.match !== null
                    onClicked: {
                        var fen = root.match.exportPositionFen()
                        var ok = Exporter.exportPositionToFile(fen, "position.fen")
                        exportPositionLabel.text = ok ? "Exported current position to position.fen" : "Export failed."
                    }
                }
            }

            Text {
                id: exportPositionLabel
                Layout.fillWidth: true
                font.family: Theme.sansFamily
                font.pixelSize: 13
                color: Theme.walnutMuted
            }
        }
    }
}
