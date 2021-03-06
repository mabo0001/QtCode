#include "HBattery_p.h"
#include <QtCore/QPropertyAnimation>
#include <QtGui/QPainter>

HE_CONTROL_BEGIN_NAMESPACE

HBattery::HBattery(QWidget *parent) :
    HAnimationProgress(*new HBatteryPrivate, parent)
{
}

HBattery::HBattery(HBatteryPrivate &p, QWidget *parent) :
    HAnimationProgress(p, parent)
{
}

HBattery::~HBattery()
{
}

QSize HBattery::sizeHint() const
{
    return QSize(150, 80);
}

QSize HBattery::minimumSizeHint() const
{
    return QSize(30, 10);
}

double HBattery::alarmValue() const
{
    Q_D(const HBattery);
    return d->alarmValue;
}

QColor HBattery::borderColorStart() const
{
    Q_D(const HBattery);
    return d->borderColorStart;
}

QColor HBattery::borderColorEnd() const
{
    Q_D(const HBattery);
    return d->borderColorEnd;
}

QColor HBattery::alarmColorStart() const
{
    Q_D(const HBattery);
    return d->alarmColorStart;
}

QColor HBattery::alarmColorEnd() const
{
    Q_D(const HBattery);
    return d->alarmColorEnd;
}

QColor HBattery::normalColorStart() const
{
    Q_D(const HBattery);
    return d->normalColorStart;
}

QColor HBattery::normalColorEnd() const
{
    Q_D(const HBattery);
    return d->normalColorEnd;
}

void HBattery::setAlarmValue(double value)
{
    Q_D(HBattery);
    if (qFuzzyCompare(d->alarmValue, value))
        return;
    d->alarmValue = value;
    update();
}

void HBattery::setBorderColorStart(const QColor &value)
{
    Q_D(HBattery);
    if (d->borderColorStart == value)
        return;
    d->borderColorStart = value;
    update();
}

void HBattery::setBorderColorEnd(const QColor &value)
{
    Q_D(HBattery);
    if (d->borderColorEnd == value)
        return;
    d->borderColorEnd = value;
    update();
}

void HBattery::setAlarmColorStart(const QColor &value)
{
    Q_D(HBattery);
    if (d->alarmColorStart == value)
        return;
    d->alarmColorStart = value;
    update();
}

void HBattery::setAlarmColorEnd(const QColor &value)
{
    Q_D(HBattery);
    if (d->alarmColorEnd == value)
        return;
    d->alarmColorEnd = value;
    update();
}

void HBattery::setNormalColorStart(const QColor &value)
{
    Q_D(HBattery);
    if (d->normalColorStart == value)
        return;
    d->normalColorStart = value;
    update();
}

void HBattery::setNormalColorEnd(const QColor &value)
{
    Q_D(HBattery);
    if (d->normalColorEnd == value)
        return;
    d->normalColorEnd = value;
    update();
}

void HBattery::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.save();
    // 绘制电池边框
    auto rect1 = QRectF(QPointF(5, 5), QPointF(width() * 9 / 10, height() - 5));
    painter.setPen(QPen(borderColorStart(), 5));
    painter.setBrush(Qt::NoBrush);
    painter.drawRoundRect(rect1, 10, 20);
    // 绘制电池头部
    auto rect2 = QRectF(QPointF(rect1.right(), height() / 3), QPointF(width() - 5, height() * 2 / 3));
    auto gradient2 = QLinearGradient(rect2.topLeft(), rect2.bottomLeft());
    gradient2.setColorAt(0.0, borderColorStart());
    gradient2.setColorAt(1.0, borderColorEnd());
    painter.setBrush(gradient2);
    painter.drawRoundRect(rect2, 15, 25);
    // 绘制电量
    auto margin = qMin(width(), height()) / 20;
    auto rect3 = rect1.adjusted(margin, margin, -margin, -margin);
    rect3.setWidth(rect3.width() * currentValue() / 100);
    auto gradient3 = QLinearGradient(QPointF(0, 0), QPointF(0, height()));
    gradient3.setColorAt(0.0, currentValue() <= alarmValue() ? alarmColorStart() : normalColorStart());
    gradient3.setColorAt(1.0, currentValue() <= alarmValue() ? alarmColorEnd() : normalColorEnd());
    painter.setPen(Qt::NoPen);
    painter.setBrush(gradient3);
    painter.drawRoundRect(rect3, 10, 20);
    painter.restore();
}

HE_CONTROL_END_NAMESPACE
