#include "ComputerControls.hpp"
#include "ui_ComputerControls.h"

QSize ComputerControls::Size  (0,0);
int ComputerControls::Width = 0;
int ComputerControls::Height = 0;

ComputerControls::ComputerControls(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputerControls)

{
        ui->setupUi(this);

    //this->setWindowFlags(Qt::FramelessWindowHint);
    //this->move(Initialize::WindowWidth/2 - Width/2,Initialize::WindowHeight - Height);
    this->move(200,990);
    //this->showFullScreen();




    ComputerControls::Size = this->size();
    ComputerControls::Width = this->width();
    ComputerControls::Height = this->height();

    qDebug() << "ComputerControls: " << this->width() << this->height() << this->pos();
}

ComputerControls::~ComputerControls()
{
    delete ui;
}


void ComputerControls::Exit (void)
{
    qDebug() << "Computer Control Exit" ;
    this->close();
}
