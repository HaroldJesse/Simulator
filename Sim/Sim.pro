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
    Simulator/Log.cpp \
    Simulator/Setup.cpp \
    Simulator/Initialize.cpp \
    Simulator/IDPort.cpp \
    Craft/Craft.cpp \
    Craft/Power/Power.cpp \
    Craft/Helm/OThruster.cpp \
    Craft/Helm/PositionOrientation.cpp \
    Craft/Helm/PThruster.cpp \
    Craft/Helm/RCS2000.cpp \
    Craft/Computer/Coordinate.cpp \
    Craft/Computer/Julian.cpp \
    Craft/Communications/Transponder.cpp \
    Craft/Power/FusionCore.cpp \
    Craft/Power/BoronInjector.cpp \
    Craft/Helm/Helm.cpp \
    Craft/Helm/RCS1000.cpp \
    Craft/Navigation/Navigation.cpp \
    Craft/Navigation/Spice.cpp \
    Craft/Computer/Voice.cpp \
    Simulator/Window.cpp \
    Simulator/main.cpp \    
    Simulator/IDAdd.cpp \
    Simulator/IDCheck.cpp \
    Simulator/Certificate.cpp \
    Craft/Computer/ComputerControl.cpp \
    Craft/CraftControls.cpp \
    Simulator/SimulatorControls.cpp \
    Simulator/BasicData.cpp


HEADERS  += \
    Craft/Helm/Helm.hpp \
    Simulator/Audio.hpp \
    Simulator/Log.hpp \
    Simulator/SimConstants.hpp \
    Simulator/SimGlobals.hpp \
    Simulator/Setup.hpp \
    Simulator/Initialize.hpp \
    Simulator/IDPort.hpp \
    Simulator/Window.hpp \
    Craft/Craft.hpp \
    Craft/Helm/OThruster.hpp \
    Craft/Helm/PositionOrientation.hpp \
    Craft/Helm/PThruster.hpp \
    Craft/Helm/RCS2000.hpp \
    Craft/Helm/RCS1000.hpp \
    Craft/Computer/Coordinate.hpp \
    Craft/Computer/Julian.hpp \
    Craft/Communications/Transponder.hpp \
    Craft/Power/Power.hpp \
    Craft/Power/FusionCore.hpp \
    Craft/Power/BoronInjector.hpp \
    Craft/Navigation/Navigation.hpp \
    Craft/Navigation/Spice.hpp \
    Craft/Computer/Voice.hpp\
    dox.hpp \
    Simulator/IDAdd.hpp \
    Simulator/IDCheck.hpp \
    Simulator/Certificate.hpp \
    Craft/Computer/ComputerControl.hpp \
    Craft/CraftControls.hpp \
    Simulator/SimulatorControls.hpp \
    Simulator/BasicData.hpp



FORMS    += \
    Simulator/Log.ui \
    Simulator/Setup.ui \
    Simulator/IDPort.ui \
    Craft/Power/Power.ui \
    Craft/Helm/OThruster.ui \
    Craft/Helm/PositionOrientation.ui \
    Craft/Helm/PThruster.ui \
    Craft/Helm/RCS2000.ui \
    Craft/Communications/Transponder.ui \
    Craft/Power/FusionCore.ui \
    Craft/Power/BoronInjector.ui \
    Craft/Helm/RCS1000.ui \
    Craft/Navigation/Navigation.ui \
    Craft/Navigation/Spice.ui \
    Simulator/IDAdd.ui \
    Simulator/IDCheck.ui \
    Simulator/Certificate.ui \
    Craft/Computer/Voice.ui \
    Craft/Computer/ComputerControl.ui \
    Craft/CraftControls.ui \
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

LIBS    +=\
    Lib/libQtCSpiced.a

DEFINES += \
    SPICE


