import QtQuick 2.0

Rectangle {
    id: root

    color: "#f7f7f7"
    radius: 5;
    border.color: "#4080A0"
    border.width: 1

    Component.onCompleted: {
        homeDataModel.requestUpdate()
    }

    Text {
        id: panelName
        anchors.top: root.top
        anchors.topMargin: 20
        anchors.left: root.left
        anchors.leftMargin: 20
        text: "Home"
        font.pixelSize: 30
        font.weight: Font.Bold
    }

    Column {
        anchors.horizontalCenter: root.horizontalCenter
        anchors.bottom: root.bottom
        anchors.bottomMargin: 20
        spacing: 10
        HomeDataRow {
            id: addressRow
            nameText: "Address: "
            valueText: homeDataModel.address
        }
        HomeDataRow {
            id: buildingName
            nameText: "Building Name: "
            valueText: homeDataModel.buildingName
        }
        HomeDataRow {
            id: flatNo
            nameText: "Flat Number: "
            valueText: homeDataModel.flatNo
        }
        HomeDataRow {
            id: flatStaircase
            nameText: "Flat Staircase: "
            valueText: homeDataModel.flatStaircase
        }
        HomeDataRow {
            id: maintenancePayment
            nameText: "Payment: "
            valueText: homeDataModel.maintenancePayment
        }
        HomeDataRow {
            id: maintenanceDueTo
            nameText: "Due Date: "
            valueText: homeDataModel.maintenanceDueTo
        }
        HomeDataRow {
            id: indexes
            nameText: "Indexes: "
            valueText: homeDataModel.indexes
        }
        HomeDataRow {
            id: notificationNumber
            nameText: "Notification Number: "
            valueText: homeDataModel.notificationNumber
        }
    }
}
