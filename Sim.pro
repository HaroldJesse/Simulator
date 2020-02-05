#-------------------------------------------------
#
# Project created by QtCreator 2016-08-27T14:23:08
#
#-------------------------------------------------

QT       += core gui multimedia sql 3dcore 3dinput 3drender 3dextras texttospeech

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sim
TEMPLATE = app


SOURCES +=\
    Simulator/Audio.cpp \
    Simulator/Logs.cpp \
    Simulator/Setup.cpp \
    Simulator/Initialize.cpp \
    Simulator/IDPort.cpp \
    Simulator/Window.cpp \
    Simulator/main.cpp \
    Simulator/IDAdd.cpp \
    Simulator/IDCheck.cpp \
    Simulator/Certificate.cpp \
    Simulator/SimulatorControls.cpp \
    Simulator/BasicData.cpp


HEADERS  += \
    Simulator/Audio.hpp \
    Simulator/Logs.hpp \
    Simulator/SimConstants.hpp \
    Simulator/SimGlobals.hpp \
    Simulator/Setup.hpp \
    Simulator/Initialize.hpp \
    Simulator/IDPort.hpp \
    Simulator/Window.hpp \
    Simulator/IDAdd.hpp \
    Simulator/IDCheck.hpp \
    Simulator/Certificate.hpp \
    Simulator/SimulatorControls.hpp \
    Simulator/BasicData.hpp



FORMS    += \
    Simulator/Logs.ui \
    Simulator/Setup.ui \
    Simulator/IDPort.ui \
    Simulator/IDAdd.ui \
    Simulator/IDCheck.ui \
    Simulator/Certificate.ui \
    Simulator/SimulatorControls.ui \
    Simulator/BasicData.ui

INCLUDEPATH += \
    Craft\
    Craft/Power\
    Craft/Helm\
    Craft/Communications\
    Craft/Computer\
    Craft/Navigation\
    Simulator\
    CSpiceInclude

    Lib/libQtCSpiced.a

LIBS    +=\


DEFINES += \
    SPICE

DISTFILES +=


