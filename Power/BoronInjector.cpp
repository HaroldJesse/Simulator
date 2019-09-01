#include "BoronInjector.hpp"
#include "ui_BoronInjector.h"

bool BoronInjector::BoronHeaterOn = false;
bool BoronInjector::HeaterTempReached = false;
bool BoronInjector::AlphaHeaterOn = false;
bool BoronInjector::AlphaFieldOn = false;
bool BoronInjector::PinchFieldOn = false;


int  BoronInjector::BoronTempSetpoint (0);
int  BoronInjector::BoronTempValue (0);
int  BoronInjector::BoronChargeSetpoint (0);
int  BoronInjector::BoronChargeValue (0);


int  BoronInjector::AlphaInjectionSetPoint (0);
int  BoronInjector::AlphaInjectionValue (0);


int  BoronInjector::BoronPlasmaFieldSetpoint (0);
int  BoronInjector::BoronPlasmaFieldValue (0);


int  BoronInjector::AlphaPlasmaFieldSetpoint (0);
int  BoronInjector::AlphaPlasmaFieldValue (0);


int  BoronInjector::AcceleratorFieldSetpoint (0);
int  BoronInjector::AcceleratorFieldValue (0);


int  BoronInjector::CollectorFieldSetpoint (0);
int  BoronInjector::CollectorFieldValue (0);


int  BoronInjector::Dc2AcConverterSetpoint (0);
int  BoronInjector::Dc2AcConverterValue (0);

QString RedSqr = "background-color: red;"
                 " color: white;"
                 "border-radius: 5px;";

QString GrnRnd = "background-color: green;"
                      " color: white;"
                      "border-radius: 20px;";


BoronInjector::BoronInjector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoronInjector)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->move(600,250);

    ui->HeaterTemp->hide();
    ui->HeaterCharge->hide();

    //Set up master 1 second timer
    QTimer *Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(MasterUpdate()));
    Timer->start(1000);
}

BoronInjector::~BoronInjector()
{
    delete ui;
}

void BoronInjector::SetBoronHeaterOn (void)
{
    if (BoronHeaterOn == false)
    {
        ui->On->setStyleSheet(GrnRnd);
        ui->On->setText("OFF");
        BoronHeaterOn = true;
        ui->HeaterTemp->show();

    }

    else

    if (BoronHeaterOn == true)
    {
        if (BoronTempValue != 0)
        {
            qApp->beep();
            QMessageBox msgBox;
            msgBox.setText("Boron Injector temperature must be 0 before turning the heater off");
            Verbalize->say(msgBox.text());
            msgBox.show();
        }

        if (BoronChargeValue != 0)
        {
            qApp->beep();
            QMessageBox msgBox;
            msgBox.setText("Boron Injector charge must be 0 before turning the heater off");
            Verbalize->say(msgBox.text());
            msgBox.show();
        }

        if (BoronHeaterOn == true && BoronTempValue == 0  && BoronChargeValue == 0)
        {
            ui->HeaterTemp->hide();
            ui->HeaterCharge->hide();

            ui->On->setStyleSheet(RedSqr);
            ui->On->setText("ON");
            BoronHeaterOn = false;
        }
    }
}

void BoronInjector::SetBoronHeaterSetPoint (void)
{
    if (BoronHeaterOn == false)
    {
        qApp->beep();
        QMessageBox msgBox;
        msgBox.setText("You must turn on the heater before setting the temperature");
        Verbalize->say(msgBox.text());
        msgBox.show();
    }

    BoronTempSetpoint = ui->BoronTempSetPoint->value();
}

void BoronInjector::SetBoronChargeSetPoint (void)
{
    if (BoronHeaterOn == false)
    {
        qApp->beep();
        QMessageBox msgBox;
        msgBox.setText("You must turn on the heater before setting the temperature");
        Verbalize->say(msgBox.text());
        msgBox.show();
    }

    BoronTempSetpoint = ui->BoronTempSetPoint->value();
}

/*
void BoronInjector::SetAlphaHeaterSetPoint (void)
{
    AlphaHeaterSetpoint = ui->HeaterSetPoint->value();
}

void BoronInjector::SetBoronFieldSetPoint (void)
{
    BoronFieldSetPoint = ui->HeaterSetPoint->value();
}

void BoronInjector::SetAlphaFieldSetPoint (void)
{
    BoronInjectionSetpoint = ui->HeaterSetPoint->value();
}

void BoronInjector::SetPinchFieldSetPoint (void)
{
    BoronInjectionSetpoint = ui->HeaterSetPoint->value();
}

void BoronInjector::SetAcceleratorSetPoint (void)
{
    BoronInjectionSetpoint = ui->HeaterSetPoint->value();
}

void BoronInjector::SetDc2AcConverterOn (void)
{
    BoronInjectionSetpoint = ui->HeaterSetPoint->value();
}

*/
void BoronInjector::Ramp (int &Setpoint,int &Variable, int Increment)
{
    int *Set = &Setpoint;
    int *Var = &Variable;

    if (*Set == *Var)
    {
        return;
    }

    *Var += Increment;
    //qDebug() << "Var: " << *Var;
    return;
}

void BoronInjector::MasterUpdate (void)
{
    QString Temp;
    QChar Degree(0xB0); //degree symbol in hex

    if (BoronTempSetpoint < BoronTempValue)
    {
        Ramp(BoronTempSetpoint,BoronTempValue, -1);
    }

    if (BoronTempSetpoint > BoronTempValue)
    {
        Ramp(BoronTempSetpoint,BoronTempValue, 1);
    }

    if (BoronTempSetpoint == BoronTempValue)
    {
        HeaterTempReached = true;
        ui->HeaterCharge->show();
    }

    Temp = Temp.setNum(BoronTempValue);
    ui->BoronTemp ->setAlignment(Qt::AlignHCenter);
    ui->BoronTemp->setText(Temp + Degree + " K");

    ui->BoronHeaterBar->setValue(BoronTempValue);
}

void BoronInjector:: Done (void)
{
    this->close();
}
