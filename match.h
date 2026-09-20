#pragma once
#include <QObject>
#include <QDateTime>
#include <QQmlEngine>
#include "enums.h"
#include "player.h"
#include "movelistmodel.h"
#include "position.h"

class Match : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("Created by TournamentManager")
    Q_PROPERTY(Player* whitePlayer READ whitePlayer CONSTANT)
    Q_PROPERTY(Player* blackPlayer READ blackPlayer CONSTANT)
    Q_PROPERTY(MatchStatus status READ status NOTIFY statusChanged)
    Q_PROPERTY(MatchResult result READ result NOTIFY resultChanged)
    Q_PROPERTY(QDateTime startTimestamp READ startTimestamp NOTIFY startedChanged)
    Q_PROPERTY(QDateTime endTimestamp READ endTimestamp NOTIFY finishedChanged)
    Q_PROPERTY(MoveListModel* moveModel READ moveModel CONSTANT)

public:
    explicit Match(QObject *parent = nullptr) : QObject(parent), m_moveModel(new MoveListModel(this)) {}

    Match(Player *white, Player *black, QObject *parent = nullptr)
        : QObject(parent), m_white(white), m_black(black),
          m_moveModel(new MoveListModel(this)) {}

    Player *whitePlayer() const { return m_white; }
    Player *blackPlayer() const { return m_black; }
    MatchStatus status() const { return m_status; }
    MatchResult result() const { return m_result; }
    QDateTime startTimestamp() const { return m_start; }
    QDateTime endTimestamp() const { return m_end; }
    MoveListModel *moveModel() const { return m_moveModel; }

    // UC-2 step 3: record match start
    Q_INVOKABLE bool start(const QDateTime &when = QDateTime::currentDateTime()) {
        if (m_status != MatchStatus::Scheduled) {
            emit errorOccurred(QStringLiteral("Match already started or finished."));
            return false;
        }
        m_start = when;
        m_status = MatchStatus::InProgress;
        emit startedChanged();
        emit statusChanged();
        return true;
    }

    // UC-2 step 4: record a move
    Q_INVOKABLE bool recordMove(const QString &from, const QString &to,
                                 const QString &piece, bool isCapture = false,
                                 const QString &promotion = QString()) {
        if (m_status != MatchStatus::InProgress) {
            emit errorOccurred(QStringLiteral("Cannot record a move: match is not in progress."));
            return false;
        }
        if (!isValidSquare(from) || !isValidSquare(to)) {
            emit errorOccurred(QStringLiteral("Invalid square notation."));
            return false;
        }
        Move mv;
        mv.number = m_moveModel->rowCount() + 1;
        mv.mover = (m_moveModel->rowCount() % 2 == 0) ? Color::White : Color::Black;
        mv.from = from;
        mv.to = to;
        mv.piece = piece;
        mv.isCapture = isCapture;
        mv.promotion = promotion;
        mv.timestamp = QDateTime::currentDateTime();
        m_position.applyMove(from, to, piece, mv.mover, promotion);
        m_moveModel->appendMove(mv);
        emit moveRecorded(mv.number);
        return true;
    }

    // UC-2 step 5-6: record match end and result
    Q_INVOKABLE bool finish(MatchResult result, const QDateTime &when = QDateTime::currentDateTime()) {
        if (m_status != MatchStatus::InProgress) {
            emit errorOccurred(QStringLiteral("Cannot finish: match is not in progress."));
            return false;
        }
        m_result = result;
        m_end = when;
        m_status = MatchStatus::Finished;
        emit resultChanged();
        emit finishedChanged();
        emit statusChanged();
        return true;
    }

    // Points helper for standings (UC-2 step 7)
    double pointsFor(Color c) const {
        if (m_result == MatchResult::Draw) return 0.5;
        if (m_result == MatchResult::WhiteWins) return c == Color::White ? 1.0 : 0.0;
        if (m_result == MatchResult::BlackWins) return c == Color::Black ? 1.0 : 0.0;
        return 0.0;
    }

    // Export the current board position as a FEN string, reconstructed by
    // replaying every recorded move. Castling rights and en passant are not
    // tracked and always report as "-" (see position.h).
    Q_INVOKABLE QString exportPositionFen() const {
        Color sideToMove = (m_moveModel->rowCount() % 2 == 0) ? Color::White : Color::Black;
        int fullMoveNumber = m_moveModel->rowCount() / 2 + 1;
        return m_position.toFen(sideToMove, fullMoveNumber);
    }

signals:
    void statusChanged();
    void resultChanged();
    void startedChanged();
    void finishedChanged();
    void moveRecorded(int moveNumber);
    void errorOccurred(const QString &message);

private:
    static bool isValidSquare(const QString &sq) {
        if (sq.size() != 2) return false;
        QChar file = sq.at(0), rank = sq.at(1);
        return file >= 'a' && file <= 'h' && rank >= '1' && rank <= '8';
    }

    Player *m_white = nullptr;
    Player *m_black = nullptr;
    MatchStatus m_status = MatchStatus::Scheduled;
    MatchResult m_result = MatchResult::Ongoing;
    QDateTime m_start;
    QDateTime m_end;
    MoveListModel *m_moveModel;
    Position m_position;
};
