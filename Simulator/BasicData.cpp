#include "BasicData.hpp"
#include "ui_BasicData.h"

QString BasicData::Choice = "None";

BasicData::BasicData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BasicData)

{
    ui->setupUi(this);



    int Width = this->width();
    int Height = this->height();
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->move(Initialize::WindowWidth - Width  ,Initialize::WindowHeight - Height - 175);

    Basic();

}

BasicData::~BasicData()
{
    delete ui;
}


void BasicData::ClearAll (void)
{
    ui->Val0->setStyleSheet("color: rgb(255,255,255)");
    ui->Val0->clear();

    ui->Lbl1->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl1->clear();
    ui->Val1->setStyleSheet("color: rgb(255,255,255)");
    ui->Val1->clear();
    ui->UM1->setStyleSheet("color: rgb(255,255,255)");
    ui->UM1->clear();

    ui->Lbl2->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl2->clear();
    ui->Val2->setStyleSheet("color: rgb(255,255,255)");
    ui->Val2->clear();
    ui->UM2->setStyleSheet("color: rgb(255,255,255)");
    ui->UM2->clear();

    ui->Val3->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl3->clear();
    ui->Val3->setStyleSheet("color: rgb(255,255,255)");
    ui->Val3->clear();
    ui->UM3->setStyleSheet("color: rgb(255,255,255)");
    ui->UM3->clear();

    ui->Lbl4->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl4->clear();
    ui->Val4->setStyleSheet("color: rgb(255,255,255)");
    ui->Val4->clear();
    ui->UM4->setStyleSheet("color: rgb(255,255,255)");
    ui->UM4->clear();


    ui->Lbl5->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl5->clear();
    ui->Val5->setStyleSheet("color: rgb(255,255,255)");
    ui->Val5->clear();
    ui->UM5->setStyleSheet("color: rgb(255,255,255)");
    ui->UM5->clear();

    ui->Lbl6->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl6->clear();
    ui->Val6->setStyleSheet("color: rgb(255,255,255)");
    ui->Val6->clear();
    ui->UM6->setStyleSheet("color: rgb(255,255,255)");
    ui->UM6->clear();

    ui->Lbl7->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl7->clear();
    ui->Val7->setStyleSheet("color: rgb(255,255,255)");
    ui->Val7->clear();
    ui->UM7->setStyleSheet("color: rgb(255,255,255)");
    ui->UM7->clear();

    ui->Lbl8->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl8->clear();
    ui->Val8->setStyleSheet("color: rgb(255,255,255)");
    ui->Val8->clear();
    ui->UM8->setStyleSheet("color: rgb(255,255,255)");
    ui->UM8->clear();

    ui->Lbl9->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl9->clear();
    ui->Val9->setStyleSheet("color: rgb(255,255,255)");
    ui->Val9->clear();
    ui->UM9->setStyleSheet("color: rgb(255,255,255)");
    ui->UM9->clear();

    ui->Lbl10->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl10->clear();
    ui->Val10->setStyleSheet("color: rgb(255,255,255)");
    ui->Val10->clear();
    ui->UM10->setStyleSheet("color: rgb(255,255,255)");
    ui->UM10->clear();

    ui->Lbl11->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl11->clear();
    ui->Val11->setStyleSheet("color: rgb(255,255,255)");
    ui->Val11->clear();
    ui->UM11->setStyleSheet("color: rgb(255,255,255)");
    ui->UM11->clear();

    ui->Lbl12->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl12->clear();
    ui->Val12->setStyleSheet("color: rgb(255,255,255)");
    ui->Val12->clear();
    ui->UM12->setStyleSheet("color: rgb(255,255,255)");
    ui->UM12->clear();

    ui->Lbl13->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl13->clear();
    ui->Val13->setStyleSheet("color: rgb(255,255,255)");
    ui->Val13->clear();
    ui->UM13->setStyleSheet("color: rgb(255,255,255)");
    ui->UM13->clear();

    ui->Lbl14->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl14->clear();
    ui->Val14->setStyleSheet("color: rgb(255,255,255)");
    ui->Val14->clear();
    ui->UM14->setStyleSheet("color: rgb(255,255,255)");
    ui->UM14->clear();

    ui->Lbl15->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl15->clear();
    ui->Val15->setStyleSheet("color: rgb(255,255,255)");
    ui->Val15->clear();
    ui->UM15->setStyleSheet("color: rgb(255,255,255)");
    ui->UM15->clear();

    ui->Lbl16->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl16->clear();
    ui->Val16->setStyleSheet("color: rgb(255,255,255)");
    ui->Val16->clear();
    ui->UM16->setStyleSheet("color: rgb(255,255,255)");
    ui->UM16->clear();

    ui->Lbl17->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl17->clear();
    ui->Val17->setStyleSheet("color: rgb(255,255,255)");
    ui->Val17->clear();
    ui->UM17->setStyleSheet("color: rgb(255,255,255)");
    ui->UM17->clear();

    ui->Lbl18->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl18->clear();
    ui->Val18->setStyleSheet("color: rgb(255,255,255)");
    ui->Val18->clear();
    ui->UM18->setStyleSheet("color: rgb(255,255,255)");
    ui->UM18->clear();

    ui->Lbl19->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl19->clear();
    ui->Val19->setStyleSheet("color: rgb(255,255,255)");
    ui->Val19->clear();
    ui->UM19->setStyleSheet("color: rgb(255,255,255)");
    ui->UM19->clear();

    ui->Lbl20->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl20->clear();
    ui->Val20->setStyleSheet("color: rgb(255,255,255)");
    ui->Val20->clear();
    ui->UM20->setStyleSheet("color: rgb(255,255,255)");
    ui->UM20->clear();

    ui->Lbl21->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl21->clear();
    ui->Val21->setStyleSheet("color: rgb(255,255,255)");
    ui->Val21->clear();
    ui->UM21->setStyleSheet("color: rgb(255,255,255)");
    ui->UM21->clear();

    ui->Lbl22->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl22->clear();
    ui->Val22->setStyleSheet("color: rgb(255,255,255)");
    ui->Val22->clear();
    ui->UM22->setStyleSheet("color: rgb(255,255,255)");
    ui->UM22->clear();

    ui->Lbl23->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl23->clear();
    ui->Val23->setStyleSheet("color: rgb(255,255,255)");
    ui->Val23->clear();
    ui->UM23->setStyleSheet("color: rgb(255,255,255)");
    ui->UM23->clear();

    ui->Lbl24->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl24->clear();
    ui->Val24->setStyleSheet("color: rgb(255,255,255)");
    ui->Val24->clear();
    ui->UM24->setStyleSheet("color: rgb(255,255,255)");
    ui->UM24->clear();

    ui->Lbl25->setStyleSheet("color: rgb(255,255,255)");
    ui->Lbl25->clear();
    ui->Val25->setStyleSheet("color: rgb(255,255,255)");
    ui->Val25->clear();
    ui->UM25->setStyleSheet("color: rgb(255,255,255)");
    ui->UM25->clear();


}
void BasicData::Basic()
{
    ClearAll();

    ui->Val0->setText("Basic Data");

    ui->Lbl1->setText("NasaNumber");
    ui->Lbl2->setText("Nasa Name");
    ui->Lbl3->setText("Mass");
    ui->Lbl4->setText("Volume");
    ui->Lbl5->setText("Equatorial Radius");
    ui->Lbl6->setText("Polar Radius");
    ui->Lbl7->setText("Vol Mean Radius");
    ui->Lbl8->setText("Core Radius");
    ui->Lbl9->setText("Ellipticity");
    ui->Lbl10->setText("Mean Density");
    ui->Lbl11->setText("Surface Gravity");
    ui->Lbl12->setText("Surface Acceleration");
    ui->Lbl13->setText("Escape Velocity");
    ui->Lbl14->setText("GM");
    ui->Lbl15->setText("Albedo");
    ui->Lbl16->setText("Magnitude");
    ui->Lbl17->setText("Irradiance");
    ui->Lbl18->setText("Black Body Temp");
    ui->Lbl19->setText("Moment Inertia");
    ui->Lbl20->setText("J2");
    ui->Lbl21->setText("Number of Moons");
    ui->Lbl22->setText("Number of Rings");
    ui->Lbl23->setText("");
    ui->Lbl24->setText("");
    ui->Lbl25->setText("");


    ui->UM1->setText("Nasa Number");
    ui->UM2->setText("Nasa Name");
    ui->UM3->setText("10<sup>24</sup> kg");
    ui->UM4->setText("10<sup>10</sup> km<sup>3</sup> ");
    ui->UM5->setText("km");
    ui->UM6->setText("km");
    ui->UM7->setText("km");
    ui->UM8->setText("km");
    ui->UM9->setText("Flattening");
    ui->UM10->setText("kg/m<sup>3</sup>");
    ui->UM11->setText("m/s<sup>2</sup>");
    ui->UM12->setText("m/s<sup>2</sup>");
    ui->UM13->setText("km/s");
    ui->UM14->setText("x 10<sup>6</sup> km<sup>3</sup>/s<sup>2</sup>");
    ui->UM15->setText("0 to 1");
    ui->UM16->setText("1,0");
    ui->UM17->setText("W/m<sup>2</sup>");
    ui->UM18->setText("K");
    ui->UM19->setText("km");
    ui->UM20->setText("x 10<sup>-6</sup>");
    ui->UM21->setText("Number");
    ui->UM22->setText("Number");
    ui->UM23->setText("");
    ui->UM24->setText("");
    ui->UM25->setText("");


    QFile Name ("DataBase/Objects.db");

    //Check for database
    if (Name.exists() == false)
    {
        qDebug() << "No object database found";
    }

    else

    {
        //create new Objectsdb database and check if good connection
        QSqlDatabase Objectsdb = QSqlDatabase::addDatabase("QSQLITE","Objects");

        Objectsdb.setConnectOptions("QSQLITE_OPEN_READONLY");
        Objectsdb.setDatabaseName("Database/Objects.db");

        if (Objectsdb.open() == false) //try to connect to the database
        {
            qApp->beep();
            QMessageBox::critical(nullptr, qApp->tr("Can not connect to the database"),
            qApp->tr("Unable to establish a database connection.\n"));
            return;
        }

        QSqlQuery query(Objectsdb);
        query.exec("select * from ObjectsData where Name = '" + Setup::SimObject + "' ");

        if (query.lastError().isValid())
        {
            qDebug() << "Error: " << query.lastError().text();
        }

        while (query.next())
        {
            //1
            QString Number = query.value("NasaNumber").toString();
            ui->Val1->setText(QString(Number));

            //2
            QString Name = query.value("Name").toString();
            ui->Val2->setText(Name);

            //3
            QString Mass = query.value("Mass").toString();
            ui->Val3->setText(Mass);

            //4
            QString Volume = query.value("Volume").toString();
            ui->Val4->setText(Volume);

            //5
            QString EquatorialRadius = query.value("EquatorialRadius").toString();
            ui->Val5->setText(EquatorialRadius);

            //6
            QString PolarRadius = query.value("PolarRadius").toString();
            ui->Val6->setText(PolarRadius);

            //7
            QString VolumetricMeanRadius = query.value("VolumetricMeanRadius").toString();
            ui->Val7->setText(VolumetricMeanRadius);

            //8
            QString CoreRadius = query.value("CoreRadius").toString();
            ui->Val8->setText(CoreRadius);

            //9
            QString Elipticity = query.value("Elipticity").toString();
            ui->Val9->setText(Elipticity);

             //10
            QString MDensity = query.value("MDensity").toString();
            ui->Val10->setText(MDensity);

            //11
            QString SurfaceGravity = query.value("SurfaceGravity").toString();
            ui->Val11->setText(SurfaceGravity);

            //12
            QString SurfaceAcceleration = query.value("SurfaceAcceleration").toString();
            ui->Val12->setText(SurfaceAcceleration);

            //13
            QString EscapeVelocity = query.value("EscapeVelocity").toString();
            ui->Val13->setText(EscapeVelocity);

            //14
            QString GMGravitatonalConstant = query.value("GMGravitatonalConstant").toString();
            ui->Val14->setText(GMGravitatonalConstant);

            //15
            QString Albedo = query.value("Albedo").toString();
            ui->Val15->setText(Albedo);

            //16
            QString Magnitude = query.value("Magnitude").toString();
            ui->Val16->setText(Magnitude);

            //17
            QString Irradiance = query.value("Irradiance").toString();
            ui->Val17->setText(Irradiance);

            //18
            QString BlackBodyTemp = query.value("BlackBodyTemp").toString();
            ui->Val18->setText(BlackBodyTemp);

            //19
            QString MomentInertia = query.value("MomentInertia").toString();
            ui->Val19->setText(MomentInertia);

            //20
            QString J2 = query.value("J2").toString();
            ui->Val20->setText(J2);

            //21
            QString NumberSatellites = query.value("NumberSatellites").toString();
            ui->Val21->setText(NumberSatellites);

            //22
            QString NumberRings = query.value("NumberRings").toString();
            ui->Val22->setText(NumberRings);

            //23
            //QString  = query.value("").toString();
            //ui->Val23->setText();

            //24
            //QString  = query.value("").toString();
            //ui->Val24->setText();

            //25
            //QString  = query.value("").toString();
            //ui->Val25->setText();

            Objectsdb.close();
            //Objectsdb.removeDatabase("Objects");
        }

    }

}


