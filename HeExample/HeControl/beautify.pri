HEADERS += \
    $$PWD/HSlideNavigation.h \
    $$PWD/HSlideNavigation_p.h \
    $$PWD/HAbstractProgress.h \
    $$PWD/HAbstractProgress_p.h \
    $$PWD/HAnimationProgress.h \
    $$PWD/HAnimationProgress_p.h

SOURCES += \
    $$PWD/HSlideNavigation.cpp \
    $$PWD/HAbstractProgress.cpp \
    $$PWD/HAnimationProgress.cpp

include(circular.pri)


include(draw.pri)
include(else.pri)
include(gauge.pri)
include(nav.pri)
include(progressBar.pri)
include(ruler.pri)
include(texture.pri)

