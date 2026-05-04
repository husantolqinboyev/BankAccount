QT       += core gui
TARGET = CyberBank

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# C++11 standartini majburiy yoqish
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    account.cpp

HEADERS += \
    mainwindow.h \
    account.h

FORMS += \
    mainwindow.ui
