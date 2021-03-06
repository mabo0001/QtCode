/***************************************************************************************************
**      2019-05-09  ISqlBrowser 数据库浏览器接口。
***************************************************************************************************/

#ifndef ISQLBROWSER_H
#define ISQLBROWSER_H

#include "HSqlGlobal.h"
#include "HeCore/IInitializeable.h"
#include <QtWidgets/QWidget>

HE_CORE_USE_NAMESPACE

HE_SQL_BEGIN_NAMESPACE

class ISqlTableModel;
class ISqlHandle;
class ISqlPrint;

class ISqlBrowser : public QWidget, public IInitializeable
{
    Q_OBJECT

public:
    using QWidget::QWidget;

public:
    // 设置模型
    virtual void setModel(ISqlTableModel *) = 0;
    // 设置记录处理
    virtual void setRecordHandle(ISqlHandle *) = 0;
    // 设置记录打印
    virtual void setRecordPrint(ISqlPrint *) = 0;
};

HE_SQL_END_NAMESPACE


#endif // ISQLBROWSER_H
