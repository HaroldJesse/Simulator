#include "SimLog.hpp"
#include "ui_SimLog.h"

SimLog::SimLog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimLog)
{
    ui->setupUi(this);
}

SimLog::~SimLog()
{
    delete ui;
}
