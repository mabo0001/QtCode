#include "HMainWindow2000DC_p.h"
#include "HBuilder2000DC.h"
#include "HeData/IConfigManage.h"
#include <QtCore/QDebug>

HE_DATA_USE_NAMESPACE

HMainWindow2000DC::HMainWindow2000DC(QWidget *parent, const HCallorHelper &helper) :
    HAbstractMainWindow(*new HMainWindow2000DCPrivate(this), helper, parent)
{
}

HMainWindow2000DC::~HMainWindow2000DC()
{
    qDebug() << __func__;
}

void HMainWindow2000DC::initImportExport()
{
    Q_D(HMainWindow2000DC);
    HAbstractMainWindow::initImportExport();
    d->importExport.insert(tr("1.光谱定标数据(&S)..."),   IConfigManage::ContainSpec);
    d->importExport.insert(tr("2.电数据(&G)..."),         IConfigManage::ContainElec);
    d->importExport.insert(tr("3.分级数据(&G)..."),       IConfigManage::ContainGrade);
    d->importExport.insert(tr("4.调整数据(&A)..."),       IConfigManage::ContainAdjust);
    d->importExport.insert(tr("5.色容差数据(&C)..."),     IConfigManage::ContainChromatism);
}

void HMainWindow2000DC::initBuilder()
{
    Q_D(HMainWindow2000DC);
    d->builder = new HBuilder2000DC(this);
    d->builder->buildAll();
}