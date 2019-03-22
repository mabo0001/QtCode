/***************************************************************************************************
**      2018-06-19  HTestData 测试数据类。
***************************************************************************************************/

#ifndef HTESTDATA_H
#define HTESTDATA_H

#include "ITestData.h"

HE_CONTROLLER_BEGIN_NAMESPACE

class HTestDataPrivate;

class HTestData : virtual public ITestData
{
public:
    explicit HTestData();
    virtual ~HTestData();

public:
    void initialize(QVariantMap param) override;
    QString typeName() override;

public:
    void setSuccessor(ITestData *) override;
    void setData(QString type, QVariant value) override;
    QVariant data(QString type) override;

protected:
    HTestData(HTestDataPrivate &p);

protected:
    QScopedPointer<HTestDataPrivate> d_ptr;
};

HE_CONTROLLER_END_NAMESPACE

#endif // HTESTDATA_H
