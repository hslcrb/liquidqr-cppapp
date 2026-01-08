import QtQuick

Item {
    id: root
    property alias content: container.children
    property real blurRadius: 25

    Rectangle {
        id: container
        anchors.fill: parent
        radius: 35
        
        // Glass effect
        color: "rgba(255, 255, 255, 0.2)"
        border.color: "rgba(255, 255, 255, 0.4)"
        border.width: 1

        // Inner shadow/glow simulation
        Rectangle {
            anchors.fill: parent
            anchors.margins: 1
            radius: 34
            color: "transparent"
            border.color: "rgba(255, 255, 255, 0.6)"
            border.width: 1
        }
    }
}
