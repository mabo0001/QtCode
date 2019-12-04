/***************************************************************************************************
**      2019-11-29  HDynamicChartView
***************************************************************************************************/

#ifndef HDYNAMICCHARTVIEW_H
#define HDYNAMICCHARTVIEW_H

#include "HZoomChartView.h"

QT_CHARTS_BEGIN_NAMESPACE
class QValueAxis;
QT_CHARTS_END_NAMESPACE

class HDynamicChartViewPrivate;

class QDESIGNER_WIDGET_EXPORT HDynamicChartView : public HZoomChartView
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HDynamicChartView)

public:
    explicit HDynamicChartView(QWidget *parent = nullptr);
    ~HDynamicChartView() override;

public:
    QValueAxis *axisX();
    QValueAxis *axisY();

public:
    void clear();
    void addPoint(QPointF point);

protected:
    HDynamicChartView(HDynamicChartViewPrivate &p, QWidget *parent = nullptr);

protected:
    void init() override;
};

#endif // HDYNAMICCHARTVIEW_H