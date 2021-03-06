#ifndef HSPECFITTINGCHARTVIEW_P_H
#define HSPECFITTINGCHARTVIEW_P_H

#include "HSpecFittingChartView.h"
#include "HePlugin/HZoomChartView_p.h"

class HSingleAxisChart;
class HMarkerChartExtend;
class HCalloutChartExtend;

QT_CHARTS_BEGIN_NAMESPACE
class QLineSeries;
class QScatterSeries;
QT_CHARTS_END_NAMESPACE
QT_CHARTS_USE_NAMESPACE

HE_GUI_BEGIN_NAMESPACE

class HSpecFittingChartViewPrivate : public HZoomChartViewPrivate
{
public:
    HSingleAxisChart *chart;
    HMarkerChartExtend *marker;
    HCalloutChartExtend *callout;
    QHash<int, QLineSeries *> lineSeries;
    QHash<int, QScatterSeries *> scatterSeries;
};

HE_GUI_END_NAMESPACE

#endif // HSPECFITTINGCHARTVIEW_P_H
