#include "Objects.hpp"
#include "ui_Objects.h"

Objects::Objects(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Objects)
{
    ui->setupUi(this);
}

Objects::~Objects()
{
    delete ui;
}
