#include "PositionOrientation.hpp"
#include "ui_PositionOrientation.h"

//Initialize static variables
QVector3D Orientation (0,0,0);
QVector3D Object (0,0,0);

//Position
double PositionOrientation::Distance (0);
double PositionOrientation::Heading (0);
double PositionOrientation::Mark (0);

//Orientation
double PositionOrientation::PitchAngle (0);
double PositionOrientation::YawAngle (0);
double PositionOrientation::RollAngle (0);

QSize PositionOrientation::Size (0,0);

PositionOrientation::PositionOrientation(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::PositionOrientation)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    Size = this->size();

    int Width = this->width();
    //int Height = this->height();
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->move(Initialize::WindowWidth/2 - Width/2,0);

    //Set up master .1 second Timer

    connect(Timer, SIGNAL(timeout()), this, SLOT(MasterUpdate()));
    Timer->start(100);

    QString Value;
    Value = "Distance: " + Value.setNum(Distance);
    ui->Distance->setText(Value);
    Value = "Heading: " + QString::number(Heading);
    ui->Heading->setText(Value);
    Value = "Mark: " + QString::number(Mark);
    ui->Mark->setText(Value);
    Value = "PitchAngle: " + QString::number(PitchAngle);
    ui->PitchAngle->setText(Value);
    Value = "YawAngle: " + QString::number(YawAngle);
    ui->YawAngle->setText(Value);
    Value = "RollAngle: " + QString::number(RollAngle);
    ui->RollAngle->setText(Value);
}

PositionOrientation::~PositionOrientation()
{
    delete ui;
}

void PositionOrientation::MasterUpdate (void)
{
    //qDebug() << "OP master update: ";

    if ((Distance == Dist) == false)
    {
        QString Value = "Position Z: " + Value.number(Distance);
        Dist = Distance;
        ui->Distance->setText(Value);
    }

    if ((Heading == Head) == false)
    {
        QString Value = "Position X: " + Value.number(Heading);
        Head = Heading;
        ui->Heading->setText(Value);
    }

    if ((Mark == Mk) == false)
    {
        QString Value = "Position Y: " + Value.number(Mark);
        Mk = Mark;
        ui->Mark->setText(Value);
    }

    if ((PitchAngle == Pitch) == false)
    {
        QString Value = "Pitch Angle: " + Value.number(PitchAngle);
        Pitch = PitchAngle;
        ui->PitchAngle->setText(Value);
    }

    if ((YawAngle == Yaw) == false)
    {
        QString Value = "YawAngle: " + Value.number(YawAngle);
        Yaw = YawAngle;
        ui->YawAngle->setText(Value);
    }

    if ((RollAngle == Roll) == false)
    {
        QString Value = "RollAngle: " + Value.number(RollAngle);
        Roll = RollAngle;
        ui->RollAngle->setText(Value);
    }

}

void PositionOrientation::Exit (void)
{
    //qDebug() << "POExit";
    Timer->stop();
    this->close();
}
