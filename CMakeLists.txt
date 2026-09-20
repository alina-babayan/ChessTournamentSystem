cmake_minimum_required(VERSION 3.16)

project(ChessTournament VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Gui Qml Quick QuickControls2)

qt_standard_project_setup(REQUIRES 6.5)

# Silences: "You need qmldir files for each extra directory that contains
# .qml files" — all our QML lives in a single qml/ subdirectory already.
qt_policy(SET QTP0004 NEW)

# Explicitly mark Theme.qml as a QML singleton (pragma Singleton alone isn't
# always auto-detected depending on the Qt/CMake combination).
set_source_files_properties(qml/Theme.qml PROPERTIES QT_QML_SINGLETON_TYPE true)

qt_add_executable(ChessTournamentApp
    main.cpp
)

qt_add_qml_module(ChessTournamentApp
    URI ChessTournament
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        qml/Theme.qml
        qml/AppButton.qml
        qml/AppTextField.qml
        qml/SectionCard.qml
        qml/StatusPill.qml
        qml/RegisterPlayerView.qml
        qml/MatchView.qml
        qml/StandingsView.qml
    SOURCES
        tournamentmanager.h
        match.h
        move.h
        position.h
        movelistmodel.h
        playerlistmodel.h
        standingsmodel.h
        player.h
        enums.h
        exporter.h
)

target_link_libraries(ChessTournamentApp
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        Qt6::Quick
        Qt6::QuickControls2
)

include(GNUInstallDirs)
install(TARGETS ChessTournamentApp
    BUNDLE  DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
