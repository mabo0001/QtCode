#ifndef HSPECELECTHREAD_P_H
#define HSPECELECTHREAD_P_H

#include "HSpecElecThread.h"
#include "HAbstractThread_p.h"
#include "HeData/HDataGlobal.h"

HE_DATA_BEGIN_NAMESPACE
class ITestSpec;
class ITestElec;
HE_DATA_END_NAMESPACE
HE_DATA_USE_NAMESPACE

HE_CONTROLLER_BEGIN_NAMESPACE

class HSpecElecThreadPrivate : public HAbstractThreadPrivate
{
public:
    HSpecElecThreadPrivate();

public:
    IProtocol *protocolSpec = nullptr;
    ITestSpec *testSpec = nullptr;
    ITestElec *testElec = nullptr;
    IActionStrategy *strategySpec = nullptr;
    IActionStrategy *strategyElec = nullptr;
};

HE_CONTROLLER_END_NAMESPACE

#endif // HSPECELECTHREAD_P_H
