#include "HSqlFactory_p.h"
#include "HSqlDatabase.h"
#include "HSqlTableModel.h"
#include <QtCore/QDebug>

HE_SQL_BEGIN_NAMESPACE

HSqlFactory::HSqlFactory(QObject *parent) :
    QObject(parent),
    d_ptr(new HSqlFactoryPrivate)
{
    registerClass();
}

HSqlFactory::HSqlFactory(HSqlFactoryPrivate &p, QObject *parent) :
    QObject(parent),
    d_ptr(&p)
{
    registerClass();
}

HSqlFactory::~HSqlFactory()
{
    qDebug() << __func__;
}

void HSqlFactory::initialize(QVariantMap /*param*/)
{
}

QString HSqlFactory::typeName()
{
    return "HSqlFactory";
}

ISqlDatabase *HSqlFactory::createDatabase(QString type, QVariantMap param)
{
    Q_UNUSED(type)
    ISqlDatabase *p = new HSqlDatabase(this);
    p->initialize(param);
    return p;
}

ISqlTableModel *HSqlFactory::createTableModel(QString type, QVariantMap param)
{
    Q_UNUSED(type)
    ISqlTableModel *p = new HSqlTableModel(this);
    p->initialize(param);
    return p;
}

void HSqlFactory::registerClass()
{
//    HFactory::registerClass<HSerialPort>("HSerialPort");
//    HFactory::registerClass<HUsbPortCy>("HUsbPortCy");
//    HFactory::registerClass<HDeviceSL>("HDeviceSL");
}

HE_SQL_END_NAMESPACE
