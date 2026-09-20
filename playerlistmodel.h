#pragma once
#include <QAbstractListModel>
#include "player.h"

class PlayerListModel : public QAbstractListModel {
    Q_OBJECT
public:
    enum Roles { IdRole = Qt::UserRole + 1, NameRole, RatingRole, FederationRole };

    explicit PlayerListModel(QObject *parent = nullptr) : QAbstractListModel(parent) {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        if (parent.isValid()) return 0;
        return m_players.size();
    }

    QVariant data(const QModelIndex &index, int role) const override {
        if (!index.isValid() || index.row() >= m_players.size())
            return {};
        const Player *p = m_players.at(index.row());
        switch (role) {
            case IdRole: return p->id();
            case NameRole: return p->name();
            case RatingRole: return p->rating();
            case FederationRole: return p->federation();
        }
        return {};
    }

    QHash<int, QByteArray> roleNames() const override {
        return { {IdRole, "playerId"}, {NameRole, "name"},
                 {RatingRole, "rating"}, {FederationRole, "federation"} };
    }

    // UC-1 step 4: registration entry point
    bool registerPlayer(const QString &name, int rating, const QString &federation) {
        if (name.trimmed().isEmpty())
            return false; // UC-1 step 3a

        // UC-1 step 3: uniqueness / basic validation could be extended here
        int newId = m_nextId++;
        beginInsertRows(QModelIndex(), m_players.size(), m_players.size());
        m_players.append(new Player(newId, name, rating, federation, this));
        endInsertRows();
        emit playerRegistered(newId);
        return true;
    }

    Player *findById(int id) const {
        for (auto *p : m_players)
            if (p->id() == id) return p;
        return nullptr;
    }

    const QList<Player*> &players() const { return m_players; }

signals:
    void playerRegistered(int playerId);

private:
    QList<Player*> m_players;
    int m_nextId = 1;
};
