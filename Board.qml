import QtQuick 2.0
import Game 1.0;

GridView {
    id: _root
    model: GameBoardModel{

    }

    cellHeight: height / 4
    cellWidth: width / 4

    delegate: Item {
        id: _backgroundDelegate
        width: _root.cellWidth
        height: _root.cellHeight

        visible: display != 16
        Block{
                displayText: display
                anchors.fill: _backgroundDelegate
                anchors.margins: 3
        }
    }
}
