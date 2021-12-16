#include "scanner.h"
#include "ui_scanner.h"
#include "scannernet.h"
#include <QDebug>

Scanner::Scanner(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Scanner)
{
    m_scan = new ScannerNet();
    ui->setupUi(this);
}

Scanner::~Scanner()
{
    delete ui;
}


void Scanner::on_startButton_clicked()
{
    QVector<unsigned short> ports;
    QVector<bool> results;

    QString hostName = ui->hostnameEntry->text();

    QStringList portStrings = ui->portEntry->text().split(',');
    for(QString p : portStrings)
        ports.push_back(p.toInt());

    results = ScannerNet::doScan(hostName, ports);

    displayRes(ports, results);
}

void Scanner::displayRes(QVector<unsigned short>& ports, QVector<bool>& results)
{
    ui->resultWindow->clear();
    for(int pIdx = 0; pIdx < ports.size(); pIdx++)
    {
        QString con = QString("Port: ") + QString::number(ports[pIdx]) + ": ";
        if(results[pIdx])
        {
            ui->resultWindow->setTextColor(QColor::fromRgb(0, 255, 0));
            con += "connection successful!";
        }
        else
        {
            ui->resultWindow->setTextColor(QColor::fromRgb(255, 0, 0));
            con += "connection failed!";
        }

        ui->resultWindow->append(con);
    }
}
