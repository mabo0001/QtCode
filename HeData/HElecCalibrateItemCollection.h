/***************************************************************************************************
**      2019-10-17  HElecCalibrateItemCollection
***************************************************************************************************/

#ifndef HELECCALIBRATEITEMCOLLECTION_H
#define HELECCALIBRATEITEMCOLLECTION_H

#include "IElecCalibrateItemCollection.h"

HE_DATA_BEGIN_NAMESPACE

class HElecCalibrateItemCollectionPrivate;

class HElecCalibrateItemCollection : public IElecCalibrateItemCollection
{
    Q_DECLARE_PRIVATE(HElecCalibrateItemCollection)

public:
    explicit HElecCalibrateItemCollection();
    virtual ~HElecCalibrateItemCollection();

public:
    QString typeName() override;

public:
    void readContent(QDataStream &) override;
    void writeContent(QDataStream &) override;

public:
    IElecCalibrateItem *itemAt(int index) override;

protected:
    HElecCalibrateItemCollection(HElecCalibrateItemCollectionPrivate &);
};

HE_DATA_END_NAMESPACE

#endif // HELECCALIBRATEITEMCOLLECTION_H