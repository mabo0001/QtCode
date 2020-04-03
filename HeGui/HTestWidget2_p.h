#ifndef HTESTWIDGET2_P_H
#define HTESTWIDGET2_P_H

#include "HTestWidget2.h"
#include "HTestWidget_p.h"
#include "HeData/HDataGlobal.h"
#include "HeSql/ISqlTableModel.h"

HE_SQL_BEGIN_NAMESPACE
class ISqlHandle;
class ISqlPrint;
HE_SQL_END_NAMESPACE
HE_SQL_USE_NAMESPACE

HE_GUI_BEGIN_NAMESPACE

class HE_GUI_EXPORT HTestWidget2Private : public HTestWidgetPrivate
{
public:
    HTestWidget2Private();

public:
    ISqlHandle *sqlHandle;
    ISqlPrint *sqlPrint;

public:
    QAction *actionExportDatabase;
    QAction *actionPrintPreview;

public:
    QStringList displays;
    QStringList tableSelecteds;
};

HE_GUI_END_NAMESPACE

#endif // HTESTWIDGET2_P_H