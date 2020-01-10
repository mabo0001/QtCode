#include "HNavigationSlider_p.h"
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QLayout>

HE_CONTROL_BEGIN_NAMESPACE

HNavigationSlider::HNavigationSlider(QWidget *parent) :
    QAbstractSlider(parent),
    d_ptr(new HNavigationSliderPrivate)
{
    init();
}

HNavigationSlider::HNavigationSlider(HNavigationSliderPrivate &p, QWidget *parent) :
    QAbstractSlider(parent),
    d_ptr(&p)
{
    init();
}

HNavigationSlider::~HNavigationSlider()
{
}

bool HNavigationSlider::isAutoRaise() const
{
    return d_ptr->first->autoRaise();
}

Qt::ToolButtonStyle HNavigationSlider::toolButtonStyle() const
{
    return d_ptr->first->toolButtonStyle();
}

void HNavigationSlider::setOrientation(Qt::Orientation value)
{
    if (orientation() == value && layout() != nullptr)
        return;
    QAbstractSlider::setOrientation(value);
    sliderChange(SliderOrientationChange);
}

void HNavigationSlider::setAutoRaise(bool b)
{
    if (isAutoRaise() == b)
        return;
    d_ptr->first->setAutoRaise(b);
    d_ptr->previous->setAutoRaise(b);
    d_ptr->next->setAutoRaise(b);
    d_ptr->last->setAutoRaise(b);
}

void HNavigationSlider::setToolButtonStyle(Qt::ToolButtonStyle value)
{
    if (toolButtonStyle() == value)
        return;
    d_ptr->first->setToolButtonStyle(value);
    d_ptr->previous->setToolButtonStyle(value);
    d_ptr->next->setToolButtonStyle(value);
    d_ptr->last->setToolButtonStyle(value);
}

void HNavigationSlider::setListWidget(QListWidget *p)
{
    if (d_ptr->listWidget)
    {
        d_ptr->listWidget->model()->disconnect(this);
        d_ptr->listWidget->disconnect(this);
    }
    d_ptr->listWidget = p;
    if (d_ptr->listWidget)
    {
        connect(d_ptr->listWidget->model(), &QAbstractItemModel::rowsInserted, this, &HNavigationSlider::updateRange);
        connect(d_ptr->listWidget->model(), &QAbstractItemModel::rowsRemoved, this, &HNavigationSlider::updateRange);
        connect(d_ptr->listWidget->model(), &QAbstractItemModel::modelReset, this, &HNavigationSlider::updateRange);
        connect(d_ptr->listWidget, &QListWidget::destroyed, this, [=] { d_ptr->listWidget = nullptr; });
        connect(d_ptr->listWidget, &QListWidget::currentRowChanged, this, &HNavigationSlider::setValue);
    }
    updateRange();
}

void HNavigationSlider::toFirst()
{
    if (value() == minimum())
        return;
    setValue(minimum());
    emit first();
}

void HNavigationSlider::toPrevious()
{
    if (value() == minimum()) return;
    setValue(value() - 1);
    emit previous();
}

void HNavigationSlider::toNext()
{
    if (value() >= maximum())
        return;
    setValue(value() + 1);
    emit next();
}

void HNavigationSlider::toLast()
{
    if (value() >= maximum())
        return;
    setValue(maximum());
    emit last();
}

