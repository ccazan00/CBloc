import QtQuick 2.12

Item {
    id: root

    property alias selectedViewIndex: footer.selectedViewIndex

    Rectangle {
        id: background

        anchors.fill: root
        color: "#ffffff"

        Loader {
            anchors.top: background.top
            anchors.topMargin: 200
            anchors.horizontalCenter: parent.horizontalCenter
            width: 480
            height: 400

            sourceComponent: HomeDataPanel {
                id: homePanel
                anchors.fill: parent
            }
            active: selectedViewIndex ===  0
        }



    }

    AppFooter {
        id: footer

        width: root.width
        height: 90

        anchors.bottom: root.bottom
    }
}
