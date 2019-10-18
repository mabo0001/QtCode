#include "HAbstractGrade_p.h"
#include "IDataFactory.h"
#include "IGradeItem.h"
#include "HDataHelper.h"
#include "HeCore/HAppContext.h"

HE_DATA_BEGIN_NAMESPACE

HAbstractGradePrivate::HAbstractGradePrivate()
{
    factory = HAppContext::getContextPointer<IDataFactory>("IDataFactory");
}

HAbstractGrade::HAbstractGrade() :
    IGrade(*new HAbstractGradePrivate)
{
}

HAbstractGrade::HAbstractGrade(HAbstractGradePrivate &p) :
    IGrade(p)
{
}

HAbstractGrade::~HAbstractGrade()
{
}

void HAbstractGrade::readContent(QDataStream &s)
{
    Q_D(HAbstractGrade);
    quint32 version;

    s >> version;
    HDataHelper::read<QString, HeData::IGradeItem>(s, d->datas, [=](QString type) { return d->factory->createGradeItem(type); });
}

void HAbstractGrade::writeContent(QDataStream &s)
{
    Q_D(HAbstractGrade);
    s << quint32(1);
    HDataHelper::write<QString, HeData::IGradeItem>(s, d->datas);
}

QVariant HAbstractGrade::levels(QString type)
{
    return contains(type) ? value(type)->levels() : QVariant();
}

HE_DATA_END_NAMESPACE
