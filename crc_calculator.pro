TEMPLATE = app
TARGET   = CRC_Calculator


QT += core
QT += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



DEFINES += MAJOR_VERSION=0
DEFINES += MINOR_VERSION=0



CONFIG += qt
CONFIG += debug_and_release  build_all



CONFIG(debug, debug|release) {
    TARGETDIR = debug
    DESTDIR   = debug
}



CONFIG(release, debug|release) {
    TARGETDIR = release
    DESTDIR   = release
}



# Input
SOURCES += main.cpp \
           mainwindow.cpp \
           bitwidget.cpp \
           bitset64.cpp \
           ucrc_t.cpp



HEADERS += mainwindow.h \
           bitwidget.h \
           bitset64.h \
           ucrc_t.h



FORMS   += mainwindow.ui
