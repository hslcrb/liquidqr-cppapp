import QtQuick
import QtQuick.Effects

Item {
    id: root
    anchors.fill: parent

    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#e1f5fe" }
            GradientStop { position: 0.3; color: "#b3e5fc" }
            GradientStop { position: 0.7; color: "#81d4fa" }
            GradientStop { position: 1.0; color: "#4fc3f7" }
        }
    }

    Repeater {
        model: 4
        Item {
            id: blobContainer
            width: parent.width * 0.8
            height: width
            x: (parent.width - width) * (0.5 + 0.3 * Math.sin(animX.value))
            y: (parent.height - height) * (0.5 + 0.3 * Math.cos(animY.value))

            property color blobColor: {
                switch(index) {
                    case 0: return "rgba(255, 255, 255, 0.4)"
                    case 1: return "rgba(144, 202, 249, 0.3)"
                    case 2: return "rgba(255, 255, 255, 0.2)"
                    default: return "rgba(129, 212, 250, 0.25)"
                }
            }

            Rectangle {
                anchors.fill: parent
                radius: width / 2
                color: blobContainer.blobColor
                
                layer.enabled: true
                layer.effect: MultiEffect {
                    blurEnabled: true
                    blur: 1.0
                    blurMaxRadius: 100
                }
            }

            NumberAnimation on x {
                id: animX
                from: -100; to: root.width + 100
                duration: 8000 + index * 2000
                loops: Animation.Infinite
                running: true
                easing.type: Easing.InOutSine
            }
            NumberAnimation on y {
                id: animY
                from: -100; to: root.height + 100
                duration: 10000 + index * 1500
                loops: Animation.Infinite
                running: true
                easing.type: Easing.InOutSine
            }
        }
    }
}
