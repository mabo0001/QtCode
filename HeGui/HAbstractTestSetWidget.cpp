#include "HAbstractTestSetWidget_p.h"
#include "HeCore/HAppContext.h"
#include "HeController/ITestData.h"
#include <QDebug>

HE_GUI_BEGIN_NAMESPACE

HAbstractTestSetWidgetPrivate::HAbstractTestSetWidgetPrivate()
{
    model = HAppContext::getContextPointer<IModel>("IModel");
    testData = HAppContext::getContextPointer<ITestData>("ITestData");
}

HAbstractTestSetWidget::HAbstractTestSetWidget(QWidget *parent)
    : ITestSetWidget(parent), d_ptr(new HAbstractTestSetWidgetPrivate)
{
}

HAbstractTestSetWidget::HAbstractTestSetWidget(HAbstractTestSetWidgetPrivate &p, QWidget *parent)
    : ITestSetWidget(parent), d_ptr(&p)
{
}

HAbstractTestSetWidget::~HAbstractTestSetWidget()
{
    qDebug() << __func__;
}

void HAbstractTestSetWidget::initialize(QVariantMap /*param*/)
{
}

bool HAbstractTestSetWidget::setTestState(bool b)
{
    if (d_ptr->testState == b)
        return false;
    d_ptr->testState = b;
    emit testStateChanged(b);
    return true;
}

bool HAbstractTestSetWidget::setTestMode(int value)
{
    if (d_ptr->testMode == value)
        return false;
    d_ptr->testMode = value;
    emit testModeChanged(value);
    return true;
}

bool HAbstractTestSetWidget::testState()
{
    return d_ptr->testState;
}

int HAbstractTestSetWidget::testMode()
{
    return d_ptr->testMode;
}

HE_GUI_END_NAMESPACE