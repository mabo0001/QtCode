/***************************************************************************************************
**      2019-07-11  HDrawHelper 绘制帮助类。
***************************************************************************************************/

#ifndef HDRAWHELPER_H
#define HDRAWHELPER_H

#include "HControlGlobal.h"

class QPainter;
class QColor;
class QPixmap;
class QImage;
class QSize;
class QPen;
class QPointF;

HE_CONTROL_BEGIN_NAMESPACE

class HDrawHelper
{
public:
    // 绘制遮罩层
    static void drawOverlay(QPainter *, double radius, QColor color);
    // 绘制十字瞄准线
    static void drawCrosshair(QPainter *, QPointF point, int width, QColor color);
    // 绘制十字光标
    static void drawCrossCursor(QPainter *, QPointF point, int size, QColor color);
    // 创建平铺图像
    static QImage createTiledImage(QColor color1, QColor color2, int size);
    // 创建十字图片
    static QImage createCrossImage(QSize size, QPen pen);

};

HE_CONTROL_END_NAMESPACE

#endif // HDRAWHELPER_H
