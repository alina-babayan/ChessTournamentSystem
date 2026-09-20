#pragma once
#include <QObject>
#include <QQmlEngine>

// Q_ENUM_NS requires an enclosing namespace tagged with Q_NAMESPACE so moc
// can generate a static meta-object for it. A bare top-level `enum class`
// with Q_ENUM_NS applied directly (no namespace/Q_NAMESPACE) fails to
// compile under MSVC with "staticMetaObject: undeclared identifier".
namespace ChessEnums {
Q_NAMESPACE
QML_ELEMENT

enum class Color { White, Black };
Q_ENUM_NS(Color)

enum class MatchStatus { Scheduled, InProgress, Finished };
Q_ENUM_NS(MatchStatus)

enum class MatchResult { Ongoing, WhiteWins, BlackWins, Draw };
Q_ENUM_NS(MatchResult)

} // namespace ChessEnums

// Type aliases so existing code (Match.h, TournamentManager.h, etc.) can
// keep referring to Color / MatchStatus / MatchResult unqualified.
using Color = ChessEnums::Color;
using MatchStatus = ChessEnums::MatchStatus;
using MatchResult = ChessEnums::MatchResult;
