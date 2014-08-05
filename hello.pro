    TEMPLATE = app
    TARGET = hello

    QT = core gui network

    greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    goprocontroller.cpp \
#    _mainwindow.cpp \
    mainwindow.cpp

HEADERS += \
    goprocontroller.h \
#    _mainwindow.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    main.qrc
