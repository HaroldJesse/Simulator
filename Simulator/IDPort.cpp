
/*!

    Copyright (C) 2020, the Sim Development Team

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

*/

#include "IDPort.hpp"
#include "ui_IDPort.h"

IDPort::IDPort(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IDPort)
{
    ui->setupUi(this);

    Verbalize->say(ui->Message->toPlainText());

    //qDebug() << ui->Message->toPlainText();

    //qDebug() << "IDPort: ";
    QFileInfoList Devices =  QDir::drives();

    for (int i = 0; i < Devices.size(); ++i)
    {
        QString Dev = Devices.at(i).filePath();
        ui->RootDirectory->addItem(Dev);
        //qDebug() << "Dev: " << Dev;
    }
}

IDPort::~IDPort()
{

}


void IDPort::ConnectPort (void)
{
    Verbalize->stop();
    IDCheck::Device = ui->RootDirectory->currentText();
    //qDebug() << "Device: " << IDCheck::Device;
    this->close();
}

