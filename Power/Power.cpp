#include "Power.hpp"
#include "ui_Power.h"

bool Power::Seg1 = true;
bool Power::Seg2 = false;
bool Power::Seg3 = false;
bool Power::Seg4 = false;
bool Power::Seg5 = false;
bool Power::Seg6 = false;
bool Power::Seg7 = false;
bool Power::Seg8 = false;
bool Power::Seg9 = false;
bool Power::Seg10 = false;

bool Power::AutoFusion1On = false;
bool Power::ManualFusion1On = false;
bool Power::AutoFusion2On = false;
bool Power::ManualFusion2On = false;
bool Power::AutoFusion3On = false;
bool Power::ManualFusion3On = false;

QString Power::TitleName = "Power Core";
QString Power::Type = "Manual Start";

Power::Power(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Power)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    //Set up master .5 second timer
    connect(Timer, SIGNAL(timeout()), this, SLOT(MasterUpdate()));
    Timer->start(200);
}

Power::~Power()
{
    delete ui;
}

void Power::AutoStart (void)
{

}

void Power::MasterUpdate (void)
{
    //Set push button icons this way QtDesigner does not do relative file names
    /*
    if (Fusion1On == true)
    {
        if (Seg1 == true)
        {
            ui->Seg1->setIcon(QIcon("Icons/Down.png"));
            ui->Seg2->setIcon(QIcon(""));
            ui->Seg3->setIcon(QIcon(""));
            ui->Seg4->setIcon(QIcon("Icons/Down.png"));
            ui->Seg5->setIcon(QIcon(""));
            ui->Seg6->setIcon(QIcon(""));
            ui->Seg7->setIcon(QIcon("Icons/Down.png"));
            ui->Seg8->setIcon(QIcon(""));
            ui->Seg9->setIcon(QIcon(""));
            ui->Seg10->setIcon(QIcon("Icons/Right.png"));
            ui->Seg11->setIcon(QIcon(""));
            ui->Seg12->setIcon(QIcon(""));
            ui->Seg13->setIcon(QIcon("Icons/Right.png"));
            ui->Seg14->setIcon(QIcon(""));
            ui->Seg15->setIcon(QIcon(""));
            ui->Seg16->setIcon(QIcon("Icons/Right.png"));
            ui->Seg17->setIcon(QIcon(""));
            ui->Seg18->setIcon(QIcon(""));
            Seg1 = false;
            Seg2 = true;
        }

        else if (Seg2 == true)

        {
            ui->Seg1->setIcon(QIcon(""));
            ui->Seg2->setIcon(QIcon("Icons/Down.png"));
            ui->Seg3->setIcon(QIcon(""));
            ui->Seg4->setIcon(QIcon(""));
            ui->Seg5->setIcon(QIcon("Icons/Down.png"));
            ui->Seg6->setIcon(QIcon(""));
            ui->Seg7->setIcon(QIcon(""));
            ui->Seg8->setIcon(QIcon("Icons/Down.png"));
            ui->Seg9->setIcon(QIcon(""));
            ui->Seg10->setIcon(QIcon(""));
            ui->Seg11->setIcon(QIcon("Icons/Right.png"));
            ui->Seg12->setIcon(QIcon(""));
            ui->Seg13->setIcon(QIcon(""));
            ui->Seg14->setIcon(QIcon("Icons/Right.png"));
            ui->Seg15->setIcon(QIcon(""));
            ui->Seg16->setIcon(QIcon(""));
            ui->Seg17->setIcon(QIcon("Icons/Right.png"));
            ui->Seg18->setIcon(QIcon(""));
            Seg2 = false;
            Seg3 = true;
        }

        else

        {
            ui->Seg1->setIcon(QIcon(""));
            ui->Seg2->setIcon(QIcon(""));
            ui->Seg3->setIcon(QIcon("Icons/Down.png"));
            ui->Seg4->setIcon(QIcon(""));
            ui->Seg5->setIcon(QIcon(""));
            ui->Seg6->setIcon(QIcon("Icons/Down.png"));
            ui->Seg7->setIcon(QIcon(""));
            ui->Seg8->setIcon(QIcon(""));
            ui->Seg9->setIcon(QIcon("Icons/Down.png"));
            ui->Seg10->setIcon(QIcon(""));
            ui->Seg11->setIcon(QIcon(""));
            ui->Seg12->setIcon(QIcon("Icons/Right.png"));
            ui->Seg13->setIcon(QIcon(""));
            ui->Seg14->setIcon(QIcon(""));
            ui->Seg15->setIcon(QIcon("Icons/Right.png"));
            ui->Seg16->setIcon(QIcon(""));
            ui->Seg17->setIcon(QIcon(""));
            ui->Seg18->setIcon(QIcon("Icons/Right.png"));
            Seg3 = false;
            Seg1 = true;
        }

    }
    */
}

