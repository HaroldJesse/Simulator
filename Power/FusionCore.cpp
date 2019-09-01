#include "FusionCore.hpp"
#include "ui_FusionCore.h"


bool FusionCore::BoronInjectionOn = false;
bool FusionCore::AlphaInjectionOn = false;
bool FusionCore::BoronPlasmaFieldOn = false;
bool FusionCore::AlphaPlasmaFieldOn = false;
bool FusionCore::AcceleratorFieldOn = false;
bool FusionCore::CollectorFieldOn = false;
bool FusionCore::Dc2AcConverterOn =false ;

FusionCore::FusionCore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FusionCore)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->Title->setText(Power::TitleName);
    ui->Type->setText(Power::Type);
}


FusionCore::~FusionCore()
{
    delete ui;
}


void FusionCore::BoronInjection (void)
{
    if (BoronInjectionOn == false)
    {        
        BoronInjector Inj;
        Inj.exec();

        ui->BoronInjector->setStyleSheet("background-color: green;"
                              "color: white;"
                              "border-radius: 10px;");
        BoronInjectionOn = true;
    }

    else

    {
        ui->BoronInjector->setStyleSheet("background-color: red;"
                              "color: white;"
                              "border-radius: 10px;");
        BoronInjectionOn = false;
    }
}

void FusionCore::AlphaInjection (void)
{
    if (AlphaInjectionOn == false)
    {
        ui->AlphaInjector->setStyleSheet("background-color: green;"
                              "color: white;"
                              "border-radius: 10px;");
        AlphaInjectionOn = true;
    }

    else

    {
        ui->AlphaInjector->setStyleSheet("background-color: red;"
                              "color: white;"
                              "border-radius: 10px;");
        AlphaInjectionOn = false;
    }
}

void FusionCore::BoronPlasmaField (void)
{
    if (BoronPlasmaFieldOn == false)
    {
        ui->BoronPlasmaField->setStyleSheet("background-color: green;"
                              "color: white;"
                              "border-radius: 10px;");
        BoronPlasmaFieldOn = true;
    }

    else

    {
        ui->BoronPlasmaField->setStyleSheet("background-color: red;"
                              "color: white;"
                              "border-radius: 10px;");
        BoronPlasmaFieldOn = false;
    }
}

void FusionCore::AlphaPlasmaField (void)
{
    if (AlphaPlasmaFieldOn == false)
    {
        ui->AlphaPlasmaField->setStyleSheet("background-color: green;"
                              "color: white;"
                              "border-radius: 10px;");
        AlphaPlasmaFieldOn = true;
    }

    else

    {
        ui->AlphaPlasmaField->setStyleSheet("background-color: red;"
                              "color: white;"
                              "border-radius: 10px;");
        AlphaPlasmaFieldOn = false;
    }
}

void FusionCore::AcceleratorField (void)
{
    if (AcceleratorFieldOn == false)
    {
        ui->AcceleratorField->setStyleSheet("background-color: green;"
                              "color: white;"
                              "border-radius: 10px;");
        AcceleratorFieldOn = true;
    }

    else

    {
        ui->AcceleratorField->setStyleSheet("background-color: red;"
                              "color: white;"
                              "border-radius: 10px;");
        AcceleratorFieldOn = false;
    }
}

void FusionCore::CollectorField (void)
{
    if (CollectorFieldOn == false)
    {
        ui->CollectorField->setStyleSheet("background-color: green;"
                              "color: white;"
                              "border-radius: 10px;");
        CollectorFieldOn = true;
    }

    else

    {
        ui->CollectorField->setStyleSheet("background-color: red;"
                              "color: white;"
                              "border-radius: 10px;");
        CollectorFieldOn = false;
    }
}

void FusionCore::Dc2AcConverter (void)
{
    if (Dc2AcConverterOn == false)
    {
        ui->Dc2AcConverter->setStyleSheet("background-color: green;"
                              "color: white;"
                              "border-radius: 10px;");
        Dc2AcConverterOn = true;
    }

    else

    {
        ui->Dc2AcConverter->setStyleSheet("background-color: red;"
                              "color: white;"
                              "border-radius: 10px;");
        Dc2AcConverterOn = false;
    }
}
