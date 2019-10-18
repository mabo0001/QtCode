/***************************************************************************************************
**      2019-07-18  HAbstractNetworkWidget 抽象网络窗体
***************************************************************************************************/

#ifndef HABSTRACTNETWORKWIDGET_H
#define HABSTRACTNETWORKWIDGET_H

#include "HControlGlobal.h"
#include <QtWidgets/QWidget>

HE_CONTROL_BEGIN_NAMESPACE

class HAbstractNetworkWidgetPrivate;

class HAbstractNetworkWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(bool hexSend READ isHexSend WRITE setHexSend)
    Q_PROPERTY(bool hexReceive READ isHexReceive WRITE setHexReceive)
    Q_PROPERTY(bool ascii READ isAscii WRITE setAscii)
    Q_PROPERTY(bool autoSend READ isAutoSend WRITE setAutoSend)
    Q_PROPERTY(int interval READ interval WRITE setInterval)

public:
    explicit HAbstractNetworkWidget(QWidget *parent = nullptr);
    ~HAbstractNetworkWidget() override;

public:
    bool isHexSend() const;
    bool isHexReceive() const;
    bool isAscii() const;
    bool isAutoSend() const;
    int interval() const;

public slots:
    void setHexSend(bool b);
    void setHexReceive(bool b);
    void setAscii(bool b);
    void setAutoSend(bool b);
    void setInterval(int value);
    virtual void sendData() = 0;

protected:
    HAbstractNetworkWidget(HAbstractNetworkWidgetPrivate &p, QWidget *parent = nullptr);

protected:
    virtual void readSettings();
    virtual void writeSettings();
    virtual bool saveData(QString value);
    virtual QString fromByteArray(QByteArray value);
    virtual QByteArray toByteArray(QString value);

protected:
    QScopedPointer<HAbstractNetworkWidgetPrivate> d_ptr;

private:
    void init();
};

HE_CONTROL_END_NAMESPACE

#endif // HABSTRACTNETWORKWIDGET_H