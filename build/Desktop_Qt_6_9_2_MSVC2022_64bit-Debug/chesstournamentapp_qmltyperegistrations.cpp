/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<enums.h>)
#  include <enums.h>
#endif
#if __has_include(<exporter.h>)
#  include <exporter.h>
#endif
#if __has_include(<match.h>)
#  include <match.h>
#endif
#if __has_include(<tournamentmanager.h>)
#  include <tournamentmanager.h>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_ChessTournament()
{
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    {
        Q_CONSTINIT static auto metaType = QQmlPrivate::metaTypeForNamespace(
            [](const QtPrivate::QMetaTypeInterface *) {return &ChessEnums::staticMetaObject;},
            "ChessEnums");
        QMetaType(&metaType).id();
    }
    qmlRegisterNamespaceAndRevisions(&ChessEnums::staticMetaObject, "ChessTournament", 1, nullptr, &ChessEnums::staticMetaObject, nullptr);
    qmlRegisterEnum<ChessEnums::Color>("ChessEnums::Color");
    qmlRegisterEnum<ChessEnums::MatchStatus>("ChessEnums::MatchStatus");
    qmlRegisterEnum<ChessEnums::MatchResult>("ChessEnums::MatchResult");
    qmlRegisterTypesAndRevisions<Exporter>("ChessTournament", 1);
    qmlRegisterTypesAndRevisions<Match>("ChessTournament", 1);
    qmlRegisterTypesAndRevisions<TournamentManager>("ChessTournament", 1);
    QT_WARNING_POP
    qmlRegisterModule("ChessTournament", 1, 0);
}

static const QQmlModuleRegistration chessTournamentRegistration("ChessTournament", qml_register_types_ChessTournament);
