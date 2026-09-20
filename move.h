#pragma once
#include <QString>
#include <QDateTime>
#include "enums.h"

struct Move {
    int number = 0;         // ply/full-move index
    Color mover = Color::White;
    QString from;           // e.g. "e2"
    QString to;             // e.g. "e4"
    QString piece;          // e.g. "P", "N", "K"...
    bool isCapture = false;
    bool isCastling = false;
    QString promotion;      // empty if none
    QDateTime timestamp;
};
