#ifndef SCANNER_H
#define SCANNER_H

#include <QWidget>
#include "scannernet.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Scanner; }
QT_END_NAMESPACE

class Scanner : public QWidget
{
    Q_OBJECT

public:
    Scanner(QWidget *parent = nullptr);
    ~Scanner();
    void displayRes(QVector<unsigned short>& ports, QVector<bool>& results);

private slots:
    void on_startButton_clicked();

private:
    Ui::Scanner *ui;
    ScannerNet* m_scan;
};
#endif // SCANNER_H
