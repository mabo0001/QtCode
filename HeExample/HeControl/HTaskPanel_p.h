#ifndef HTASKPANEL_P_H
#define HTASKPANEL_P_H

#include "HTaskPanel.h"
#include "HAbstractMultiPanel_p.h"

class QVBoxLayout;

HE_CONTROL_BEGIN_NAMESPACE

class HTaskWidget;

class HTaskPanelPrivate : public HAbstractMultiPanelPrivate
{
public:
    bool animated = false;
    QIcon toggleIcon;
    QList<HTaskWidget *> tasks;
    QWidget *panel;
    QVBoxLayout *layout;
};

HE_CONTROL_END_NAMESPACE

#endif // HTASKPANEL_P_H
