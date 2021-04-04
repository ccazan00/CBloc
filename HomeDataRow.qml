import QtQuick 2.0

Rectangle {
    id: root

    width: 450
    height: 30
    radius: 12

    property alias nameText: rowName.text
    property alias valueText: rowValue.text
    color: "#000000"

    Text {
        id: rowName
        anchors.verticalCenter: root.verticalCenter
        anchors.left: root.left
        anchors.leftMargin: 20
        font.pixelSize: 14
        color: "#a0a0a0"
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: rowValue
        anchors.verticalCenter: root.verticalCenter
        anchors.right: root.right
        anchors.rightMargin: 20
        font.pixelSize: 14
        color: "#ffffff"
        verticalAlignment: Text.AlignVCenter
    }
}
