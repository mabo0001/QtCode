/***************************************************************************************************
**      2019-06-04  HControlHelper 控件帮助类。
***************************************************************************************************/

#ifndef HCONTROLHELPER_H
#define HCONTROLHELPER_H

#include "HControlGlobal.h"
#include <QtCore/QObject>

class QStringList;
class QDateTime;
class QWidget;

HE_CONTROL_BEGIN_NAMESPACE

class HControlHelper : public QObject
{
public:
    // 初始化翻译
    static void initTranslator();
    // 运行时间
    static QString runTime(QDateTime start, QDateTime end);
    // 窗体居中桌面
    static void centerWidget(QWidget *);
    // 无边框窗体
    static void framelessWidget(QWidget *, bool moveEnable = true, bool resizeEnable = true);
    // 无边框背景窗体
    static void translucentWidget(QWidget *, QStringList files, bool moveEnable = true);

protected:
    // 添加关闭
    static void addClose(QWidget *);
};

HE_CONTROL_END_NAMESPACE

#endif // HCONTROLHELPER_H
