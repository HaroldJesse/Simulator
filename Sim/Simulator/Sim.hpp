#ifndef SIM_HPP
#define SIM_HPP

class Sim
{
public:
    Sim();
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
};

#endif // SIM_HPP
