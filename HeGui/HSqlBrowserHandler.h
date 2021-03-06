/***************************************************************************************************
**      2019-05-15  HSqlBrowserHandler 数据库浏览器处理者类。
***************************************************************************************************/

#ifndef HSQLBROWSERHANDLER_H
#define HSQLBROWSERHANDLER_H

#include "HAbstractGuiHandler.h"

HE_GUI_BEGIN_NAMESPACE

class HSqlBrowserHandlerPrivate;

class HSqlBrowserHandler : public HAbstractGuiHandler
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HSqlBrowserHandler)

public:
    explicit HSqlBrowserHandler(QObject *parent = nullptr);
    ~HSqlBrowserHandler() override;

public:
    void initialize(QVariantMap param) override;
    QString typeName() override;

public:
    void execute(QObject *sender = nullptr, QVariantMap param = QVariantMap()) override;
};

HE_GUI_END_NAMESPACE

#endif // HSQLBROWSERHANDLER_H
