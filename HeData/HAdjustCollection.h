/***************************************************************************************************
**      2019-04-26  HAdjustCollection 校正数据集合类。
***************************************************************************************************/

#ifndef HADJUSTCOLLECTION_H
#define HADJUSTCOLLECTION_H

#include "IAdjustCollection.h"

HE_DATA_BEGIN_NAMESPACE

class HAdjustCollectionPrivate;

class HAdjustCollection : public IAdjustCollection
{
    Q_DECLARE_PRIVATE(HAdjustCollection)

public:
    HAdjustCollection(IDataFactory *);
    virtual ~HAdjustCollection();

public:
    QString typeName() override;

public:
    IDataFactory *dataFactory() override;
    IFileStream *fileStream() override;
    void setUseIndex(QString value) override;
    QString useIndex() override;

public:
    QVariantMap correct(QVariantMap value) override;

protected:
    HAdjustCollection(HAdjustCollectionPrivate &);
};

HE_DATA_END_NAMESPACE

#endif // HADJUSTCOLLECTION_H
