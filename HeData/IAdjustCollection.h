/***************************************************************************************************
**      2019-04-26  IAdjustCollection 调整数据集合接口。
***************************************************************************************************/

#ifndef IADJUSTCOLLECTION_H
#define IADJUSTCOLLECTION_H

#include "HDataCollection.h"

HE_DATA_BEGIN_NAMESPACE

class IAdjust;

class IAdjustCollection : public HDataCollection<IAdjust>
{
public:
    using HDataCollection::HDataCollection;

public:
    // 纠正
    virtual QVariantMap correct(QVariantMap value) = 0;
};

HE_DATA_END_NAMESPACE

#endif // IADJUSTCOLLECTION_H
