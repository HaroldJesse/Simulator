#include "Clock.hpp"
#include "ui_Clock.h"

QString Clock::ShipTime = "00:00:00:00";

Clock::Clock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Clock)
{
    ui->setupUi(this);
    ui->DateTime->setReadOnly(true);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->move(0,0);


    //Set up master .1 second timer
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(ClockUpdate()));
    Timer->start(1000);

}

Clock::~Clock()
{
    delete ui;
}

/*void Clock::SetDateTime (qint64 DateTime)
{
    QString DT;
    DT = DT.setNum(DateTime);
    ui->DateTime->setText(DT);
}
*/

void Clock::ClockUpdate (void)
{
    QDateTime DT;
    qint64 Time = DT.currentMSecsSinceEpoch();

    qint64 Sec;
    qint64 Min;
    qint64 Hour;
    qint64 Day;
    qint64 Temp;

    Day = Time / 1000000000;
    Temp = Time - (Day * 1000000000);
    Hour = Temp / 10000000;
    Temp = Temp - (Hour * 10000000);
    Min = Temp / 100000;
    Temp = Temp - (Min * 100000);
    Sec = Temp / 1000;
    Temp = Temp - (Sec * 1000);

    QString Days;
    Days.setNum(Day);
    QString Hours;
    Hours.setNum(Hour);
    QString Minutes;
    Minutes.setNum(Min);
    QString Seconds;
    Seconds.setNum(Sec);

    QChar Sep = ':';
    QString Shiptime = Days + QString(Sep) + Hours + QString(Sep) + Minutes + QString(Sep) + Seconds;
    //ui->DateTime->setText(ShipTime);

    ShipTime = Shiptime;
    qDebug() << "Tick:" << ShipTime;
}

QString Clock::GetClock (void)
{
    qDebug() << "Shiptime: " << Clock::ShipTime;
    return ShipTime;

}
