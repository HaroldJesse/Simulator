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
    CraftControls::SetTime();

    Camera = BasicCamera;

    //this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->move(Initialize::WindowWidth/2 - Width/2,Initialize::WindowHeight - Height);


    ui->Com->hide();
    ui->Env->hide();
    ui->Trn->hide();
    ui->Cmp->hide();
    ui->Nav->hide();
    ui->Say->hide();
    ui->Helm->hide();


    //Set up master .1 second timer
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(SetTime()));
    Timer->start(1000);

    //Camera = BasicCamera;
    //qDebug() << "Create Camera: " << Camera;
}

CraftControls::~CraftControls()
{
    delete ui;
}

void CraftControls::PowerType (void)
{
    if (PwrUp == false)
    {
        Power Pwr;
        Pwr.exec();

        // Set up transponder
        UDPSocket = new QUdpSocket(this);
        connect(Timer, SIGNAL(timeout()), this, SLOT(Broadcast()));
        ui->Pwr->setStyleSheet(GrnRnd);

        PwrUp = true;
        TranUp = true;

        ui->Com->show();
        ui->Env->show();
        ui->Trn->show();
        ui->Helm->show();
        ui->Cmp->show();
        ui->Nav->show();
        ui->Say->show();

        ui->Trn->setStyleSheet(GrnRnd);

        //qDebug() << "Transponder Initialized";
    }

    else

        if (PwrUp == true)
    {

        //Transponder Power Off

        ui->Pwr->setStyleSheet(RedSqr);
        ui->Trn->setStyleSheet(RedSqr);

        PwrUp = false;
        TranUp = false;

        ui->Com->hide();
        ui->Env->hide();
        ui->Trn->hide();
        ui->Helm->hide();
        ui->Cmp->hide();
        ui->Nav->hide();
        ui->Say->hide();
    }
}

void CraftControls::CommunicationType (void)
{
    if (ComUp == false)
    {
        ui->Com->setStyleSheet(GrnRnd);
        ComUp = true;
    }

    else

    if (ComUp == true)
    {
        ui->Com->setStyleSheet(RedSqr);
        ComUp = false;
    }

}

void CraftControls::TransponderType (void)
{
    if (TranUp == false)
    {
        return;
    }

    else

    {
        Transponder Trans;
        Trans.exec();
    }
}

void CraftControls::EnvironmentType (void)
{
    if (EnvUp == false)
    {
        ui->Env->setStyleSheet(GrnRnd);
        EnvUp = true;
    }

    else

    if (EnvUp == true)
    {
        ui->Env->setStyleSheet(RedSqr);
        EnvUp = false;
    }

}

void CraftControls::HelmType (void)
{
    Helm *H = new Helm();

    if (HelmUp == false)
    {
        H->LoadHelm(Camera);
        connect(this, SIGNAL(CloseHelm()), H, SLOT(ExitHelm()));
        ui->Helm->setStyleSheet(GrnRnd);
        HelmUp = true;
    }

    else

    if (HelmUp == true)
    {
        ui->Helm->setStyleSheet(RedSqr);
        HelmUp = false;
        emit CloseHelm();
    }
}

void CraftControls::NavigationType (void)
{
    if (NavUp == false)
    {
        Navigation *N = new Navigation();
        N->LoadNavigation();
        connect(this, SIGNAL(CloseNavigation()), N, SLOT(Exit()));
        this->close();
        ui->Nav->setStyleSheet(GrnRnd);
        NavUp = true;
    }

    else

    if (NavUp == true)
    {
        ui->Nav->setStyleSheet(RedSqr);
        NavUp = false;
        emit CloseNavigation();
    }

}


void CraftControls::ComputerType (void)
{
    if (CompUp == false)
    {
        ui->Cmp->setStyleSheet(GrnRnd);
        CompUp = true;
    }

    else

    if (CompUp == true)
    {
        ui->Cmp->setStyleSheet(RedSqr);
        CompUp = false;
    }
}

void CraftControls::SensorArrayType (void)
{
    if (SensUp == false)
    {
        ui->Say->setStyleSheet(GrnRnd);
        SensUp = true;
    }

    else

    if (SensUp == true)
    {
        ui->Say->setStyleSheet(RedSqr);
        SensUp = false;
    }
}

void CraftControls::Exit (void)
{
    emit CloseAll();
    Timer->stop();
    this->close();
}


void  CraftControls::SetTime (void)
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
    ui->Time->setText(ShipTime);

    ShipTime = Shiptime;

    if (TranUp == true)
    {
        QChar NewLine = '\n';
        Transponder::TransponderDataSend.append("ID: 15623");
        Transponder::TransponderDataSend.append(NewLine);
        Transponder::TransponderDataSend.append("Time: ");
        Transponder::TransponderDataSend.append(ShipTime);
        Transponder::TransponderDataSend.append(NewLine);
        Transponder::TransponderDataSend.append(Setup::SimCraftClass.toLatin1());
        Transponder::TransponderDataSend.append(NewLine);
        Transponder::TransponderDataSend.append(Setup::SimCraftName.toLatin1());
        Transponder::TransponderDataSend.append(NewLine);
    }

    //qDebug() << "Tick:" << ShipTime;
}

void CraftControls::Broadcast (void)
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
