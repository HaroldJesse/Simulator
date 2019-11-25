//#pragma once
#ifndef JULIAN_HPP
#define JULIAN_HPP
//#endif // JULIAN_HPP

#include <QDate>
#include <QTime>
#include <QAbstractActionInput>
#include <QDoubleValidator>


class Julian
{
public:
    Julian();
    double JulianDateTime (void);
    double GetCurrentJulianDay (void);
};

#endif // JULIAN_HPP
