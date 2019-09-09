#include "RCS1000.hpp"
#include "ui_RCS1000.h"

#include "SimGlobals.hpp"

RCS1000::RCS1000(Qt3DCore::QCamera *CameraEntity, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RCS1000)

{
    ui->setupUi(this);

    //int Width = this->width();
    //int Height = this->height();
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->move(Window::WindowWidth/2 - this->width()/2, 0);

    qDebug() << "Position: " << this->pos();


    //Set push button icons this way QtDesigner does not do relative file names
    ui->PitchUp->setIcon(QIcon("Icons/Up.png"));
    ui->PitchDown->setIcon(QIcon("Icons/Down.png"));
    ui->YawLeft->setIcon(QIcon("Icons/Left.png"));
    ui->YawRight->setIcon(QIcon("Icons/Right.png"));
    ui->CW->setIcon(QIcon("Icons/RollLeft.png"));
    ui->CCW->setIcon(QIcon("Icons/RollRight.png"));

    ui->TransUp->setIcon(QIcon("Icons/Up.png"));
    ui->TransDown->setIcon(QIcon("Icons/Down.png"));
    ui->TransPort->setIcon(QIcon("Icons/Left.png"));
    ui->TransStarboard->setIcon(QIcon("Icons/Right.png"));
    ui->TransForward->setIcon(QIcon("Icons/Forward.png"));
    ui->TransReverse->setIcon(QIcon("Icons/Reverse.png"));

    Camera = CameraEntity;

    //Cart2Earth ();
    //UpDateSphericalPosition ();
    UpDateCartesianPosition ();

    UpDatePositionThrust();
    UpDateAttitudeThrust ();

    //Set up master .1 second timer
    connect(Timer, SIGNAL(timeout()), this, SLOT(MasterUpdate()));
    Timer->start(100);

    //CreateCraft *CC;
    //connect(CC, SIGNAL(CloseHelm()), this, SLOT(Exit()));



}

RCS1000::~RCS1000()
{
    delete ui;
}

//Rotation

void RCS1000::PitchUp(void)
{

    QString Value;
    Craft::PitchDirection = 1;
    Craft::PitchThrusterOn = true;
    Craft::PitchThrust += Craft::PitchDirection * Craft::PitchThrottle;
    Value = Value.setNum (Craft::PitchThrust);
    ui->PitchThrust->setText (Value);
}

void RCS1000::PitchDown(void)
{
    QString Value;
    Craft::PitchDirection = -1;
    Craft::PitchThrusterOn = true;
    Craft::PitchThrust += Craft::PitchDirection * Craft::PitchThrottle;
    Value = Value.setNum (Craft::PitchThrust);
    ui->PitchThrust->setText (Value);
}

void RCS1000::YawLeft(void)
{
    QString Value;
    Craft::YawDirection = 1;
    Craft::YawThrusterOn = true;
    Craft::YawThrust += Craft::YawDirection * Craft::YawThrottle;
    Value = Value.setNum (Craft::YawThrust);
    ui->YawThrust->setText (Value);
}

void RCS1000::YawRight(void)
{
    QString Value;
    Craft::YawDirection = -1;
    Craft::YawThrusterOn = true;
    Craft::YawThrust += Craft::YawDirection * Craft::YawThrottle;
    Value = Value.setNum (Craft::YawThrust);
    ui->YawThrust->setText (Value);
}

void RCS1000::RollCounterClockWise(void)
{
    QString Value;
    Craft::RollDirection = 1;
    Craft::RollThrusterOn = true;
    Craft::RollThrust += Craft::RollDirection * Craft::RollThrottle;
    Value = Value.setNum (Craft::RollThrust);
    ui->RollThrust->setText (Value);
}

void RCS1000::RollClockWise(void)
{
    QString Value;
    Craft::RollDirection = -1;
    Craft::RollThrusterOn = true;
    Craft::RollThrust += Craft::RollDirection * Craft::RollThrottle;
    Value = Value.setNum (Craft::RollThrust);
    ui->RollThrust->setText (Value);
}

