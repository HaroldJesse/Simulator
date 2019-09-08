#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include <QVector3D>
#include <QtMath>

class Coordinate
{
public:
    Coordinate();

    QVector3D RaDec2Cart(QVector3D Sphere);
    QVector3D RaDec2Cart (double Ra, double Dec, double Distance);

    QVector3D Cart2Sphere (QVector3D Cartesian);
    QVector3D Cart2Sphere (int x ,int y, int z);
};

#endif // COORDINATE_HPP
