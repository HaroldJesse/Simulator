#include "RCS2000.hpp"
#include "ui_RCS2000.h"

RCS2000::RCS2000(Qt3DRender::QCamera *CameraEntity, QDialog *parent) :
    QDialog(parent),
    ui(new Ui::RCS2000)

{
    ui->setupUi(this);

    int Width = this->width();
    int Height = this->height();
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setModal(true);
    this->move(Initialize::WindowWidth/2 - Width/2,Initialize::WindowHeight - CraftControls::Height - Height);


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

    UpDateSphericalPosition ();
    UpDateCartesianPosition ();

    UpDatePositionThrust ();
    UpDateAttitude ();

    //Set up master .1 second timer
    connect(Timer, SIGNAL(timeout()), this, SLOT(MasterUpdate()));
    Timer->start(100);

}

RCS2000::~RCS2000()
{
    delete ui;
}

void RCS2000::PitchUp(void)
{
    QString Value;
    Craft::PitchDirection = 1;
    Craft::PitchThrusterOn = true;
    OThruster::PitchThrust += Craft::PitchDirection * OThruster::PitchThrottle;
    Value = Value.setNum (OThruster::PitchThrust);
    ui->PitchThrust->setText (Value);
}

void RCS2000::PitchDown(void)
{
    QString Value;
    Craft::PitchDirection = -1;
    Craft::PitchThrusterOn = true;
    OThruster::PitchThrust += Craft::PitchDirection * OThruster::PitchThrottle;
    Value = Value.setNum (OThruster::PitchThrust);
    ui->PitchThrust->setText (Value);
}

void RCS2000::YawLeft(void)
{
    QString Value;
    Craft::YawDirection = 1;
    Craft::YawThrusterOn = true;
    OThruster::YawThrust += Craft::YawDirection * OThruster::YawThrottle;
    Value = Value.setNum (OThruster::YawThrust);
    ui->YawThrust->setText (Value);
}

void RCS2000::YawRight(void)
{
    QString Value;
    Craft::YawDirection = -1;
    Craft::YawThrusterOn = true;
    OThruster::YawThrust += Craft::YawDirection * OThruster::YawThrottle;
    Value = Value.setNum (OThruster::YawThrust);
    ui->YawThrust->setText (Value);
}

void RCS2000::RollCounterClockWise(void)
{
    QString Value;
    Craft::RollDirection = 1;
    Craft::RollThrusterOn = true;
    OThruster::RollThrust += Craft::RollDirection * OThruster::RollThrottle;
    Value = Value.setNum (OThruster::RollThrust);
    ui->RollThrust->setText (Value);
}

void RCS2000::RollClockWise(void)
{
    QString Value;
    Craft::RollDirection = -1;
    Craft::RollThrusterOn = true;
    OThruster::RollThrust += Craft::RollDirection * OThruster::RollThrottle;
    Value = Value.setNum (OThruster::RollThrust);
    ui->RollThrust->setText (Value);
}

// Translation
void RCS2000::TranslateUp(void)
{
    Craft::MarkDirection = 1;
    Craft::MarkThrusterOn = true;
    PThruster::MarkThrust += Craft::MarkDirection * PThruster::MarkThrottle;
}

void RCS2000::TranslateDown(void)
{
    Craft::MarkDirection = -1;
    Craft::MarkThrusterOn = true;
    PThruster::MarkThrust += Craft::MarkDirection * PThruster::MarkThrottle;
}

void RCS2000::TranslatePort(void)
{
    Craft::HeadingDirection = 1;
    Craft::HeadingThrusterOn = true;
    PThruster::HeadingThrust += Craft::MarkDirection * PThruster::HeadingThrottle;
}

void RCS2000::TranslateStarboard(void)
{
    Craft::HeadingDirection = -1;
    Craft::HeadingThrusterOn = true;
    PThruster::HeadingThrust += Craft::HeadingDirection * PThruster::HeadingThrottle;
}

void RCS2000::TranslateForward(void)
{
    Craft::FwdRevDirection = -1;
    Craft::FwdRevThrusterOn = true;
    PThruster::FwdRevThrust += Craft::FwdRevDirection * PThruster::FwdRevThrottle;
}

void RCS2000::TranslateReverse(void)
{
    Craft::FwdRevDirection = 1;
    Craft::FwdRevThrusterOn = true;
    PThruster::FwdRevThrust += Craft::FwdRevDirection * PThruster::FwdRevThrottle;
}

void RCS2000::UpDateSphericalPosition (void)
{
    qfloat16 Distance = Craft::Heading.z ();
    QString distance;
    distance = distance.setNum (Distance);

    qfloat16 Heading = Craft::Heading.x ();
    QString heading;
    heading = heading.setNum (Heading);

    qfloat16 Mark = Craft::Heading.y ();
    QString mark;
    mark = mark.setNum (Mark);

}

