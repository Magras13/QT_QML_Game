import QtQuick 2.0
import Game 1.0;

GridView {
    id: _root
    model: GameBoardModel{

    }

    cellHeight: height / _root.model.dimension
    cellWidth: width / _root.model.dimension

    delegate: Item {
        id: _backgroundDelegate
        width: _root.cellWidth
        height: _root.cellHeight

        visible: display !== _root.model.hiddenValue
        Block{
                displayText: display
                anchors.fill: _backgroundDelegate
                anchors.margins: 3

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        _root.model.move(index);
                    }
                }
        }
    }
}