// Translation
void RCS1000::TranslateUp(void)
{
    Craft::UpDwnDirection = 1;
    Craft::UpDwnThrusterOn = true;
    Craft::UpDwnThrust += Craft::UpDwnDirection * Craft::UpDwnThrottle;
}

void RCS1000::TranslateDown(void)
{
    Craft::UpDwnDirection = -1;
    Craft::UpDwnThrusterOn = true;
    Craft::UpDwnThrust += Craft::UpDwnDirection * Craft::UpDwnThrottle;
}

void RCS1000::TranslatePort(void)
{
    Craft::PrtSrbDirection = 1;
    Craft::PrtSrbThrusterOn = true;
    Craft::PrtSrbThrust += Craft::PrtSrbDirection * Craft::PrtSrbThrottle;
}

void RCS1000::TranslateStarboard(void)
{
    Craft::PrtSrbDirection = -1;
    Craft::PrtSrbThrusterOn = true;
    Craft::PrtSrbThrust += Craft::PrtSrbDirection * Craft::PrtSrbThrottle;
}

void RCS1000::TranslateForward(void)
{
    Craft::FwdRevDirection = -1;
    Craft::FwdRevThrusterOn = true;
    Craft::FwdRevThrust += Craft::FwdRevDirection * Craft::FwdRevThrottle;
}

void RCS1000::TranslateReverse(void)
{
    Craft::FwdRevDirection = 1;
    Craft::FwdRevThrusterOn = true;
    Craft::FwdRevThrust += Craft::FwdRevDirection * Craft::FwdRevThrottle;
}


void RCS1000::UpDateSphericalPosition (void)
{
    float Distance = Craft::Heading.z ();
    QString distance;
    distance = distance.setNum (Distance);
    ui->Distance->setText (distance);
    //qDebug() << "Distance: " << distance;

    float Heading = Craft::Heading.x ();
    QString heading;
    heading = heading.setNum (Heading);
    ui->Heading->setText (heading);

    float Mark = Craft::Heading.y ();
    QString mark;
    mark = mark.setNum (Mark);
    ui->Mark->setText (mark);
}

void RCS1000::UpDateCartesianPosition (void)
{
    QString Value;

    //PositionOrientation Pos(Camera);
    QVector3D Position;

    Position = Camera->position ();

    Craft::Mark = Position.x();
    Value = Value.setNum (Craft::Mark);
    ui->Mark->setText(Value);

    Craft::Direction = Position.y();
    Value = Value.setNum (Craft::Direction);
    ui->Heading->setText(Value);


    Craft::Distance = Position.z();
    Value = Value.setNum (Craft::Distance);
    ui->Distance->setText (Value);
}

void RCS1000::UpDatePositionThrust (void)
{
    QString Value;
    Value = Value.setNum (Craft::UpDwnThrust);
    ui->UpDwnThrust->setText (Value);
    Value = Value.setNum (Craft::PrtSrbThrust);
    ui->PrtStbThrust->setText (Value);
    Value = Value.setNum (Craft::FwdRevThrust);
    ui->FwdRevThrust->setText (Value);
}

void RCS1000::UpDateAttitudeThrust (void)
{
    QString Value;
    Value = Value.setNum (Craft::PitchThrust);
    ui->PitchThrust->setText (Value);
    Value = Value.setNum (Craft::YawThrust);
    ui->YawThrust->setText (Value);
    Value = Value.setNum (Craft::RollThrust);
    ui->RollThrust->setText (Value);
    Value = Value.setNum(Craft::PitchAngle);
    ui->PitchAngle->setText(Value);
    Value = Value.setNum(Craft::YawAngle);
    ui->YawAngle->setText(Value);
    Value = Value.setNum(Craft::RollAngle);
    ui->RollAngle->setText(Value);


}

