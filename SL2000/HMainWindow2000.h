#ifndef HMAINWINDOW2100_H
#define HMAINWINDOW2100_H

#include "HeGui/HAbstractMainWindow.h"

HE_GUI_USE_NAMESPACE

class HMainWindow2000Private;

class HMainWindow2000 : public HAbstractMainWindow
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HMainWindow2000)

public:
    explicit HMainWindow2000(QWidget *parent = 0, const HCallorHelper &helper = HCallorHelper());
    ~HMainWindow2000();

protected:
    void initImportExport() override;
    void initBuilder() override;
};

#endif // HMAINWINDOW2100_H
