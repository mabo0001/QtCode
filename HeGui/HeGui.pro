#-------------------------------------------------
#
# Project created by QtCreator 2018-05-11T08:34:21
#
#-------------------------------------------------

QT          += widgets

TEMPLATE    = lib

CONFIG      += c++11

DESTDIR     = "../Dest"

DEFINES     += HE_BUILD_GUI_LIB

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES     += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES     += \
    HAction.cpp \
    HGuiHelper.cpp

HEADERS     += \
            HGuiGlobal.h \
    HAction.h \
    HAction_p.h \
    HGuiHelper.h

INCLUDEPATH += ".."

Debug {
    TARGET = HeGuid
    LIBS    += \
            -L$$DESTDIR -lHeCored \
            -L$$DESTDIR -lHeCommunicated \
            -L$$DESTDIR -lHeControllerd
}

Release {
    TARGET  = HeGui
    LIBS    += \
            -L$$DESTDIR -lHeCore \
            -L$$DESTDIR -lHeCommunicate \
            -L$$DESTDIR -lHeController
}

unix {
    target.path = /usr/lib
    INSTALLS += target
}

include(handle.pri)