void HNavigationSlider::sliderChange(SliderChange change)
{
    updateUi(value());
    if (change == SliderRangeChange)
        d_ptr->slider->setRange(minimum(), maximum());
    if (change == SliderStepsChange)
    {
        d_ptr->slider->setSingleStep(singleStep());
        d_ptr->slider->setPageStep(pageStep());
    }
    if (change == SliderOrientationChange)
    {
        QBoxLayout *layout = nullptr;
        auto old = this->layout();
        if (old != nullptr)
        {
            old->removeWidget(d_ptr->first);
            old->removeWidget(d_ptr->previous);
            old->removeWidget(d_ptr->slider);
            old->removeWidget(d_ptr->next);
            old->removeWidget(d_ptr->last);
            delete old;
            auto policy = sizePolicy();
            policy.transpose();
            setSizePolicy(policy);
        }
        if (orientation() == Qt::Horizontal)
        {
            layout = new QHBoxLayout(this);
            d_ptr->slider->setInvertedAppearance(false);
            d_ptr->slider->setInvertedControls(false);
            d_ptr->slider->setOrientation(Qt::Horizontal);
            d_ptr->first->setIcon(QIcon::fromTheme("go-first", QIcon(":/image/ww/go-first.png")));
            d_ptr->previous->setIcon(QIcon::fromTheme("go-previous", QIcon(":/image/ww/go-previous.png")));
            d_ptr->next->setIcon(QIcon::fromTheme("go-next", QIcon(":/image/ww/go-next.png")));
            d_ptr->last->setIcon(QIcon::fromTheme("go-last", QIcon(":/image/ww/go-last.png")));
        }
        if (orientation() == Qt::Vertical)
        {
            layout = new QVBoxLayout(this);
            d_ptr->slider->setInvertedAppearance(true);
            d_ptr->slider->setInvertedControls(true);
            d_ptr->slider->setOrientation(Qt::Vertical);
            d_ptr->first->setIcon(QIcon::fromTheme("go-top", QIcon(":/image/ww/go-top.png")));
            d_ptr->previous->setIcon(QIcon::fromTheme("go-up", QIcon(":/image/ww/go-up.png")));
            d_ptr->next->setIcon(QIcon::fromTheme("go-down", QIcon(":/image/ww/go-down.png")));
            d_ptr->last->setIcon(QIcon::fromTheme("go-bottom", QIcon(":/image/ww/go-bottom.png")));
        }
        layout->setMargin(0);
        layout->addWidget(d_ptr->first);
        layout->addWidget(d_ptr->previous);
        layout->addWidget(d_ptr->slider);
        layout->addWidget(d_ptr->next);
        layout->addWidget(d_ptr->last);
        resize(sizeHint());
    }
    QAbstractSlider::sliderChange(change);
}

void HNavigationSlider::updateUi(int value)
{
    d_ptr->slider->setValue(value);
    d_ptr->first->setEnabled(value != minimum() && minimum() != maximum());
    d_ptr->previous->setEnabled(value != minimum() && minimum() != maximum());
    d_ptr->next->setEnabled(value != maximum() && minimum() != maximum());
    d_ptr->last->setEnabled(value != maximum() && minimum() != maximum());
    if (d_ptr->listWidget)
        d_ptr->listWidget->setCurrentRow(value);
}

void HNavigationSlider::updateRange()
{
    if (d_ptr->listWidget == nullptr)
    {
        setRange(0, 0);
        return;
    }
    setRange(0, d_ptr->listWidget->count() - 1);
    setValue(d_ptr->listWidget->currentRow());
}

void HNavigationSlider::init()
{
    d_ptr->first = new QToolButton;
    d_ptr->first->setText(tr("第一个"));
    d_ptr->first->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    d_ptr->previous = new QToolButton;
    d_ptr->previous->setText(tr("上一个"));
    d_ptr->previous->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    d_ptr->next = new QToolButton;
    d_ptr->next->setText(tr("下一个"));
    d_ptr->next->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    d_ptr->last = new QToolButton;
    d_ptr->last->setText(tr("最后一个"));
    d_ptr->last->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    d_ptr->slider = new QSlider(Qt::Horizontal);
    d_ptr->slider->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    connect(d_ptr->first, &QToolButton::clicked, this, &HNavigationSlider::toFirst);
    connect(d_ptr->previous, &QToolButton::clicked, this, &HNavigationSlider::toPrevious);
    connect(d_ptr->next, &QToolButton::clicked, this, &HNavigationSlider::toNext);
    connect(d_ptr->last, &QToolButton::clicked, this, &HNavigationSlider::toLast);
    connect(d_ptr->slider, &QSlider::valueChanged, this, &HNavigationSlider::setValue);
    connect(this, &HNavigationSlider::valueChanged, this, &HNavigationSlider::updateUi);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    setOrientation(Qt::Horizontal);
    setWindowIcon(QIcon(":/image/ww/listnavigator.png"));
}

HE_CONTROL_END_NAMESPACE