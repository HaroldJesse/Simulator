#include "Logs.hpp"
#include "ui_Logs.h"

Logs::Logs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Logs)
{
    ui->setupUi(this);
}

Logs::~Logs()
{
    delete ui;
}
