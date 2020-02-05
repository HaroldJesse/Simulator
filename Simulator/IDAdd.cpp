/*!

    Copyright (C) 2020, the Sim Development Team

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

*/

#include "IDAdd.hpp"
#include "ui_IDAdd.h"



IDAdd::IDAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IDAdd)
{
    ui->setupUi(this);

    // here ui->RecordNumber->setText(CraftControls::ShipTime);
    ui->Department->setText("Basic Training");
    ui->Level->setText("Trainee");
    ui->ActivationDate->setText(QDateTime::currentDateTime().toString());

    Verbalize->say(ui->Instructions->text());
}

IDAdd::~IDAdd()
{
    delete ui;
}


void IDAdd::Accept (void)
{
    Verbalize->stop();

    IDCheck::IndividualName = ui->IndividualName->text();
    IDCheck::FamilyName = ui->FamilyName->text();

    CreateID ();
    CreateCertificates();
}


void IDAdd::CreateID (void)
{
    IDCheck::RecordNumber = QDateTime::currentSecsSinceEpoch();

    IDCheck::Department = "Academy";
    IDCheck::Level = "Trainee";
    IDCheck::ActivationDate = QDateTime(QDateTime::currentDateTime());

    //set up database
    QString DataBase = IDCheck::Device + "/" + IDCheck::DeviceFolder + "/" + "ID.sim";

    QSqlDatabase IDdb = QSqlDatabase::database("ID");
    IDdb.setDatabaseName(DataBase);
    //qDebug() << "Database: " << DataBase;

    if (IDdb.open() == false) //try to connect to the database
    {
        QMessageBox msgBox;
        msgBox.setText("Sorry! could not open ID device");
        msgBox.setStandardButtons(QMessageBox::Ok);
        Verbalize->say(msgBox.text());
        msgBox.show();
        //qDebug() << "Can't open database";
    }


    /* set up table ID for the database */
    Edit = new QSqlTableModel(this,IDdb);

    Edit->setTable("ID");
    Edit->select();

    //Utility util;

    QSqlRecord Crecord;

    //QSqlField F0 ("ID", QVariant::Int);
    QSqlField F1 ("RecordNumber", QVariant::Int);
    QSqlField F2 ("IndividualName", QVariant::String);
    QSqlField F3 ("FamilyName", QVariant::String);
    QSqlField F4 ("Department", QVariant::String);
    QSqlField F5 ("Level", QVariant::String);
    QSqlField F6 ("ActivationDate", QVariant::DateTime);


    //F0.setValue(QVariant(NULL));
    F1.setValue(QVariant(IDCheck::RecordNumber));
    F2.setValue(QVariant(IDCheck::IndividualName));
    F3.setValue(QVariant(IDCheck::FamilyName));
    F4.setValue(QVariant(IDCheck::Department));
    F5.setValue(QVariant(IDCheck::Level));
    F6.setValue(QVariant(IDCheck::ActivationDate));


    //Crecord.append(F0);
    Crecord.append(F1);
    Crecord.append(F2);
    Crecord.append(F3);
    Crecord.append(F4);
    Crecord.append(F5);
    Crecord.append(F6);


    if (Edit->insertRecord(-1, Crecord) == false)
    {
        qDebug() << "Failed to update ID";
        //qDebug() << Crecord;
    }

    IDdb.close();
}

void IDAdd::CreateCertificates (void)
{

    IDCheck::CertNumber = QDateTime::currentSecsSinceEpoch();
    IDCheck::Type = "Academy";
    IDCheck::SimCertificate = "Acceptance";
    IDCheck::IssueDate = QDateTime::currentDateTime();
    IDCheck::IssuedBy = "Accademy Commander Jesse";

    //IDCheck::IndividualName = ui->IndividualName->text();
    //IDCheck::FamilyName = ui->FamilyName->text();
    //qDebug() << "Name: " << IDCheck::IndividualName << IDCheck::FamilyName;


    //set up database
    QString DataBase = IDCheck::Device + "/" + IDCheck::DeviceFolder + "/" + "ID.sim";

    QSqlDatabase IDdb = QSqlDatabase::database("ID");
    IDdb.setDatabaseName(DataBase);

    if (IDdb.open() == false) //try to connect to the database
    {
        QMessageBox msgBox;
        msgBox.setText("Sorry! could not open ID device");
        msgBox.setStandardButtons(QMessageBox::Ok);
        Verbalize->say(msgBox.text());
        msgBox.show();
        //qDebug() << "Can't open database";
    }

    /* set up table Certificates for the database */
    Edit = new QSqlTableModel(this,IDdb);

    Edit->setTable("Certificates");
    Edit->select();

    QSqlRecord Crecord;

    //QSqlField F10 ("Certificates", QVariant::Int);
    QSqlField F1 ("CertNumber", QVariant::Int);
    QSqlField F2 ("Type", QVariant::String);
    QSqlField F3 ("SimCertificate", QVariant::String);
    QSqlField F4 ("IssueDate", QVariant::DateTime);
    QSqlField F5 ("IssuedBy", QVariant::String);


    //F10.setValue(QVariant(NULL));
    F1.setValue(QVariant(IDCheck::CertNumber));
    F2.setValue(QVariant(IDCheck::Type));
    F3.setValue(QVariant(IDCheck::SimCertificate));
    F4.setValue(QVariant(IDCheck::IssueDate));
    F5.setValue(QVariant(IDCheck::IssuedBy));


    //Crecord.append(F10);
    Crecord.append(F1);
    Crecord.append(F2);
    Crecord.append(F3);
    Crecord.append(F4);
    Crecord.append(F5);



//  qDebug() << "Add Certificate has run";
    //qDebug() << Crecord;

    if (Edit->insertRecord(-1, Crecord) == false)
    {
        qDebug() << "Failed to update Certificates";
        //qDebug() << Edit->lastError();
    }

    this->close();
}



void IDAdd::Cancel (void)
{
    this->close();
}


void IDAdd::CertificateAdd (void)
{

}
