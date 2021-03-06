/***************************************************************************************************
**      2019-05-05  HQuality 品质数据。
***************************************************************************************************/

#ifndef HQUALITY_H
#define HQUALITY_H

#include "IQuality.h"

HE_DATA_BEGIN_NAMESPACE

class HQualityPrivate;
class IQualityItemCollection;

class HQuality : public IQuality
{
public:
    explicit HQuality();
    virtual ~HQuality();

public:
    void initialize(QVariantMap param) override;
    QString typeName() override;

public:
    void readContent(QDataStream &, IDataFactory *) override;
    void writeContent(QDataStream &) override;

public:
    IQualityItemCollection *itemCollection(QualityType type) override;
    void setColor(HQualityReport type, QColor color) override;
    QColor color(HQualityReport value) override;
    HQualityReport check(QVariantMap value, QVariantMap *color) override;
    double drift(QString type, QVariant value) override;

protected:
    HQuality(HQualityPrivate &p);

protected:
    QScopedPointer<HQualityPrivate> d_ptr;
};

HE_DATA_END_NAMESPACE

#endif // HQUALITY_H
