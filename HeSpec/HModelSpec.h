/***************************************************************************************************
**      2019-09-19  HModelSpec
***************************************************************************************************/

#ifndef HMODELSPEC_H
#define HMODELSPEC_H

#include "HeController/HAbstractModel.h"

HE_CONTROLLER_USE_NAMESPACE

class HModelSpecPrivate;

class HModelSpec : public HAbstractModel
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HModelSpec)

public:
    explicit HModelSpec(QObject *parent = nullptr);
    ~HModelSpec() override;

public:
    void initialize(QVariantMap param) override;
    QString typeName() override;

protected:
    void syncTestData(quint32 type) override;
    void syncMachine(quint32 type) override;
};

#endif // HMODELSPEC_H