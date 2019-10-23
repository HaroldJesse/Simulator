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

/*
    //Bullet
    /// collision configuration contains default setup for memory , collision setup . Advanced users can create their own configuration .
    ///
    btDefaultCollisionConfiguration * collisionConfiguration = new btDefaultCollisionConfiguration ();
    /// use the default collision dispatcher . For parallel processing you can use a different dispatcher (see Extras / BulletMultiThreaded )
    btCollisionDispatcher * dispatcher = new btCollisionDispatcher ( collisionConfiguration );

    /// btDbvtBroadphase is a good general purpose broadphase . You can also try out btAxis3Sweep .
    btBroadphaseInterface * overlappingPairCache = new btDbvtBroadphase ();

    /// the default constraint solver . For parallel processing you can use a different solver(see Extras / BulletMultiThreaded )
    btSequentialImpulseConstraintSolver * solver = new btSequentialImpulseConstraintSolver ;

    btDiscreteDynamicsWorld * dynamicsWorld = new btDiscreteDynamicsWorld ( dispatcher ,
    overlappingPairCache ,solver , collisionConfiguration );

    dynamicsWorld -> setGravity ( btVector3 (0 , -10 ,0));
*/
    //CSpice

    //SpiceDouble Half = halfpi_c ();
    //furnsh_c ("Data/de421.bsp");
    //qDebug() << "Pi/2: " << Half;

    //Start Initialization

    //LogView.WriteLog(LogView.MasterLog,LogView.Info,"Main","Logging is on");

    //LogView.ReadLog(LogView.MasterLog);
    //LogView.exec();

    //Window

    Initialize::StartupPath = QDir::currentPath();

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


    Certificate Cert;
    Cert.exec();

    //qDebug() << "Current Path Certificate: " << QDir::currentPath();


    //qDebug() << "LogView";
    //Log LogView;
    //LogView.Initialize();

    //qDebug() << "Current Path Log: " << QDir::currentPath();

    //Reset from removable device path
    QDir::setCurrent(Initialize::StartupPath);

    //qDebug() << "Setup";
    Setup Set;
    Set.exec();

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
    QString ObjectTextureFile = "Location/" + Setup::SimLocation +"/" + Setup::SimObject + ".jpg";
    //qDebug() << "Location folder" << ObjectTextureFile;
    QString TargetObject = "file:" + ObjectTextureFile;
    QFile Image(ObjectTextureFile);

    //qDebug() << "Texture file:" << ObjectTextureFile;

    //Check for texture photo
    if (Image.exists() == true)
    {
        ObjectTexture->setSource (QUrl(TargetObject));
    }

    else

    {
        QString ObjectTextureFile = "Location/Bogus.jpg";
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


/*
    //SpaceStation
    //qDebug() << "SpaceStation";

    Qt3DCore::QEntity *SpacestationEntity = new Qt3DCore::QEntity(SceneRoot);

    //add Spacestation Mesh
    Qt3DExtras::QTorusMesh *SpaceStation = new Qt3DExtras::QTorusMesh();
    SpaceStation->setRadius(100);
    SpaceStation->setMinorRadius(20);
    SpaceStation->setRings(72);
    SpaceStation ->setSlices(40);
    SpacestationEntity->addComponent(SpaceStation);

    //add SpaceStation Transforms
    Qt3DCore::QTransform *SpaceStationTransforms = new Qt3DCore::QTransform();
    SpaceStationTransforms->setTranslation(QVector3D(0.0f, 0.0f, -50.0f));
    SpaceStationTransforms->setRotationX(90.0f);
    SpaceStationTransforms->setScale (0.05f);
    SpacestationEntity->addComponent(SpaceStationTransforms);

    //add SpaceStation Texture
    Qt3DRender::QTextureImage *SpaceStationTexture = new Qt3DRender::QTextureImage;
    Setup::SimObject = "Moon";
    QString StationTextureFile = "Location/" + Setup::SimLocation + "/" + Setup::SimObject + ".jpg";
    QString StationObject = "file:" + StationTextureFile;


    SpaceStationTexture->setSource (QUrl(StationObject));

    Qt3DExtras::QDiffuseMapMaterial *SpaceStationDiffuse = new Qt3DExtras::QDiffuseMapMaterial;
    SpaceStationDiffuse->setShininess (2.0);
    SpaceStationDiffuse->setSpecular (QColor::fromRgbF(0.2, 0.2, 0.2, 1.0));
    SpaceStationDiffuse->diffuse ()->addTextureImage (SpaceStationTexture);
    SpacestationEntity->addComponent(SpaceStationDiffuse);

    //add SpaceStation Animation
    QPropertyAnimation *SpaceStationAnim = new QPropertyAnimation (SceneRoot);
    SpaceStationAnim->setDuration (20000);
    SpaceStationAnim->setStartValue(0.0f);
    SpaceStationAnim->setEndValue(360.0f);
    SpaceStationAnim->setLoopCount(-1);
    SpaceStationAnim->setDirection(QAbstractAnimation::Forward);
    SpaceStationAnim->setTargetObject(SpaceStationTransforms);
    SpaceStationAnim->setPropertyName ("rotationY");
    SpaceStationAnim->start ();

    //Moon
    //qDebug() << "Moon";

    Qt3DCore::QEntity *MoonEntity = new Qt3DCore::QEntity(SceneRoot);

    //Moon shape data
    Qt3DExtras::QSphereMesh *MoonMesh = new Qt3DExtras::QSphereMesh();
    MoonMesh->setSlices (72);
    MoonMesh->setRings (72);
    MoonMesh->setRadius(40);
    MoonEntity->addComponent(MoonMesh);

    // Add Moon Transforms
    Qt3DCore::QTransform *MoonTransforms = new Qt3DCore::QTransform();
    MoonTransforms->setTranslation(QVector3D(100.0f, 0.0f, -100.0f));
    MoonTransforms->setRotationX(180.0f);
    MoonTransforms->setRotationY(0.0f);
    MoonTransforms->setRotationZ(0.0f);
    MoonTransforms->setScale (0.123f);
    MoonEntity->addComponent(MoonTransforms);

    Qt3DRender::QTextureImage *MoonTexture = new Qt3DRender::QTextureImage;
    Setup::SimObject = "Moon";
    QString MoonTextureFile = "Location/" + Setup::SimLocation + "/" + Setup::SimObject + ".jpg";
    QString MoonObject = "file:" + MoonTextureFile;

    MoonTexture->setSource (QUrl(MoonObject));
    Qt3DExtras::QDiffuseMapMaterial *MoonDiffuse = new Qt3DExtras::QDiffuseMapMaterial;
    MoonDiffuse->setShininess (2.0);
    MoonDiffuse->setSpecular (QColor::fromRgbF(0.2, 0.2, 0.2, 1.0));
    MoonDiffuse->diffuse ()->addTextureImage (MoonTexture);
    MoonEntity->addComponent(MoonDiffuse);

    //add Moon Animations
    QPropertyAnimation *MoonAnim = new QPropertyAnimation (SceneRoot);
    //ObjectObj->setDuration (8640000);
    MoonAnim->setDuration (2000);
    MoonAnim->setStartValue(0.0f);
    MoonAnim->setEndValue(360.0f);
    MoonAnim->setLoopCount(-1);
    MoonAnim->setDirection(QAbstractAnimation::Forward);
    MoonAnim->setTargetObject(MoonTransforms);
    MoonAnim->setPropertyName ("rotationY");
    MoonAnim->start (); //needed for tidal locking

    // SpaceCraft
    //qDebug() << "SpaceCraft";

    //connect(SceneLoader, SIGNAL(statusChanged()), this, SLOT(OnStatusChanged()));
    // Scene loader

    SceneLoaderEntity = new Qt3DCore::QEntity(SceneRoot);
    SceneLoader = new Qt3DRender::QSceneLoader(SceneLoaderEntity);

    SceneLoaderEntity->addComponent(SceneLoader);

    //Break down scene components

    //Object Transforms

    Qt3DCore::QTransform *CraftTransforms = new Qt3DCore::QTransform();
    CraftTransforms->setTranslation(QVector3D(-100.0f, 0.0f, -100.0f));
    CraftTransforms->setRotationX(0.0f);
    CraftTransforms->setScale (1.0f);
    SceneLoaderEntity->addComponent(CraftTransforms);

    QDir Dir;
    QString directory = Dir.currentPath();
    //qDebug() << "Current directory: " << directory;
    QUrl SourceFileName;

    qDebug() << "Before: " << Setup::SimObject;
    Setup::SimLocation = "SpaceCraft";
    Setup::SimObject = "Enterprise";

    SourceFileName = "file:" + "Location/Object/" + Setup::SimLocation + "/" + Setup::SimObject + "/" + Setup::SimObject + ".obj";
    //SourceFileName = "file:///" + directory +  "/" + "Objects/SpaceCraft/Enterprise/Enterprise.obj";
    //SourceFileName = "file:///" + directory +  "/" + "Objects/SpaceCraft/Spider/Spider.obj";
    //SourceFileName = "file:///" + directory +  "/" + "Objects/SpaceCraft/Spider/Enterprise.obj";
    //qDebug() << "sourcefilename: " << SourceFileName;

    SceneLoader->setSource(QUrl(SourceFileName));

    //Qt3DRender::QTextureImage *ShipTexture = new Qt3DRender::QTextureImage;
    //ShipTexture->setSource (QUrl(QStringLiteral("file:Objects/Moon.webp")));

    Qt3DExtras::QDiffuseMapMaterial *ShipDiffuse = new Qt3DExtras::QDiffuseMapMaterial;
    ShipDiffuse->setShininess (2.0);
    ShipDiffuse->setSpecular (QColor::fromRgbF(0.2, 0.2, 0.2, 1.0));
    //ShipDiffuse->diffuse ()->addTextureImage (ShipTexture);
    SceneLoaderEntity->addComponent(ShipDiffuse);

*/


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
        qDebug() << "Error: " << query.lastError().text();
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



    if (Setup::SimType == "Simulation")
    {
        CraftControls *Craft = new CraftControls(BasicCamera);
        Craft->exec();
    }

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

/*
void Initialize::OnStatusChanged()
{
    //qDebug() << "Status changed:" << SceneLoader->status();
    if (SceneLoader->status() != Qt3DRender::QSceneLoader::Ready)
        return;

    // The QSceneLoader instance is a component of an entity. The loaded scene
    // tree is added under this entity.
    QVector<Qt3DCore::QEntity *> entities = SceneLoader->entities();

    // Technically there could be multiple entities referencing the scene loader
    // but sharing is discouraged, and in our case there will be one anyhow.
    if (entities.isEmpty())
        return;
    Qt3DCore::QEntity *root = entities[0];

    // Print the tree.
    //walkEntity(root);

    // To access a given node (like a named mesh in the scene), use QObject::findChild().
    // The scene structure and names always depend on the asset.
    Qt3DCore::QEntity *e = root->findChild<Qt3DCore::QEntity *>(QStringLiteral("PlanePropeller_mesh")); // toyplane.obj
    if (e)
        qDebug() << "Found propeller node" << e << "with components" << e->components();
}

*/


/*
 *
void Initialize::WalkEntity(Qt3DCore::QEntity *e, int depth)
{
    Qt3DCore::QNodeVector nodes = e->childNodes();
    for (int i = 0; i < nodes.count(); ++i) {
        Qt3DCore::QNode *node = nodes[i];
        Qt3DCore::QEntity *entity = qobject_cast<Qt3DCore::QEntity *>(node);
        if (entity) {
            QString indent;
            indent.fill(' ', depth * 2);
            qDebug().noquote() << indent << "Entity:" << entity << "Components:" << entity->components();
            WalkEntity(entity, depth + 1);
        }
    }
}

*/
