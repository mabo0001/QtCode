#include "HUi2008Protocol_p.h"
#include "HSerialPort.h"
#include "HPowerFactorDevice.h"
#include <QtCore/QVector>
#include <QtCore/QtMath>

HE_COMMUNICATE_BEGIN_NAMESPACE

HUi2008ProtocolPrivate::HUi2008ProtocolPrivate()
{
    QVariantMap param;
    param.insert("timeOut", 1000);
    param.insert("baudRate", 4800);
    auto port = new HSerialPort();
    port->initialize(param);
    device = new HPowerFactorDevice;
    device->setPort(port, 4, true);
    device->addActionParam(ACT_CHECK_DEVICE,    QList<uchar>() << 0x00 << 0x15 << 0x3F);
    device->addActionParam(ACT_GET_ELEC_PARAM,  QList<uchar>() << 0x00 << 0x15 << 0x3F);
}

HUi2008Protocol::HUi2008Protocol() :
    HLittleProtocol(*new HUi2008ProtocolPrivate)
{
}

HUi2008Protocol::~HUi2008Protocol()
{

}

QString HUi2008Protocol::typeName()
{
    return "HUi2008Protocol";
}

HErrorType HUi2008Protocol::getData(HActionType action, QVector<double> &value, int delay)
{
    int i,j,n,d;
    double t;
    QVector<uchar> data;
    auto error = HLittleProtocol::getData(action, data, delay);
    if (error != E_OK)
        return error;
    if (value.size() == 0)
        value.resize(data.size() / 4);
    auto size = qMin(value.size(), data.size() / 4);
    for (i = 0; i < size; i++)
    {
        n = 0;
        t = 0.0;
        for (j = 0; j < 4; j++)
        {
            d = data[1 + 4 * i + j];
            if (d >= 0x1B)
                d = 0x00;
            if (d >= 0x10)
            {
                d -= 0x10;
                n = j;
            }
            t = t * 10 + d;
        }
        value[i] = t * qPow(0.1, 3 - n);
    }
    return E_OK;
}

HE_COMMUNICATE_END_NAMESPACE
