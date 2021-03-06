#ifndef HANTLINE_P_H
#define HANTLINE_P_H

#include "HAntLine.h"

HE_CONTROL_BEGIN_NAMESPACE

class HAntLinePrivate
{
public:
    int lineLength = 6;
    int lineWidth = 2;
    int lineStep = 1;
    int lineSpeed = 100;
    QColor lineColor = Qt::black;
    HAntLine::LineStyle lineStyle = HAntLine::LineStyle_Rect;

public:
    int dash = 6;                   // 线条长度
    int space = 6;                  // 空白长度
    QVector<double> dashPattern;    // 线条样式数据
    QTimer *timer;
};

HE_CONTROL_END_NAMESPACE

#endif // HANTLINE_P_H
