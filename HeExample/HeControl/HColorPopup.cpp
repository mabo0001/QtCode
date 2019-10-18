#include "HColorPopup_p.h"
#include "HColorModel.h"
#include "HColorDelegate.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QColorDialog>

HE_CONTROL_BEGIN_NAMESPACE

HColorPopup::HColorPopup(HColorModel *model, QWidget *parent) :
    QWidget(parent, Qt::Popup),
    d_ptr(new HColorPopupPrivate)
{
    auto l = new QVBoxLayout(this);
    d_ptr->view = new QListView;
    d_ptr->view->setFlow(QListView::LeftToRight);
    d_ptr->view->setResizeMode(QListView::Adjust);
    d_ptr->view->setWrapping(true);
    d_ptr->view->setUniformItemSizes(true);
    d_ptr->view->setMouseTracking(true);
    d_ptr->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    d_ptr->view->setItemDelegate(new HColorDelegate(this));
    d_ptr->view->setModel(model);
    d_ptr->button = new QPushButton(tr("其他"));
    d_ptr->button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    l->setSpacing(0);
    l->setMargin(0);
    l->addWidget(d_ptr->view);
    l->addWidget(d_ptr->button);
    connect(d_ptr->view, &QListView::clicked, this, &HColorPopup::selectIndex);
    connect(d_ptr->button, &QPushButton::clicked, this, &HColorPopup::popupDialog);
    setMaximumHeight(250);
}

HColorPopup::~HColorPopup()
{
}

QListView *HColorPopup::colorView() const
{
    return d_ptr->view;
}

void HColorPopup::setCurrentIndex(const QModelIndex &index)
{
    d_ptr->currentColor = qvariant_cast<QColor>(index.data(Qt::DecorationRole));
    d_ptr->view->selectionModel()->select(index, QItemSelectionModel::ClearAndSelect);
}

void HColorPopup::popupDialog()
{
    auto c = QColorDialog::getColor(d_ptr->currentColor, this, tr("选取颜色"), QColorDialog::ShowAlphaChannel);
    if (c == d_ptr->currentColor || !c.isValid())
        return;
    d_ptr->currentColor = c;
    emit selectColor(c);
}

HE_CONTROL_END_NAMESPACE