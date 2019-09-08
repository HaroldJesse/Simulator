#ifndef STARS_H
#define STARS_H

#include "SimGlobals.hpp"

class Stars : public Qt3DCore::QEntity
{
public:
    Stars(Qt3DCore::QNode *parent = 0);
    Qt3DRender::QSphereMesh *StarMesh;
    Qt3DCore::QTransform *StarTransform;
    Qt3DRender::QPhongMaterial *StarPhong;

    //float theta() const;
    //float phi() const;
    QVector3D position() const;
    //QColor diffuseColor() const;

public slots:
    //void setTheta(float theta);
    //void setPhi(float phi);
    void setPosition(QVector3D position);
    //void setDiffuseColor(QColor diffuseColor);

signals:
    //void thetaChanged(float theta);
    //void phiChanged(float phi);
    void positionChanged(QVector3D position);
    //void diffuseColorChanged(QColor diffuseColor);

private:
    void updateTransform();

    QVector3D starposition;


};

#endif // STARS_H
