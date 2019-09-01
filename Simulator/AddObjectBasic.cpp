#include "AddObjectBasic.hpp"
#include "ui_AddObjectBasic.h"

AddObjectBasic::AddObjectBasic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddObjectBasic)
{
    ui->setupUi(this);


    ui->Masslbl->setText("10 <sup> 15");
    ui->MassUM->setText("10<sup>24</sup> kg");
    ui->VolUM->setText("10<sup>10</sup> km<sup>3</sup> ");
    ui->ERadiusUM->setText("km");
    ui->PRadiusUM->setText("km");
    ui->MRadiusUM->setText("km");
    ui->CoreRadiusUM->setText("km");
    ui->ElipticityUM->setText("Flattening");
    ui->MDensityUM->setText("kg/m<sup>3</sup>");
    ui->SGravityUM->setText("m/s<sup>2</sup>");
    ui->SAccelUM->setText("m/s<sup>2</sup>");
    ui->EVelocityUM->setText("km/s");
    ui->GMUM->setText("x 10<sup>6</sup> km<sup>3</sup>/s<sup>2</sup>");
    ui->IrradianceUM->setText("W/m<sup>2</sup>");
    ui->MInteriaUM->setText("I/MR<sup>2</sup>");
    ui->BBodyTempUM->setText("K");
    ui->TopographicRangeUm->setText("km");
    ui->J2UM->setText("x 10<sup>-6</sup>");

}

AddObjectBasic::~AddObjectBasic()
{
    delete ui;
}

void AddObjectBasic::SetData (void)
{
AddObjectBasic Basic;
Basic.show();
}

void AddObjectBasic::AddBasicData(void)
{

    qDebug() << "addbasicdata";
    //set up database
    QSqlDatabase Objectsdb = QSqlDatabase::addDatabase("QSQLITE","Objects");
    Objectsdb.setDatabaseName("Objects.db");

    if (Objectsdb.open() == false) //try to connect to the database
    {
        qApp->beep();
        QMessageBox::critical(nullptr, qApp->tr("Can not connect to the database"),
            qApp->tr("Unable to establish a database connection.\n"), QMessageBox::Ok);
    }

    /* set up table model for database */
    QSqlTableModel *Model = new QSqlTableModel(this,Objectsdb);

    Model->setTable("ObjectsData");
    Model->select();

    //Utility util;

    QSqlRecord Crecord;

    //QSqlField F0 ("ID", QVariant::Int);
    QSqlField F1 ("NasaNumber", QVariant::String);
    QSqlField F2 ("Name", QVariant::String);
    QSqlField F3 ("Mass", QVariant::String);
    QSqlField F4 ("Volume", QVariant::String);
    QSqlField F5 ("EquatorialRadius", QVariant::String);
    QSqlField F6 ("PolarRadius", QVariant::String);
    QSqlField F7 ("MedianRadius", QVariant::String);
    QSqlField F8 ("Elipticity", QVariant::String);
    QSqlField F9 ("MDensity", QVariant::String);
    QSqlField F10 ("SurfaceGravity", QVariant::String);
    QSqlField F11 ("SurfaceAcceleration", QVariant::String);
    QSqlField F12 ("EscapeVelocity", QVariant::String);
    QSqlField F13 ("GM", QVariant::String);
    QSqlField F14 ("Albedo", QVariant::String);
    QSqlField F15 ("Magnitude", QVariant::String);
    QSqlField F16 ("Irradiance", QVariant::String);
    QSqlField F17 ("BlackBodyTemp", QVariant::String);
    QSqlField F18 ("MomentInertia", QVariant::String);
    QSqlField F19 ("J2", QVariant::String);
    QSqlField F20 ("NumberSatellites", QVariant::String);
    QSqlField F21 ("NumberRings", QVariant::String);

    //F0.setValue(QVariant(NULL));
    F1.setValue(QVariant(ui->NasaNumber->text()));
    F2.setValue(QVariant(ui->Name->text()));
    F3.setValue(QVariant(ui->Mass->text()));
    F4.setValue(QVariant(ui->Volume->text()));
    F5.setValue(QVariant(ui->EquatorialRadius->text()));
    F6.setValue(QVariant(ui->PolarRadius->text()));
    F7.setValue(QVariant(ui->MedianRadius->text()));
    F8.setValue(QVariant(ui->Elipticity->text()));
    F9.setValue(QVariant(ui->MDensity->text()));
    F10.setValue(QVariant(ui->SurfaceGravity->text()));
    F11.setValue(QVariant(ui->SurfaceAcceleration->text()));
    F12.setValue(QVariant(ui->EscapeVelocity->text()));
    F13.setValue(QVariant(ui->GM->text()));
    F14.setValue(QVariant(ui->Albedo->text()));
    F15.setValue(QVariant(ui->Magnitude->text()));
    F16.setValue(QVariant(ui->Irradiance->text()));
    F17.setValue(QVariant(ui->BlackBodyTemp->text()));
    F18.setValue(QVariant(ui->MomentInertia->text()));
    F19.setValue(QVariant(ui->J2->text().toDouble()));
    F20.setValue(QVariant(ui->NumberSatellites->text()));
    F21.setValue(QVariant(ui->NumberRings->text()));

    //Crecord.append(F0);
    Crecord.append(F1);
    Crecord.append(F2);
    Crecord.append(F3);
    Crecord.append(F4);
    Crecord.append(F5);
    Crecord.append(F6);
    Crecord.append(F7);
    Crecord.append(F8);
    Crecord.append(F9);
    Crecord.append(F10);
    Crecord.append(F11);
    Crecord.append(F12);
    Crecord.append(F13);
    Crecord.append(F14);
    Crecord.append(F15);
    Crecord.append(F16);
    Crecord.append(F17);
    Crecord.append(F18);
    Crecord.append(F19);
    Crecord.append(F20);
    Crecord.append(F21);

    //qDebug() << "Add inventory has run";
    qDebug() << Crecord;

    if (Model->insertRecord(-1, Crecord) == false)
    {
        qDebug() << "Error: " << Model->lastError();
        qDebug() << "Failed to update";
    }

    AddObjectBasic Basic;
    Basic.close();
}

void AddObjectBasic::Exit (void)
{
    this->close();
}
