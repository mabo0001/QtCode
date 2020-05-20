#include "HElecStrategy_p.h"
#include "HeCore/HAppContext.h"
#include "HeData/ITestElec.h"
#include "HeCommunicate/IProtocol.h"
#include "HeCommunicate/IProtocolCollection.h"
#include <QtCore/QDebug>

HE_CONTROLLER_BEGIN_NAMESPACE

HElecStrategyPrivate::HElecStrategyPrivate()
{
    actionSupport << ACT_SET_SOURCE_MODE
                  << ACT_SET_OUTPUT_VOLTAGE
                  << ACT_SET_OUTPUT_CURRENT
                  << ACT_SET_GEARS_OUTPUT_CURRENT
                  << ACT_SET_REVERSE_VOLTAGE
                  << ACT_GET_ELEC_PARAM
                  << ACT_GET_MEASURED_VOLTAGE
                  << ACT_GET_MEASURED_CURRENT
                  << ACT_GET_REVERSE_CURRENT
                  << ACT_RESET_STATE_TRIGGER
                  << ACT_QUERY_STATE_TRIGGER;
    protocol = HAppContext::getContextPointer<IProtocolCollection>("IProtocolCollection")->value("Elec");
    testElec = HAppContext::getContextPointer<ITestElec>("ITestElec");
}

HElecStrategy::HElecStrategy(QObject *parent) :
    HAbstractActionStrategy(*new HElecStrategyPrivate, parent)
{
}

HElecStrategy::HElecStrategy(HElecStrategyPrivate &p, QObject *parent) :
    HAbstractActionStrategy(p, parent)
{
}

HElecStrategy::~HElecStrategy()
{
    qDebug() << __func__;
}

QString HElecStrategy::typeName()
{
    return "HElecStrategy";
}

HErrorType HElecStrategy::handle(HActionType action)
{
    Q_D(HElecStrategy);
    HErrorType error;
    int sample;
    QVector<int> buff;

    switch(action)
    {
    case ACT_SET_SOURCE_MODE:
        return d->protocol->setData(action, d->testElec->data("[电源模式]").toInt());
    case ACT_SET_OUTPUT_VOLTAGE:
        return d->protocol->setData(action, d->testElec->data("[输出电压_F]").toInt());
    case ACT_SET_OUTPUT_CURRENT:
        return d->protocol->setData(action, d->testElec->data("[输出电流_F]").toInt());
    case ACT_SET_GEARS_OUTPUT_CURRENT:
        return d->protocol->setData(action, d->testElec->data("[输出电流_档位]").toInt());
    case ACT_SET_REVERSE_VOLTAGE:
        return d->protocol->setData(action, d->testElec->data("[反向电压_F]").toInt());
    case ACT_GET_ELEC_PARAM:
        error = d->protocol->getData(action, buff);
        if (error == E_OK)
            d->testElec->setSample(buff);
        return error;
    case ACT_GET_MEASURED_VOLTAGE:
        error = d->protocol->getData(action, sample);
        if (error == E_OK)
            d->testElec->setParam(MeasuredVoltage, sample);
        return error;
    case ACT_GET_MEASURED_CURRENT:
        error = d->protocol->getData(action, sample);
        if (error == E_OK)
            d->testElec->setParam(MeasuredCurrent, sample);
        return error;
    case ACT_GET_REVERSE_CURRENT:
        error = d->protocol->getData(action, sample);
        if (error == E_OK)
            d->testElec->setParam(ReverseCurrent, sample);
        return error;
    case ACT_RESET_STATE_TRIGGER:
        return d->protocol->setData(action, 0);
    case ACT_QUERY_STATE_TRIGGER:
        error = d->protocol->getData(action, sample);
        if (error == E_OK)
            d->testElec->setData("[触发状态]", sample);
        return error;
    }
    return E_OK;
}

HE_CONTROLLER_END_NAMESPACE
