#ifndef SCANNERNET_H
#define SCANNERNET_H

#include <QObject>

class ScannerNet : public QObject
{
    Q_OBJECT
public:
    explicit ScannerNet(QObject *parent = nullptr);
    static QVector<bool> doScan(const QString& hostname, const QVector<unsigned short>& ports);

signals:

};

#endif // SCANNERNET_H
