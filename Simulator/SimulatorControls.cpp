/*!

    Copyright (C) 2020, the Sim Development Team

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

*/

#include "SimulatorControls.hpp"
#include "ui_SimulatorControls.h"

QString SimulatorControls::SimDescription;

bool SimulatorControls::RunUp (false);
bool SimulatorControls::WrittenUp (false);
bool SimulatorControls::VerbalUp (false);

SimulatorControls::SimulatorControls(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimulatorControls)
{
    ui->setupUi(this);
    //ui->ObjectText->setGeometry(5,15,1900,100);


    this->setWindowFlags(Qt::FramelessWindowHint);
    this->adjustSize();
    this->move(Initialize::WindowWidth/2 - this->width()/2,Initialize::WindowHeight - this->height());

    //ui->ObjectText->setReadOnly(true);
    ui->ObjectText->hide();

    QDir directory(Initialize::StartupPath + "/Data-Pak/Description/" + Setup::SimLocation + "/" + Setup::SimObject);
    QStringList NameFilter("*.html");
    QStringList DescriptionFiles = directory.entryList(NameFilter);

    ui->DescriptionSelection->clear();
    ui->DescriptionSelection->addItems(DescriptionFiles);
    ui->DescriptionSelection->show();
    ui->DescriptionSelectionlbl->show();
}

SimulatorControls::~SimulatorControls()
{
    delete ui;
}

void SimulatorControls::Name (void)
{
    SimDescription = (ui->DescriptionSelection->currentText());

}

void SimulatorControls::Run (void)
{
    if (RunUp == false)
    {
        ui->Run->setStyleSheet(GrnRnd15);
        RunUp = true;

        //Load ("Script/Moon.html");
        //GetText();
    }

    else

    if (RunUp == true)
    {
        ui->Run->setStyleSheet(RedSqr5);
        RunUp = false;

        //Load ("Script/Moon.html");
        //GetText();
    }
}

void SimulatorControls::Written (void)
{
    if (WrittenUp == false)
    {
        ui->Written->setStyleSheet(GrnRnd15);

        QFile Name (Initialize::StartupPath + "/Data-Pak/Description/" + Setup::SimLocation + "/" +  Setup::SimObject + "/" + SimDescription);

        //Check for database
        if (Name.exists() == false)
        {
            Verbalize->say("No object text file found");
        }

        else

        Name.open(QIODevice::ReadOnly);

        QByteArray Script = Name.readAll();
        ui->ObjectText->setText(Script);

        ui->ObjectText->show();
        WrittenUp = true;

    }

    else

    if (WrittenUp == true)
    {
        ui->Written->setStyleSheet(RedSqr5);
        ui->ObjectText->hide();
        ui->ObjectText->setText("");
        WrittenUp = false;
    }
}

void SimulatorControls::Verbal (void)
{
    if (VerbalUp == false)
    {
        ui->Verbal->setStyleSheet(GrnRnd15);
        VerbalUp = true;

        //Verbalize->say ("Welcome to the location" + Setup::SimLocation  + IDCheck::Level + "    " + IDCheck::IndividualName + " " + IDCheck::FamilyName);
        Verbalize->say ("Welcome to the location" + Setup::SimLocation + "and the object" + Setup::SimObject + "        " + IDCheck::Level + "    " + IDCheck::IndividualName + " " + IDCheck::FamilyName);
        Verbalize->say (ui->ObjectText->toPlainText());

        //Verbalize->say("Select a description file from the selection list above");

    }

    else

    if (VerbalUp == true)
    {
        ui->Verbal->setStyleSheet(RedSqr5);
        VerbalUp = false;
    }
}

void SimulatorControls::SetText (QString Text)
{
    ui->ObjectText->setText(Text);
}

QString SimulatorControls::GetText (void)
{
    QString Text;
    Text = ui->ObjectText->toPlainText();

    if (VerbalUp == true)
    {
        Verbalize->say(Text);
        return (Text);
    }

    return (Text);
}

void SimulatorControls::BasicDataDisplay (void)
{
    BasicData Display;
    Display.exec();
}

bool SimulatorControls::Load(const QString &Scriptfile)
{
    textEdit = new QTextEdit(this);

    if (!QFile::exists(Scriptfile))
        qDebug() << "Script file: " << Scriptfile;
        return false;

    QFile file(Scriptfile);

    if (!file.open(QFile::ReadOnly))
        return false;

    QByteArray data = file.readAll();
    QTextCodec *codec = Qt::codecForHtml(data);
    QString str = codec->toUnicode(data);

    if (Qt::mightBeRichText(str))
    {
        textEdit->setHtml(str);

        if (WrittenUp == true)
        {
        ui->ObjectText->setText(data);
        }

        else

        return false;
    }

    else
    {
        str = QString::fromLocal8Bit(data);
        textEdit->setPlainText(str);

        if (WrittenUp == true)
        {
            ui->ObjectText->setText(str);
        }

        else

        return false;

    }

    return true;
}

void SimulatorControls::Exit (void)
{
    this->close();
}





