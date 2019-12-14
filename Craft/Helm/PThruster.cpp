#include "PThruster.hpp"
#include "ui_PThruster.h"

double PThruster::FwdRevThrust (0);
double PThruster::HeadingThrust (0);
double PThruster::MarkThrust (0);

double PThruster::FwdRevThrottle (0);
double PThruster::HeadingThrottle (0);
double PThruster::MarkThrottle (0);

QSize PThruster::Size (0,0);

PThruster::PThruster(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::PThruster)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setModal(true);

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

    MarkThrottle = ui->MarkTSlider->value() * Multiplier;
    ui->UpDwnT->setText("UpDwn: " + Value.setNum(MarkThrottle));

    HeadingThrottle = ui->HeadingTSlider->value() * Multiplier;
    ui->PrtSrbT->setText("PrtSrb: " + Value.setNum(HeadingThrottle));

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

    MarkThrottle = ui->MarkTSlider->value() * Multiplier;
    ui->UpDwnT->setText("UpDwn: " + Value.setNum(MarkThrottle));
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

    MarkThrottle = ui->MarkTSlider->value() * Multiplier;
    ui->UpDwnT->setText("UpDwn: " + Value.setNum(MarkThrottle));
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

    HeadingThrottle = ui->HeadingTSlider->value() * Multiplier;
    ui->PrtSrbT->setText("PrtSrb: " + Value.setNum(HeadingThrottle));
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

    HeadingThrottle = ui->HeadingTSlider->value() * Multiplier;
    ui->PrtSrbT->setText("PrtSrb: " + Value.setNum(HeadingThrottle));
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
