#include "OThruster.hpp"
#include "ui_OThruster.h"

double OThruster::PitchThrust (0);
double OThruster::YawThrust (0);
double OThruster::RollThrust (0);

double OThruster::PitchThrottle (0);
double OThruster::YawThrottle (0);
double OThruster::RollThrottle (0);

QSize OThruster::Size (0,0);

OThruster::OThruster(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::OThruster)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setModal(true);

    Size = this->size();

    int Width = this->width();
    int Height = this->height();
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->move(Initialize::WindowWidth/2 - Width/2,Initialize::WindowHeight - Height);
    this->move(0,Initialize::WindowHeight/2 - Height/2);
    QString Value;
    double Multiplier (0.01);
    ui->PTenth->setChecked(true);
    ui->YTenth->setChecked(true);
    ui->RTenth->setChecked(true);

    PitchThrottle = ui->PitchThrust->value() * Multiplier;
    ui->PitchT ->setText("Pitch Throttle: " + Value.setNum(PitchThrottle));

    YawThrottle = ui->YawThrust->value() * Multiplier;
    ui->YawT ->setText("Yaw Throttle: " + Value.setNum(YawThrottle));

    RollThrottle = ui->RollThrust->value() * Multiplier;
    ui->RollT ->setText("Roll Throttle: " + Value.setNum(RollThrottle));

}

OThruster::~OThruster()
{
    delete ui;
}

void OThruster::PitchRange(void)
{
    QString Value;
    double Multiplier;
    if (ui->PTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->POne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->PTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    Multiplier = .01;

    PitchThrottle = ui->PitchThrust->value() * Multiplier;
    ui->PitchT ->setText("Pitch Throttle: " + Value.setNum(PitchThrottle));
}

void OThruster::SetPitchValue(void)
{
    QString Value;
    double Multiplier;
    if (ui->PTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->POne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->PTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    Multiplier = .01;

    PitchThrottle = ui->PitchThrust->value() * Multiplier;
    ui->PitchT ->setText("Pitch Throttle: " + Value.setNum(PitchThrottle));
}

void OThruster::YawRange(void)
{
    QString Value;
    double Multiplier;
    if (ui->YTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->YOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->YTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    Multiplier = .01;

    YawThrottle = ui->YawThrust->value() * Multiplier;
    ui->YawT->setText("Yaw Throttle: " + Value.setNum(YawThrottle));
}

void OThruster::SetYawValue(void)
{
    QString Value;
    double Multiplier;
    if (ui->YTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->YOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->YTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    Multiplier = .01;

    YawThrottle = ui->YawThrust->value() * Multiplier;
    ui->YawT->setText("Yaw Throttle: " + Value.setNum(YawThrottle));
}

void OThruster::RollRange(void)
{
    QString Value;
    double Multiplier;
    if (ui->RTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->ROne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->RTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    Multiplier = .01;

    RollThrottle = ui->RollThrust->value() * Multiplier;
    ui->RollT ->setText("Roll Throttle: " + Value.setNum(RollThrottle));
}

void OThruster::SetRollValue(void)
{
    QString Value;
    double Multiplier;
    if (ui->RTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->ROne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->RTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    Multiplier = .01;

    RollThrottle = ui->RollThrust->value() * Multiplier;
    ui->RollT ->setText("Roll Throttle: " + Value.setNum(RollThrottle));
}

void OThruster::Exit (void)
{
    //qDebug() << "OTExit";
    this->close();
}

