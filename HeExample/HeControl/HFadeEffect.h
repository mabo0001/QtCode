/***************************************************************************************************
**      2019-07-24  HFadeEffect
***************************************************************************************************/

#ifndef HFADEEFFECT_H
#define HFADEEFFECT_H

#include "HAbstractShaderEffect.h"

HE_CONTROL_BEGIN_NAMESPACE

class HFadeEffectPrivate;

class HFadeEffect : public HAbstractShaderEffect
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HFadeEffect)

public:
    explicit HFadeEffect(QObject *parent = nullptr);
    ~HFadeEffect() override;

public:
    void initialize(QVariantMap param) override;
    QString typeName() override;

public:
    void draw(QPainter *, double factor, const QRect &rect, const QPixmap &pixmap) override;

protected:
    HFadeEffect(HFadeEffectPrivate &p, QObject *parent = nullptr);
};

HE_CONTROL_END_NAMESPACE

#endif // HFADEEFFECT_H