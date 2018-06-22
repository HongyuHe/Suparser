#-------------------------------------------------
#
# Project created by QtCreator 2018-05-19T22:33:21
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SubtitleParser
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        subtitleparser.cpp \
    maininterface.cpp

HEADERS += \
        subtitleparser.h \
    maininterface.h

FORMS += \
        subtitleparser.ui \
    maininterface.ui

RESOURCES += \
    theme.qrc \
    icon.qrc \
    welcomepage.qrc \
    language.qrc

TRANSLATIONS += En2Ch.ts

DISTFILES +=

UI_DIR = C:/Qt/QtMW/SubtitleParser

RC_ICONS = SuParser.ico
