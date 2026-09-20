#pragma once
#include <QAbstractTableModel>
#include "player.h"
#include "enums.h"

struct StandingsEntry {
    Player *player;
    int played = 0, wins = 0, draws = 0, losses = 0;
    double points = 0.0;
};

class StandingsModel : public QAbstractTableModel {
    Q_OBJECT
public:
    enum Roles { NameRole = Qt::UserRole + 1, PlayedRole, WinsRole,
                 DrawsRole, LossesRole, PointsRole };

    explicit StandingsModel(QObject *parent = nullptr) : QAbstractTableModel(parent) {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        return parent.isValid() ? 0 : m_entries.size();
    }
    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        return parent.isValid() ? 0 : 6;
    }

    QVariant data(const QModelIndex &index, int role) const override {
        if (!index.isValid() || index.row() >= m_entries.size()) return {};
        const auto &e = m_entries.at(index.row());
        switch (role) {
            case NameRole: return e.player->name();
            case PlayedRole: return e.played;
            case WinsRole: return e.wins;
            case DrawsRole: return e.draws;
            case LossesRole: return e.losses;
            case PointsRole: return e.points;
        }
        return {};
    }

    QHash<int, QByteArray> roleNames() const override {
        return { {NameRole,"name"}, {PlayedRole,"played"}, {WinsRole,"wins"},
                 {DrawsRole,"draws"}, {LossesRole,"losses"}, {PointsRole,"points"} };
    }

    void ensureEntry(Player *p) {
        for (auto &e : m_entries) if (e.player == p) return;
        beginInsertRows(QModelIndex(), m_entries.size(), m_entries.size());
        m_entries.append({p, 0, 0, 0, 0, 0.0});
        endInsertRows();
    }

    // UC-2 step 7: apply a finished match's result to both players' standings
    void applyResult(Player *white, Player *black, MatchResult r) {
        applyOne(white, r == MatchResult::WhiteWins ? 1.0 : (r == MatchResult::Draw ? 0.5 : 0.0));
        applyOne(black, r == MatchResult::BlackWins ? 1.0 : (r == MatchResult::Draw ? 0.5 : 0.0));
    }

    const QList<StandingsEntry> &entries() const { return m_entries; }

private:
    void applyOne(Player *p, double pts) {
        for (int i = 0; i < m_entries.size(); ++i) {
            if (m_entries[i].player != p) continue;
            m_entries[i].played++;
            m_entries[i].points += pts;
            if (pts == 1.0) m_entries[i].wins++;
            else if (pts == 0.5) m_entries[i].draws++;
            else m_entries[i].losses++;
            emit dataChanged(index(i, 0), index(i, columnCount() - 1));
            return;
        }
    }
    QList<StandingsEntry> m_entries;
};
