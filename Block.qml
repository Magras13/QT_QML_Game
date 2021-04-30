import QtQuick 2.0

Rectangle {
    id: root

    property string displayText: ""
    color: "lightgreen"

    radius: 10
    border.color: "black"
    border.width: 1

    Text{
        id: _firtsText
        anchors.centerIn: root

        text: root.displayText

        font.bold: true
        font.pointSize: root.height * 0.33
    }


}
