#include "PThruster.hpp"
#include "ui_PThruster.h"

double PThruster::FwdRevThrust (0);
double PThruster::PrtSrbThrust (0);
double PThruster::UpDwnThrust (0);

double PThruster::FwdRevThrottle (0);
double PThruster::PrtSrbThrottle (0);
double PThruster::UpDwnThrottle (0);

QSize PThruster::Size (0,0);

PThruster::PThruster(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::PThruster)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    int Width = this->width();
    int Height = this->height();
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->move(Initialize::WindowWidth/2 - Width/2,Initialize::WindowHeight - Height);
    this->move(Initialize::WindowWidth - Width,Initialize::WindowHeight/2 - Height/2);


    QString Value;

    double Multiplier (0.01);
    ui->UDTenth->setChecked(true);
    ui->PSTenth->setChecked(true);
    ui->FRTenth->setChecked(true);

    UpDwnThrottle = ui->UpDwnTSlider->value() * Multiplier;
    ui->UpDwnT->setText("UpDwn: " + Value.setNum(UpDwnThrottle));

    PrtSrbThrottle = ui->PrtSrbTSlider->value() * Multiplier;
    ui->PrtSrbT->setText("PrtSrb: " + Value.setNum(PrtSrbThrottle));

    FwdRevThrottle = ui->FwdRevTSlider->value() * Multiplier;
    ui->FwdRevT->setText("FwdRev: " + Value.setNum(FwdRevThrottle));

}

PThruster::~PThruster()
{
    delete ui;
}

void PThruster::SetUpDwnValue(void)
{
    QString Value;
    double Multiplier;
    if (ui->UDTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->UDOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->UDTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    Multiplier = .01;

    UpDwnThrottle = ui->UpDwnTSlider->value() * Multiplier;
    ui->UpDwnT->setText("UpDwn: " + Value.setNum(UpDwnThrottle));
}

void PThruster::UpDwnRange (void)
{
    QString Value;
    double Multiplier;
    if (ui->UDTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->UDOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->UDTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    Multiplier = .01;

    UpDwnThrottle = ui->UpDwnTSlider->value() * Multiplier;
    ui->UpDwnT->setText("UpDwn: " + Value.setNum(UpDwnThrottle));
}

void PThruster::SetPrtSrbValue(void)
{
    QString Value;
    double Multiplier;
    if (ui->PSTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->PSOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->PSTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    Multiplier = .01;

    PrtSrbThrottle = ui->PrtSrbTSlider->value() * Multiplier;
    ui->PrtSrbT->setText("PrtSrb: " + Value.setNum(PrtSrbThrottle));
}

void PThruster::PrtSrbRange (void)
{
    QString Value;
    double Multiplier;
    if (ui->PSTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->PSOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->PSTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    Multiplier = .01;

    PrtSrbThrottle = ui->PrtSrbTSlider->value() * Multiplier;
    ui->PrtSrbT->setText("PrtSrb: " + Value.setNum(PrtSrbThrottle));
}

void PThruster::SetFwdRevValue(void)
{
    QString Value;
    double Multiplier;
    if (ui->FRTenth->isChecked())
    {
        Multiplier = .1;

        FwdRevThrottle = ui->FwdRevTSlider->value() * Multiplier;
        qDebug() << "FwdRevThrottle .1: " << FwdRevThrottle;
    }

    else if (ui->FROne->isChecked())
    {
        Multiplier = 1;

        FwdRevThrottle = ui->FwdRevTSlider->value() * Multiplier;
        qDebug() << "FwdRevThrottle 1: " << FwdRevThrottle;
    }

    else if (ui->FRTen->isChecked())
    {
        Multiplier = 10;

        FwdRevThrottle = ui->FwdRevTSlider->value() * Multiplier;
        qDebug() << "FwdRevThrottle 10: " << FwdRevThrottle;
    }

    else

    Multiplier = .01;

    FwdRevThrottle = ui->FwdRevTSlider->value() * Multiplier;
    qDebug() << "FwdRevThrottle: " << FwdRevThrottle;

    ui->FwdRevT->setText("FwdRev: " + Value.setNum(FwdRevThrottle));
}

void PThruster::FwdRevRange(void)
{
    QString Value;
    double Multiplier;
    if (ui->FRTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->FROne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->FRTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    Multiplier = .01;

    FwdRevThrottle = ui->FwdRevTSlider->value() * Multiplier;
    ui->FwdRevT->setText("FwdRev: " + Value.setNum(FwdRevThrottle));
}

void PThruster::Exit (void)
{
    //qDebug() << "PExit";
    this->close();
}
