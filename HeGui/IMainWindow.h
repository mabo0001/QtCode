/***************************************************************************************************
**      2019-04-09  IMainWindow 主窗口接口。
***************************************************************************************************/

#ifndef IMAINWINDOW_H
#define IMAINWINDOW_H

#include "HGuiGlobal.h"
#include <QtWidgets/QMainWindow>

HE_GUI_BEGIN_NAMESPACE

class IMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    using QMainWindow::QMainWindow;

public:
    // 插入菜单
    virtual QAction *insertMenu(QMenu *) = 0;
    // 打开定标对话框
    virtual bool openCalibrateDlg(QDialog *) = 0;
};

HE_GUI_END_NAMESPACE

#endif // IMAINWINDOW_H
