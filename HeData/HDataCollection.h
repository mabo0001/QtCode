/***************************************************************************************************
**      2019-10-16
***************************************************************************************************/

#ifndef HDATACOLLECTION_H
#define HDATACOLLECTION_H

#include "IDataCollection.h"

HE_CORE_USE_NAMESPACE

HE_DATA_BEGIN_NAMESPACE

class IDataFactory;

template <typename T>
class HDataCollectionPrivate : public HCollectionPrivate<T>
{
public:
    IDataFactory *factory = nullptr;
    IFileStream *fileStream = nullptr;
    QString useIndex;
};

template <typename T>
class HDataCollection : public IDataCollection<T>
{
    H_DECLARE_PRIVATE(HDataCollection, T)

public:
    HDataCollection();

public:
    IFileStream *fileStream() override;
    void setUseIndex(QString value) override;
    QString useIndex() override;

protected:
    HDataCollection(HDataCollectionPrivate<T> &);
};

template <typename T>
HDataCollection<T>::HDataCollection() :
    IDataCollection<T>(*new HDataCollectionPrivate<T>)
{
}

template<typename T>
HDataCollection<T>::HDataCollection(HDataCollectionPrivate<T> &p) :
    IDataCollection<T>(p)
{
}

template<typename T>
IFileStream *HDataCollection<T>::fileStream()
{
    H_D(HDataCollection, T);
    return d->fileStream;
}

template<typename T>
void HDataCollection<T>::setUseIndex(QString value)
{
    H_D(HDataCollection, T);
    if (d->useIndex == value || !this->contains(value))
        return;
    d->useIndex = value;
}

template<typename T>
QString HDataCollection<T>::useIndex()
{
    H_D(HDataCollection, T);
    return d->useIndex;
}

HE_DATA_END_NAMESPACE

#endif // HDATACOLLECTION_H
