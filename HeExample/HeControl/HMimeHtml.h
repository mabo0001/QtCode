/***************************************************************************************************
**      2019-12-26  HMimeHtml
***************************************************************************************************/

#ifndef HMIMEHTML_H
#define HMIMEHTML_H

#include "HMimeText.h"

HE_CONTROL_BEGIN_NAMESPACE

class HMimeHtmlPrivate;

class HMimeHtml : public HMimeText
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HMimeHtml)

public:
    explicit HMimeHtml(QString html = QString(), QObject *parent = nullptr);
    ~HMimeHtml() override;

public:
    QString html() const;

public:
    void setHtml(const QString &value);

protected:
    HMimeHtml(HMimeHtmlPrivate &p, QString html = QString(), QObject *parent = nullptr);
};

HE_CONTROL_END_NAMESPACE

#endif // HMIMEHTML_H