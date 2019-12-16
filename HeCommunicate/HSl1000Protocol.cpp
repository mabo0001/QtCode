#include "HSl1000Protocol_p.h"
#include "HSerialPort.h"
#include "HSlCodecDevice.h"

HE_COMMUNICATE_BEGIN_NAMESPACE

HSl1000ProtocolPrivate::HSl1000ProtocolPrivate()
{
    QVariantMap param;
    param.insert("timeOut", 3000);
    param.insert("baudRate", 115200);
    auto port = new HSerialPort;
    port->initialize(param);
    device = new HSlCodecDevice;
    device->setPort(port, 4, true);
    device->setDeviceID(0x01);
    device->addActionParam(ACT_CHECK_DEVICE,               QList<uchar>() << 0x00 << 0x02 << 0x01 << 0x00);
    device->addActionParam(ACT_SET_SOURCE_MODE,            QList<uchar>() << 0x00 << 0x02 << 0x01 << 0x05);
    device->addActionParam(ACT_SET_OUTPUT_VOLTAGE,         QList<uchar>() << 0x00 << 0x02 << 0x01 << 0x06);
    device->addActionParam(ACT_SET_OUTPUT_CURRENT,         QList<uchar>() << 0x00 << 0x02 << 0x01 << 0x07);
    device->addActionParam(ACT_SET_GEARS_OUTPUT_CURRENT,   QList<uchar>() << 0x00 << 0x02 << 0x01 << 0x08);
    device->addActionParam(ACT_SET_REVERSE_VOLTAGE,        QList<uchar>() << 0x00 << 0x02 << 0x01 << 0x09);
    device->addActionParam(ACT_GET_ELEC_PARAM,             QList<uchar>() << 0x00 << 0x06 << 0x01 << 0x11);
    device->addActionParam(ACT_GET_MEASURED_VOLTAGE,       QList<uchar>() << 0x00 << 0x02 << 0x01 << 0x12);
    device->addActionParam(ACT_GET_MEASURED_CURRENT,       QList<uchar>() << 0x00 << 0x02 << 0x01 << 0x13);
    device->addActionParam(ACT_GET_REVERSE_CURRENT,        QList<uchar>() << 0x00 << 0x02 << 0x01 << 0x14);
}

HSl1000Protocol::HSl1000Protocol() :
    HLittleProtocol(*new HSl1000ProtocolPrivate)
{
}

HSl1000Protocol::HSl1000Protocol(HSl1000ProtocolPrivate &p) :
    HLittleProtocol(p)
{
}

HSl1000Protocol::~HSl1000Protocol()
{
}

void HSl1000Protocol::initialize(QVariantMap param)
{
    Q_D(HSl1000Protocol);
    d->device->initialize(param);
}

QString HSl1000Protocol::typeName()
{
    return "HSl1000Protocol";
}

HE_COMMUNICATE_END_NAMESPACE