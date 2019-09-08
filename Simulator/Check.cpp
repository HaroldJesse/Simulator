#include "IDCheck.hpp"
#include "ui_IDCheck.h"

QString IDCheck::SimFile("");
QStringList DeviceRoot ("");

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
    Verbalize->say("Checking for I D device");


    if (GetIDFile () == false)
    {    
        QMessageBox msgBox;
        msgBox.setText("An ID device could not be created");
        msgBox.setInformativeText("Go directly to the simulator or quit the simulation");
        msgBox.setStandardButtons(QMessageBox::Ok);

        Verbalize->say(msgBox.text());
        Verbalize->say(msgBox.informativeText());

        msgBox.exec();

        //qDebug() << "getfileID";
    }



 //else
    //{
        this->close();
   // }

}

void IDCheck::Simulator (void)
{
    Verbalize->stop();
    this->close();
}


bool IDCheck::GetIDFile (void)
{
    //Windows returns drive letters of removable devices. Linux returns "\"

    QFileInfoList Devices =  QDir::drives();

    for (int i = 0; i < Devices.size(); ++i)
    {
        QString Dev = Devices.at(i).filePath();
        QDir Base;
        Base.setPath(Dev + "SimFolder");  //Do not use / after folder name

        QFile File;
        File.setFileName("/ID.db");

        QString DataBase = Base.path() + File.fileName();
        //qDebug() << "DataBase: "  << DataBase;

        if (File.exists(DataBase))
        {
            Verbalize->say("ID file found");
            SimFile = DataBase;
            qDebug() << "SimFile: " << SimFile;
        }
    }

    if (SimFile == "")
    {
        QMessageBox msgBox;
        msgBox.setText("An I D file was not found.");
        msgBox.setInformativeText("Do you want to create one?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

        Verbalize->say(msgBox.text());
        Verbalize->say(msgBox.informativeText());

        int button = msgBox.exec();


        if (button == QMessageBox::Yes)
        {
            Verbalize->say("You have chosen to create an  I  D device");

            IDPort Port;
            Port.exec();

            CreateID(IDPort::Device);

        }

        else

        if (button == QMessageBox::No)
        {
            Verbalize->say("You have chosen to not create an  I  D device");
            //return false;
        }
    }
    return true;
}


void IDCheck::CreateID (QString Port)
{
    Verbalize->stop();

    QDir Dir;
    Dir.setCurrent(Port.toLatin1());
    Dir.mkdir("SimFolder");
    Dir.setCurrent("SimFolder");
    //qDebug() << "Dir: " << Dir;
    QString IDName = "ID.db";
    //qDebug() << "Filename: " << IDName;

    QFile FileName (IDName);

    if (FileName.open(QIODevice::WriteOnly)  == false)
    {
        qApp->beep();
        QMessageBox msgBox;
        msgBox.setText("ID device file");
        msgBox.setInformativeText("The ID file could not be created!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }

    else

    {
        //create new ID and check if good connection
        QSqlDatabase Identification = QSqlDatabase::addDatabase("QSQLITE","ID");
        Identification.setDatabaseName(IDName);

        if (Identification.open() == false) //try to connect to the database
        {
            qApp->beep();
            QMessageBox msgBox;
            msgBox.setText("ID device connection");
            msgBox.setInformativeText("A connection to your ID device could not be made!");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();

            Identification.close();
            return;
        }

        qDebug() << "create  table";

        QSqlQuery IDQuery("create table ID (Key integer primary key,"
                        "RecordNumber int,"
                        "Firstname varchar(20),"
                        "MiddleName varchar(20),"
                        "Lastname varchar(20),"
                        "Department varchar(20),"
                        "Level varchar(20),"
                        "ActivationDate datetime,",Identification);

        if (IDQuery.lastError().isValid())
        {
            qDebug() << IDQuery.lastError();

            QMessageBox msgBox;
            msgBox.setText("ID Device Creation");
            msgBox.setInformativeText("Could not create ID device Sorry! Do you want to login without ID");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.show();
        }

        //qDebug()  << "Log table created";

        QSqlQuery CertQuery("create table Certicates (Key integer primary key,"
                        "RecordNumber int,"
                        "Type varchar(10),"
                        "Certificate varchar(20), "
                        "IssueDate date,"
                        "IssueTime time,"
                        "IssuedBy varchar(20))",Identification);



        if (CertQuery.lastError().isValid())
        {
            qDebug() << IDQuery.lastError();

            QMessageBox msgBox;
            msgBox.setText("ID Device Creation");
            msgBox.setInformativeText("Could not create ID device Sorry! Do you want to login without ID");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.show();
        }

    }

    qDebug() << "Database creation complete";

    IDAdd Person;
    Person.exec();

    return;
}

void  IDCheck::AddIndividual(void)
{
    //AddItem Add;
    //Add.exec();
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
    this->close();
}

