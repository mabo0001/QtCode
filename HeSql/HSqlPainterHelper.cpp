#include "HSqlPainterHelper.h"
#include <QtGui/QPainter>
#include <QtWidgets/QWidget>

HE_SQL_BEGIN_NAMESPACE

QPointF HSqlPainterHelper::drawText(QPainter *painter, double x, double y, QString text, int flags)
{
    auto rect = painter->boundingRect(x, y, painter->viewport().width() - x, painter->viewport().height() - y, flags, text);
    painter->drawText(rect, flags, text);
    return rect.bottomRight();
}

QPointF HSqlPainterHelper::drawText(QPainter *painter, QRectF rect, QString text, int flags)
{
    rect = painter->boundingRect(rect, flags, text);
    painter->drawText(rect, flags, text);
    return rect.bottomRight();
}

QPointF HSqlPainterHelper::drawChart(QPainter *painter, QRectF rect, QString title, QWidget *widget)
{
    painter->setFont(QFont("宋体", 10));
    auto y = drawText(painter, rect, title, Qt::AlignHCenter).y();
    rect.setTop(y);
    auto side = qMin(rect.width(), rect.height());
    rect.adjust((rect.width() - side) / 2, 0, -(rect.width() - side) / 2, -(rect.height() - side));
    widget->resize(rect.size().toSize());
    widget->render(painter, rect.topLeft().toPoint());
    return rect.bottomRight();
}

HE_SQL_END_NAMESPACE
