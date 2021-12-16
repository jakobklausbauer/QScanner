#include "scannernet.h"
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QVector>

ScannerNet::ScannerNet(QObject *parent) : QObject(parent)
{

}

QVector<bool> ScannerNet::doScan(const QString& hostname, const QVector<short>& ports)
{
    QVector<bool> res;
    QTcpSocket* socket = new QTcpSocket();

    for(short port : ports)
    {
        socket->connectToHost(hostname, port);

        if (!socket->waitForConnected(1000)) res.push_back(false);
        else
        {
            socket->disconnectFromHost();
            res.push_back(true);
        }
    }

    return res;
}