void RCS1000::MasterUpdate (void)
{
/*
    qDebug() << "FwdRvrThrottle: " << FwdRvrThrottle;
    qDebug() << "PrtSrbThrottle: " << PrtSrbThrottle;
    qDebug() << "UpDwnThrottle: " << UpDwnThrottle;
    qDebug() << "PitchThrottle: " << PitchThrottle;
    qDebug() << "YawThrottle: " << YawThrottle;
    qDebug() << "RollThrottle: " << RollThrottle;

*/


    QString Rotation;
    QQuaternion RotationAngle;

    PositionOrientation Pos;

    if (Craft::PitchThrusterOn == true)
    {
        if(Craft::PitchThrust == 0)
        {
            Craft::PitchThrusterOn = false;
        }

        RotationAngle = Camera->tiltRotation (Craft::PitchThrust);
        Craft::PitchAngle += Craft::PitchThrust;

        if (Craft::PitchAngle >= 360)
        {
            Craft::PitchAngle -= 360;
        }

        if (Craft::PitchAngle < 0)
        {
            Craft::PitchAngle += 360;
        }

        Camera->rotate (RotationAngle);
        Pos.PitchAngle = Craft::PitchAngle;

    }

    if (Craft::YawThrusterOn == true)
    {
        if(Craft::YawThrust == 0)
        {
            Craft::YawThrusterOn = false;
        }

        RotationAngle = Camera->panRotation (Craft::YawThrust);
        Craft::YawAngle += Craft::YawThrust;

        if (Craft::YawAngle >= 360)
        {
            Craft::YawAngle -= 360;
        }

        if (Craft::YawAngle < 0)
        {
            Craft::YawAngle += 360;
        }

        Camera->rotate (RotationAngle);
        Pos.YawAngle = Craft::YawAngle;
    }

    if (Craft::RollThrusterOn == true)
    {
        if(Craft::RollThrust == 0)
        {
            Craft::RollThrusterOn = false;
        }

        RotationAngle = Camera->rollRotation (Craft::RollThrust);
        Craft::RollAngle += Craft::RollThrust;

        if (Craft::RollAngle >= 360)
        {
            Craft::RollAngle -= 360;
        }

        if (Craft::RollAngle < 0)
        {
            Craft::RollAngle += 360;
        }

        Camera->rotate (RotationAngle);
        Pos.RollAngle = Craft::RollAngle;

    }

    if (Craft::UpDwnThrusterOn == true)
    {
        Craft::ShipTranslation = QVector3D (0.0f,Craft::Craft::UpDwnThrust,0.0f);
        Camera->translateWorld(Craft::ShipTranslation);
    }

    if (Craft::PrtSrbThrusterOn == true)
    {
        Craft::ShipTranslation = QVector3D (Craft::PrtSrbThrust,0.0f,0.0f);
        Camera->translateWorld(Craft::ShipTranslation);
    }

    if (Craft::FwdRevThrusterOn == true)
    {
        Craft::ShipTranslation = QVector3D (0.0f,0.0f,Craft::FwdRevThrust);
        Camera->translateWorld(Craft::ShipTranslation);
    }

    UpDateCartesianPosition ();

    UpDatePositionThrust();
    UpDateAttitudeThrust();
 }


void RCS1000::SetUpDwnValue(void)
{
    Craft::UpDwnThrottle = ui->UpDwnTSlider->value();
    ui->UpDwnValue->setText(QString::number(Craft::UpDwnThrottle));
}

void RCS1000::SetPrtSrbValue(void)
{
    Craft::PrtSrbThrottle = ui->PrtSrbTSlider->value();
    ui->PrtSrbValue->setText(QString::number(Craft::PrtSrbThrottle));
}

void RCS1000::SetFwdRvrValue(void)
{
    Craft::FwdRevThrottle = ui->FwdRvrTSlider->value();
    ui->FwdRvrValue->setText(QString::number(Craft::FwdRevThrottle));
}

void RCS1000::SetPitchValue(void)
{
    Craft::PitchThrottle = ui->PitchTSlider->value();
    ui->PitchValue->setText(QString::number(Craft::PitchThrottle));
}

void RCS1000::SetYawValue(void)
{
    Craft::YawThrottle = ui->YawTSlider->value();
    ui->YawValue->setText(QString::number(Craft::YawThrottle));
}

void RCS1000::SetRollValue(void)
{
    Craft::RollThrottle = ui->RollTSlider->value();
    ui->RollValue->setText(QString::number(Craft::RollThrottle));
}

void RCS1000::Exit (void)
{
    qDebug() << "RCS1 Exit";
    this->close();
}
