#include "HAbstractServerWidget_p.h"
#include "HeCore/HAppContext.h"
#include <QtCore/QSettings>

HE_CORE_USE_NAMESPACE
HE_CONTROL_BEGIN_NAMESPACE

HAbstractServerWidget::HAbstractServerWidget(QWidget *parent) :
    HAbstractNetworkWidget(*new HAbstractServerWidgetPrivate, parent)
{
}

HAbstractServerWidget::HAbstractServerWidget(HAbstractServerWidgetPrivate &p, QWidget *parent) :
    HAbstractNetworkWidget(p, parent)
{
}

HAbstractServerWidget::~HAbstractServerWidget()
{
}

QString HAbstractServerWidget::listenIP() const
{
    Q_D(const HAbstractServerWidget);
    return d->listenIP;
}

quint16 HAbstractServerWidget::listenPort() const
{
    Q_D(const HAbstractServerWidget);
    return d->listenPort;
}

void HAbstractServerWidget::setListenIP(const QString &value)
{
    Q_D(HAbstractServerWidget);
    if (d->listenIP == value)
        return;
    d->listenIP = value;
}

void HAbstractServerWidget::setListenPort(int value)
{
    Q_D(HAbstractServerWidget);
    if (d->listenPort == value)
        return;
    d->listenPort = value;
}

void HAbstractServerWidget::handleSentData(const QString &ip, quint16 port, const QByteArray &data)
{
    auto text = fromByteArray(data);
    append(0, QString("[%1:%2] %3").arg(ip).arg(port).arg(text));
}

void HAbstractServerWidget::handleReceiveData(const QString &ip, quint16 port, const QByteArray &data)
{
    auto text = fromByteArray(data);
    append(1, QString("[%1:%2] %3").arg(ip).arg(port).arg(text));
}

void HAbstractServerWidget::readSettings()
{
    Q_D(HAbstractServerWidget);
    HAbstractNetworkWidget::readSettings();
    auto fileName = HAppContext::getContextValue<QString>("Settings");
    auto settings = new QSettings(fileName, QSettings::IniFormat, this);
    settings->beginGroup(groupName());
    d->listenIP = settings->value("iListenIP", "127.0.0.1").toString();
    d->listenPort = settings->value("iListenPort", 6000).value<quint16>();
    settings->endGroup();
}

void HAbstractServerWidget::writeSettings()
{
    Q_D(HAbstractServerWidget);
    HAbstractNetworkWidget::writeSettings();
    auto fileName = HAppContext::getContextValue<QString>("Settings");
    auto settings = new QSettings(fileName, QSettings::IniFormat, this);
    settings->beginGroup(groupName());
    settings->setValue("iListenIP", d->listenIP);
    settings->setValue("iListenPort", d->listenPort);
    settings->endGroup();
}

HE_CONTROL_END_NAMESPACE