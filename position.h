#pragma once
#include <QChar>
#include <QString>
#include <QStringList>
#include "enums.h"

// A minimal 8x8 board tracker used to produce a piece-placement FEN string
// from recorded moves. This is NOT a full rules engine: it does not validate
// legality, and always reports "-" for castling rights and en passant
// (neither is tracked). It exists to give exportPositionFen() a real,
// human-checkable board snapshot instead of a placeholder string.
class Position {
public:
    Position() { resetToStartingPosition(); }

    void resetToStartingPosition() {
        static const char backRank[8] = {'R','N','B','Q','K','B','N','R'};
        for (int file = 0; file < 8; ++file) {
            m_board[0][file] = QChar(backRank[file]);            // rank 1 (White)
            m_board[1][file] = QChar('P');                       // rank 2 (White pawns)
            for (int rank = 2; rank < 6; ++rank)
                m_board[rank][file] = QChar(' ');                // empty
            m_board[6][file] = QChar('p');                       // rank 7 (Black pawns)
            m_board[7][file] = QChar(backRank[file]).toLower();  // rank 8 (Black)
        }
    }

    // Moves whatever occupies `from` to `to` (overwriting any captured piece),
    // applying the correct case for `color` and honoring promotion if given.
    void applyMove(const QString &from, const QString &to, const QString &pieceLetter,
                    Color color, const QString &promotion) {
        int ff, fr, tf, tr;
        if (!parseSquare(from, ff, fr) || !parseSquare(to, tf, tr))
            return;

        QChar piece = pieceLetter.isEmpty() ? m_board[fr][ff] : QChar(pieceLetter.at(0));
        if (!promotion.isEmpty())
            piece = QChar(promotion.at(0));
        piece = color == Color::White ? piece.toUpper() : piece.toLower();

        m_board[tr][tf] = piece;
        m_board[fr][ff] = QChar(' ');
    }

    QString toFen(Color sideToMove, int fullMoveNumber) const {
        QStringList ranks;
        for (int rank = 7; rank >= 0; --rank) {
            QString row;
            int emptyRun = 0;
            for (int file = 0; file < 8; ++file) {
                QChar c = m_board[rank][file];
                if (c == QChar(' ')) {
                    ++emptyRun;
                } else {
                    if (emptyRun > 0) { row += QString::number(emptyRun); emptyRun = 0; }
                    row += c;
                }
            }
            if (emptyRun > 0) row += QString::number(emptyRun);
            ranks << row;
        }
        QString placement = ranks.join('/');
        QString active = sideToMove == Color::White ? "w" : "b";
        return QStringLiteral("%1 %2 - - 0 %3").arg(placement, active).arg(fullMoveNumber);
    }

private:
    static bool parseSquare(const QString &sq, int &file, int &rank) {
        if (sq.size() != 2) return false;
        QChar f = sq.at(0), r = sq.at(1);
        if (f < 'a' || f > 'h' || r < '1' || r > '8') return false;
        file = f.unicode() - 'a';
        rank = r.unicode() - '1';
        return true;
    }

    QChar m_board[8][8];
};
