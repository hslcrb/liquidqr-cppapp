import QtQuick
import QtQuick.Controls

TextField {
    id: control
    
    padding: 18
    font.family: "Noto Sans KR"
    font.pixelSize: 18
    font.weight: Font.Bold
    color: "#1976d2"
    
    background: Rectangle {
        radius: 25
        color: control.activeFocus ? "rgba(255, 255, 255, 0.6)" : "rgba(255, 255, 255, 0.4)"
        border.color: control.activeFocus ? "rgba(255, 255, 255, 0.8)" : "rgba(255, 255, 255, 0.5)"
        border.width: 1
        
        Behavior on color { ColorAnimation { duration: 200 } }
        
        Rectangle {
            anchors.fill: parent
            anchors.margins: 1
            radius: 24
            color: "transparent"
            border.color: "rgba(255, 255, 255, 0.3)"
            border.width: 1
        }
    }
    
    placeholderText: "텍스트를 입력하세요..."
    placeholderTextColor: "#81c784"
}
