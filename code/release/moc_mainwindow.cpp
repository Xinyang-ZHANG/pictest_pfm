/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "algo_signal"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "QImage*"
QT_MOC_LITERAL(4, 32, 3), // "img"
QT_MOC_LITERAL(5, 36, 12), // "write_signal"
QT_MOC_LITERAL(6, 49, 8), // "read_bmp"
QT_MOC_LITERAL(7, 58, 8), // "filePath"
QT_MOC_LITERAL(8, 67, 9), // "write_bmp"
QT_MOC_LITERAL(9, 77, 9), // "algo_slot"
QT_MOC_LITERAL(10, 87, 18), // "on_algoBtn_clicked"
QT_MOC_LITERAL(11, 106, 20), // "on_fileinBtn_clicked"
QT_MOC_LITERAL(12, 127, 21), // "on_fileoutBtn_clicked"
QT_MOC_LITERAL(13, 149, 23), // "on_fileRadioBtn_clicked"
QT_MOC_LITERAL(14, 173, 23), // "on_algoRadioBtn_clicked"
QT_MOC_LITERAL(15, 197, 27), // "on_rgbCheckBox_stateChanged"
QT_MOC_LITERAL(16, 225, 4), // "arg1"
QT_MOC_LITERAL(17, 230, 28) // "on_grayCheckBox_stateChanged"

    },
    "MainWindow\0algo_signal\0\0QImage*\0img\0"
    "write_signal\0read_bmp\0filePath\0write_bmp\0"
    "algo_slot\0on_algoBtn_clicked\0"
    "on_fileinBtn_clicked\0on_fileoutBtn_clicked\0"
    "on_fileRadioBtn_clicked\0on_algoRadioBtn_clicked\0"
    "on_rgbCheckBox_stateChanged\0arg1\0"
    "on_grayCheckBox_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   80,    2, 0x0a /* Public */,
       8,    1,   83,    2, 0x0a /* Public */,
       9,    1,   86,    2, 0x0a /* Public */,
      10,    0,   89,    2, 0x08 /* Private */,
      11,    0,   90,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,
      15,    1,   94,    2, 0x08 /* Private */,
      17,    1,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->algo_signal((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 1: _t->write_signal((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 2: _t->read_bmp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->write_bmp((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 4: _t->algo_slot((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 5: _t->on_algoBtn_clicked(); break;
        case 6: _t->on_fileinBtn_clicked(); break;
        case 7: _t->on_fileoutBtn_clicked(); break;
        case 8: _t->on_fileRadioBtn_clicked(); break;
        case 9: _t->on_algoRadioBtn_clicked(); break;
        case 10: _t->on_rgbCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_grayCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QImage * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::algo_signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QImage * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::write_signal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::algo_signal(QImage * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::write_signal(QImage * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
