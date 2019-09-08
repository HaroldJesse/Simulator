#include "Stars.hpp"

Stars::Stars(Qt3DCore::QNode *parent)
    : QEntity(parent)
    , StarTransform (new Qt3DCore::QTransform())
    , StarMesh (new Qt3DRender::QSphereMesh())
    , StarPhong (new Qt3DRender::QPhongMaterial)
{
    StarMesh->setRings(10.0f);
    StarMesh->setSlices(10.0f);
    StarMesh->setRadius(.25f);

    StarPhong->setAmbient(Qt::white);

    addComponent(StarMesh);
    addComponent(StarTransform);
    addComponent(StarPhong);
}


void Stars::updateTransform()
{
    QMatrix4x4 m;
    m.translate(starposition);
    // m.rotate(m_phi, QVector3D(1.0f, 0.0f, 0.0f));
    //m.rotate(m_theta, QVector3D(0.0f, 0.0f, 1.0f));
    //m_transform->setMatrix(m);
}

/*
float Stars::theta() const
{
    return m_theta;
}

float Stars::phi() const
{
    return m_phi;
}
*/

QVector3D Stars::position() const
{
    return starposition;
}

/*
QColor Stars::diffuseColor() const
{
    return m_material->diffuse();
}

void Stars::setTheta(float theta)
{
    if (m_theta == theta)
        return;

    m_theta = theta;
    emit thetaChanged(theta);
    updateTransform();
}

void Stars::setPhi(float phi)
{
    if (m_phi == phi)
        return;

    m_phi = phi;
    emit phiChanged(phi);
    updateTransform();
}
*/
void Stars::setPosition(QVector3D position)
{
    if (starposition == position)
        return;

    starposition = position;
    //emit positionChanged(position);
    updateTransform();
}

/*
void Stars::setDiffuseColor(QColor diffuseColor)
{
    if (m_material->diffuse() == diffuseColor)
        return;

    m_material->setDiffuse(diffuseColor);
    emit diffuseColorChanged(diffuseColor);
}
*/
