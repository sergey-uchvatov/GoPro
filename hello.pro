    TEMPLATE = app
    TARGET = hello

    QT = core gui network

    greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    goprocontroller.cpp

HEADERS += \
    mainwindow.h \
    goprocontroller.h
