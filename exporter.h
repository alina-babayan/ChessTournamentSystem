#pragma once
#include <QObject>
#include <QQmlEngine>
#include <QFile>
#include <QTextStream>
#include "standingsmodel.h"

// Handles exporting current position / standings to disk.
// Extend exportPositionFen() in Match with a real rules engine for accurate FEN.
class Exporter : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    explicit Exporter(QObject *parent = nullptr) : QObject(parent) {}

    // Export the match table / standings as CSV
    Q_INVOKABLE bool exportStandingsCsv(StandingsModel *model, const QString &filePath) {
        if (!model) return false;
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return false;

        QTextStream out(&file);
        out << "Name,Played,Wins,Draws,Losses,Points\n";
        for (const auto &e : model->entries()) {
            out << e.player->name() << ','
                << e.played << ','
                << e.wins << ','
                << e.draws << ','
                << e.losses << ','
                << e.points << '\n';
        }
        file.close();
        return true;
    }

    // Export a raw text snapshot of a position (e.g. FEN string) to disk
    Q_INVOKABLE bool exportPositionToFile(const QString &positionText, const QString &filePath) {
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return false;
        QTextStream out(&file);
        out << positionText;
        file.close();
        return true;
    }
};
