import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "views" as Views
import "styles" as Styles

ApplicationWindow {
    id: window
    width: 1180
    height: 760
    visible: true
    title: qsTr("Modern Qt Architecture")

    color: Styles.Theme.background

    Component.onCompleted: machineListViewModel.loadMachines()

    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: Styles.Theme.gradientStart }
            GradientStop { position: 1.0; color: Styles.Theme.gradientEnd }
        }
        opacity: 0.65
    }

    Views.MachineListView {
        anchors.fill: parent
        anchors.margins: 24
        viewModel: machineListViewModel
    }
}
