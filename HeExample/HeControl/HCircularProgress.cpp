#include "HCircularProgress_p.h"
#include "HCircularFactory.h"
#include "ICircular.h"
#include <QtCore/QTimer>
#include <QtGui/QPainter>
#include <QtWidgets/QActionGroup>

HE_CONTROL_BEGIN_NAMESPACE

HCircularProgress::HCircularProgress(QWidget *parent) :
    QWidget(parent),
    d_ptr(new HCircularProgressPrivate)
{
    init();
}

HCircularProgress::HCircularProgress(HCircularProgressPrivate &p, QWidget *parent) :
    QWidget(parent),
    d_ptr(&p)
{
    init();
}

HCircularProgress::~HCircularProgress()
{
}

QSize HCircularProgress::sizeHint() const
{
    return QSize(100, 100);
}

void HCircularProgress::setReverse(bool b)
{
    if (d_ptr->reverse == b)
        return;
    d_ptr->reverse = b;
    update();
}

void HCircularProgress::step(int value)
{
    if (d_ptr->step == value)
        return;
    d_ptr->step = value;
    update();
}

void HCircularProgress::setDuration(int value)
{
    if (d_ptr->timer->interval() == value)
        return;
    d_ptr->timer->setInterval(value);
}

void HCircularProgress::setCircular(ICircular *p)
{
    if (d_ptr->circular != nullptr)
        disconnect(d_ptr->circular, SIGNAL(dataChanged()), this, SLOT(update()));
    d_ptr->circular = p;
    connect(d_ptr->circular, SIGNAL(dataChanged()), this, SLOT(update()));
}

bool HCircularProgress::isReverse() const
{
    return d_ptr->reverse;
}

int HCircularProgress::step() const
{
    return d_ptr->step;
}

int HCircularProgress::duration() const
{
    return d_ptr->timer->interval();
}

void HCircularProgress::paintEvent(QPaintEvent *)
{
    if (d_ptr->circular == nullptr)
        return;

    QVariantMap param;
    param.insert("width", width());
    param.insert("height", height());
    param.insert("palette", palette());
    param.insert("reverse", d_ptr->reverse);
    param.insert("value", d_ptr->value);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    d_ptr->circular->draw(&painter, param);
}

void HCircularProgress::updateValue()
{
    d_ptr->value += d_ptr->reverse ? -d_ptr->step : d_ptr->step;
    d_ptr->value %= 360;
    update();
}

void HCircularProgress::changeCircular(QAction *p)
{
    if (p == nullptr)
        return;
    auto k = p->data().toString();
    if (!d_ptr->circularCache.contains(k))
        d_ptr->circularCache.insert(k, d_ptr->factory->create(k));
    setCircular(d_ptr->circularCache.value(k));
}

void HCircularProgress::init()
{
    d_ptr->factory = new HCircularFactory(this);
    auto group = new QActionGroup(this);
    for (auto k : d_ptr->factory->keys())
    {
        auto action = group->addAction(d_ptr->factory->alias(k));
        action->setCheckable(true);
        action->setData(k);
    }
    addActions(group->actions());
    connect(group, &QActionGroup::triggered, this, &HCircularProgress::changeCircular);
    setContextMenuPolicy(Qt::ActionsContextMenu);
    group->actions().first()->setChecked(true);
    changeCircular(group->actions().first());
    d_ptr->timer = new QTimer(this);
    d_ptr->timer->setInterval(100);
    connect(d_ptr->timer, &QTimer::timeout, this, &HCircularProgress::updateValue);
    d_ptr->timer->start();
}

HE_CONTROL_END_NAMESPACE
