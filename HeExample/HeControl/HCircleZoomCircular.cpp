#include "HCircleZoomCircular_p.h"
#include <QtGui/QPainter>

HE_CONTROL_BEGIN_NAMESPACE

HZoomCircleCircular::HZoomCircleCircular(QObject *parent) :
    HAbstractCircular(*new HZoomCircleCircularPrivate, parent)
{
}

HZoomCircleCircular::HZoomCircleCircular(HZoomCircleCircularPrivate &p, QObject *parent) :
    HAbstractCircular(p, parent)
{
}

HZoomCircleCircular::~HZoomCircleCircular()
{
}

void HZoomCircleCircular::initialize(QVariantMap param)
{
    if (param.contains("foreground"))
        setForeground(param.value("foreground").value<QColor>());
}

QString HZoomCircleCircular::typeName()
{
    return "HZoomCircleCircular";
}

void HZoomCircleCircular::draw(QPainter *painter, QVariantMap param)
{
    Q_D(HZoomCircleCircular);
    HAbstractCircular::draw(painter, param);
    auto value = param.value("value", 0).toInt();
    auto radious = calcRaidous(value);

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(d->foreground);
    painter->drawEllipse(QRectF(-radious, -radious, 2 * radious, 2 * radious));
    painter->restore();
}

QColor HZoomCircleCircular::foreground() const
{
    Q_D(const HZoomCircleCircular);
    return d->foreground;
}

double HZoomCircleCircular::minimum() const
{
    Q_D(const HZoomCircleCircular);
    return d->minimum;
}

bool HZoomCircleCircular::bounce() const
{
    Q_D(const HZoomCircleCircular);
    return d->bounce;
}

void HZoomCircleCircular::setForeground(const QColor &value)
{
    Q_D(HZoomCircleCircular);
    if (d->foreground == value)
        return;
    d->foreground = value;
    emit dataChanged();
}

void HZoomCircleCircular::setMinimum(int value)
{
    Q_D(HZoomCircleCircular);
    value = qBound(0, value, 50);
    if (d->minimum == value)
        return;
    d->minimum = value;
    emit dataChanged();
}

void HZoomCircleCircular::setBounce(bool b)
{
    Q_D(HZoomCircleCircular);
    if (d->bounce == b)
        return;
    d->bounce = b;
    emit dataChanged();
}

double HZoomCircleCircular::calcRaidous(int value)
{
    Q_D(HZoomCircleCircular);
    auto span = (50 - d->minimum) / 360.0;
    if (d->bounce)
    {
        value = qAbs(qAbs(value) - 180);
        return d->minimum + 2 * span * value;
    }
    return value >= 0 ? d->minimum + span * value : 50 + span * value;
}

HE_CONTROL_END_NAMESPACE
