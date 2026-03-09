import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../styles" as Styles

Rectangle {
    id: root
    required property string label
    required property string value

    radius: 8
    color: Styles.Theme.surface
    border.width: 1
    border.color: Styles.Theme.border

    Layout.fillWidth: true
    implicitHeight: 62

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 2

        Label {
            text: root.label
            color: Styles.Theme.textSecondary
            font.pixelSize: 12
            font.bold: true
        }

        Label {
            text: root.value.length > 0 ? root.value : qsTr("-")
            color: Styles.Theme.textPrimary
            font.pixelSize: 16
        }
    }
}
