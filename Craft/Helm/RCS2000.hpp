#pragma once
#ifndef RCS2000_HPP
#define RCS2000_HPP
//#endif // RCS2000_HPP

#include <QDialog>
#include <Qt3DRender>

#include "Craft.hpp"
#include "OThruster.hpp"
#include "PThruster.hpp"
#include "PositionOrientation.hpp"
#include "CraftControls.hpp"

namespace Ui {
class RCS2000;
}

class RCS2000 : public QDialog
{
    Q_OBJECT

public:
    explicit RCS2000(Qt3DRender::QCamera *CameraEntity, QDialog *parent = nullptr);
    ~RCS2000();

    static double FwdRevThrottle;
    static bool   FwdRevThrusterOn;
    static int    FwdRevDirection;
    static double FwdRevThrust;

    static double HeadingThrottle;
    static bool   HeadingThrusterOn;
    static int    HeadingDirection;
    static double HeadingThrust;

    static double MarkThrottle;
    static bool   MarkThrusterOn;
    static int    MarkDirection;
    static double  MarkThrust;

    static bool  ThrusterSync;

    static double PitchThrottle;
    static int   PitchDirection;
    static bool  PitchThrusterOn;

    static double YawThrottle;
    static int   YawDirection;
    static bool  YawThrusterOn;

    static double RollThrottle;
    static int   RollDirection;
    static bool  RollThrusterOn;


    static QQuaternion RotationQuat;
    static QVector3D CartPosition;
    static QVector3D ShipTranslation;

    static QVector3D Heading;
    static double Direction;
    static double Mark;
    static double Distance;

    static double  PitchAngle;
    static double  YawAngle;
    static double  RollAngle;

    static double Angle;
    static QVector3D Attitude;
    static QVector3D Velocity;

    static int FuelTanks;
    static int OxidizerTanks;
    static double ThrusterFuel;
    static double ThrusterOxidizer;
    static double VernierThrust;
    static double PrimaryThrust;

signals:

    void RCS2Close ();

public slots:
    void Exit (void);

    void PitchUp(void);
    void PitchDown(void);
    void YawLeft(void);
    void YawRight(void);
    void RollCounterClockWise(void);
    void RollClockWise(void);

    void TranslateUp(void);
    void TranslateDown(void);
    void TranslatePort(void);
    void TranslateStarboard(void);
    void TranslateForward(void);
    void TranslateReverse(void);
    void MasterUpdate (void);

private:
    Ui::RCS2000 *ui;

    QTimer *Timer = new QTimer(this);

    Qt3DRender::QCamera *Camera;

    void UpDateSphericalPosition (void);
    void UpDateCartesianPosition (void);

    void UpDatePositionThrust (void);
    void UpDateAttitude (void);

};

#endif // RCS2000_HPP
