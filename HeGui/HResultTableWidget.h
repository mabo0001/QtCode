/***************************************************************************************************
**      2019-04-09  HResultTableWidget 结果表。
***************************************************************************************************/

#ifndef HRESULTTABLEWIDGET_H
#define HRESULTTABLEWIDGET_H

#include "HGuiGlobal.h"
#include "HePlugin/HEntireTableWidget.h"

HE_GUI_BEGIN_NAMESPACE

class HResultTableWidgetPrivate;

class HE_GUI_EXPORT HResultTableWidget : public HEntireTableWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HResultTableWidget)

public:
    explicit HResultTableWidget(QWidget *parent = nullptr);
    ~HResultTableWidget() override;

public:
    void setOptionals(QStringList value);
    void setSelecteds(QStringList value);
    void clearResult();
    void refreshResult(int row, bool append);

protected:
    HResultTableWidget(HResultTableWidgetPrivate &p, QWidget *parent = nullptr);

protected:
    void openOptionalDialog();

private:
    void init();
};

HE_GUI_END_NAMESPACE

#endif // HRESULTTABLEWIDGET_H
