import QtQuick 2.0

Item {
    id: root

    property int selectedViewIndex: 0

    Rectangle {
        id: background

        anchors.fill: root

        color: "#ffffff"
        border.width: 1
        border.color: "#4080A0"

        Row {
            FooterButton {
                text: "Home"
                selected: selectedViewIndex === 0
                onClicked: selectedViewIndex = 0
            }
            FooterButton {
                text: "Payments"
                selected: selectedViewIndex === 1
                onClicked: selectedViewIndex = 1
            }
            FooterButton {
                text: "History"
                selected: selectedViewIndex === 2
                onClicked: selectedViewIndex = 2
            }
        }
    }
}
