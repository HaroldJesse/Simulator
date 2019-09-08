/*!
*/
#ifndef OBJANIMATION_HPP
#define OBJANIMATION_HPP

#include "SimGlobals.hpp"


class ObjAnimation : public Qt3DCore::QEntity
{
    Q_OBJECT
    Q_PROPERTY(float X READ X WRITE SetX NOTIFY XChanged)
    Q_PROPERTY(float Y READ Y WRITE SetY NOTIFY YChanged)
    Q_PROPERTY(float Z READ Z WRITE SetZ NOTIFY ZChanged)

public:
    explicit ObjAnimation(Qt3DCore::QNode *parent = 0);
    ~ObjAnimation();

    float Y();
    float X();
    float Z();

public slots:
    void SetY(float Y);
    void SetX(float X);
    void SetZ(float Z);

signals:
    void YChanged(float Y);
    void XChanged(float X);
    void ZChanged(float Z);

private:
    void UpdateTransform();

    float ObjY;
    float ObjX;
    float ObjZ;
};

#endif // OBJANIMATION_HPP
