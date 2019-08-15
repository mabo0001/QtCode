#-------------------------------------------------
#
# Project created by QtCreator 2018-04-08T10:50:53
#
#-------------------------------------------------

TEMPLATE    = lib

CONFIG      += c++11

DESTDIR     = "../Dest"

DEFINES     += HE_BUILD_ALGORITHM_LIB

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES     += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS     += \
            HAlgorithmGlobal.h \
            HMath.h \
            HRegister.h \
            HRegister_p.h

SOURCES     += \
            HRegister.cpp \
            HMath.cpp

RESOURCES   += HeAlgorithm.qrc

Debug:      TARGET  = HeAlgorithmd
Release:    TARGET  = HeAlgorithm

unix {
    target.path = /usr/lib
    INSTALLS += target
}

include(gsl.pri)
include(spec.pri)
