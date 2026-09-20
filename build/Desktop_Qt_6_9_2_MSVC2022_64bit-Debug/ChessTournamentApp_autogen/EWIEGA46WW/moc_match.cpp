/****************************************************************************
** Meta object code from reading C++ file 'match.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../match.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'match.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN5MatchE_t {};
} // unnamed namespace

template <> constexpr inline auto Match::qt_create_metaobjectdata<qt_meta_tag_ZN5MatchE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Match",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "Created by TournamentManager",
        "statusChanged",
        "",
        "resultChanged",
        "startedChanged",
        "finishedChanged",
        "moveRecorded",
        "moveNumber",
        "errorOccurred",
        "message",
        "start",
        "when",
        "recordMove",
        "from",
        "to",
        "piece",
        "isCapture",
        "promotion",
        "finish",
        "MatchResult",
        "result",
        "exportPositionFen",
        "whitePlayer",
        "Player*",
        "blackPlayer",
        "status",
        "MatchStatus",
        "startTimestamp",
        "endTimestamp",
        "moveModel",
        "MoveListModel*"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'statusChanged'
        QtMocHelpers::SignalData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'resultChanged'
        QtMocHelpers::SignalData<void()>(9, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'startedChanged'
        QtMocHelpers::SignalData<void()>(10, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'finishedChanged'
        QtMocHelpers::SignalData<void()>(11, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'moveRecorded'
        QtMocHelpers::SignalData<void(int)>(12, 8, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 13 },
        }}),
        // Signal 'errorOccurred'
        QtMocHelpers::SignalData<void(const QString &)>(14, 8, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 15 },
        }}),
        // Method 'start'
        QtMocHelpers::MethodData<bool(const QDateTime &)>(16, 8, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QDateTime, 17 },
        }}),
        // Method 'start'
        QtMocHelpers::MethodData<bool()>(16, 8, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool),
        // Method 'recordMove'
        QtMocHelpers::MethodData<bool(const QString &, const QString &, const QString &, bool, const QString &)>(18, 8, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 19 }, { QMetaType::QString, 20 }, { QMetaType::QString, 21 }, { QMetaType::Bool, 22 },
            { QMetaType::QString, 23 },
        }}),
        // Method 'recordMove'
        QtMocHelpers::MethodData<bool(const QString &, const QString &, const QString &, bool)>(18, 8, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool, {{
            { QMetaType::QString, 19 }, { QMetaType::QString, 20 }, { QMetaType::QString, 21 }, { QMetaType::Bool, 22 },
        }}),
        // Method 'recordMove'
        QtMocHelpers::MethodData<bool(const QString &, const QString &, const QString &)>(18, 8, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool, {{
            { QMetaType::QString, 19 }, { QMetaType::QString, 20 }, { QMetaType::QString, 21 },
        }}),
        // Method 'finish'
        QtMocHelpers::MethodData<bool(MatchResult, const QDateTime &)>(24, 8, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 25, 26 }, { QMetaType::QDateTime, 17 },
        }}),
        // Method 'finish'
        QtMocHelpers::MethodData<bool(MatchResult)>(24, 8, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool, {{
            { 0x80000000 | 25, 26 },
        }}),
        // Method 'exportPositionFen'
        QtMocHelpers::MethodData<QString() const>(27, 8, QMC::AccessPublic, QMetaType::QString),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'whitePlayer'
        QtMocHelpers::PropertyData<Player*>(28, 0x80000000 | 29, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'blackPlayer'
        QtMocHelpers::PropertyData<Player*>(30, 0x80000000 | 29, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'status'
        QtMocHelpers::PropertyData<MatchStatus>(31, 0x80000000 | 32, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
        // property 'result'
        QtMocHelpers::PropertyData<MatchResult>(26, 0x80000000 | 25, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 1),
        // property 'startTimestamp'
        QtMocHelpers::PropertyData<QDateTime>(33, QMetaType::QDateTime, QMC::DefaultPropertyFlags, 2),
        // property 'endTimestamp'
        QtMocHelpers::PropertyData<QDateTime>(34, QMetaType::QDateTime, QMC::DefaultPropertyFlags, 3),
        // property 'moveModel'
        QtMocHelpers::PropertyData<MoveListModel*>(35, 0x80000000 | 36, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<Match, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject Match::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5MatchE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5MatchE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN5MatchE_t>.metaTypes,
    nullptr
} };

void Match::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Match *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->statusChanged(); break;
        case 1: _t->resultChanged(); break;
        case 2: _t->startedChanged(); break;
        case 3: _t->finishedChanged(); break;
        case 4: _t->moveRecorded((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: { bool _r = _t->start((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->start();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->recordMove((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->recordMove((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->recordMove((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->finish((*reinterpret_cast< std::add_pointer_t<MatchResult>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->finish((*reinterpret_cast< std::add_pointer_t<MatchResult>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->exportPositionFen();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Match::*)()>(_a, &Match::statusChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Match::*)()>(_a, &Match::resultChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Match::*)()>(_a, &Match::startedChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Match::*)()>(_a, &Match::finishedChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (Match::*)(int )>(_a, &Match::moveRecorded, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (Match::*)(const QString & )>(_a, &Match::errorOccurred, 5))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MoveListModel* >(); break;
        case 1:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Player* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<Player**>(_v) = _t->whitePlayer(); break;
        case 1: *reinterpret_cast<Player**>(_v) = _t->blackPlayer(); break;
        case 2: *reinterpret_cast<MatchStatus*>(_v) = _t->status(); break;
        case 3: *reinterpret_cast<MatchResult*>(_v) = _t->result(); break;
        case 4: *reinterpret_cast<QDateTime*>(_v) = _t->startTimestamp(); break;
        case 5: *reinterpret_cast<QDateTime*>(_v) = _t->endTimestamp(); break;
        case 6: *reinterpret_cast<MoveListModel**>(_v) = _t->moveModel(); break;
        default: break;
        }
    }
}

const QMetaObject *Match::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Match::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5MatchE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Match::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Match::statusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Match::resultChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Match::startedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Match::finishedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Match::moveRecorded(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void Match::errorOccurred(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}
QT_WARNING_POP
