#include "HUdpClient_p.h"
#include <QtNetwork/QNetworkDatagram>

HE_CONTROL_BEGIN_NAMESPACE

HUdpClient::HUdpClient(QObject *parent) :
    QUdpSocket(parent),
    d_ptr(new HUdpClientPrivate)
{
    init();
}

HUdpClient::HUdpClient(HUdpClientPrivate &p, QObject *parent) :
    QUdpSocket(parent),
    d_ptr(&p)
{
    init();
}

HUdpClient::~HUdpClient()
{
}

void HUdpClient::sendData(const QString &ip, quint16 port, const QByteArray &value)
{
    if (writeDatagram(value, QHostAddress(ip), port) != -1)
        emit sentData(ip, port, value);
}

void HUdpClient::handleReadyRead()
{
    while (hasPendingDatagrams())
    {
        auto datagram = receiveDatagram();
        auto ip = datagram.senderAddress().toString().replace("::ffff:", "");
        auto port = static_cast<quint16>(datagram.senderPort());
        auto data = datagram.data();
        if (ip.isEmpty() || data.isEmpty())
            continue;
        emit receiveData(ip, port, data);
    }
}

void HUdpClient::init()
{
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(deleteLater()));
    connect(this, &HUdpClient::disconnected, this, &HUdpClient::deleteLater);
    connect(this, &HUdpClient::readyRead, this, &HUdpClient::handleReadyRead);
}

HE_CONTROL_END_NAMESPACE