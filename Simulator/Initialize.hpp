#ifndef INITIALIZE_HPP
#define INITIALIZE_HPP

#include <QDir>
#include <iostream>
#include <QDialog>
#include <QString>
#include <Qt3DCore>
#include <Qt3DRender>
#include <QMediaPlaylist>
#include <QNormalDiffuseMapMaterial>
#include <QTextToSpeech>
#include <QDesktopWidget>
#include <QtTextToSpeech>

#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QFirstPersonCameraController>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QTorusMesh>
#include <Qt3DExtras/QDiffuseMapMaterial>

#include "SimConstants.hpp"
#include "SimulatorControls.hpp"
#include "IDCheck.hpp"
#include "Certificate.hpp"
#include "Logs.hpp"
#include "Setup.hpp"
#include "CraftControls.hpp"

class Initialize : public Qt3DCore::QEntity

{
        Q_OBJECT
        //Q_PROPERTY(QVector3D Position READ Position WRITE SetPosition NOTIFY PositionChanged)
public:
    explicit Initialize(void);

    ~Initialize();

    static QString StartupPath;

    static double PlanetRotationX;
    static double PlanetRotationY;
    static double PlanetRotationZ;

    static int WindowHeight;
    static int WindowWidth;

    static bool Abort;

    void OnStatusChanged();
    void WalkEntity(Qt3DCore::QEntity *e, int Depth);

private:

    QColor OType = QColor(155,176,255);
    QColor BType = QColor(170,191,255);
    QColor AType = QColor(202,215,255);
    QColor FType = QColor(248,247,255);
    QColor GType = QColor(255,244,234);
    QColor KType = QColor(255,210,161);
    QColor MType = QColor(255,204,111);

    Qt3DCore::QEntity *SceneRoot;
    Qt3DCore::QEntity *SceneLoaderEntity;
    Qt3DRender::QSceneLoader *SceneLoader;
    QMediaPlaylist *playlist;
    QTextToSpeech *Verbalize = new QTextToSpeech;

signals:

public slots:

};

#endif // INITIALIZE_HPP


/*
public:
    SceneWalker(Qt3DRender::QSceneLoader *loader) : m_loader(loader) { }

    void onStatusChanged();

private:
    void walkEntity(Qt3DCore::QEntity *e, int depth = 0);

    Qt3DRender::QSceneLoader *m_loader;
*/
