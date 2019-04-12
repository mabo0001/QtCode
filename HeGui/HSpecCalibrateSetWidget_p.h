#ifndef HSPECCALIBRATESETWIDGET_P_H
#define HSPECCALIBRATESETWIDGET_P_H

#include "HSpecCalibrateSetWidget.h"
#include "HAbstractTestSetWidget_p.h"

HE_CONTROLLER_BEGIN_NAMESPACE
class ITestSpec;
HE_CONTROLLER_END_NAMESPACE

HE_GUI_BEGIN_NAMESPACE

class HSpecCalibrateSetWidgetPrivate : public HAbstractTestSetWidgetPrivate
{
public:
    HSpecCalibrateSetWidgetPrivate();

public:
    ITestSpec *testSpec;
    bool integralTimeAuto = false;
};

HE_GUI_END_NAMESPACE

#endif // HSPECCALIBRATESETWIDGET_P_H
