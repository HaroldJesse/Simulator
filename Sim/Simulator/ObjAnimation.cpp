#include "ObjAnimation.hpp"

ObjAnimation::ObjAnimation(Qt3DCore::QNode *parent): QEntity(parent)

{

}
ObjAnimation::~ObjAnimation()
{
}

void ObjAnimation::UpdateTransform()
{
    QMatrix4x4 m;
    m.rotate(ObjX, QVector3D(1.0f, 0.0f, 0.0f));
    m.rotate(ObjY, QVector3D(0.0f, 0.0f, 1.0f));
    m.rotate(ObjZ, QVector3D(0.0f, 1.0f, 0.0f));
}

float ObjAnimation::Y()
{
    return ObjY;
}

float ObjAnimation::X()
{
    return ObjX;
}

float ObjAnimation::Z()
{
    return ObjZ;
}

void ObjAnimation::SetX(float X)
{
    if (ObjX == X)
        return;

    ObjX = X;
    emit XChanged(X);
    UpdateTransform();
}

void ObjAnimation::SetY(float Y)
{
    if (ObjY == Y)
        return;

    ObjY = Y;
    emit YChanged(Y);
    UpdateTransform();
}

void ObjAnimation::SetZ(float Z)
{
    if (ObjZ == Z)
        return;

    ObjZ = Z;
    emit ZChanged(Z);
    UpdateTransform();
}
