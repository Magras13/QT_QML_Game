#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <QAbstractListModel>
#include <vector>
#include <QVector>

class GameBoard : public QAbstractListModel
{
    Q_OBJECT
public:
    static constexpr size_t defaultDimension {4};
    GameBoard(const size_t boardDimension = defaultDimension, QObject* parent = nullptr);

    struct Block{
        size_t value {};
        Block& operator=(const size_t newValue){
            value = newValue;
            return *this;
        }
        bool operator==(const size_t other){
            return other == value;
        }
    };

    int rowCount(const QModelIndex& parent = QModelIndex{}) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

private:
    void shuffle();
    std::vector<Block> m_rawBoard;
    const size_t m_dimension;
    const size_t m_boardSize;

};

#endif // GAMEBOARD_H
