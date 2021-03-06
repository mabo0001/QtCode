/***************************************************************************************************
**      2019-06-19  HAbstractCircular
***************************************************************************************************/

#ifndef HABSTRACTCIRCULAR_H
#define HABSTRACTCIRCULAR_H

#include "ICircular.h"

HE_CONTROL_BEGIN_NAMESPACE

class HAbstractCircularPrivate;

class HAbstractCircular : public ICircular
{
    Q_OBJECT

public:
    explicit HAbstractCircular(QObject *parent = nullptr);
    ~HAbstractCircular() override;

public:
    void draw(QPainter *, QVariantMap param = QVariantMap()) override;

protected:
    HAbstractCircular(HAbstractCircularPrivate &p, QObject *parent = nullptr);

protected:
    QScopedPointer<HAbstractCircularPrivate> d_ptr;
};

HE_CONTROL_END_NAMESPACE

#endif // HABSTRACTCIRCULAR_H
