#include "TrainingControl.hpp"
#include "ui_TrainingControl.h"

TrainingControl::TrainingControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrainingControl)
{
    ui->setupUi(this);
}

TrainingControl::~TrainingControl()
{
    delete ui;
}
