#include "RCS1000.hpp"
#include "ui_RCS1000.h"

RCS1000::RCS1000(Qt3DRender::QCamera *CameraEntity, QDialog *parent) :
    QDialog(parent),
    ui(new Ui::RCS1000)

{
    ui->setupUi(this);

    /*

    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect;
    qreal op = .7;
    effect->setOpacityMask(op);

    */


    //int Width = this->width();
    //int Height = this->height();
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->move(Initialize::WindowWidth/2 - this->width()/2, 0);

    //qDebug() << "RCS1000 Path: " << QDir::current();

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

    //Clear Thrust Orientation check boxes
    ui->YawTen->setChecked(false);
    ui->YawOne->setChecked(false);
    ui->YawTenth->setChecked(false);
    ui->PitchTen->setChecked(false);
    ui->PitchOne->setChecked(false);
    ui->PitchTenth->setChecked(false);
    ui->RollTen->setChecked(false);
    ui->RollOne->setChecked(false);
    ui->RollTenth->setChecked(false);

    //Clear Thrust Translation check boxes
    ui->HeadingTen->setChecked(false);
    ui->HeadingOne->setChecked(false);
    ui->HeadingTenth->setChecked(false);
    ui->MarkTen->setChecked(false);
    ui->MarkOne->setChecked(false);
    ui->MarkTenth->setChecked(false);
    ui->FwdRevTen->setChecked(false);
    ui->FwdRevOne->setChecked(false);
    ui->FwdRevTenth->setChecked(false);

    Camera = CameraEntity;

    //Cart2Earth ();
    //UpDateSphericalPosition ();
    UpDateCartesianPosition ();

    UpDatePositionThrust();
    UpDateAttitudeThrust ();

    //connect(Craft, SIGNAL(CloseHelm()), this, SLOT(ExitRCS1()));

    //Set up master .1 second timer
    connect(Timer, SIGNAL(timeout()), this, SLOT(MasterUpdate()));
    Timer->start(100);
}

RCS1000::~RCS1000()
{
    delete ui;
}

//Rotation

