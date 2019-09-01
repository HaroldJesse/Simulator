#ifndef SPACESTATIONS_HPP
#define SPACESTATIONS_HPP

#include "SimGlobals.hpp"


class Spacestations : public Qt3DCore::QEntity
{  
public:
    explicit Spacestations(Qt3DCore::QNode *parent = 0);
    ~Spacestations();

    //Qt3DCore::QScaleTransform *scaleTransform() const;
    //Qt3DCore::QRotateTransform *xAxisRotateTransform() const;
    //Qt3DCore::QRotateTransform *yAxisRotateTransform() const;
    //Qt3DCore::QTranslateTransform *TranslateTransform() const;

private:
    //Qt3DCore::QMesh *SpacestationsMesh;
    Qt3DCore::QTransform *SpacestationsTransform;
    //Qt3DCore::QScaleTransform *SpacestationsScaleTransform;
    //Qt3DCore::QRotateTransform *SpacestationsxAxisRotation;
    //Qt3DCore::QRotateTransform *SpacestationsyAxisRotation;
    //Qt3DCore::QTranslateTransform *SpacestationsTranslateTransform;
};

#endif // SPACESTATIONS_HPP
