#ifndef HUDPSERVER_P_H
#define HUDPSERVER_P_H

#include "HUdpServer.h"
#include <QtCore/QSet>

class QUdpSocket;

HE_CONTROL_BEGIN_NAMESPACE

class HUdpServerPrivate
{
public:
    bool isRunning = false;
    QString listenIP = "127.0.0.1";
    quint16 listenPort = 6000;
    QSet<QString> clients;
    QUdpSocket *udpSocket;
};

HE_CONTROL_END_NAMESPACE

#endif // HUDPSERVER_P_H
