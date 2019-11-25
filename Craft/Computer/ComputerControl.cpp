#include "ComputerControl.hpp"
#include "ui_ComputerControl.h"

ComputerControl::ComputerControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputerControl)
{
    ui->setupUi(this);

}

ComputerControl::~ComputerControl()
{
    delete ui;
}

//void ComputerControl::Computer (void)
//{
    //Computer Comp;

//}
