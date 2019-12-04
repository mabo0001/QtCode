#ifndef HDETAILWIDGET2000DC_H
#define HDETAILWIDGET2000DC_H

#include "HeGui/HAbstractTestDetailWidget.h"

HE_GUI_USE_NAMESPACE

namespace Ui {
class HDetailWidget2000DC;
}

class HDetailWidget2000DCPrivate;

class HDetailWidget2000DC : public HAbstractTestDetailWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HDetailWidget2000DC)

public:
    explicit HDetailWidget2000DC(QWidget *parent = nullptr);
    ~HDetailWidget2000DC() override;

public:
    void initialize(QVariantMap param) override;
    QString typeName() override;

public:
    void refreshWidget() override;

private:
    Ui::HDetailWidget2000DC *ui;
};

#endif // HDETAILWIDGET2000DC_H