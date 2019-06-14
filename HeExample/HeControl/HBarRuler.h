/***************************************************************************************************
**      2019-06-11  HBarRuler 柱状标尺控件。
**                  http://www.qtcn.org/bbs/read-htm-tid-63464.html
**                  1：可设置精确度(小数点后几位)和间距
**                  2：可设置背景色/柱状颜色/线条颜色
**                  3：可设置长线条步长及短线条步长
**                  4：可启用动画及设置动画步长
**                  5：可设置范围值
**                  6：支持负数刻度值
***************************************************************************************************/

#ifndef HBARRULER_H
#define HBARRULER_H

#include "HControlGlobal.h"
#include <QtWidgets/QWidget>

HE_CONTROL_BEGIN_NAMESPACE

class HBarRulerPrivate;

class HBarRuler : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(double minValue READ minValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ maxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ value WRITE setValue)
    Q_PROPERTY(int precision READ precision WRITE setPrecision)
    Q_PROPERTY(int longStep READ longStep WRITE setLongStep)
    Q_PROPERTY(int shortStep READ shortStep WRITE setShortStep)
    Q_PROPERTY(int space READ space WRITE setSpace)
    Q_PROPERTY(bool animation READ isAnimation WRITE setAnimation)
    Q_PROPERTY(double animationStep READ animationStep WRITE setAnimationStep)
    Q_PROPERTY(QColor backgroundStart READ backgroundStart WRITE setBackgroundStart)
    Q_PROPERTY(QColor backgroundEnd READ backgroundEnd WRITE setBackgroundEnd)
    Q_PROPERTY(QColor lineColor READ lineColor WRITE setLineColor)
    Q_PROPERTY(QColor barBackground READ barBackground WRITE setBarBackground)
    Q_PROPERTY(QColor barColor READ barColor WRITE setBarColor)

public:
    explicit HBarRuler(QWidget *parent = nullptr);
    ~HBarRuler() override;

signals:
    void valueChanged(double value);

public:
    void setRange(double minValue, double maxValue);
    void setMinValue(double value);
    void setMaxValue(double value);
    void setValue(double value);
    void setPrecision(int value);
    void setLongStep(int value);
    void setShortStep(int value);
    void setSpace(int value);
    void setAnimation(bool b);
    void setAnimationStep(double value);
    void setBackgroundStart(QColor value);
    void setBackgroundEnd(QColor value);
    void setLineColor(QColor value);
    void setBarBackground(QColor value);
    void setBarColor(QColor value);

public:
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    double minValue() const;
    double maxValue() const;
    double value() const;
    int precision() const;
    int longStep() const;
    int shortStep() const;
    int space() const;
    bool isAnimation() const;
    double animationStep() const;
    QColor backgroundStart() const;
    QColor backgroundEnd() const;
    QColor lineColor() const;
    QColor barBackground() const;
    QColor barColor() const;

protected:
    HBarRuler(HBarRulerPrivate &p, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *) override;
    void drawBackground(QPainter *);
    void drawRuler(QPainter *);
    void drawBar(QPainter *);

protected:
    QScopedPointer<HBarRulerPrivate> d_ptr;

private:
    void init();
    void animationUpdate();
};

HE_CONTROL_END_NAMESPACE

#endif // HBARRULER_H
