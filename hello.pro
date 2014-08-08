TEMPLATE = app
TARGET = hello

CONFIG  += c++11

QT = core gui network

    greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    goprocontroller.cpp \
    mainwindow.cpp

HEADERS += \
    goprocontroller.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    main.qrc
