import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../components" as Components
import "../styles" as Styles

Item {
    id: root

    required property var viewModel

    Rectangle {
        anchors.fill: parent
        radius: 14
        color: Styles.Theme.surface
        border.width: 1
        border.color: Styles.Theme.border
    }

    RowLayout {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 20

        Rectangle {
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width * 0.56
            radius: 10
            color: Styles.Theme.panel
            border.width: 1
            border.color: Styles.Theme.border

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 16
                spacing: 12

                Label {
                    text: qsTr("Machines")
                    font.pixelSize: 22
                    font.bold: true
                    color: Styles.Theme.textPrimary
                }

                Label {
                    visible: root.viewModel.errorMessage.length > 0
                    text: root.viewModel.errorMessage
                    color: Styles.Theme.error
                    font.pixelSize: 14
                }

                ListView {
                    id: machineList
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    clip: true
                    spacing: 8
                    model: root.viewModel.machineModel

                    delegate: Rectangle {
                        required property int index
                        required property string machineId
                        required property string name
                        required property string status
                        required property string location

                        width: ListView.view.width
                        height: 72
                        radius: 8
                        color: ListView.isCurrentItem ? Styles.Theme.accent : Styles.Theme.surface
                        border.width: 1
                        border.color: ListView.isCurrentItem ? Styles.Theme.accentStrong : Styles.Theme.border

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                machineList.currentIndex = index
                                root.viewModel.selectMachine(index)
                            }
                        }

                        RowLayout {
                            anchors.fill: parent
                            anchors.margins: 12

                            ColumnLayout {
                                Layout.fillWidth: true
                                spacing: 2

                                Label {
                                    text: name
                                    color: Styles.Theme.textPrimary
                                    font.pixelSize: 16
                                    font.bold: true
                                }

                                Label {
                                    text: machineId + " - " + location
                                    color: Styles.Theme.textSecondary
                                    font.pixelSize: 13
                                }
                            }

                            Rectangle {
                                radius: 6
                                color: Styles.Theme.statusBackground
                                border.color: Styles.Theme.border
                                border.width: 1
                                implicitWidth: 110
                                implicitHeight: 30

                                Label {
                                    anchors.centerIn: parent
                                    text: status
                                    color: Styles.Theme.textPrimary
                                    font.pixelSize: 13
                                }
                            }
                        }
                    }
                }
            }
        }

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            radius: 10
            color: Styles.Theme.panel
            border.width: 1
            border.color: Styles.Theme.border

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 16
                spacing: 16

                Label {
                    text: qsTr("Machine Details")
                    font.pixelSize: 22
                    font.bold: true
                    color: Styles.Theme.textPrimary
                }

                Components.DetailField {
                    label: qsTr("ID")
                    value: root.viewModel.selectedMachineId
                }

                Components.DetailField {
                    label: qsTr("Name")
                    value: root.viewModel.selectedMachineName
                }

                Components.DetailField {
                    label: qsTr("Status")
                    value: root.viewModel.selectedMachineStatus
                }

                Components.DetailField {
                    label: qsTr("Location")
                    value: root.viewModel.selectedMachineLocation
                }

                Item { Layout.fillHeight: true }
            }
        }
    }
}