void RCS2000::UpDateCartesianPosition (void)
{
    QString Value;

    //PositionOrientation Pos(Camera);
    QVector3D Position;

    Position = Camera->position ();

    PositionOrientation::Mark = Position.x();
    PositionOrientation::Heading = Position.y();
    PositionOrientation::Distance = Position.z();

    //Value = Value.setNum (Mark);
    //PositionOrientation.Mark->Mark->setText(Value);

    //Direction = Position.y();
    //Value = Value.setNum (Direction);
    //ui->Heading->setText(Value);


    //Distance = Position.z();
    //Value = Value.setNum (Distance);
    //ui->Distance->setText (Value);

}

void RCS2000::UpDatePositionThrust (void)
{
    QString Value;
    Value = Value.setNum (PThruster::MarkThrust);
    ui->MarkThrust->setText (Value);
    Value = Value.setNum (PThruster::HeadingThrust);
    ui->HeadingThrust->setText (Value);
    Value = Value.setNum (PThruster::FwdRevThrust);
    ui->FwdRevThrust->setText (Value);
}

void RCS2000::UpDateAttitude (void)
{

    //qDebug() << "RCS2000Cart" << Camera->viewCenter();

    QString Value;
    Value = Value.setNum (OThruster::PitchThrust);
    ui->PitchThrust->setText (Value);
    Value = Value.setNum (OThruster::YawThrust);
    ui->YawThrust->setText (Value);
    Value = Value.setNum (OThruster::RollThrust);
    ui->RollThrust->setText (Value);
    Value = Value.setNum(Craft::PitchAngle);
    //ui->PitchAngle->setText(Value);
    Value = Value.setNum(Craft::YawAngle);
    //ui->YawAngle->setText(Value);
    Value = Value.setNum(Craft::RollAngle);
    //ui->RollAngle->setText(Value);


}

void RCS2000::MasterUpdate (void)
{
/*
    qDebug() << "FwdRvrThrottle: " << FwdRvrThrottle;
    qDebug() << "HeadingThrottle: " << HeadingThrottle;
    qDebug() << "MarkThrottle: " << MarkThrottle;
    qDebug() << "PitchThrottle: " << PitchThrottle;
    qDebug() << "YawThrottle: " << YawThrottle;
    qDebug() << "RollThrottle: " << RollThrottle;

*/
    QString Rotation;
    QQuaternion RotationAngle;

    if (Craft::PitchThrusterOn == true)
    {
        if(OThruster::PitchThrust <= 0)
        {
            Craft::PitchThrusterOn = false;
        }

        RotationAngle = Camera->tiltRotation (OThruster::PitchThrust);
        Craft::PitchAngle += OThruster::PitchThrust;

        if (Craft::PitchAngle >= 360)
        {
            Craft::PitchAngle -= 360;
        }

        if (Craft::PitchAngle < 0)
        {
            Craft::PitchAngle += 360;
        }

        Camera->rotate (RotationAngle);
        PositionOrientation::PitchAngle = Craft::PitchAngle;

    }

    if (Craft::YawThrusterOn == true)
    {
        if(OThruster::YawThrust <= 0)
        {
            Craft::YawThrusterOn = false;
        }

        RotationAngle = Camera->panRotation (OThruster::YawThrust);
        Craft::YawAngle += OThruster::YawThrust;

        if (Craft::YawAngle >= 360)
        {
            Craft::YawAngle -= 360;
        }

        if (Craft::YawAngle < 0)
        {
            Craft::YawAngle += 360;
        }

        Camera->rotate (RotationAngle);
        PositionOrientation::YawAngle = Craft::YawAngle;
    }

    if (Craft::RollThrusterOn == true)
    {
        if(OThruster::RollThrust <= 0)
        {
            Craft::RollThrusterOn = false;
        }

        RotationAngle = Camera->rollRotation (OThruster::RollThrust);
        Craft::RollAngle += OThruster::RollThrust;

        if (Craft::RollAngle >= 360)
        {
            Craft::RollAngle -= 360;
        }

        if (Craft::RollAngle < 0)
        {
            Craft::RollAngle += 360;
        }

        Camera->rotate (RotationAngle);
        PositionOrientation::RollAngle = Craft::RollAngle;

    }

    if (Craft::MarkThrusterOn == true)
    {
        Craft::ShipTranslation = QVector3D (PThruster::MarkThrust,0.0,0.0);
        Camera->translateWorld(Craft::ShipTranslation);
    }

    if (Craft::HeadingThrusterOn == true)
    {
        Craft::ShipTranslation = QVector3D (PThruster::HeadingThrust,0.0,0.0);
        Camera->translateWorld(Craft::ShipTranslation);
    }

    if (Craft::FwdRevThrusterOn == true)
    {
        Craft::ShipTranslation = QVector3D (0.0,0.0,PThruster::FwdRevThrust);
        Camera->translateWorld(Craft::ShipTranslation);
    }

    UpDateCartesianPosition ();

    //UpDateSphericalPosition ();

    UpDatePositionThrust();
    UpDateAttitude();
 }

void RCS2000::Exit (void)
{
    qDebug() << "RCS2Exit";
    emit RCS2Close ();
    Timer->stop();
    this->close();
}