void BasicData::Orbital (void)
{
    ClearAll();

    ui->Val0->setStyleSheet("color: rgb(85, 255, 0)");
    ui->Val0->setText("Orbital Parameters");
    ui->Val15->setStyleSheet("color: rgb(85, 255, 0)");
    ui->Val15->setText("Orbital Parameters");

    ui->Lbl1->setText("SemimajorAxis");
    ui->Lbl2->setText("SiderealOrbitPeriod");
    ui->Lbl3->setText("Tropical orbit period");
    ui->Lbl4->setText("Perihelion");
    ui->Lbl5->setText("Aphelion");
    ui->Lbl6->setText("Synodicperiod");
    ui->Lbl7->setText("Mean orbital velocity");
    ui->Lbl8->setText("Max. orbital velocity");
    ui->Lbl9->setText("Min. orbital velocity");
    ui->Lbl10->setText("Orbit inclination");
    ui->Lbl11->setText("Orbit eccentricity");
    ui->Lbl12->setText("Sidereal rotation period");
    ui->Lbl13->setText("Length of day");
    ui->Lbl14->setText("Obliquity to orbit");
    ui->Lbl15->setText("");
    ui->Lbl16->setText("Discoverer");
    ui->Lbl17->setText("Discovery Date");
    ui->Lbl18->setText("MinDistEarth");
    ui->Lbl19->setText("MaxDistEarth");
    ui->Lbl20->setText("MaxApparentDiameter");
    ui->Lbl21->setText("MinApparentDiameter");
    ui->Lbl22->setText("MeanDistanceAtOpposition");
    ui->Lbl23->setText("ApparentDiameter");
    ui->Lbl24->setText("ApparentMagnitude");
    ui->Lbl25->setText("");


    ui->UM1->setText("10<sup>6  km");
    ui->UM2->setText("days");
    ui->UM3->setText("days");
    ui->UM4->setText("10<sup>6  km");
    ui->UM5->setText("10<sup>6  km");
    ui->UM6->setText("days");
    ui->UM7->setText("km/s");
    ui->UM8->setText("km/s");
    ui->UM9->setText("km/s");
    ui->UM10->setText("deg");
    ui->UM11->setText("");
    ui->UM12->setText("hrs");
    ui->UM13->setText("hrs");
    ui->UM14->setText("deg");
    ui->UM15->setText("");
    ui->UM16->setText("Person");
    ui->UM17->setText("Date");
    ui->UM18->setText("10<sup>6  km");
    ui->UM19->setText("10<sup>6  km");
    ui->UM20->setText("seconds of arc");
    ui->UM21->setText("seconds of arc");
    ui->UM22->setText("10<sup>6  km");
    ui->UM23->setText("seconds of arc");
    ui->UM24->setText("magnitude");
    ui->UM25->setText("");




    QFile Name ("Database/Objects.db");

    //Check for database
    if (Name.exists() == false)
    {
        qDebug() << "No object database found";
    }

    else

    {
        //create new Objects.db database and check if good connection
        QSqlDatabase Objectsdb = QSqlDatabase::addDatabase("QSQLITE","Objects");

        Objectsdb.setConnectOptions("QSQLITE_OPEN_READONLY");
        Objectsdb.setDatabaseName("Database/Objects.db");

        if (Objectsdb.open() == false) //try to connect to the database
        {
            qApp->beep();
            QMessageBox::critical(nullptr, qApp->tr("Can not connect to the database"),
            qApp->tr("Unable to establish a database connection.\n"));
            return;
        }

        QSqlQuery query(Objectsdb);
        query.exec("select * from ObjectsData where Name = '" + Setup::SimObject + "' ");

        if (query.lastError().isValid())
        {
            qDebug() << "Error: " << query.lastError().text();
        }

        while (query.next())
        {
            //1
            QString SemimajorAxis = query.value("SemimajorAxis").toString();
            ui->Val1->setText(QString(SemimajorAxis));

            //2
            QString SiderealOrbitPeriod = query.value("SiderealOrbitPeriod").toString();
            ui->Val2->setText(SiderealOrbitPeriod);

            //3
            QString TropicalOrbitPeriod = query.value("TropicalOrbitPeriod").toString();
            ui->Val3->setText(TropicalOrbitPeriod);

            //4
            QString Perihelion = query.value("Perihelion").toString();
            ui->Val4->setText(Perihelion);

            //5
            QString Aphelion = query.value("Aphelion").toString();
            ui->Val5->setText(Aphelion);

            //6
            QString SynodicPeriod = query.value("SynodicPeriod").toString();
            ui->Val6->setText(SynodicPeriod);

            //7
            QString MeanOrbitalVelocity = query.value("MeanOrbitalVelocity").toString();
            ui->Val7->setText(MeanOrbitalVelocity);


            //8
            QString MaxOrbitalVelocity = query.value("MaxOrbitalVelocity").toString();
            ui->Val8->setText(MaxOrbitalVelocity);

            //9
            QString MinOrbitalVelocity = query.value("MinOrbitalVelocity").toString();
            ui->Val9->setText(MinOrbitalVelocity);

             //10
            QString OrbitInclination = query.value("OrbitInclination").toString();
            ui->Val10->setText(OrbitInclination);

            //11
            QString OrbitEccentricity = query.value("OrbitEccentricity").toString();
            ui->Val11->setText(OrbitEccentricity);

            //12
            QString SiderealRotationPeriod = query.value("SiderealRotationPeriod").toString();
            ui->Val12->setText(SiderealRotationPeriod);

            //13
            QString LengthOfDay = query.value("LengthOfDay").toString();
            ui->Val13->setText(LengthOfDay);

            //14
            QString ObliquityToOrbit = query.value("ObliquityToOrbit").toString();
            ui->Val14->setText(ObliquityToOrbit);

            //15
            //QString MeanOrbitalElements = query.value("Observational parameters").toString();
            //ui->Val15->setText("MeanOrbitalElements");

            //16
            QString Discoverer = query.value("Discoverer").toString();
            ui->Val16->setText(Discoverer);

            //17
            QString Discoverydate = query.value("Discoverydate").toString();
            ui->Val17->setText(Discoverydate);

            //18
            QString MinDistEarth = query.value("MinDistEarth").toString();
            ui->Val18->setText(MinDistEarth);

            //19
            QString MaxDistEarth = query.value("MaxDistEarth").toString();
            ui->Val19->setText(MaxDistEarth);

            //20
            QString MaxApparentDiameter = query.value("MaxApparentDiameter").toString();
            ui->Val20->setText(MaxApparentDiameter);

            //21
            QString MinApparentDiameter = query.value("MinApparentDiameter").toString();
            ui->Val21->setText(MinApparentDiameter);

            //22
            QString MeanValueDistanceOpposition = query.value("MeanValueDistanceOppostion").toString();
            ui->Val22->setText(MeanValueDistanceOpposition);

            //23
            QString MeanApparentDiameterOpposition = query.value("MeanApparentDiameterOpposition").toString();
            ui->Val23->setText(MeanApparentDiameterOpposition);

            //24
            QString MaxApparentMagnitude = query.value("MaxApparentMagnitude").toString();
            ui->Val24->setText(MaxApparentMagnitude);

            //25
            //QString  = query.value("").toString();
            //ui->Val25->setText();    

            Objectsdb.close();
            //Objectsdb.removeDatabase("Objects");
        }

    }
}



