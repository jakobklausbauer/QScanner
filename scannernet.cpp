#include "scannernet.h"
#include <QVector>

ScannerNet::ScannerNet(QObject *parent) : QObject(parent)
{

}

QVector<bool> ScannerNet::doScan(const QString& hostname, const QVector<short>& ports)
{
    //
}
