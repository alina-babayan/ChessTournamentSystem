# Chess Tournament System

A Qt6 / C++ / QML application for tracking a chess tournament: registering
participants, running a match (start time, moves, end time/result), and
exporting the current position and standings table.

## Requirements

- Qt 6.5+ (Core, Gui, Qml, Quick, QuickControls2)
- CMake 3.16+
- A C++17 compiler

## Building

```bash
mkdir build && cd build
cmake .. -DCMAKE_PREFIX_PATH=/path/to/Qt/6.x.x/gcc_64
cmake --build .
./ChessTournamentApp        # or ChessTournamentApp.exe on Windows
```

## Project Layout

```
ChessTournament/
├── CMakeLists.txt
├── main.cpp
├── enums.h              # Color, MatchStatus, MatchResult
├── player.h             # Player domain entity
├── playerlistmodel.h    # QAbstractListModel exposing the roster (UC-1)
├── move.h               # Move struct (from/to/piece/timestamp)
├── movelistmodel.h      # QAbstractListModel exposing a match's move list
├── match.h              # Match QObject: start/recordMove/finish (UC-2)
├── standingsmodel.h      # QAbstractTableModel: tournament standings
├── tournamentmanager.h  # QML_SINGLETON facade tying it all together
├── exporter.h           # QML_SINGLETON: CSV / position export helpers
└── qml/
    ├── Main.qml
    ├── RegisterPlayerView.qml   # UC-1: Register Participant
    ├── MatchView.qml            # UC-2: Game Play / Match Tracking
    └── StandingsView.qml        # Standings + export
```

## Use Cases Implemented

### UC-1: Register Participant
Add a player (name, rating, federation) to the tournament roster. Validates
non-empty name; creates a `Player` and an initial zeroed `StandingsEntry`.

### UC-2: Game Play (Match Tracking)
1. Create a match between two registered players — colors are auto-assigned
   using an alternation rule (`TournamentManager::colorFor`): whoever played
   Black most recently (or has never played) gets White.
2. Start the match (`Match::start`) — records the start timestamp.
3. Record moves (`Match::recordMove`) — each move stores origin square,
   destination square, piece, capture flag, and timestamp; rejected if the
   match isn't `InProgress` or squares are invalid.
4. Finish the match (`Match::finish`) — records end timestamp and result
   (White wins / Black wins / Draw); standings update automatically via the
   `resultChanged` signal.
5. Export the current position (`Match::exportPositionFen`, stubbed —
   plug in a real chess rules engine for accurate FEN) or the standings
   table (`Exporter::exportStandingsCsv`).

## Extending

- **Rules engine**: replace the `exportPositionFen()` stub with a real
  board/position tracker that replays `MoveListModel`'s moves and validates
  legality, check/checkmate, castling rights, en passant, etc.
- **Persistence**: back `TournamentManager` with SQLite (`QSqlDatabase`) so
  the roster and match history survive restarts.
- **Concurrent boards**: swap the single `activeMatch` property for a
  `MatchListModel` if multiple boards run simultaneously.
"# ChessTournamentSystem" 
