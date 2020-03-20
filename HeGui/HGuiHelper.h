/***************************************************************************************************
**      2019-03-01  HGuiHelper Gui帮助类。
***************************************************************************************************/

#ifndef HGUIHELPER_H
#define HGUIHELPER_H

#include "HGuiGlobal.h"

class QWidget;
class QMainWindow;

HE_GUI_BEGIN_NAMESPACE

class ITestWidget;

class HE_GUI_EXPORT HGuiHelper
{
public:
    static QMainWindow *decoratorInMainWindow(ITestWidget *widget, QWidget *parent = nullptr);
//    static QString copy(QTableView *widget, bool withHeader = false);
//    static QString copy(QTableWidget *widget, bool withHeader = false);
//    static QString paste(QTableView *widget);
//    static QString paste(QTableWidget *widget);
//    static QString selectedParameter(QWidget *parent, QStringList optional);
//    static QAction *addSeparator(QWidget *widget);
};

HE_GUI_END_NAMESPACE

#endif // HGUIHELPER_H
