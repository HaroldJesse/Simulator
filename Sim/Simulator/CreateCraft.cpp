#include "CreateCraft.hpp"
#include "ui_CreateCraft.h"

QString CreateCraft::ShipTime = "00:00:00:00";

bool CreateCraft::PwrUp (false);
bool CreateCraft::EnvUp = false;
bool CreateCraft::HelmUp = false;
bool CreateCraft::NavUp = false;
bool CreateCraft::ComUp = false;
bool CreateCraft::CompUp = false;
bool CreateCraft::SensUp = false;
bool CreateCraft::TranUp = false;

QSize CreateCraft::Size (0,0);

CreateCraft::CreateCraft(Qt3DRender::QCamera *BasicCamera, QDialog *parent) :
    QDialog(parent),
    ui(new Ui::CreateCraft)
{
    ui->setupUi(this);
    qDebug() << "CreateCraft";
    Size = this->size();
    int Width = this->width();
    int Height = this->height();

    Camera = BasicCamera;

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->move(Window::WindowWidth/2 - Width/2,Window::WindowHeight - Height);

    ui->Com->hide();
    ui->Env->hide();
    ui->Trn->hide();
    ui->Cmp->hide();
    ui->Nav->hide();
    ui->Say->hide();
    ui->Helm->hide();


    //Set up master .1 second timer
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(Time()));
    Timer->start(1000);

    Camera = BasicCamera;
    //qDebug() << "Create Camera: " << Camera;
}

CreateCraft::~CreateCraft()
{
    delete ui;
}

void CreateCraft::PowerType (void)
{
    if (PwrUp == false)
    {
        Power Pwr;
        Pwr.show();

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

void CreateCraft::CommunicationType (void)
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

void CreateCraft::TransponderType (void)
{
    if (TranUp == false)
    {
        return;
    }

    else

    {
        Transponder Trans;
        Trans.show();
    }
}

void CreateCraft::EnvironmentType (void)
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

void CreateCraft::HelmType (void)
{


    if (HelmUp == false)
    {
        qDebug() << "Helmup false";
        ui->Helm->setStyleSheet(GrnRnd);
        HelmUp = true;
        QTextToSpeech Verbalize;
        Verbalize.say("Helm control is on line");

        Helm *H = new Helm();
        connect(this, SIGNAL(CloseHelm()), H, SLOT(ExitHelm()));
        H->LoadHelm(Camera);
    }

    else

    if (HelmUp == true)
    {
        qDebug() << "Helmup true";
        ui->Helm->setStyleSheet(RedSqr);
        QTextToSpeech Verbalize;
        Verbalize.say("Helm control is going off line");

        HelmUp = false;
        emit CloseHelm();
    }
}

void CreateCraft::NavigationType (void)
{


    if (NavUp == false)
    {
        Navigation *N = new Navigation();
        N->LoadNavigation();
        connect(this, SIGNAL(CloseNavigation()), N, SLOT(ExitNavigation()));
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


void CreateCraft::ComputerType (void)
{
    if (CompUp == false)
    {
        ui->Cmp->setStyleSheet(GrnRnd);
        CompUp = true;

        Voice AIVoice;
        AIVoice.exec();

    }

    else

    if (CompUp == true)
    {
        ui->Cmp->setStyleSheet(RedSqr);
        CompUp = false;

        Voice AIVoice;
        AIVoice.exec();

    }
}

void CreateCraft::SensorArrayType (void)
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

void CreateCraft::Exit (void)
{
    qDebug() << "Exit Close All";
    emit CloseAll();
    Timer->stop();
    this->close();
}


void  CreateCraft::Time (void)
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

void CreateCraft::Broadcast (void)
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

void CreateCraft::on_Cmp_clicked()
{

}
