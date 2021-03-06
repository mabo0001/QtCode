/***************************************************************************************************
**      2018-06-19  HCIE1931Widget CIE1931窗口部件。
***************************************************************************************************/

#ifndef HCIE1931WIDGET_H
#define HCIE1931WIDGET_H

#include "HCartesianWidget.h"

class HCie1931WidgetPrivate;

class QDESIGNER_WIDGET_EXPORT HCie1931Widget : public HCartesianWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HCie1931Widget)
    Q_PROPERTY(bool enableTracking READ isEnableTracking WRITE setEnableTracking)
    Q_PROPERTY(bool drawCIE READ isDrawCIE WRITE setDrawCIE)
    Q_PROPERTY(bool drawHorseshoe READ isDrawHorseshoe WRITE setDrawHorseshoe)
    Q_PROPERTY(QColor colorHorseshoe READ colorHorseshoe WRITE setColorHorseshoe)
    Q_PROPERTY(bool drawPlanckian READ isDrawPlanckian WRITE setDrawPlanckian)
    Q_PROPERTY(QColor colorPlanckian READ colorPlanckian WRITE setColorPlanckian)
    Q_PROPERTY(bool drawGrade READ isDrawGrade WRITE setDrawGrade)
    Q_PROPERTY(QColor colorGrade READ colorGrade WRITE setColorGrade)
    Q_PROPERTY(QColor colorGradeFocus READ colorGradeFocus WRITE setColorGradeFocus)
    Q_PROPERTY(bool drawPoint READ isDrawPoint WRITE setDrawPoint)
    Q_PROPERTY(QColor colorPoint READ colorPoint WRITE setColorPoint)
    Q_PROPERTY(QColor colorPointFocus READ colorPointFocus WRITE setColorPointFocus)
    Q_PROPERTY(QFont fontPointFocus READ fontPointFocus WRITE setFontPointFocus)

public:
    explicit HCie1931Widget(QWidget *parent = nullptr);
    ~HCie1931Widget();

signals:
    void mouseDoubleClicked(QPointF point);

public:
    void setEnableTracking(bool b);
    void setDrawCIE(bool b);
    void setDrawHorseshoe(bool b);
    void setDrawPlanckian(bool b);
    void setDrawGrade(bool b);
    void setDrawPoint(bool b);
    void setColorHorseshoe(QColor value);
    void setColorPlanckian(QColor value);
    void setColorGrade(QColor value);
    void setColorGradeFocus(QColor value);
    void setColorPoint(QColor value);
    void setColorPointFocus(QColor value);
    void setFontPointFocus(QFont value);

public:
    bool isEnableTracking();
    bool isDrawCIE();
    bool isDrawHorseshoe();
    bool isDrawPlanckian();
    bool isDrawGrade();
    bool isDrawPoint();
    QColor colorHorseshoe();
    QColor colorPlanckian();
    QColor colorGrade();
    QColor colorGradeFocus();
    QColor colorPoint();
    QColor colorPointFocus();
    QFont fontPointFocus();

public:
    void setGradeFocus(QPolygonF value);
    void setGrade(QList<QPolygonF> value);
    void addGrade(QPolygonF value, bool focus = true, bool refresh = true);
    void removeGrade(QPolygonF value, bool refresh = true);
    void clearGrade();
    void setPointFocus(QPointF value);
    void setPoint(QList<QPointF> value);
    void addPoint(QPointF value, bool focus = true, bool refresh = true);
    void clearPoint();

protected:
    void mouseMoveEvent(QMouseEvent *) override;
    void mouseDoubleClickEvent(QMouseEvent *) override;
    bool drawElse(QPainter *) override;
    bool drawCIE(QPainter *);
    bool drawHorseshoe(QPainter *);
    bool drawPlanckian(QPainter *);
    bool drawGradeBlock(QPainter *);
    bool drawPoint(QPainter *);

protected slots:
    void handlePlotAreaChanged(QRectF value);
    void handlePositionChanged(QPointF pos);

private:
    void init();
};

#endif // HCIE1931WIDGET_H
