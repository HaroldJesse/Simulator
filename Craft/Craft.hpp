#ifndef CRAFT_HPP
#define CRAFT_HPP

#include <QVector3D>
#include <QQuaternion>

class Craft
{
public:
    Craft();

    static int   CraftTime;

    static double   FwdRevThrottle;
    static bool     FwdRevThrusterOn;
    static double   FwdRevDirection;
    static double   FwdRevThrust;

    static double   PrtSrbThrottle;
    static bool     PrtSrbThrusterOn;
    static double   PrtSrbDirection;
    static double   PrtSrbThrust;

    static double   UpDwnThrottle;
    static bool     UpDwnThrusterOn;
    static double   UpDwnDirection;
    static double   UpDwnThrust;

    static bool     ThrusterSync;

    static double   PitchThrottle;
    static double   PitchDirection;
    static bool     PitchThrusterOn;

    static double   YawThrottle;
    static int      YawDirection;
    static bool     YawThrusterOn;

    static double   RollThrottle;
    static int      RollDirection;
    static bool     RollThrusterOn;


    static QQuaternion RotationQuat;
    static QVector3D CartPosition;
    static QVector3D ShipTranslation;

    static QVector3D Heading;
    static float Direction;
    static float Mark;
    static float Distance;

    static double PitchThrust;
    static double PitchAngle;
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
