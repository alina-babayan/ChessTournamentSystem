/****************************************************************************
** Meta object code from reading C++ file 'enums.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../enums.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enums.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10ChessEnumsE_t {};
} // unnamed namespace

template <> constexpr inline auto ChessEnums::qt_create_metaobjectdata<qt_meta_tag_ZN10ChessEnumsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ChessEnums",
        "QML.Element",
        "auto",
        "Color",
        "White",
        "Black",
        "MatchStatus",
        "Scheduled",
        "InProgress",
        "Finished",
        "MatchResult",
        "Ongoing",
        "WhiteWins",
        "BlackWins",
        "Draw"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Color'
        QtMocHelpers::EnumData<Color>(3, 3, QMC::EnumIsScoped).add({
            {    4, Color::White },
            {    5, Color::Black },
        }),
        // enum 'MatchStatus'
        QtMocHelpers::EnumData<MatchStatus>(6, 6, QMC::EnumIsScoped).add({
            {    7, MatchStatus::Scheduled },
            {    8, MatchStatus::InProgress },
            {    9, MatchStatus::Finished },
        }),
        // enum 'MatchResult'
        QtMocHelpers::EnumData<MatchResult>(10, 10, QMC::EnumIsScoped).add({
            {   11, MatchResult::Ongoing },
            {   12, MatchResult::WhiteWins },
            {   13, MatchResult::BlackWins },
            {   14, MatchResult::Draw },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN10ChessEnumsE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}

static constexpr auto qt_staticMetaObjectContent_ZN10ChessEnumsE =
    ChessEnums::qt_create_metaobjectdata<qt_meta_tag_ZN10ChessEnumsE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN10ChessEnumsE =
    qt_staticMetaObjectContent_ZN10ChessEnumsE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN10ChessEnumsE =
    qt_staticMetaObjectContent_ZN10ChessEnumsE.relocatingData;

Q_CONSTINIT const QMetaObject ChessEnums::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN10ChessEnumsE.stringdata,
    qt_staticMetaObjectStaticContent_ZN10ChessEnumsE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN10ChessEnumsE.metaTypes,
    nullptr
} };

QT_WARNING_POP
