#ifndef CRAFT_HPP
#define CRAFT_HPP

#include <QVector3D>
#include <QQuaternion>

class Craft
{
public:
    Craft();

    static int   CraftTime;

    static int   FwdRevThrottle;
    static bool  FwdRevThrusterOn;
    static int   FwdRevDirection;
    static int   FwdRevThrust;

    static int   PrtSrbThrottle;
    static bool  PrtSrbThrusterOn;
    static int   PrtSrbDirection;
    static int   PrtSrbThrust;

    static int   UpDwnThrottle;
    static bool  UpDwnThrusterOn;
    static int   UpDwnDirection;
    static int   UpDwnThrust;

    static bool  ThrusterSync;

    static int   PitchThrottle;
    static int   PitchDirection;
    static bool  PitchThrusterOn;

    static int   YawThrottle;
    static int   YawDirection;
    static bool  YawThrusterOn;

    static int   RollThrottle;
    static int   RollDirection;
    static bool  RollThrusterOn;


    static QQuaternion RotationQuat;
    static QVector3D CartPosition;
    static QVector3D ShipTranslation;

    static QVector3D Heading;
    static double Direction;
    static double Mark;
    static double Distance;

    static double PitchThrust;
    static int  PitchAngle;
    static double YawThrust;
    static int  YawAngle;
    static double RollThrust;
    static int  RollAngle;

    static double Angle;
    static QVector3D Attitude;
    static QVector3D Velocity;

    static double FuelTanks;
    static double OxidizerTanks;
    static double ThrusterFuel;
    static double ThrusterOxidizer;
    static double VernierThrust;
    static double PrimaryThrust;


};

#endif // CRAFT_HPP
