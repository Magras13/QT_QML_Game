#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <QAbstractListModel>
#include <vector>
#include <QVector>

class GameBoard : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int dimension READ dimension CONSTANT)
    Q_PROPERTY(int hiddenValue READ boardSize CONSTANT)
public:
    static constexpr size_t defaultDimension {4};
    using Position = std::pair<size_t, size_t>;
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



    size_t dimension() const;

    size_t boardSize() const;

    Q_INVOKABLE bool move(int index);
    int rowCount(const QModelIndex& parent = QModelIndex{}) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;


private:
    void shuffle();
    bool isPositionValid(const size_t position) const;
    bool isBoardValid() const ;
    Position getRowCol(size_t index) const;

    std::vector<Block> m_rawBoard;
    const size_t m_dimension;
    const size_t m_boardSize;

};

#endif // GAMEBOARD_H
