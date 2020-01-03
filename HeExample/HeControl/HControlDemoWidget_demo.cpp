#include "HControlDemoWidget_p.h"
#include "HStyleWidget.h"
#include "HFlatStyleWidget.h"
#include "HQssCreator.h"
#include "HIconFontWidget.h"
#include "HSpliteWidget.h"

HE_CONTROL_BEGIN_NAMESPACE

void HControlDemoWidget::addStyle()
{
    addTab(tr("DEMO"), "Style", new HStyleWidget);
    addTab(tr("DEMO"), "Flat", new HFlatStyleWidget);
    addTab(tr("DEMO"), "Qss", new HQssCreator);
    addTab(tr("DEMO"), tr("字体图标"), new HIconFontWidget);
    addTab(tr("DEMO"), tr("分割界面"), new HSpliteWidget);
}

HE_CONTROL_END_NAMESPACE