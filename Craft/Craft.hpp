//#pragma once
#ifndef CRAFT_HPP
#define CRAFT_HPP
//#endif // CRAFT_HPP

#include <QVector3D>
#include <QQuaternion>

class Craft
{
public:
    Craft();

    static int   CraftTime;

    static double    FwdRevThrottle;
    static bool      FwdRevThrusterOn;
    static double    FwdRevDirection;
    static double    FwdRevThrust;
    static double    FwdRevValue;

    static double    HeadingThrottle;
    static bool      HeadingThrusterOn;
    static double    HeadingDirection;
    static double    HeadingThrust;
    static double    HeadingValue;

    static double    MarkThrottle;
    static bool      MarkThrusterOn;
    static double    MarkDirection;
    static double    MarkThrust;
    static double    MarkValue;


    static bool      ThrusterSync;

    static double    PitchThrottle;
    static double    PitchDirection;
    static bool      PitchThrusterOn;

    static double    YawThrottle;
    static int       YawDirection;
    static bool      YawThrusterOn;

    static double    RollThrottle;
    static double    RollDirection;
    static bool      RollThrusterOn;


    static QQuaternion RotationQuat;
    static QVector3D CartPosition;
    static QVector3D ShipTranslation;
    static QVector3D Heading;

    static double  Direction;
    static double  Mark;
    static double  Distance;

    static double  PitchThrust;
    static double  PitchAngle;

    static double  YawThrust;
    static double  YawAngle;

    static double  RollThrust;
    static double  RollAngle;

    static double  Angle;

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
