#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
    // Force the "Basic" Quick Controls 2 style so AppButton/AppTextField's
    // custom background/contentItem are honored. Native styles (Windows,
    // macOS) silently ignore control customization. Must be set before
    // QGuiApplication is constructed.
    qputenv("QT_QUICK_CONTROLS_STYLE", "Basic");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // TournamentManager, Match, and Exporter register themselves via
    // QML_ELEMENT / QML_SINGLETON macros (see tournamentmanager.h, match.h,
    // exporter.h) and the qt_add_qml_module() call in CMakeLists.txt.

    engine.loadFromModule("ChessTournament", "Main");

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
