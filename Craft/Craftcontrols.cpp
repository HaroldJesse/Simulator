#include "CraftControls.hpp"
#include "ui_CraftControls.h"

QString CraftControls::ShipTime = "00:00:00:00";

bool CraftControls::PwrUp (false);
bool CraftControls::EnvUp = false;
bool CraftControls::HelmUp = false;
bool CraftControls::NavUp = false;
bool CraftControls::ComUp = false;
bool CraftControls::CompUp = false;
bool CraftControls::SensUp = false;
bool CraftControls::TranUp = false;

QSize CraftControls::Size  (0,0);
int CraftControls::Width = 0;
int CraftControls::Height = 0;

CraftControls::CraftControls(Qt3DRender::QCamera *BasicCamera, QWidget *parent) :
        QDialog(parent),
        ui(new Ui::CraftControls)
{
    ui->setupUi(this);

    CraftControls::Size = this->size();
    CraftControls::Width = this->width();
    CraftControls::Height = this->height();
    CraftControls::CraftSetTime();

    Camera = BasicCamera;

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->move(Initialize::WindowWidth/2 - Width/2,Initialize::WindowHeight - Height);

    ui->Communication->hide();
    ui->Computer->hide();
    ui->Enviroment->hide();
    ui->Transponder->hide();
    ui->Computer->hide();
    ui->Navigation->hide();
    ui->Sensors->hide();
    ui->Helm->hide();
    ui->Local->setCheckable(true);
    ui->Local->setChecked(false);
    ui->Solar->setCheckable(true);
    ui->Solar->setChecked(true);
    ui->UTC->setCheckable(true);
    ui->UTC->setChecked(false);

    //Set up master .1 second timer
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(CraftSetTime()));
    Timer->start(1000);

    Helm *HelmSig = new Helm(this);
    connect(HelmSig, SIGNAL(CloseHelm()), this, SLOT(HelmOff()));


    //Camera = BasicCamera;
    //qDebug() << "Create Camera: " << Camera;
}

CraftControls::~CraftControls()
{
    delete ui;
}

void CraftControls::CraftPower (void)
{
    if (PwrUp == false)
    {
        Power *Pwr = new Power();
        Pwr->exec();

        // Set up transponder
        UDPSocket = new QUdpSocket(this);
        //connect(Timer, SIGNAL(timeout()), this, SLOT(Broadcast()));

        PwrUp = true;
        TranUp = true;

        ui->Communication->show();
        ui->Computer->show();
        ui->Enviroment->show();
        ui->Transponder->show();
        ui->Helm->show();
        ui->Computer->show();
        ui->Navigation->show();
        ui->Sensors->show();

        ui->Transponder->setStyleSheet(GrnRnd);

        //qDebug() << "Transponder Initialized";
    }

    else

        if (PwrUp == true)
    {

        //Transponder Power Off

        ui->Power->setStyleSheet(RedSqr);
        ui->Transponder->setStyleSheet(RedSqr);

        PwrUp = false;
        TranUp = false;

        ui->Communication->hide();
        ui->Computer->hide();
        ui->Enviroment->hide();
        ui->Transponder->hide();
        ui->Helm->hide();
        //ui->Computer->hide();
        ui->Navigation->hide();
        ui->Sensors->hide();

    }
}

void CraftControls::CraftTransponder (void)
{
    if (TranUp == false)
    {
        return;
    }

    else

    {
        //Transponder Trans;
        //Trans.exec();
    }
}

void CraftControls::CraftComputer (void)
{
    if (CompUp == false)
    {
        CompUp = true;
        ui->Computer->setStyleSheet(GrnRnd);

        //ComputerControl *CompControl = new ComputerControl() ;
    }

    else

    if (CompUp == true)
    {
        ui->Computer->setStyleSheet(RedSqr);
        CompUp = false;
    }
}

void CraftControls::CraftEnvironment (void)
{
    if (EnvUp == false)
    {
        ui->Enviroment->setStyleSheet(GrnRnd);
        EnvUp = true;
    }

    else

    if (EnvUp == true)
    {
        ui->Enviroment->setStyleSheet(RedSqr);
        EnvUp = false;
    }

}

