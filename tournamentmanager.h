#pragma once
#include <QObject>
#include <QQmlEngine>
#include "playerlistmodel.h"
#include "standingsmodel.h"
#include "match.h"

class TournamentManager : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(PlayerListModel* players READ players CONSTANT)
    Q_PROPERTY(StandingsModel* standings READ standings CONSTANT)
    Q_PROPERTY(Match* activeMatch READ activeMatch NOTIFY activeMatchChanged)

public:
    explicit TournamentManager(QObject *parent = nullptr)
        : QObject(parent),
          m_players(new PlayerListModel(this)),
          m_standings(new StandingsModel(this)) {}

    PlayerListModel *players() const { return m_players; }
    StandingsModel *standings() const { return m_standings; }
    Match *activeMatch() const { return m_activeMatch; }

    // UC-1: Register participant
    Q_INVOKABLE bool registerPlayer(const QString &name, int rating, const QString &federation) {
        bool ok = m_players->registerPlayer(name, rating, federation);
        if (ok) m_standings->ensureEntry(m_players->players().last());
        return ok;
    }

    // UC-2 steps 1-2: create match, auto-assign colors by alternation rule
    Q_INVOKABLE bool createMatch(int player1Id, int player2Id) {
        Player *p1 = m_players->findById(player1Id);
        Player *p2 = m_players->findById(player2Id);
        if (!p1 || !p2 || p1 == p2) return false;

        Color p1Color = colorFor(p1);
        Player *white = (p1Color == Color::White) ? p1 : p2;
        Player *black = (white == p1) ? p2 : p1;

        if (m_activeMatch) m_activeMatch->deleteLater();
        m_activeMatch = new Match(white, black, this);
        connect(m_activeMatch, &Match::resultChanged, this, [this]() {
            m_standings->applyResult(m_activeMatch->whitePlayer(),
                                      m_activeMatch->blackPlayer(),
                                      m_activeMatch->result());
        });
        emit activeMatchChanged();
        m_history.append(m_activeMatch);
        return true;
    }

signals:
    void activeMatchChanged();

private:
    // Alternation rule: player who was NOT white last time gets white now.
    // Never-played players default to White.
    Color colorFor(Player *p) const {
        for (int i = m_history.size() - 1; i >= 0; --i) {
            Match *m = m_history.at(i);
            if (m->whitePlayer() == p) return Color::Black;
            if (m->blackPlayer() == p) return Color::White;
        }
        return Color::White;
    }

    PlayerListModel *m_players;
    StandingsModel *m_standings;
    Match *m_activeMatch = nullptr;
    QList<Match*> m_history;
};
