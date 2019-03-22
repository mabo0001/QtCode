/***************************************************************************************************
**      2019-03-21  ITestWidget.h 测试窗体接口。
***************************************************************************************************/

#ifndef ITESTWIDGET_H
#define ITESTWIDGET_H

#include "HGuiGlobal.h"
#include "HeCore/IInitializeable.h"
#include <QWidget>

class QMenu;
class QToolBar;

HE_CORE_USE_NAMESPACE

HE_GUI_BEGIN_NAMESPACE

class ITestWidget : public QWidget, public IInitializeable
{
    Q_OBJECT

public:
    using QWidget::QWidget;

public:
    // 菜单
    virtual QVector<QMenu *> menus() = 0;
    // 工具栏
    virtual QVector<QToolBar *> toolBars() = 0;

public:
    // 启动
    virtual void start() = 0;
    // 暂停
    virtual void pause() = 0;
};

HE_GUI_END_NAMESPACE

#endif // ITESTWIDGET_H
