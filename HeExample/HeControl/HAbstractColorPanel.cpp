#include "HAbstractColorPanel_p.h"

HE_CONTROL_BEGIN_NAMESPACE

HAbstractColorPanel::HAbstractColorPanel(QWidget *parent) :
    QWidget(parent),
    d_ptr(new HAbstractColorPanelPrivate)
{
}

HAbstractColorPanel::HAbstractColorPanel(HAbstractColorPanelPrivate &p, QWidget *parent) :
    QWidget(parent),
    d_ptr(&p)
{
}

HAbstractColorPanel::~HAbstractColorPanel()
{
}

QColor HAbstractColorPanel::color() const
{
    return d_ptr->color;
}

void HAbstractColorPanel::setColor(const QColor &value)
{
    if (d_ptr->color == value)
        return;
    d_ptr->color = value;
    emit colorPicked(value);
}

HE_CONTROL_END_NAMESPACE