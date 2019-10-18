/***************************************************************************************************
**      2019-05-20  IChromatismCollection 色容差数据集合接口。
***************************************************************************************************/

#ifndef ICHROMATISMCOLLECTION_H
#define ICHROMATISMCOLLECTION_H

#include "HDataCollection.h"

HE_DATA_BEGIN_NAMESPACE

class IChromatism;

class IChromatismCollection : public HDataCollection<IChromatism>
{
public:
    using HDataCollection::HDataCollection;

public:
    // 计算色容差
    virtual double calcSdcm(double tc, QPointF xy) = 0;
    // 转成Json
    virtual QJsonObject toJson() = 0;
};

HE_DATA_END_NAMESPACE

#endif // ICHROMATISMCOLLECTION_H
