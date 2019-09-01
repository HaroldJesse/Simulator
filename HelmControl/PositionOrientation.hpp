#ifndef POSITIONORIENTATION_HPP
#define POSITIONORIENTATION_HPP

#include "SimGlobals.hpp"

namespace Ui {
class PositionOrientation;
}

class PositionOrientation : public QDialog
{
    Q_OBJECT

public:
    explicit PositionOrientation(QDialog *parent = 0);
    ~PositionOrientation();

    static QVector3D Orientation;
    static QVector3D Object;

    static double Distance;
    static double Heading;
    static double Mark;
    static double PitchAngle;
    static double YawAngle;
    static double RollAngle;

    static QSize Size;

private:
    Ui::PositionOrientation *ui;

    QTimer *Timer = new QTimer(this);

    double Dist;
    double Head;
    double Mk;
    double Pitch;
    double Yaw;
    double Roll;

private slots:
        void Exit (void);
        void MasterUpdate (void);

};

#endif // POSITIONORIENTATION_HPP
