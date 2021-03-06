/***************************************************************************************************
**      2018-06-19  各种转换函数。
***************************************************************************************************/

#ifndef HCORE_H
#define HCORE_H

#include "HActionType.h"
#include "HErrorType.h"

class QVariant;
class QStringList;

HE_CORE_BEGIN_NAMESPACE

class HDataFormatInfo;

class HE_CORE_EXPORT HCore
{
public:
    static QString toComment(HActionType type);
    static QString toComment(HErrorType type);

public:
    static HDataFormatInfo *toFormatInfo(QString type);
    static QString toString(QString type, double value, char f = 'f');
    static QString toString(QString type, QVariant value);
    static QStringList toString(QString type, QVector<double> value, char f = 'f');
    static QString toUnit(QString type);
    static QString toCaption(QString type);
    static QStringList toCaption(QStringList type);
    static QString toCaptionUnit(QString type);
    static QStringList toCaptionUnit(QStringList type);

public:
    static QString filenameFilter(const QString &name, const QList<QByteArray> formats);
    static QString filenameFilter(const QString &name, const QStringList &mimeTypes);
};

HE_CORE_END_NAMESPACE

#endif // HCORE_H
