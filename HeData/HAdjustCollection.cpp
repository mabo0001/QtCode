#include "HAdjustCollection_p.h"
#include "IDataFactory.h"
#include "IAdjust.h"
#include "IFileStream.h"
#include "HDataHelper.h"
#include "HeCore/HAppContext.h"

HE_DATA_BEGIN_NAMESPACE

HAdjustCollectionPrivate::HAdjustCollectionPrivate()
{
    factory = HAppContext::getContextPointer<IDataFactory>("IDataFactory");
    fileStream = factory->createFileStream("HFileStream");
    fileStream->setMagicNumber(0x00040001);
    fileStream->setFileVersion(0x01010101);
    fileStream->setFileFilter("Adjust files (*.hca)");
    fileStream->setReadContent([=](QDataStream &s) { readContent(s); });
    fileStream->setWriteContent([=](QDataStream &s) { writeContent(s); });
}

void HAdjustCollectionPrivate::readContent(QDataStream &s)
{
    quint32 version;

    s >> version;
    HDataHelper::read<QString, HeData::IAdjust>(s, datas, [=](QString type) { return factory->createAdjust(type); });
    s >> useIndex;
}

void HAdjustCollectionPrivate::writeContent(QDataStream &s)
{
    s << quint32(1);
    HDataHelper::write<QString, HeData::IAdjust>(s, datas);
    s << useIndex;
}

HAdjustCollection::HAdjustCollection() :
    IAdjustCollection(*new HAdjustCollectionPrivate)
{
}

HAdjustCollection::HAdjustCollection(HAdjustCollectionPrivate &p) :
    IAdjustCollection(p)
{
}

HAdjustCollection::~HAdjustCollection()
{
}

QString HAdjustCollection::typeName()
{
    return "HAdjustCollection";
}

QVariantMap HAdjustCollection::correct(QVariantMap value)
{
    auto i = item(useIndex());
    return i == nullptr ? QVariantMap() : i->correct(value);
}

HE_DATA_END_NAMESPACE
