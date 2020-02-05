/*!

    Copyright (C) 2020, the Sim Development Team

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

*/

#include "Initialize.hpp"

/*!
  \title Model Initializer

  The new simulator is used to provide.

*/

bool Initialize::Abort = false;

int Initialize::WindowHeight(0);
int Initialize::WindowWidth(0);

QString Initialize::StartupPath = QDir::currentPath();

Initialize::Initialize()
{
    //Window

    Initialize::StartupPath = QDir::currentPath();
    //qDebug() << "StartupPath: " << Initialize::StartupPath;



    Qt3DExtras::Qt3DWindow *View = new Qt3DExtras::Qt3DWindow();

    View->setFlag(Qt::FramelessWindowHint);
    View->defaultFrameGraph()->setClearColor(Qt::black);
    View->setVisibility(QWindow::FullScreen);
    View->setVisible(true);

    View->setSurfaceType(QSurface::OpenGLSurface);

    // Get desktop screen parameters
    QDesktopWidget DW;


    if (DW.screenCount() > 1)
    {
        //qDebug() << "Number of screens: " << DW.screenCount();
        int PrimaryScreen = DW.primaryScreen();
        QRect QR = DW.availableGeometry(PrimaryScreen);
        View->resize(QR.width(),QR.height());
    }

    else

    {
        //qDebug() << "Primary Screen Width and Height: " << DW.width() << DW.height();
        View->resize(DW.width(),DW.height());
    }

    QSurfaceFormat format;

    if (QOpenGLContext::openGLModuleType() == QOpenGLContext::LibGL)
    {
        format.setVersion(4, 3);
        format.setProfile(QSurfaceFormat::CoreProfile);
    }
    format.setDepthBufferSize( 24 );
    format.setSamples( 4 );
    format.setStencilBufferSize(8);
    View->setFormat(format);
    View->create();
    Initialize::WindowHeight = View->height();
    Initialize::WindowWidth = View->width();

    //qDebug() << "ID";
    IDCheck ID;
    ID.exec();
    //qDebug() << "Current Path ID: " << QDir::currentPath();

    if (IDCheck::Status == "Running")
    {
        Certificate Cert;
        Cert.exec();
    }

    if (IDCheck::Status == "Aborted")
    {

    }
    //qDebug() << "Current Path Certificate: " << QDir::currentPath();


    //qDebug() << "LogView";
    //Logs LogsView;
    //LogsView.Initialize();
    //LogsView.exec();



    //Reset from removable device path
    QDir::setCurrent(Initialize::StartupPath);



    if (IDCheck::Status == "Running" || IDCheck::Status == "Simulator")
    {
        //qDebug() << "Setup";
        Setup Set;
        Set.exec();
    }


    // Scene Root
    Qt3DCore::QEntity *SceneRoot = new Qt3DCore::QEntity();
    View->setRootEntity(SceneRoot);        //.setRootEntity(SceneRoot);

    // Scene Camera
    Qt3DRender::QCamera *BasicCamera = View->camera();
    BasicCamera->setProjectionType(Qt3DRender::QCameraLens::PerspectiveProjection);
    BasicCamera->setPosition(QVector3D(0.0, 0.0, 200.0));
    BasicCamera->setUpVector(QVector3D(0.0f, 1.0f, 0.0f));
    BasicCamera->setViewCenter(QVector3D(1.0f, 0.0f, 0.0f));
    BasicCamera->lens()->setPerspectiveProjection(60.0f, 16.0f/9.0f, 0.001f, 10000.0f);

    // For camera controls
    Qt3DExtras::QFirstPersonCameraController *CamController = new Qt3DExtras::QFirstPersonCameraController(SceneRoot);
    CamController->setCamera(BasicCamera);

    // Scene Lighting
    Qt3DCore::QEntity *LightEntity = new Qt3DCore::QEntity(SceneRoot);
    Qt3DRender::QSpotLight *Light = new Qt3DRender::QSpotLight(SceneRoot);
    Light->setColor (GType);   //Sun spectrum
    Light->setIntensity(1.0);

    Light->setCutOffAngle(90.0);
    QVector3D LightDirection = QVector3D(0.0, 0.0, 0.0);
    Light->setLocalDirection(LightDirection);

    LightEntity->addComponent(Light);

    Qt3DCore::QTransform *LightTransform = new Qt3DCore::QTransform(SceneRoot);
    LightTransform->setTranslation(QVector3D(0.0, 0.0, 0.0));

    LightEntity->addComponent(LightTransform);

    //qDebug() << "Initialize Abort: " << Initialize::Abort;
    if (Initialize::Abort == true)
    {
        View->close();
        return;
    }

    //System Objects

    Qt3DCore::QEntity *ObjectEntity = new Qt3DCore::QEntity(SceneRoot);

    //add Object Mesh
    Qt3DExtras::QSphereMesh *ObjectMesh = new Qt3DExtras::QSphereMesh();
    ObjectMesh->setSlices (72);
    ObjectMesh->setRings (72);
    ObjectMesh->setRadius(40);
    ObjectEntity->addComponent(ObjectMesh);

    // Add Object Transforms
    Qt3DCore::QTransform *ObjectTransforms = new Qt3DCore::QTransform();
    ObjectTransforms->setTranslation(QVector3D(0.0, 0.0, -100.0));
    ObjectTransforms->setRotationX(0.0f);
    ObjectTransforms->setRotationY(0.0f);
    ObjectTransforms->setRotationZ(0.0f);
    ObjectTransforms->setScale (1.0f);
    ObjectEntity->addComponent(ObjectTransforms);



    Qt3DRender::QTextureImage *ObjectTexture = new Qt3DRender::QTextureImage;
    QString ObjectTextureFile = Initialize::StartupPath + "/Data-Pak/Location/" + Setup::SimLocation +"/" + Setup::SimObject + "/" + Setup::SimObject + ".jpg";
    //qDebug() << "Object texture file: " << ObjectTextureFile;
    QString TargetObject = "file:" + ObjectTextureFile;
    QFile Image(ObjectTextureFile);

    //Check for texture photo
    if (Image.exists() == true)
    {
        ObjectTexture->setSource (QUrl(TargetObject));
    }

    else

    {
        QString ObjectTextureFile = Initialize::StartupPath + "/Data-Pak/Location/Bogus.jpg";
        QString TargetObject = "file:" + ObjectTextureFile;
        ObjectTexture->setSource (QUrl(TargetObject));
    }

    //Set material
    Qt3DExtras::QDiffuseMapMaterial *ObjectDiffuse = new Qt3DExtras::QDiffuseMapMaterial;
    ObjectDiffuse->setShininess (2.0);
    ObjectDiffuse->setSpecular (QColor::fromRgbF(0.2, 0.2, 0.2, 1.0));
    ObjectDiffuse->diffuse()->addTextureImage (ObjectTexture);

    ObjectEntity->addComponent(ObjectDiffuse);

    //add Object Animations
    QPropertyAnimation *ObjectAnim = new QPropertyAnimation (SceneRoot);
    //ObjectObj->setDuration (8640000);
    ObjectAnim->setDuration (20000);
    ObjectAnim->setStartValue(0.0f);
    ObjectAnim->setEndValue(360.0f);
    ObjectAnim->setLoopCount(-1);
    ObjectAnim->setDirection(QAbstractAnimation::Forward);
    ObjectAnim->setTargetObject(ObjectTransforms);
    ObjectAnim->setPropertyName ("rotationY");
    ObjectAnim->start ();

    //Stars

/*    QFile StarsDatabase ("Data/Stars.db");

    if(StarsDatabase.exists() == false)
    {
        QMessageBox msgBox;
        msgBox.setText("No star database was found so no stars will be shown.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        Verbalize->say(msgBox.text());
        msgBox.exec();
    }


    QSqlDatabase Stardb = QSqlDatabase::addDatabase ("QSQLITE","Starchart");
    Stardb.setDatabaseName("Data/Stars.db");

    if (Stardb.open() == false) //try to connect to the database
    {
        qApp->beep();
        QMessageBox::critical(0, qApp->tr("Can not connect to the Star database"),
            qApp->tr("Unable to establish a Star database connection.\n"));
    }
*/

/*
    //Setup for stars
    QSqlQuery query(Stardb);
    //query.exec("SELECT * FROM STARS WHERE MAG < 4.0");

    query.exec("SELECT * FROM STARS WHERE HIP LIKE '11767'"
               " or HIP LIKE '72607' or HIP LIKE '75097' or HIP LIKE '82080' or HIP LIKE '70692' or HIP LIKE '77055'"
               "or HIP LIKE '85822' or HIP LIKE '73199' or HIP LIKE '69112' or HIP LIKE '79822' or HIP LIKE '76008' or HIP LIKE '74793'");

    //qDebug() << "Last query: " << query.lastQuery ();

    if (query.lastError().isValid())
    {
        //qDebug() << "Error: " << query.lastError().text();
    }

    int count = 0;

    while (query.next())
    {

        Qt3DCore::QEntity *Star = new Qt3DCore::QEntity(SceneRoot);

        Qt3DExtras::QSphereMesh *Core = new Qt3DExtras::QSphereMesh();

        Core->setSlices (10);
        Core->setRings (10);
        Core->setRadius(10);

        Star->addComponent(Core);

        //Qt3DExtras:: QDiffuseSpecularMaterial *phongMaterial = new Qt3DExtras::QPhongMaterial();
        //phongMaterial->setDiffuse(QColor(204, 205, 75)); // Safari Yellow #cccd4b

        QString Spectrum = query.value("Spectrum").toString();
        QString ProperName = query.value("ProperName").toString();

        Spectrum.chop(Spectrum.size() -1);

        if (Spectrum == "O")
        {
            phongMaterial->setDiffuse(O);
        }

        if (Spectrum == "B")
        {
            phongMaterial->setDiffuse(B);
        }

        if (Spectrum == "A")
        {
            phongMaterial->setDiffuse(A);
        }

        if (Spectrum == "F")
        {
            phongMaterial->setDiffuse(F);
        }

        if (Spectrum == "G")
        {
            phongMaterial->setDiffuse(G);
        }

        if (Spectrum == "K")
        {
            phongMaterial->setDiffuse(K);
        }

        if (Spectrum == "M")
        {
            phongMaterial->setDiffuse(M);
        }

        if (ProperName == "Polaris")
        {
            phongMaterial->setDiffuse(Qt::red);
        }

        phongMaterial->setShininess(0);
        Star->addComponent(phongMaterial);

        Qt3DCore::QTransform *StarTransforms = new Qt3DCore::QTransform();
        StarTransforms->setScale (.25f);
        Star->addComponent(StarTransforms);


        //double Mag = query.value("Mag").toDouble();
        double Ra = query.value("RA").toDouble();
        double Dec = query.value("DEC").toDouble();
        //double X = query.value("X").toDouble();
        //double Y = query.value("Y").toDouble();
        //double Z = query.value("Z").toDouble();


        double Distance =100;
        //double Distance = query.value("Distance").toDouble();
        QString HIP = query.value("HIP").toString();
        //double Lum = query.value("Lum").toDouble();
        //double ColorIndex = query.value("ColorIndex").toDouble();

        //Polar to Cartesian conversion
        Coordinate Co;
        QVector3D Cart;
        QVector3D RaDec;

        Cart = Co.Coordinate::RaDec2Cart(Ra,Dec,Distance);
        //RaDec = Co.Cart2Sphere(Cart.x(), Cart.y(), Cart.z());

        //Cart = Co.Coordinate::RaDec2Cart(RaDec);
        //RaDec = Co.Cart2Sphere(Cart);

        //qDebug() << "Cart: " << Cart;

        count ++;
        QVector3D Position;
    }

*/


/*

        x,y,z: The Cartesian coordinates of the star, in a system based on the equatorial coordinates as seen from Object.
        +X is in the direction of the vernal equinox (at epoch 2000), +Z towards the north celestial pole,
        and +Y in the direction of R.A. 6 hours, declination 0 degrees.

        Position.setX(Cart.x());
        Position.setY(Cart.y());
        Position.setZ(Cart.z());

        //qDebug() << "Position: " << Position;

        StarTransforms->setTranslation(Position);


        //qDebug() << "RA: " << RA;
        //qDebug() << "DEC: " << DEC;
        //qDebug() << "Distance: " << Distance;

        //qDebug() << "XYZ: " << XYZ;

        //qDebug() << "Ra: " << Ra << "Dec: " << Dec<< "Distance: " << Distance;
        //qDebug() << "X:" << X << "Y: " << Y << "Z:" << Z;
        //qDebug() << "Cart: " << "X: " << Cart.x() << "Y: " << Cart.y() << "Z: " << Cart.z();
        //qDebug() << "Sphere: " << "Ra: " << Sphere.x() << "Dec: " << Sphere.y() << "Distance: " << Sphere.z();
        //qDebug() << "Mag: " << Mag;
        //qDebug() << "Luminosity: " << Lum;
        //qDebug() << "ColorIndex: " << ColorIndex;
        //qDebug() << "Spectrum: " << Spectrum;
        //qDebug() << "ProperName: " << ProperName;
        //qDebug() << "HIP: " << HIP;
        //qDebug() << "Polar Cordinates: " << Polar;
        //qDebug() << "Count: " << count;

    }
*/

/*  playlist = new QMediaPlaylist;
    // playlist->load(QUrl("file://Audio/Thruster.ogg");
    //playlist->addMedia(QUrl("file://Audio/Thruster.ogg");
    playlist->setCurrentIndex(1);
    //playlist->p
*/
    //if (Setup::SimType == "Simulation" && Setup::SimBranch == "SpaceCraft")


/*
    if (Setup::SimType == "Simulation")
    {
        CraftControls *Craft = new CraftControls(BasicCamera);
        Craft->exec();
    }
*/
    if (Setup::SimType == "Training")
    {
        SimulatorControls *Sim = new SimulatorControls();
        Sim->exec();
    }

    View->close();

    return;

}

Initialize::~Initialize()
{

}


