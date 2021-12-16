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
    QVector<short> ports;

    QStringList portStrings = ui->portEntry->text().split(',');

    for(QString p : portStrings)
        ports.push_back(p.toInt());

    qDebug() << "Ports: " << ports;
    qDebug() << "Hostname: " << ui->hostnameEntry->text();
}
