#ifndef HSLIDENAVIGATION_P_H
#define HSLIDENAVIGATION_P_H

#include "HSlideNavigation.h"

HE_CONTROL_BEGIN_NAMESPACE

class HSlideNavigationPrivate
{
public:
    int currentIndex = -1;
    bool keyMoveEnable = false;
    Qt::Orientation orientation = Qt::Horizontal;
    bool fixed = false;
    int space = 25;
    int barRadious = 0;
    QColor barBackgroundStart = QColor(121, 121, 121);
    QColor barBackgroundEnd = QColor(78, 78, 78);
    int itemRadious = 0;
    QColor itemBackgroundStart = QColor(46, 132, 243);
    QColor itemBackgroundEnd  = QColor(39, 110, 203);
    QColor itemTextColor = Qt::white;
    HSlideNavigation::ItemLineStyle itemLineStyle = HSlideNavigation::None;
    int itemLineWidth = 3;
    QColor itemLineColor = QColor(255, 107, 107);

public:
    QMap<int, QPair<QString, QRectF>> items;
    int totalTextWidth = 0;
    int totalTextHeight = 0;

public:
    QTimer *slide = nullptr;
    QTimer *shake = nullptr;
    bool forward;
    QRectF rectStart;
    QRectF rectEnd;
};

HE_CONTROL_END_NAMESPACE

#endif // HSLIDENAVIGATION_P_H
