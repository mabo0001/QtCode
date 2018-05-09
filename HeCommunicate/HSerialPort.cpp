#include "HSerialPort_p.h"
#include <QVector>
#include <QtSerialPort/QSerialPort>

HE_COMMUNICATE_USE_NAMESPACE

bool HSerialPortPrivate::openSerialPort(int portNum, QObject *parent)
{
    serial = new QSerialPort(QString("COM%1").arg(portNum), parent);
    return serial->setBaudRate(baudRate) && serial->open(QIODevice::ReadWrite);
}


HSerialPort::HSerialPort(QObject *parent)
    : HAbstractPort(*new HSerialPortPrivate(), parent)
{
}

HSerialPort::HSerialPort(HSerialPortPrivate &p, QObject *parent)
    : HAbstractPort(p, parent)
{
}

HSerialPort::~HSerialPort()
{
}

void HSerialPort::initialize(QVariantMap param)
{
    Q_D(HSerialPort);
    HAbstractPort::initialize(param);
    if (param.contains("baudRate"))
        d->baudRate = param.value("baudRate").toInt();
}

QString HSerialPort::typeName()
{
    return "COM";
}

HErrorType HSerialPort::transport(QVector<uchar> &downData, QVector<uchar> &upData, int delay)
{
    Q_D(HSerialPort);
    auto error = write(downData);
    if (error != E_OK)
        return error;

    if (delay >= 10)
        d->serial->waitForReadyRead(delay);

    return read(upData);
}

HErrorType HSerialPort::clear()
{
    if (!isConnected())
        return E_PORT_CLOSED;

    Q_D(HSerialPort);
    d->serial->clear();
    return E_OK;
}

HErrorType HSerialPort::openPort(int portNum)
{
    Q_D(HSerialPort);
    if (!d->openSerialPort(portNum, this))
        return E_PORT_INVALID_HANDLE;
    return E_OK;
}

HErrorType HSerialPort::closePort()
{
    Q_D(HSerialPort);
    d->serial->close();
    return E_OK;
}

HErrorType HSerialPort::writeData(uchar *data, int maxSize)
{
    Q_D(HSerialPort);
    auto ret = d->serial->write(reinterpret_cast<char *>(data), maxSize);
    if(!d->serial->waitForBytesWritten(d->timeOut))
        return E_PORT_WRITE_FAILED;
    if (ret < maxSize)
        return E_PORT_WRITE_DATA_LESS;
    return E_OK;

}
HErrorType HSerialPort::readData(uchar *data, int maxSize)
{
    Q_D(HSerialPort);

    if (!d->serial->waitForReadyRead(d->timeOut))
        return E_PORT_READ_FAILED;
    auto ret = d->serial->read(reinterpret_cast<char *>(data), maxSize);
    if (ret < maxSize)
        return E_PORT_READ_DATA_LESS;
    return E_OK;
}
