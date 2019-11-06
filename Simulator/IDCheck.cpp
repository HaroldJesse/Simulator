  #include "IDCheck.hpp"
#include "ui_IDCheck.h"

QString IDCheck::Device("");
QString IDCheck::DeviceFolder("IDFolder");
QString IDCheck::File("");

qint64 IDCheck::RecordNumber = QDateTime::currentMSecsSinceEpoch();
QString IDCheck::IndividualName("");
QString IDCheck::FamilyName("");
QString IDCheck::Department("");
QString IDCheck::Level("");
QDateTime IDCheck::ActivationDate = QDateTime(QDateTime::currentDateTime());

int IDCheck::CertNumber(0);
QString IDCheck::Type("");
QString IDCheck::SimCertificate("");
QDateTime IDCheck::IssueDate = QDateTime(QDateTime::currentDateTime());
QString IDCheck::IssuedBy("");

QString IDCheck::Status = "Running";

IDCheck::IDCheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IDCheck)
{
    ui->setupUi(this);

    //SetAllCorners(50);
    SetRoundedCorners(50,50,25,25);
    //SetRectHole(10,5,100,100);

    VoiceList = Verbalize->availableVoices();

    Verbalize->setPitch(.3);
    Verbalize->setRate(0);
    //Verbalize->setVoice();
    Verbalize->say(ui->Message->toPlainText());
}

IDCheck::~IDCheck()
{
    delete ui;
}

void IDCheck::ConnectDevice (void)
{
    Verbalize->stop();
    Verbalize->say("Checking for ID device");


    if (GetIDFile () == false)
    {
        QMessageBox msgBox;
        msgBox.setText("An ID device could not be created. Go directly to the simulator or quit the simulation");
        msgBox.setStandardButtons(QMessageBox::Ok);
        Verbalize->say(msgBox.text());
        msgBox.exec();

        //qDebug() << "getfileID";
    }
         this->close();
}

void IDCheck::Simulator (void)
{
    Verbalize->stop();
    IDCheck::Status = "Simulator";
    //this->close();
}


