/***************************************************************************************************
**      2019-06-12  HBattery 电池电量控件。
**                  http://www.qtcn.org/bbs/read-htm-tid-63464.html
**                  1:可设置电池电量,动态切换电池电量变化
**                  2:可设置电池电量警戒值
**                  3:可设置电池电量正常颜色和报警颜色
**                  4:可设置边框渐变颜色
**                  5:可设置电量变化时每次移动的步长
***************************************************************************************************/

#ifndef HBATTERY_H
#define HBATTERY_H

#include "HAnimationProgress.h"

HE_CONTROL_BEGIN_NAMESPACE

class HBatteryPrivate;

class HBattery : public HAnimationProgress
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HBattery)
    Q_PROPERTY(double alarmValue READ alarmValue WRITE setAlarmValue)
    Q_PROPERTY(QColor borderColorStart READ borderColorStart WRITE setBorderColorStart)
    Q_PROPERTY(QColor borderColorEnd READ borderColorEnd WRITE setBorderColorEnd)
    Q_PROPERTY(QColor alarmColorStart READ alarmColorStart WRITE setAlarmColorStart)
    Q_PROPERTY(QColor alarmColorEnd READ alarmColorEnd WRITE setAlarmColorEnd)
    Q_PROPERTY(QColor normalColorStart READ normalColorStart WRITE setNormalColorStart)
    Q_PROPERTY(QColor normalColorEnd READ normalColorEnd WRITE setNormalColorEnd)

public:
    explicit HBattery(QWidget *parent = nullptr);
    ~HBattery() override;

public:
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    double alarmValue() const;
    QColor borderColorStart() const;
    QColor borderColorEnd() const;
    QColor alarmColorStart() const;
    QColor alarmColorEnd() const;
    QColor normalColorStart() const;
    QColor normalColorEnd() const;

public:
    void setAlarmValue(double value);
    void setBorderColorStart(const QColor &value);
    void setBorderColorEnd(const QColor &value);
    void setAlarmColorStart(const QColor &value);
    void setAlarmColorEnd(const QColor &value);
    void setNormalColorStart(const QColor &value);
    void setNormalColorEnd(const QColor &value);

protected:
    HBattery(HBatteryPrivate &, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *) override;
};

HE_CONTROL_END_NAMESPACE

#endif // HBATTERY_H
