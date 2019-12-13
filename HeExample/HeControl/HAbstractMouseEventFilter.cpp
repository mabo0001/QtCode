#include "HAbstractMouseEventFilter_p.h"
#include <QtGui/QMouseEvent>
#include <QtWidgets/QWidget>

HE_CONTROL_BEGIN_NAMESPACE

HAbstractMouseEventFilter::HAbstractMouseEventFilter(QObject *parent) :
    HAbstractEventFilter(*new HAbstractMouseEventFilterPrivate, parent)
{
}

HAbstractMouseEventFilter::HAbstractMouseEventFilter(HAbstractMouseEventFilterPrivate &p, QObject *parent) :
    HAbstractEventFilter(p, parent)
{
}

HAbstractMouseEventFilter::~HAbstractMouseEventFilter()
{
}

bool HAbstractMouseEventFilter::addWatched(QObject *p)
{
    if (!p->inherits("QWidget"))
        return false;
    return HAbstractEventFilter::addWatched(p);
}

bool HAbstractMouseEventFilter::handleInternal(QObject *watched, QEvent *event)
{
    auto w = static_cast<QWidget *>(watched);
    auto e = static_cast<QMouseEvent *>(event);
    if (w == nullptr || e == nullptr)
        return false;
    if (e->type() == QEvent::MouseButtonPress)
        return mousePressEvent(w, e);
    if (e->type() == QEvent::MouseButtonRelease)
        return mouseReleaseEvent(w, e);
    if (e->type() == QEvent::MouseMove)
        return mouseMoveEvent(w, e);
    return false;
}

HE_CONTROL_END_NAMESPACE
