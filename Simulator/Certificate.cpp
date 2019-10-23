#include "Certificate.hpp"
#include "ui_Certificate.h"

QString Certificate::CertificateStatus = "Normal";

Certificate::Certificate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Certificate)
{
    ui->setupUi(this);

    GetID();
    //qDebug() << CertificateStatus;

    if (CertificateStatus == "Normal")
    {
        GetCertificates();
        GetSimulators();
    }

    else if (CertificateStatus == "Aborted")
    {
        return;
    }
}

Certificate::~Certificate()
{
    delete ui;
}


void Certificate::GetID (void)
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
    //qDebug() << "Current Path: " << Device.path();

    QString IDFileName = "ID.sim";

    QSqlDatabase Certificatedb = QSqlDatabase::database("ID");
    Certificatedb.setDatabaseName("ID.sim");

    if (Certificatedb.open() == false) //try to connect to the database
    {
        qApp->beep();
        QMessageBox::critical(nullptr, qApp->tr("Can not connect to the Certificate database"),
            qApp->tr("Unable to establish a Certificate database connection.\n"), QMessageBox::Ok);

    }

    else

    {
        return;
    }

    model = new QSqlTableModel(this, Certificatedb);
    model->setTable("ID");
    model->select();

    /* Set up sorting and filtering */
    Cmodel = new QSortFilterProxyModel(this);
    Cmodel->setSourceModel(model);

    ui->IDView->setModel(Cmodel);
    ui->IDView->setColumnHidden(model->fieldIndex("ID"), true);
    ui->IDView->setSortingEnabled(model);
    ui->IDView->hideColumn(0);

    //set view as read only No edits allowed
    ui->IDView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Set rows to alternate colors
    ui->IDView->setAlternatingRowColors(true);

    //use row selection
    ui->IDView->setSelectionBehavior(QAbstractItemView::SelectRows);

    //Set for single selection
    ui->IDView->setSelectionMode(QAbstractItemView::SingleSelection);

    //Restore previous path
    QDir::setCurrent(Current);

    //setWindowTitle(tr("Certificates"));
}

void Certificate::GetCertificates (void)
{
    QDir CurrentDir;
    CurrentDir = QDir::current();
    QString Current = QDir::currentPath();
    //qDebug() << "GetCertificate currentpath:" << Current;

    QDir  Device;
    Device.cd(IDCheck::Device);
    //qDebug() << "Device Path: " << IDCheck::Device << Device.path();
    Device.mkdir(IDCheck::DeviceFolder);
    Device.cd(IDCheck::DeviceFolder);
    Device.setCurrent(IDCheck::Device + IDCheck::DeviceFolder);
    //qDebug() << "Current Path: " << Device.path();

    QString IDFileName = "ID.sim";

    QSqlDatabase Certificatedb = QSqlDatabase::database("ID");
    Certificatedb.setDatabaseName("ID.sim");

    if (Certificatedb.open() == false) //try to connect to the database
    {
        qApp->beep();
        QMessageBox::critical(nullptr, qApp->tr("Can not connect to the Certificate database"),
            qApp->tr("Unable to establish a Certificate database connection.\n"), QMessageBox::Ok);
    }

    model = new QSqlTableModel(this, Certificatedb);
    model->setTable("Certificates");
    model->select();

    /* Set up sorting and filtering */
    Cmodel = new QSortFilterProxyModel(this);
    Cmodel->setSourceModel(model);

    ui->CertificateView->setModel(Cmodel);
    ui->CertificateView->setColumnHidden(model->fieldIndex("ID"), true);
    ui->CertificateView->setSortingEnabled(model);
    ui->CertificateView->hideColumn(0);

    //set view as read only No edits allowed
    ui->CertificateView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Set rows to alternate colors
    ui->CertificateView->setAlternatingRowColors(true);

    //use row selection
    ui->CertificateView->setSelectionBehavior(QAbstractItemView::SelectRows);

    //Set for single selection
    ui->CertificateView->setSelectionMode(QAbstractItemView::SingleSelection);

    //Restore previous path
    QDir::setCurrent(Current);

    //setWindowTitle(tr("Certificates"));
}

void Certificate::GetSimulators (void)
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
    //qDebug() << "Current Path: " << Device.path();

    QString IDFileName = "ID.sim";

    QSqlDatabase Simulatorsdb = QSqlDatabase::database("ID");
    Simulatorsdb.setDatabaseName("ID.sim");

    if (Simulatorsdb.open() == false) //try to connect to the database
    {
        qApp->beep();
        QMessageBox::critical(nullptr, qApp->tr("Can not connect to the Certificate database"),
            qApp->tr("Unable to establish a Certificate database connection.\n"), QMessageBox::Ok);
    }

    model = new QSqlTableModel(this, Simulatorsdb);
    model->setTable("Simulators");
    model->select();

    /* Set up sorting and filtering */
    Cmodel = new QSortFilterProxyModel(this);
    Cmodel->setSourceModel(model);

    ui->SimulatorsView->setModel(Cmodel);
    ui->SimulatorsView->setColumnHidden(model->fieldIndex("ID"), true);
    ui->SimulatorsView->setSortingEnabled(model);
    ui->SimulatorsView->hideColumn(0);

    //set view as read only No edits allowed
    ui->SimulatorsView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Set rows to alternate colors
    ui->SimulatorsView->setAlternatingRowColors(true);

    //use row selection
    ui->SimulatorsView->setSelectionBehavior(QAbstractItemView::SelectRows);

    //Set for single selection
    ui->SimulatorsView->setSelectionMode(QAbstractItemView::SingleSelection);

    //Restore previous path
    QDir::setCurrent(Current);


    //setWindowTitle(tr("Certificates"));
}

void Certificate::Quit (void)
{
    Certificate::CertificateStatus = "Aborted";
    this->close();
}
