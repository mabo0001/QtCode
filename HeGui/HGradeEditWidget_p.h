#ifndef HGRADEEDITWIDGET_P_H
#define HGRADEEDITWIDGET_P_H

#include "HGradeEditWidget.h"

HE_DATA_BEGIN_NAMESPACE
class IDataFactory;
HE_DATA_END_NAMESPACE

HE_GUI_BEGIN_NAMESPACE

class HGradeEditWidgetPrivate
{
public:
    HGradeEditWidgetPrivate();

public:
    IDataFactory *factory = nullptr;
    IGrade *data = nullptr;
    QStringList optionals;
    QStringList selecteds;
    QStringList unselecteds;
};

HE_GUI_END_NAMESPACE

#endif // HGRADEEDITWIDGET_P_H
