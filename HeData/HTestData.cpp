#include "HTestData_p.h"
#include "HeCore/HCore.h"
#include <QtCore/QDateTime>
#include <QtGui/QColor>

HE_DATA_BEGIN_NAMESPACE

void HTestDataPrivate::setData(const QString &type, const QVariant &value)
{
    if (datas.contains(type))
    {
        datas[type] = value;
        return;
    }
    if (successor != nullptr)
        return successor->setData(type, value);
    addData(type, value);
}

void HTestDataPrivate::setData(QVariantMap value)
{
    for (auto i = value.begin(); i != value.end(); i++)
        setData(i.key(), i.value());
}

void HTestDataPrivate::addData(const QString &type, const QVariant &value)
{
    datas.insert(type, value);
}

void HTestDataPrivate::addData(QVariantMap value)
{
    for (auto i = value.begin(); i != value.end(); i++)
        addData(i.key(), i.value());
}

QVariant HTestDataPrivate::data(const QString &type)
{
    if (datas.contains(type))
        return datas.value(type);
    if (successor != nullptr)
        return successor->data(type);
    if (type == "[测量日期时间]")
        return QDateTime::currentDateTime();
    if (type == "[测量日期]")
        return data("[测量日期时间]").toDate();
    if (type == "[测量时间]")
        return data("[测量日期时间]").toTime();
    return QVariant();
}

HTestData::HTestData() :
    d_ptr(new HTestDataPrivate)
{
}

HTestData::HTestData(HTestDataPrivate &p) :
    d_ptr(&p)
{
}

void HTestData::initialize(QVariantMap param)
{
    if (param.contains("successor"))
        setSuccessor(FromVariant(ITestData, param.value("successor")));
    if (param.contains("datas"))
        addData(param.value("datas").toMap());
}

QString HTestData::typeName()
{
    return "HTestData";
}

void HTestData::setSuccessor(ITestData *p)
{
    d_ptr->successor = p;
}

void HTestData::setData(QString type, QVariant value)
{
    d_ptr->setData(type, value);
}

void HTestData::setData(QVariantMap value)
{
    d_ptr->setData(value);
}

void HTestData::addData(QString type, QVariant value)
{
    d_ptr->addData(type, value);
}

void HTestData::addData(QVariantMap value)
{
    d_ptr->addData(value);
}

QVariant HTestData::data(QString type)
{
    return d_ptr->data(type);
}

QVariantMap HTestData::select(QStringList type)
{
    QVariantMap r;
    for (auto t : type)
        r.insert(t, data(t));
    return r;
}

QString HTestData::toString(QString type)
{
    return HCore::toString(type, data(type));
}

QStringList HTestData::toString(QStringList type)
{
    QStringList list;
    for (auto t : type)
        list << toString(t);
    return list;
}

QString HTestData::toHtmlTable(QStringList type, QColor bgcolor)
{
    QString text;
    for (auto t : type)
    {
        text += QString("<tr>"
                        "<td><p align = right>%1</p></td>"
                        "<td><p align = center>%2</p></td>"
                        "<td><p align = left>%3</p></td>"
                        "</tr>").arg(HCore::toCaption(t), toString(t), HCore::toUnit(t));
    }
    return QString("<table align = center border = 0 width = 300 cellspacing = 5 cellpadding = 5 bgcolor = %1 style = table-layout:fixed;>%2</table>").arg(bgcolor.name(), text);
}

HE_DATA_END_NAMESPACE
