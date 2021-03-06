/***************************************************************************************************
**      2018-06-19  HUsbPortLpc214 USB端口类。
***************************************************************************************************/

#ifndef HUSBPORTLPC214_H
#define HUSBPORTLPC214_H

#include "HAbstractPort.h"

HE_COMMUNICATE_BEGIN_NAMESPACE

class HUsbPortLpc214Private;

class HUsbPortLpc214 : public HAbstractPort
{
    Q_DECLARE_PRIVATE(HUsbPortLpc214)

public:
    explicit HUsbPortLpc214();
    ~HUsbPortLpc214() override;

public:
    QString typeName() override;

protected:
    HUsbPortLpc214(HUsbPortLpc214Private &);

protected:
    HErrorType openPort(int portNum) override;
    HErrorType closePort() override;
    HErrorType writeData(uchar *data, int maxSize) override;
    HErrorType readData(uchar *data, int maxSize) override;
};

HE_COMMUNICATE_END_NAMESPACE

#endif // HUSBPORTLPC214_H
