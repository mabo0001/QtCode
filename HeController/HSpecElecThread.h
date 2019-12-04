/***************************************************************************************************
**      2019-10-24  HSpecElecThread
***************************************************************************************************/

#ifndef HSPECELECTHREAD_H
#define HSPECELECTHREAD_H

#include "HAbstractThread.h"

HE_CONTROLLER_BEGIN_NAMESPACE

class HSpecElecThreadPrivate;

class HSpecElecThread : public HAbstractThread
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HSpecElecThread)

public:
    explicit HSpecElecThread(QObject *parent = nullptr);
    ~HSpecElecThread() override;

public:
    QString typeName() override;

public:
    QString threadInfo() override;

protected:
    HSpecElecThread(HSpecElecThreadPrivate &p, QObject *parent = nullptr);

protected:
    HErrorType handleAction(HActionType action) override;
    void setEfficacy();
};

HE_CONTROLLER_END_NAMESPACE

#endif // HSPECELECTHREAD_H