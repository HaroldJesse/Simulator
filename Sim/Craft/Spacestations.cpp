#include "Spacestations.hpp"
#include "ObjectLoader.hpp"

Spacestations::Spacestations(Qt3DCore::QNode *parent)
    : Qt3DCore::QEntity(parent)
    //, SpacestationsMesh(new Qt3DCore::QMesh())
    , SpacestationsTransform(new Qt3DCore::QTransform())
    //, SpacestationsScaleTransform(new Qt3DCore::QScaleTransform())
    //, SpacestationsxAxisRotation(new Qt3DCore::QRotateTransform())
    //, SpacestationsyAxisRotation(new Qt3DCore::QRotateTransform())
    //, SpacestationsTranslateTransform(new Qt3DCore::QTranslateTransform())

{
    //Torus mesh generation
    Qt3DRender::QTorusMesh *Torus = new Qt3DRender::QTorusMesh;
    Torus->setMinorRadius (2);
    Torus->setRadius (10);
    Torus->setRings (75);

    // TorusMesh Transforms
    //Qt3DCore::QScaleTransform *TorusScale = new Qt3DCore::QScaleTransform();
    //Qt3DCore::QRotateTransform *TorusRotation = new Qt3DCore::QRotateTransform();
    Qt3DCore::QTransform *TorusTransforms = new Qt3DCore::QTransform();
    //Qt3DCore::QTranslateTransform *TorusTranslateTransforms = new Qt3DCore::QTranslateTransform();

    //TorusScale->setScale(1.0f);
    //TorusRotation->setAngleDeg(90.0f);
    //TorusRotation->setAxis(QVector3D(1, 0, 0));
    //TorusTranslateTransforms->setDx (0.0);
    //TorusTranslateTransforms->setDy (0.0);
    //TorusTranslateTransforms->setDz (-32.0);

    //TorusTransforms->addTransform(TorusScale);
    //TorusTransforms->addTransform(TorusRotation);
    //TorusTransforms->addTransform(TorusTranslateTransforms);



    Qt3DRender::QDiffuseMapMaterial *DiffuseMapMaterial = new Qt3DRender::QDiffuseMapMaterial();
    DiffuseMapMaterial->setSpecular(QColor::fromRgbF(0.2f, 0.2f, 0.2f, 1.0f));
    DiffuseMapMaterial->setShininess(2.0f);

    Qt3DRender::QTextureImage *DiffuseImage = new Qt3DRender::QTextureImage();
    DiffuseImage->setSource(QUrl(QStringLiteral("file:SpaceStation.webp")));
    DiffuseMapMaterial->diffuse()->addTextureImage(DiffuseImage);

    // Torus
    Qt3DCore::QEntity *TorusEntity = new Qt3DCore::QEntity(parent);

    TorusEntity->addComponent(Torus);
    TorusEntity->addComponent(TorusTransforms);
    TorusEntity->addComponent(DiffuseMapMaterial);

    //addComponent(planetmesh);
    addComponent(SpacestationsTransform);
    addComponent(DiffuseMapMaterial);

}

Spacestations::~Spacestations()
{
}

