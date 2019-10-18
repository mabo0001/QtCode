/***************************************************************************************************
**      2019-10-16 IElecCalibrateItemCollection 电参数校准数据项集合。
***************************************************************************************************/

#ifndef IELECCALIBRATEITEMCOLLECTION_H
#define IELECCALIBRATEITEMCOLLECTION_H

#include "HDataGlobal.h"
#include "HeCore/HCollection.h"

HE_CORE_USE_NAMESPACE

HE_DATA_BEGIN_NAMESPACE

class IElecCalibrateItem;

class IElecCalibrateItemCollection : public HCollection<IElecCalibrateItem>
{
public:
    using HCollection::HCollection;

public:
    // 读取内容
    virtual void readContent(QDataStream &) = 0;
    // 写入内容
    virtual void writeContent(QDataStream &) = 0;

public:
    virtual IElecCalibrateItem *itemAt(int index) = 0;
};

HE_DATA_END_NAMESPACE

#endif // IELECCALIBRATEITEMCOLLECTION_H