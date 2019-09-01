#include "Transponder.hpp"
#include "ui_Transponder.h"



QByteArray Transponder::TransponderData = "";
QByteArray Transponder::TransponderDataSend = "";


Transponder::Transponder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transponder)
{
    ui->setupUi(this);

    UDPSocket = new QUdpSocket(this);
    UDPSocket->bind(63666, QUdpSocket::ShareAddress);
    connect(UDPSocket, SIGNAL(readyRead()), this, SLOT(Listen()));
    qDebug() << "Status: " << UDPSocket->hasPendingDatagrams();
}

Transponder::~Transponder()
{
    delete ui;
}

void Transponder::StartBroadcast(void)
{

}



void Transponder::ActivateDisplay (void)
{
    this->show();
}

void Transponder::DeactivateDisplay (void)
{
    this->close();
}

void Transponder::Stop(void)
{
    qDebug() << "Stop";
    Timer->stop();
}

void Transponder::Listen (void)
{
    qDebug() << "Listen";

    while (UDPSocket->hasPendingDatagrams())
    {
        QByteArray Datagram;
        Datagram.resize(UDPSocket->pendingDatagramSize());
        quint64 Count = UDPSocket->readDatagram(Datagram.data(), Datagram.size());
        qDebug() << "Receive: " << Datagram.data() << "Count: " << Count;
        ui->TransponderData->clear();
        ui->TransponderData->setText(Datagram);

        Transponder::TransponderData.clear();
        qDebug() << "Data:" << Datagram.data();
    }
}

