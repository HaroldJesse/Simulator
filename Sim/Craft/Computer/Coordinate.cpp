#include "Coordinate.hpp"

Coordinate::Coordinate()
{

}

QVector3D Coordinate::RaDec2Cart (double Ra, double Dec,double Distance)
{
    Ra = Ra * 15;
    Ra = qDegreesToRadians(Ra);
    Dec = qDegreesToRadians(Dec);

    //qDebug() << "RaDecDist: " << Ra << Dec << Distance;

    double x = Distance * qCos (Ra) * qSin(Dec);
    double y = Distance * qSin (Ra) * qSin(Dec);
    double z = Distance * qCos (Dec);
/*
    if (x <= 0.00009f)
    {
        if (x >= -0.00009f)
        {
            x = 0;
        }
    }

    if (x >= 0.9999f)
    {
        x = 1;
    }

    if (y <= 0.00009f)
    {
        if (y >= -0.00009f)
        {
            y = 0;
        }
    }

    if (y >= 0.9999f)
    {
        y = 1;
    }

    if (z <= 0.00009f)
    {
        if (z >= -0.00009f)
        {
            z = 0;
        }
    }

    if (z >= 0.9999f)
    {
        z = 1;
    }
*/
    //qDebug() << "Cart int Ra " << qRadiansToDegrees(Ra) << qRadiansToDegrees(Dec) << Distance;
    //qDebug() << "Cart int: " << x << y << z;
    return QVector3D(x,y,z);
}

QVector3D Coordinate::RaDec2Cart (QVector3D Sphere)
{
    int Ra =  qDegreesToRadians (Sphere.x());
    int Dec = qDegreesToRadians(Sphere.y());
    int Distance = Sphere.z();

    int x = Distance * qCos (Ra) * qSin(Dec);
    int y = Distance * qSin (Ra) * qSin(Dec);
    int z = Distance * qCos (Dec);

    if (x <= 0.00009f)
    {
        if (x >= -0.00009f)
        {
            x = 0;
        }
    }

    if (x >= 0.9999f)
    {
        x = 1;
    }

    if (y <= 0.00009f)
    {
        if (y >= -0.00009f)
        {
            y = 0;
        }
    }

    if (y >= 0.9999f)
    {
        y = 1;
    }

    if (z <= 0.00009f)
    {
        if (z >= -0.00009f)
        {
            z = 0;
        }
    }

    if (z >= 0.9999f)
    {
        z = 1;
    }

    //qDebug() << "Cart QVector: " << x << y << z;
    return QVector3D(x,y,z);
}



QVector3D Coordinate::Cart2Sphere (int x, int y, int z)
{
    int Distance = qSqrt((x * x) + (y * y) + (z * z));

    //azimuth = atan2(y,x)
    double Ra = atan2(y, x);

    //elevation = atan2(z,sqrt(x.^2 + y.^2))
    double Dec = atan2(sqrt((x * x) + (y * y)), z);

    Ra =  qRadiansToDegrees(Ra);
    Dec = qRadiansToDegrees(Dec);

    //qDebug() << "Sphere int xyz: " << x << y << z ;
    //qDebug() << "Sphere int: " << Ra << Dec << Distance;
    return QVector3D (Ra,Dec,Distance);
}

QVector3D Coordinate::Cart2Sphere (QVector3D Cartesian)
{
    int Distance = qSqrt((Cartesian.x() * Cartesian.x()) + (Cartesian.y() * Cartesian.y()) + (Cartesian.z() * Cartesian.z()));

    //azimuth = atan2(y,x)
    int Ra = qAtan2(Cartesian.y (), Cartesian.x ());

    //elevation = atan2(z,sqrt(x.^2 + y.^2))
    int Dec = qAtan2(sqrt((Cartesian.x()* Cartesian.x()) + (Cartesian.y () * Cartesian.y ())), Cartesian.z());

    Ra = Ra * 57.30;
    Dec = Dec * 57.30;

    //qDebug() << "Sphere QVector: " << Ra << Dec << Distance;
    return QVector3D (Ra,Dec,Distance);
}



