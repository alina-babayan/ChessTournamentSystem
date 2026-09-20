#pragma once
#include <QAbstractListModel>
#include "move.h"

class MoveListModel : public QAbstractListModel {
    Q_OBJECT
public:
    enum Roles { NumberRole = Qt::UserRole + 1, MoverRole, FromRole, ToRole,
                 PieceRole, CaptureRole, PromotionRole };

    explicit MoveListModel(QObject *parent = nullptr) : QAbstractListModel(parent) {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        return parent.isValid() ? 0 : m_moves.size();
    }

    QVariant data(const QModelIndex &index, int role) const override {
        if (!index.isValid() || index.row() >= m_moves.size()) return {};
        const Move &m = m_moves.at(index.row());
        switch (role) {
            case NumberRole: return m.number;
            case MoverRole: return m.mover == Color::White ? QStringLiteral("White") : QStringLiteral("Black");
            case FromRole: return m.from;
            case ToRole: return m.to;
            case PieceRole: return m.piece;
            case CaptureRole: return m.isCapture;
            case PromotionRole: return m.promotion;
        }
        return {};
    }

    QHash<int, QByteArray> roleNames() const override {
        return { {NumberRole,"moveNumber"}, {MoverRole,"mover"}, {FromRole,"from"},
                 {ToRole,"to"}, {PieceRole,"piece"}, {CaptureRole,"isCapture"},
                 {PromotionRole,"promotion"} };
    }

    void appendMove(const Move &m) {
        beginInsertRows(QModelIndex(), m_moves.size(), m_moves.size());
        m_moves.append(m);
        endInsertRows();
    }

    const QList<Move> &moves() const { return m_moves; }

    void clear() {
        beginResetModel();
        m_moves.clear();
        endResetModel();
    }

private:
    QList<Move> m_moves;
};
