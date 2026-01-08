import QtQuick

Rectangle {
    id: root
    height: 40
    color: "rgba(255, 255, 255, 0.3)"
    
    Rectangle {
        anchors.bottom: parent.bottom
        width: parent.width
        height: 1
        color: "rgba(255, 255, 255, 0.2)"
    }

    Text {
        anchors.centerIn: parent
        text: "Liquid QR Coder"
        font.family: "Noto Sans KR"
        font.weight: Font.Black
        color: "#1976d2"
        font.pixelSize: 14
    }

    Row {
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10

        // Minimize
        Rectangle {
            width: 12; height: 12; radius: 6
            color: "#ffbd2e"
            MouseArea {
                anchors.fill: parent
                onClicked: window.showMinimized()
            }
        }

        // Close
        Rectangle {
            width: 12; height: 12; radius: 6
            color: "#ff5f56"
            MouseArea {
                anchors.fill: parent
                onClicked: Qt.quit()
            }
        }
    }

    DragHandler {
        onActiveChanged: if (active) window.startSystemMove()
    }
}
