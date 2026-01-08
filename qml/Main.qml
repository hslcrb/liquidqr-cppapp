import QtQuick
import QtQuick.Controls
import LiquidQR

Window {
    id: window
    width: 450
    height: 700
    visible: true
    title: "Liquid QR Coder"
    color: "transparent"
    flags: Qt.FramelessWindowHint | Qt.Window

    // 전역 상태
    property string lang: "ko"
    property int qrNonce: 0 // 이미지 리프레시용

    Connections {
        target: QRGenerator
        function onQrImageChanged() {
            qrNonce++
        }
    }

    LiquidBackground {
        anchors.fill: parent
    }

    // 메인 컨텐츠
    Column {
        anchors.fill: parent

        TitleBar {
            width: parent.width
        }

        Item {
            width: parent.width
            height: parent.height - 40

            Column {
                anchors.centerIn: parent
                width: parent.width * 0.9
                spacing: 30

                // 헤더
                Column {
                    width: parent.width
                    spacing: 5
                    
                    Text {
                        width: parent.width
                        horizontalAlignment: Text.AlignHCenter
                        text: lang === "ko" ? "실시간 QR 생성기" : "Live QR Generator"
                        font.family: "Noto Sans KR"
                        font.pixelSize: 32
                        font.weight: Font.Black
                        color: "#1976d2"
                    }
                    
                    Text {
                        width: parent.width
                        horizontalAlignment: Text.AlignHCenter
                        text: lang === "ko" ? "입력과 동시에 QR 코드가 생성됩니다" : "QR code generates as you type"
                        font.family: "Noto Sans KR"
                        font.pixelSize: 14
                        color: "#42a5f5"
                    }
                }

                // 입력 필드
                StyledInput {
                    id: inputField
                    width: parent.width
                    placeholderText: lang === "ko" ? "텍스트를 입력하세요..." : "Enter text here..."
                    onTextChanged: QRGenerator.text = text
                }

                // QR 디스플레이
                GlassContainer {
                    width: parent.width
                    height: width
                    
                    Image {
                        anchors.centerIn: parent
                        width: parent.width * 0.8
                        height: width
                        fillMode: Image.PreserveAspectFit
                        source: QRGenerator.text !== "" ? "image://qrgen/latest?id=" + qrNonce : ""
                        visible: QRGenerator.text !== ""
                        
                        Rectangle {
                            anchors.fill: parent
                            anchors.margins: -10
                            radius: 15
                            color: "white"
                            z: -1
                            opacity: 0.9
                        }
                    }

                    Text {
                        anchors.centerIn: parent
                        width: parent.width * 0.8
                        horizontalAlignment: Text.AlignHCenter
                        wrapMode: Text.WordWrap
                        text: lang === "ko" ? "위에 텍스트를 입력하면\nQR 코드가 나타납니다" : "QR code will appear\nwhen you type above"
                        font.family: "Noto Sans KR"
                        color: "#81c784"
                        visible: QRGenerator.text === ""
                    }
                }

                // 언어 전환 버튼
                Button {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: lang === "ko" ? "English" : "한국어"
                    onClicked: lang = (lang === "ko" ? "en" : "ko")
                    
                    contentItem: Text {
                        text: parent.text
                        font.family: "Noto Sans KR"
                        font.weight: Font.Bold
                        color: "#1976d2"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                    
                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 40
                        radius: 20
                        color: "rgba(255, 255, 255, 0.5)"
                        border.color: "rgba(255, 255, 255, 0.3)"
                    }
                }
            }
        }
    }
}
