//#pragma once
#ifndef SIMCONSTANTS_HPP
#define SIMCONSTANTS_HPP
//#endif // SIMCONSTANTS_HPP

#include <QColor>
class SimConstants
{
public:
    SimConstants();

    static const quint32 LightSpeed = 299792458;  // meters/sec
    static const quint32 LightMicroSecond = 300; //meters
    static const quint32 LightMilliSecond = 299792; // meters
    static const quint32 LightSecond = 299792458; // meters
    static const quint64 LightMinute = LightSecond * 60; //
    static const quint32 LightHour = LightSecond * 3600;
    static const quint32 LightDay = LightSecond * 86400;
    static const quint32 LightYear = LightSecond* 30815550; // based on 364.25 days

    static const quint64 HalfStandardSolarMass = 1000000000000; // is equal to 10^12 Kilograms
    static const quint64 StandardSolarMass = 1; // is equal to 10^24 Kilograms
    static const quint64 Volume  = 1; // is equal to 10^10 km^3;
    static const quint64 MeanDensity = 1; //kg/m^3

    //Star spectrum colors
    QColor OType = QColor(155,176,255);
    QColor BType = QColor(170,191,255);
    QColor AType = QColor(202,215,255);
    QColor FType = QColor(248,247,255);
    QColor GType = QColor(255,244,234);
    QColor KType = QColor(255,210,161);
    QColor MType = QColor(255,204,111);
};

#endif // SIMCONSTANTS_HPP