void Power::AutoStartup1 ()
{
    if (AutoFusion1On == false)
    {
        ui->Auto1->setStyleSheet("background-color: green;"
                              "color: white;"
                              "border-radius: 20px;");
        AutoFusion1On = true;
    }

    else

    if (AutoFusion1On == true)
    {
        ui->Auto1->setStyleSheet("background-color: red;"
                                  "color: white;");
        AutoFusion1On = false;
    }
}

void Power::ManualStartup1 ()
{
    if (ManualFusion1On == false)
    {
        ui->Manual1->setStyleSheet("background-color: green;"
                              "color: white;"
                              "border-radius: 20px;");
        ManualFusion1On = true;

        TitleName = "Fusion Core #1";
        Type = "Manual";
        FusionCore Core;
        //Core.setAttribute(Qt::WA_AlwaysStackOnTop);
        Core.exec();

    }

    else

    if (ManualFusion1On == true)
    {
        ui->Manual1->setStyleSheet("background-color: red;"
                                  "color: white;");
        ManualFusion1On = false;
    }
}

void Power::AutoStartup2 ()
{
    if (AutoFusion2On == false)
    {
        ui->Auto2->setStyleSheet("background-color: green;"
                              "color: white;"
                              "border-radius: 20px;");
        AutoFusion2On = true;
    }

    else

    if (AutoFusion2On == true)
    {
        ui->Auto2->setStyleSheet("background-color: red;"
                                  "color: white;");
        AutoFusion2On = false;
    }
}

void Power::ManualStartup2 ()
{
    if (ManualFusion2On == false)
    {
        ui->Manual2->setStyleSheet("background-color: green;"
                              "color: white;"
                              "border-radius: 20px;");
        ManualFusion2On = true;

        TitleName = "Fusion Core #2";

        FusionCore Core;
        //Core.setAttribute(Qt::WA_AlwaysStackOnTop);
        Core.setWindowTitle("Core 2 Startup");
        Core.exec();
    }

    else

    if (ManualFusion2On == true)
    {
        ui->Manual2->setStyleSheet("background-color: red;"
                                  "color: white;");
        ManualFusion2On = false;
    }
}

void Power::AutoStartup3 ()
{
    if (AutoFusion3On == false)
    {
        ui->Auto3->setStyleSheet("background-color: green;"
                              "color: white;"
                              "border-radius: 20px;");
        AutoFusion3On = true;
    }

    else

    if (AutoFusion3On == true)
    {
        ui->Auto3->setStyleSheet("background-color: red;"
                                  "color: white;");
        AutoFusion3On = false;
    }
}

void Power::ManualStartup3 ()
{
    if (ManualFusion3On == false)
    {
        ui->Manual3->setStyleSheet("background-color: green;"
                              "color: white;"
                              "border-radius: 20px;");
        ManualFusion3On = true;

        TitleName = "Fusion Core #3";

        FusionCore Core;
        //Core.setAttribute(Qt::WA_AlwaysStackOnTop);
        Core.setWindowTitle("Core 3 Startup");
        Core.exec();
    }

    else

    if (ManualFusion3On == true)
    {
        ui->Manual3->setStyleSheet("background-color: red;"
                                  "color: white;");
        ManualFusion3On = false;
    }
}


void Power::Done (void)
{
    Timer->stop();
    this->close();
}
