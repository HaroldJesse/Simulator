#include "Julian.hpp"

Julian::Julian()
{

}


double Julian::JulianDateTime (void)
{
    QDoubleValidator Validate;
    Validate.setNotation (QDoubleValidator::StandardNotation);
    QDate Date;
    qint64 JulianDay = Date.currentDate ().toJulianDay ();
    //qDebug() << "Julian Day as integer: " << JulianDay;
    QTime Time;
    Time = Time.currentTime ();
    int Hours = Time.hour ();
    int Minutes = Time.minute ();
    int Seconds = Time.second ();
    int Fraction = (Hours *3600) + (Minutes * 60) + Seconds;
    //qDebug() << "Fraction: " << Fraction * .00001;
    //qDebug() << "Fractional Julian: " << JulianDay + (Fraction * .00001);

    return (double)JulianDay + Fraction;
}

double Julian::GetCurrentJulianDay (void)
{
    QDate Date;
    qint64 JulianDay = Date.currentDate ().toJulianDay ();
    double Julian = JulianDay;

    return (Julian);
}