void RCS1000::PitchUp(void)
{
    QString Value;
    double Multiplier;

    if (ui->PitchTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->PitchOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->PitchTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    {
        Multiplier = 0;
    }

    Craft::PitchDirection = 1;
    Craft::PitchThrusterOn = true;
    Craft::PitchThrust += Craft::PitchDirection * Craft::PitchThrottle * Multiplier;
    Value = Value.setNum (Craft::PitchThrust);
    ui->PitchThrust->setText (Value);
}

void RCS1000::PitchDown(void)
{
    QString Value;
    double Multiplier;

    if (ui->PitchTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->PitchOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->PitchTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    {
        Multiplier = 0;
    }

    Craft::PitchDirection = -1;
    Craft::PitchThrusterOn = true;
    Craft::PitchThrust += Craft::PitchDirection * Craft::PitchThrottle * Multiplier;
    Value = Value.setNum (Craft::PitchThrust);
    ui->PitchThrust->setText (Value);
}

void RCS1000::YawLeft(void)
{
    QString Value;
    double Multiplier;

    if (ui->YawTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->YawOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->YawTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    {
        Multiplier = 0;
    }

    Craft::YawDirection = 1;
    Craft::YawThrusterOn = true;
    Craft::YawThrust += Craft::YawDirection * Craft::YawThrottle * Multiplier;
    Value = Value.setNum (Craft::YawThrust);
    ui->YawThrust->setText (Value);
}

void RCS1000::YawRight(void)
{
    QString Value;
    double Multiplier;

    if (ui->YawTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->YawOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->YawTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    {
        Multiplier = 0;
    }

    Craft::YawDirection = -1;
    Craft::YawThrusterOn = true;
    Craft::YawThrust += Craft::YawDirection * Craft::YawThrottle * Multiplier;
    Value = Value.setNum (Craft::YawThrust);
    ui->YawThrust->setText (Value);
}

void RCS1000::RollCounterClockWise(void)
{    
    QString Value;
    double Multiplier;

    if (ui->RollTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->RollOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->RollTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    {
        Multiplier = 0;
    }

    Craft::RollDirection = 1;
    Craft::RollThrusterOn = true;
    Craft::RollThrust += Craft::RollDirection * Craft::RollThrottle * Multiplier;
    Value = Value.setNum (Craft::RollThrust);
    ui->RollThrust->setText (Value);

    //qDebug() << "RollThrust: " << Craft::RollThrust << "RollValue: " << Value;

}

void RCS1000::RollClockWise(void)
{
    QString Value;
    double Multiplier;

    if (ui->RollTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->RollOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->RollTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    {
        Multiplier = 0;
    }

    Craft::RollDirection = -1;
    Craft::RollThrusterOn = true;
    Craft::RollThrust += Craft::RollDirection * Craft::RollThrottle * Multiplier;
    Value = Value.setNum (Craft::RollThrust);
    ui->RollThrust->setText (Value);
}

// Translation
void RCS1000::TranslateUp(void)
{
    Craft::MarkDirection = 1;
    Craft::MarkThrusterOn = true;
    Craft::MarkThrust += Craft::MarkDirection * Craft::MarkThrottle;
}

void RCS1000::TranslateDown(void)
{
    Craft::MarkDirection = -1;
    Craft::MarkThrusterOn = true;
    Craft::MarkThrust += Craft::MarkDirection * Craft::MarkThrottle;
}

void RCS1000::TranslatePort(void)
{    
    Craft::HeadingDirection = 1;
    Craft::HeadingThrusterOn = true;
    Craft::HeadingThrust += Craft::HeadingDirection * Craft::HeadingThrottle;
}

void RCS1000::TranslateStarboard(void)
{
    Craft::HeadingDirection = -1;
    Craft::HeadingThrusterOn = true;
    Craft::HeadingThrust += Craft::HeadingDirection * Craft::HeadingThrottle;
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
    double Distance = (double) Craft::Heading.z ();
    QString distance;
    distance = distance.setNum (Distance);
    ui->FwdRevAngle->setText (distance);
    //qDebug() << "Distance: " << distance;

    double Heading = (double) Craft::Heading.x ();
    QString heading;
    heading = heading.setNum (Heading);
    ui->HeadingAngle->setText (heading);

    double Mark = (double) Craft::Heading.y ();
    QString mark;
    mark = mark.setNum (Mark);
    ui->MarkAngle->setText (mark);
}

void RCS1000::UpDateCartesianPosition (void)
{
    QString Value;

    //PositionOrientation Pos(Camera);
    QVector3D Position;

    Position = Camera->position ();

    Craft::Mark = (double) Position.x();
    Value = Value.setNum (Craft::Mark);
    ui->MarkAngle->setText(Value);

    Craft::Direction = (double) Position.y();
    Value = Value.setNum (Craft::Direction);
    ui->HeadingAngle->setText(Value);


    Craft::Distance = (double) Position.z();
    Value = Value.setNum (Craft::Distance);
    ui->FwdRevAngle->setText (Value);
}

void RCS1000::UpDatePositionThrust (void)
{
    QString Value;
    Value = Value.setNum (Craft::MarkThrust);
    ui->MarkThrust->setText (Value);
    Value = Value.setNum (Craft::HeadingThrust);
    ui->HeadingThrust->setText (Value);
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
    qDebug() << "HeadingThrottle: " << HeadingThrottle;
    qDebug() << "MarkThrottle: " << MarkThrottle;
    qDebug() << "PitchThrottle: " << PitchThrottle;
    qDebug() << "YawThrottle: " << YawThrottle;
    qDebug() << "RollThrottle: " << RollThrottle;

*/


    QString Rotation;
    QQuaternion RotationAngle;

    PositionOrientation Pos;

    if (Craft::PitchThrusterOn == true)
    {
        if(Craft::PitchThrust == 0.0)
        {
            Craft::PitchThrusterOn = false;
        }

        RotationAngle = Camera->tiltRotation ((float) Craft::PitchThrust);
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
        if(Craft::YawThrust == 0.0)
        {
            Craft::YawThrusterOn = false;
        }

        RotationAngle = Camera->panRotation ((float) Craft::YawThrust);
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
        if(Craft::RollThrust == 0.0)
        {
            Craft::RollThrusterOn = false;
        }

        RotationAngle = Camera->rollRotation ((float) Craft::RollThrust);
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

    if (Craft::MarkThrusterOn == true)
    {
        Craft::ShipTranslation = QVector3D (0.0,(float) Craft::Craft::MarkThrust,0.0);
        Camera->translateWorld(Craft::ShipTranslation);
    }

    if (Craft::HeadingThrusterOn == true)
    {
        Craft::ShipTranslation = QVector3D ((float) Craft::HeadingThrust,0.0,0.0);
        Camera->translateWorld(Craft::ShipTranslation);
    }

    if (Craft::FwdRevThrusterOn == true)
    {
        Craft::ShipTranslation = QVector3D (0.0,0.0,(float) Craft::FwdRevThrust);
        Camera->translateWorld(Craft::ShipTranslation);
    }

    UpDateCartesianPosition ();

    UpDatePositionThrust();
    UpDateAttitudeThrust();
 }


void RCS1000::SetUpDwnValue(void)
{
    double Multiplier = 0;
    if (ui->MarkTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->MarkOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->MarkTen->isChecked())
    {
        Multiplier = 10;
    }

    Craft::MarkThrottle = ui->MarkTSlider->value() * Multiplier;
    ui->MarkValue->setText(QString::number(Craft::MarkThrottle));
    ui->MarkThrust->setText(QString::number(Craft::MarkThrottle));

}

void RCS1000::SetPrtSrbValue(void)
{
    double Multiplier;

    if (ui->HeadingTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->HeadingOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->HeadingTen->isChecked())
    {
        Multiplier = 10;
    }

    else
    {
       Multiplier = 0;
    }

    Craft::HeadingThrottle = ui->HeadingTSlider->value() * Multiplier;
    ui->HeadingValue->setText(QString::number(Craft::HeadingThrottle));
    ui->HeadingThrust->setText(QString::number(Craft::HeadingThrottle));
}

void RCS1000::SetFwdRvrValue(void)
{
    double Multiplier;

    if (ui->FwdRevTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->FwdRevOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->FwdRevTen->isChecked())
    {
        Multiplier = 10;
    }

    else

    {
        Multiplier = 0;
    }

    Craft::FwdRevThrottle = ui->FwdRvrTSlider->value() * Multiplier;
    ui->FwdRevValue->setText(QString::number(Craft::FwdRevThrottle));
    ui->FwdRevThrust->setText(QString::number(Craft::FwdRevThrottle));
    //qDebug() << "FrwRevSlider: " << ui->FwdRvrTSlider->value() << "Throttle:   " << Craft::FwdRevThrottle;


}

void RCS1000::SetPitchValue(void)
{
    double Multiplier;

    if (ui->PitchTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->PitchOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->PitchTen->isChecked())   
    {
        Multiplier = 10;
    }

    else
    {
        Multiplier = 0;
    }

    Craft::PitchThrottle = ui->PitchTSlider->value() * Multiplier;
    ui->PitchValue->setText(QString::number(Craft::PitchThrottle));
    ui->PitchThrust->setText(QString::number(Craft::PitchThrottle));
}

void RCS1000::SetYawValue(void)
{
    double Multiplier;

    if (ui->YawTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->YawOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->YawTen->isChecked())
    {
        Multiplier = 10;
    }

    else
    {
        Multiplier = 0;
    }

    Craft::YawThrottle = ui->YawTSlider->value() * Multiplier;
    ui->YawValue->setText(QString::number(Craft::YawThrottle));
    ui->YawThrust->setText(QString::number(Craft::YawThrottle));
}

void RCS1000::SetRollValue(void)
{
    double Multiplier = 0;
    if (ui->RollTenth->isChecked())
    {
        Multiplier = .1;
    }

    else if (ui->RollOne->isChecked())
    {
        Multiplier = 1;
    }

    else if (ui->RollTen->isChecked())
    {
        Multiplier = 10;
    }

    Craft::RollThrottle = ui->RollTSlider->value() * Multiplier;
    ui->RollValue->setText(QString::number(Craft::RollThrottle));
    ui->RollThrust->setText(QString::number(Craft::RollThrottle));
}

void RCS1000::Exit (void)
{
    this->close();
}
