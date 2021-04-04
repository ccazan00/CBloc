import QtQuick 2.0

Item {
    id: root
    width: 100
    height: 80
    property alias text: buttonText.text
    property bool selected: false

    signal clicked()

    Rectangle {
        id: topBar
        anchors.top: root.top
        anchors.topMargin: 4
        anchors.horizontalCenter: root.horizontalCenter
        width: selected ? 50 : 40
        height: 4
        radius: 2

        color: selected ? "#0080ff" : "#000000"
    }

    Text {
        id: buttonText
        anchors.horizontalCenter: root.horizontalCenter
        anchors.bottom: root.bottom
        anchors.bottomMargin: 4

        color: "#000000"

        font.pixelSize: 14
        font.weight: Font.Bold
        horizontalAlignment: Text.AlignHCenter
    }

    MouseArea {
        anchors.fill: root

        onClicked: {
            root.clicked()
        }
    }

}