bool IDCheck::GetIDFile (void)
{
    //Windows returns drive letters of removable devices. Linux returns "\"

    QFileInfoList Devices =  QDir::drives();

    for (int i = 0; i < Devices.size(); ++i)
    {
        QString Dev = Devices.at(i).filePath();
        QDir Folder;
        Folder.setPath(Dev + "IDFolder");  //Do not use / after folder name

        //qDebug() << "Folder:" << Folder.dirName();

        QFile File;
        File.setFileName("/ID.sim");
        //qDebug() << "File:" << File.fileName();

        QString DataBase = Folder.path() + File.fileName();
        //qDebug() << "DataBase: "  << DataBase;

        if (File.exists(DataBase))
        {
            Verbalize->say("ID file found");
            //SimFile = DataBase;

            IDCheck::Device = Dev;
            IDCheck::DeviceFolder = Folder.dirName();
            IDCheck::File = File.fileName();

            GetID();

            Verbalize->say("Greetings " + IDCheck::Level + " " + IDCheck::IndividualName + " " + IDCheck::FamilyName);

        }
    }

    if (File == "")
    {
        QMessageBox msgBox;
        msgBox.setText("An I D file was not found. Do you want to create one?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

        Verbalize->say(msgBox.text());
        int button = msgBox.exec();

        if (button == QMessageBox::Yes)
        {
            Verbalize->say("You have chosen to create an I  D device");

            IDPort Port;
            Port.exec();


            CreateID();

        }

        else

        if (button == QMessageBox::No)
        {
            Verbalize->say("You have chosen to not created an  I  D device");
            //return false;
            //QDir = Initialize::StartupPath;
        }

    }

    return true;
}


void IDCheck::CreateID (void)
{
    Verbalize->stop();

    QDir CurrentDir;
    CurrentDir = QDir::current();
    QString Current = QDir::currentPath();

    QDir  Device;
    Device.cd(IDCheck::Device);
    Device.mkdir(IDCheck::DeviceFolder);
    Device.cd(IDCheck::DeviceFolder);
    Device.setCurrent(IDCheck::Device + IDCheck::DeviceFolder);
    //qDebug() << "Current Path: " << Device.path();

    QString IDFileName = "ID.sim";
    QFile FileName (IDFileName);

    //qDebug() << "Device: " << QDir::currentPath();

    if (FileName.open(QIODevice::WriteOnly)  == false)
    {
        qApp->beep();
        QMessageBox msgBox;
        msgBox.setText("The ID file could not be created!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        Verbalize->say(msgBox.text());
        msgBox.exec();
        qDebug() << "File Error: " << FileName.errorString();
    }

    //else


    {
        //create new ID and check if good connection
        QSqlDatabase Identification = QSqlDatabase::addDatabase("QSQLITE","ID");
        Identification.setDatabaseName(IDFileName);

        if (Identification.open() == false) //try to connect to the database
        {
            qApp->beep();
            QMessageBox msgBox;
            msgBox.setText("A  connection to your ID device could not be made!");
            msgBox.setStandardButtons(QMessageBox::Ok);
            Verbalize->say(msgBox.text());
            msgBox.exec();

            Identification.close();
            return;
        }

        //qDebug() << "create  table";

        QSqlQuery IDQuery("create table ID (Key integer primary key,"
                        "RecordNumber int,"
                        "IndividualName varchar(20),"
                        "FamilyName varchar(20),"
                        "Department varchar(20),"
                        "Level varchar(20),"
                        "ActivationDate datetime)",Identification);

        if (IDQuery.lastError().isValid())
        {
            qDebug() << IDQuery.lastError();

            QMessageBox msgBox;
            msgBox.setText("Sorry! could not create ID table");
            msgBox.setStandardButtons(QMessageBox::Ok);
            Verbalize->say(msgBox.text());
            msgBox.show();
        }

        //qDebug()  << "Certificate table created";

        QSqlQuery CertQuery("create table Certificates (Key integer primary key,"
                        "CertNumber int,"
                        "Type varchar(10),"
                        "SimCertificate varchar(20),"
                        "IssueDate datetime,"
                        "IssuedBy varchar(20))",Identification);



        if (CertQuery.lastError().isValid())
        {
            qDebug() << IDQuery.lastError();

            QMessageBox msgBox;
            msgBox.setText("Sorry! could not create Certificate table");
            msgBox.setStandardButtons(QMessageBox::Ok);
            Verbalize->say(msgBox.text());
            msgBox.show();
        }

        //qDebug()  << "Simulators table created";

        QSqlQuery SimulatorQuery("create table Simulators (Key integer primary key,"
                        "Type varchar(10),"
                        "SimTime time,"
                        "SimGrade varchar(20),"
                        "IssuedBy varchar(20))",Identification);



        if (SimulatorQuery.lastError().isValid())
        {
            qDebug() << IDQuery.lastError();

            QMessageBox msgBox;
            msgBox.setText("Sorry! could not create Simulators table");
            msgBox.setStandardButtons(QMessageBox::Ok);
            Verbalize->say(msgBox.text());
            msgBox.show();
        }
    }

    //qDebug() << "Database creation complete";

    IDAdd Person;
    Person.exec();

    Verbalize->say("Greetings " + IDCheck::Level + " " + IDCheck::IndividualName + " " + IDCheck::FamilyName);

    //qDebug() << "IndName: " << IDCheck::IndividualName << "FamilyName: " << IDCheck::FamilyName;
    //qDebug() << "Department: " << IDCheck::Department << "Level: " << IDCheck::Level;
    //qDebug() << "RecordNumber: " << IDCheck::RecordNumber << "Activation Date: " << IDCheck::ActivationDate;

    //Restore previous path
    QDir::setCurrent(Current);

    return;
}

void  IDCheck::AddIndividual(void)
{
    //AddItem Add;
    //Add.exec();
}

void IDCheck::GetID (void)
{
    QDir CurrentDir;
    CurrentDir = QDir::current();
    QString Current = QDir::currentPath();


    QDir  Device;
    Device.cd(IDCheck::Device);
    //qDebug() << "Device Path: " << IDCheck::Device << Device.path();
    Device.mkdir(IDCheck::DeviceFolder);
    Device.cd(IDCheck::DeviceFolder);
    Device.setCurrent(IDCheck::Device + IDCheck::DeviceFolder);
    //qDebug() << "GetIDCurrentPath: " << Device.path() ;

    QString IDFileName = "ID.sim";
    //QFile FileName (IDFileName);


    //set up databases
    QSqlDatabase IDdb = QSqlDatabase::addDatabase("QSQLITE","ID");
    IDdb.setDatabaseName("ID.sim");

    if (IDdb.open() == false) //try to connect to the database
    {
        qApp->beep();
        QMessageBox::critical(nullptr, qApp->tr("Can not connect to the ID database"),
        qApp->tr("Unable to establish a ID database connection.\n"), QMessageBox::Ok);
    }

    QSqlQuery query(IDdb);

    query.exec("SELECT * FROM ID");
    query.next();

    //qDebug() << "Record: " << query.record()  ;

    IDCheck::RecordNumber   = query.value("RecordNumber").toInt();
    IDCheck::IndividualName = query.value("IndividualName").toString();
    IDCheck::FamilyName     = query.value("FamilyName").toString();
    IDCheck::Department     = query.value("Department").toString();
    IDCheck::Level          = query.value("Level").toString();
    IDCheck::ActivationDate = query.value("ActivationDate").toDateTime();

    //Restore previous path
    QDir::setCurrent(Current);
    //qDebug() << "ExitIDCheckPath: " << QDir::currentPath();
    IDdb.close();

}



void IDCheck::SetRectHole (int PosX, int PosY, int H, int W)
{
    QRegion region(PosX, PosY, width(), height(), QRegion::Rectangle);
    qDebug() << "Region: " << region;
    QRegion Hole(PosX,PosY,H,W,QRegion::Rectangle);
    qDebug() << "Hole: " << Hole;
    region = region.subtracted(region.subtracted(Hole));
    qDebug() << "Finished Region: " << region;

    setMask(region);
}


void IDCheck::SetAllCorners(int Radius)
{
    QRegion region(0, 0, width(), height(), QRegion::Rectangle);

    // top left
    QRegion round (0, 0, 2*Radius, 2*Radius, QRegion::Ellipse);
    QRegion corner(0, 0, Radius, Radius, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    // top right
    round = QRegion(width()-2*Radius, 0, 2*Radius, 2*Radius, QRegion::Ellipse);
    corner = QRegion(width()-Radius, 0, Radius, Radius, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    // bottom right
    round = QRegion(width()-2*Radius, height()-2*Radius, 2*Radius, 2*Radius, QRegion::Ellipse);
    corner = QRegion(width()-Radius, height()-Radius, Radius, Radius, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    // bottom left
    round = QRegion(0, height()-2*Radius, 2*Radius, 2*Radius, QRegion::Ellipse);
    corner = QRegion(0, height()-Radius, Radius, Radius, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    setMask(region);
}

void IDCheck::SetRoundedCorners(int Radius_tl, int Radius_tr, int Radius_bl, int Radius_br)
{
    QRegion region(0, 0, width(), height(), QRegion::Rectangle);

    // top left
    QRegion round (0, 0, 2*Radius_tl, 2*Radius_tl, QRegion::Ellipse);
    QRegion corner(0, 0, Radius_tl, Radius_tl, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    // top right
    round = QRegion(width()-2*Radius_tr, 0, 2*Radius_tr, 2*Radius_tr, QRegion::Ellipse);
    corner = QRegion(width()-Radius_tr, 0, Radius_tr, Radius_tr, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    // bottom right
    round = QRegion(width()-2*Radius_br, height()-2*Radius_br, 2*Radius_br, 2*Radius_br, QRegion::Ellipse);
    corner = QRegion(width()-Radius_br, height()-Radius_br, Radius_br, Radius_br, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    // bottom left
    round = QRegion(0, height()-2*Radius_bl, 2*Radius_bl, 2*Radius_bl, QRegion::Ellipse);
    corner = QRegion(0, height()-Radius_bl, Radius_bl, Radius_bl, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    setMask(region);
}

void IDCheck::Quit (void)
{
    Verbalize->stop();
    IDCheck::Status = "Abort";
    this->close();
}

