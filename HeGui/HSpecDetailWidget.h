/***************************************************************************************************
**      2019-04-11  HSpecDetailWidget 光谱详情窗体类。
***************************************************************************************************/

#ifndef HSPECDETAILWIDGET_H
#define HSPECDETAILWIDGET_H

#include "HAbstractTestDetailWidget.h"

namespace Ui {
class HSpecDetailWidget;
}

HE_GUI_BEGIN_NAMESPACE

class HSpecDetailWidgetPrivate;

class HSpecDetailWidget : public HAbstractTestDetailWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HSpecDetailWidget)

public:
    explicit HSpecDetailWidget(QWidget *parent = nullptr);
    ~HSpecDetailWidget() override;

public:
    void initialize(QVariantMap param) override;
    QString typeName() override;

public:
    void refreshWidget() override;

private:
    Ui::HSpecDetailWidget *ui;
};

HE_GUI_END_NAMESPACE

#endif // HSPECDETAILWIDGET_H
