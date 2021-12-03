#include "scanner.h"
#include "ui_scanner.h"

Scanner::Scanner(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Scanner)
{
    ui->setupUi(this);
}

Scanner::~Scanner()
{
    delete ui;
}


void Scanner::on_startButton_clicked()
{

}
