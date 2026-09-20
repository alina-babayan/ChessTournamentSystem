pragma Singleton
import QtQuick

QtObject {
    // Palette — an analog chess tournament hall: paper scoresheets, walnut
    // boards, brass clocks — rather than a generic SaaS palette.
    readonly property color ivory: "#F5F1E8"
    readonly property color parchment: "#EBE3D2"
    readonly property color walnut: "#2B2016"
    readonly property color walnutMuted: "#7A6A55"
    readonly property color hairline: "#D9CDB6"
    readonly property color verdigris: "#3F6B54"
    readonly property color crimson: "#9C2B3A"
    readonly property color gold: "#AD8A3F"

    readonly property string serifFamily: "Palatino Linotype"
    readonly property string sansFamily: "Segoe UI"
    readonly property string monoFamily: "Consolas"

    readonly property int radiusSmall: 4
    readonly property int radiusMedium: 8

    readonly property int spaceXS: 4
    readonly property int spaceS: 8
    readonly property int spaceM: 16
    readonly property int spaceL: 24
    readonly property int spaceXL: 32
}
