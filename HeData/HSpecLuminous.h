/***************************************************************************************************
**      2018-06-19  HSpecLuminous 光谱光通量数据类。
***************************************************************************************************/

#ifndef HSPECLUMINOUS_H
#define HSPECLUMINOUS_H

#include "HAbstractDataItem.h"

HE_DATA_BEGIN_NAMESPACE

class HSpecLuminousPrivate;

class HSpecLuminous : public HAbstractDataItem
{
    Q_DECLARE_PRIVATE(HSpecLuminous)

public:
    explicit HSpecLuminous();
    ~HSpecLuminous() override;

public:
    QString typeName() override;

public:
    void readContent(QDataStream &) override;
    void writeContent(QDataStream &) override;

public:
    void restoreDefault();
    double handle(double value);

protected:
    HSpecLuminous(HSpecLuminousPrivate &p);
};

HE_DATA_END_NAMESPACE

#endif // HSPECLUMINOUS_H