void CraftControls::CraftCommunication (void)
{
    if (ComUp == false)
    {
        ui->Communication->setStyleSheet(GrnRnd);
        ComUp = true;
    }

    else

    if (ComUp == true)
    {
        ui->Communication->setStyleSheet(RedSqr);
        ComUp = false;
    }

}

void CraftControls::CraftSensors (void)
{
    if (SensUp == false)
    {
        ui->Sensors->setStyleSheet(GrnRnd);
        SensUp = true;
    }

    else

    if (SensUp == true)
    {
        ui->Sensors->setStyleSheet(RedSqr);
        SensUp = false;
    }
}

void CraftControls::CraftNavigation (void)
{
    if (NavUp == false)
    {
        ui->Navigation->setStyleSheet(GrnRnd);
        NavUp = true;

        Navigation *Nav = new Navigation();
        Nav->LoadNavigation();

        ui->Navigation->setStyleSheet(RedSqr);
        NavUp = false;

    }

    else

    if (NavUp == true)
    {
        ui->Navigation->setStyleSheet(RedSqr);
        NavUp = false;
     }

}

void CraftControls::CraftHelm (void)
{
    if (HelmUp == false)
    {
        ui->Helm->setStyleSheet(GrnRnd);
        HelmUp = true;

        Helm *H = new Helm();
        //H->show();
        H->LoadHelm(Camera);

        ui->Helm->setStyleSheet(RedSqr);
        HelmUp = false;
     }

    else

    if (HelmUp == true)
    {
        ui->Helm->setStyleSheet(RedSqr);
        HelmUp = false;

    }

}


void CraftControls::CraftSetLocal (void)
{
    ui->Local->setChecked(true);
    ui->Solar->setChecked(false);
    ui->UTC->setChecked(false);
}

void CraftControls::CraftSetSolar (void)
{
    ui->Local->setChecked(false);
    ui->Solar->setChecked(true);
    ui->UTC->setChecked(false);
}

void CraftControls::CraftSetUTC (void)
{
    ui->Local->setChecked(false);
    ui->Solar->setChecked(false);
    ui->UTC->setChecked(true);
}

void CraftControls::Exit (void)
{
    Timer->stop();
    this->close();
}


void  CraftControls::CraftSetTime (void)
{
    if (ui->Local->isChecked() == true)
    {
        QDateTime DT;
        QString LocalTime;
        LocalTime = DT.currentDateTime().toString();
        ui->Time->setText(LocalTime);
        //qDebug() << "Local: " <<LocalTime;
    }

    if (ui->UTC->isChecked() == true)
    {
        QDateTime DT;
        QString UTCTime;
        UTCTime = DT.currentDateTimeUtc().toString();
        ui->Time->setText(UTCTime);
        //qDebug() << "UTC: " <<UTCTime;
    }

    if (ui->Solar->isChecked() == true)
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
        ui->Time->setText(Shiptime);

        ShipTime = Shiptime;
        //qDebug() << "Solar: " << ShipTime;

    }

    if (TranUp == true)
    {
    QChar NewLine = '\n';
    Transponder::TransponderDataSend.append("ID: 15623");
    Transponder::TransponderDataSend.append(NewLine);
    Transponder::TransponderDataSend.append("Time: ");
    Transponder::TransponderDataSend.append(ShipTime);
    Transponder::TransponderDataSend.append(NewLine);
    Transponder::TransponderDataSend.append(Setup::SimCraftType.toLatin1());
    Transponder::TransponderDataSend.append(NewLine);
    Transponder::TransponderDataSend.append(Setup::SimCraftName.toLatin1());
    Transponder::TransponderDataSend.append(NewLine);
    }

}

void CraftControls::CraftBroadcast (void)
{
    if (TranUp == false)
    {
        return;
    }

    //qDebug() << "TranUp: " << TranUp << "PowerUp: " << PwrUp;
    if (TranUp == false)
    {
        return;
    }

    qint64 Count = UDPSocket->writeDatagram(Transponder::TransponderDataSend, Transponder::TransponderDataSend.size(),
                             QHostAddress::LocalHost, 63666);

    if (Count == -1)
    {
        qDebug() << "No datagram to send";
    }

    Transponder::TransponderDataSend.clear();
    //qDebug() << "Bytes sent: " << Count;

}


void CraftControls::HelmOff (void)
    {
        ui->Helm->setStyleSheet(RedSqr);
        HelmUp = false;

        //qDebug() << "Helm signal";
    }

