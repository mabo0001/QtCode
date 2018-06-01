#ifndef HBUILDER2000_H
#define HBUILDER2000_H

#include "HeGui/HAbstractBuilder.h"

HE_GUI_USE_NAMESPACE

class HBuilder2000Private;

class HBuilder2000 : public HAbstractBuilder
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HBuilder2000)

public:
    explicit HBuilder2000(QObject *parent = nullptr);
    ~HBuilder2000();

signals:
    void configManageChanged(quint32 type);

public:
    virtual HMainWindow *createMainWindow() override;

protected:
    void buildFactory();
    void buildTestData();
    void buildConfigManage();
    void buildDevices();
    void buildProtocols();
    void buildThreads();
    void buildModel();
    void buildMainWindow();
    void buildMenu();



    void initMainWindow();
    void initConfigManageDefault();
    void initTestData(quint32 type);
};

#endif // HBUILDER2000_H