void BasicData::Environmental  (void)
{
    ClearAll();

    ui->Val0->setStyleSheet("color: rgb(85, 255, 0)");
    ui->Val0->setText("Environmental Parameters");

    ui->Val7->setStyleSheet("color: rgb(85, 255, 0)");
    ui->Val7->setText("North Pole of Rotation");

    ui->Val11->setStyleSheet("color: rgb(85, 255, 0)");
    ui->Val11->setText("Magnetic Field");

    ui->Val17->setStyleSheet("color: rgb(85, 255, 0)");
    ui->Val17->setText("Atmosphere");

    ui->Lbl1->setText("Semimajor axis");
    ui->Lbl2->setText("Orbital eccentricity");
    ui->Lbl3->setText("Orbital inclination");
    ui->Lbl4->setText("Longitude of ascending node");
    ui->Lbl5->setText("Longitude of perihelion");
    ui->Lbl6->setText("Mean Longitude");
    ui->Lbl7->setText("");
    ui->Lbl8->setText("RightAcension");
    ui->Lbl9->setText("Declination");
    ui->Lbl10->setText("ReferenceDate");
    ui->Lbl11->setText("");
    ui->Lbl12->setText("DipoleFieldStrength");
    ui->Lbl13->setText("TiltRotationAxis");
    ui->Lbl14->setText("LongitudeOfTilt");
    ui->Lbl15->setText("DipoleOffset");
    ui->Lbl16->setText("LatLongOfOffsetVector");
    ui->Lbl17->setText("");
    ui->Lbl18->setText("Surface Pressure");
    ui->Lbl19->setText("Temperature 1 bar");
    ui->Lbl20->setText("Temperature 0.1 bar");
    ui->Lbl21->setText("Density");
    ui->Lbl22->setText("Wind Speed <30 degrees lat");
    ui->Lbl23->setText("Wind Speed >30 degrees lat");
    ui->Lbl24->setText("Scale Height");
    ui->Lbl25->setText("Mean molecular weight");

    ui->UM1->setText("AU");
    ui->UM2->setText("");
    ui->UM3->setText("deg");
    ui->UM4->setText("deg");
    ui->UM5->setText("deg");
    ui->UM6->setText("deg");
    ui->UM7->setText("");    
    ui->UM8->setText("Julian centuries");
    ui->UM9->setText("");
    ui->UM10->setText("");
    ui->UM11->setText("");
    ui->UM12->setText("gauss-Rj<sup>3");
    ui->UM13->setText("degrees");
    ui->UM14->setText("Re");
    ui->UM15->setText("degrees");
    ui->UM16->setText("latdeg longdeg");
    ui->UM17->setText("");
    ui->UM18->setText("bars");
    ui->UM19->setText("deg K");
    ui->UM20->setText("deg K");
    ui->UM21->setText("kg/m<sup>3");
    ui->UM22->setText("m/s");
    ui->UM23->setText("m/s");
    ui->UM24->setText("km");
    ui->UM25->setText("compounds");

    QFile Name ("Database/Objects.db");

    //Check for database
    if (Name.exists() == false)
    {
        qDebug() << "No object database found";
    }

    else

    {
        //create new Objectsdb database and check if good connection
        QSqlDatabase Objectsdb = QSqlDatabase::addDatabase("QSQLITE","Objects");

        Objectsdb.setConnectOptions("QSQLITE_OPEN_READONLY");
        Objectsdb.setDatabaseName("Database/Objects.db");

        if (Objectsdb.open() == false) //try to connect to the database
        {
            qApp->beep();
            QMessageBox::critical(nullptr, qApp->tr("Can not connect to the database"),
            qApp->tr("Unable to establish a database connection.\n"));
            return;
        }

        QSqlQuery query(Objectsdb);
        query.exec("select * from ObjectsData where Name = '" + Setup::SimObject + "' ");

        if (query.lastError().isValid())
        {
            qDebug() << "Error: " << query.lastError().text();
        }

        while (query.next())
        {
            //1
            QString SemimajorAxis = query.value("SemimajorAxis").toString();
            ui->Val1->setText(QString(SemimajorAxis));

            //2
            QString OrbitalEccentricity = query.value("OrbitalEccentricity").toString();
            ui->Val2->setText(OrbitalEccentricity);

            //3
            QString Orbitalinclination = query.value("Orbitalinclination").toString();
            ui->Val3->setText(Orbitalinclination);

            //4
            QString LongitudeAscendingNode = query.value("LongitudeAscendingNode").toString();
            ui->Val4->setText(LongitudeAscendingNode);

            //5
            QString LongitudeofPerihelion = query.value("LongitudeofPerihelion").toString();
            ui->Val5->setText(LongitudeofPerihelion);

            //6
            QString MeanLongitude = query.value("MeanLongitude").toString();
            ui->Val6->setText(MeanLongitude);

            //7
            //QString  = query.value("").toString();
            //ui->Val7->setText("North Pole of Rotation");

            //8
            QString RightAscension = query.value("RightAscension").toString();
            ui->Val8->setText(RightAscension);

            //9
            QString Declination = query.value("Declination").toString();
            ui->Val9->setText(Declination);

            //10
            QString ReferenceDate = query.value("ReferenceDate").toString();
            ui->Val10->setText(ReferenceDate);

            //11
            //QString JulianCenturies = query.value("JulianCenturies").toString();
            //ui->Val11->setText(JulianCenturies);

            //12
            QString DipoleFieldStrength  = query.value("DipoleFieldStrength").toString();
            ui->Val12->setText(DipoleFieldStrength);

            //13
            QString TiltRotationAxis = query.value("TiltRotationAxis").toString();
            ui->Val13->setText(TiltRotationAxis);

            //14
            QString LongitudeOfTilt = query.value("LongitudeOfTilt").toString();
            ui->Val14->setText(LongitudeOfTilt);

            //15
            QString DipoleOffset = query.value("DipoleOffset").toString();
            ui->Val15->setText(DipoleOffset);

            //16
            QString Latlong = query.value("Latlong").toString();
            ui->Val16->setText(Latlong);

            //17
            //QString SurfacePressure = query.value("SurfacePressure").toString();
            //ui->Val17->setText(SurfacePressure);

            //18
            QString SurfacePressure = query.value("SurfacePressure").toString();
            ui->Val18->setText(SurfacePressure);

            //19
            QString TemperatureAt1bar = query.value("TemperatureAt1bar").toString();
            ui->Val19->setText(TemperatureAt1bar);

            //20
            QString TemperatureAt01bar = query.value("TemperatureAt01bar").toString();
            ui->Val20->setText(TemperatureAt01bar);

            //21
            QString Density = query.value("Density").toString();
            ui->Val21->setText(Density);

            //22
            QString WindSpeedunder30Lat = query.value("WindSpeedunder30Lat").toString();
            ui->Val22->setText(WindSpeedunder30Lat);

            //23
            QString  WindSpeedabove30Lat = query.value("WindSpeedabove30Lat").toString();
            ui->Val23->setText(WindSpeedabove30Lat);

            //24
            QString  ScaleHeight = query.value("ScaleHeight").toString();
            ui->Val24->setText(ScaleHeight);

            //25
            QString  MeanMolecularWeight = query.value("MeanMolecularWeight").toString();
            ui->Val25->setText(MeanMolecularWeight);

            Objectsdb.close();
            //Objectsdb.removeDatabase("Objects");
        }

    }

}


void BasicData::Exit (void)
{
    this->close();
}

