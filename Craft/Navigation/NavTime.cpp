#include "NavTime.hpp"
#include "ui_NavTime.h"

#include "SimGlobals.hpp"

/*  ConstSpiceChar     *targ,
    SpiceDouble         et,
    ConstSpiceChar     *ref,
    ConstSpiceChar     *abcorr,
    ConstSpiceChar     *obs,
    SpiceDouble         starg[6],
    SpiceDouble        *lt
*/

    QString NavTime::Target("");
    SpiceDouble NavTime::SpiceET;
    QString NavTime::Frame("");
    QString NavTime::Abberation("");
    QString NavTime::Observer("");
    SpiceDouble NavTime::SpiceState[6];
    SpiceDouble NavTime::SpiceLightTime(0);


NavTime::NavTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NavTime)
{
    ui->setupUi(this);
    LocalTime();
    furnsh_c ("PSK/de421.bsp");     //Load SPK file;
    furnsh_c ("LSK/naif0012.tls.pc");  //Load leap second file
}

NavTime::~NavTime()
{
    delete ui;
}


void NavTime::SetTime (void)
{
    NavTime *NTime = new NavTime();
    NTime->show();
}


void NavTime::LocalTime (void)
{
    QDate *Date = new QDate();
    QTime *Time = new QTime();

    QString time = Time->currentTime().toString("hh:mm:ss");
    QString date = Date->currentDate().toString("yyyy MM dd");

    time = "Time: " + time;
    date = "Date: " + date;

    //qDebug() << "Time:" << time;
    //Debug() << "Date:" << date;

    ui->LocalTime->setText(time);
    ui->LocalDate->setText(date);
}

void NavTime::SetETTime (void)
{
    NavTime::Target = ui->Target->currentText();
    ConstSpiceChar *SpiceTarget = ui->Target->currentText().toStdString().c_str();
    qDebug() << "Target: " << SpiceTarget << ui->Target->currentText().toStdString().c_str();;

    //Get datetime and convert to QString and then to c_string
    ConstSpiceChar *UTCString = QDateTime::currentDateTimeUtc().toString("MMMM dd yyyy hh:mm:ss").toStdString().c_str();
    qDebug() << "DateTimeString: " << UTCString;
    utc2et_c (UTCString, &SpiceET);
    QString EphemerisTime;
    ui->EphemerisTime->setText(EphemerisTime.setNum(NavTime::SpiceET));
    qDebug() << "SpiceET: " << SpiceET;

    NavTime::Frame = ui->Frame->currentText();
    ConstSpiceChar *SpiceFrame = ui->Frame->currentText().toStdString().c_str();
    qDebug() << "Frame: " << SpiceFrame;

    NavTime::Abberation = ui->AberrationCorrection->currentText();
    ConstSpiceChar *SpiceAbberation = ui->AberrationCorrection->currentText().toStdString().c_str();
    qDebug() << "SpiceAbberation: " << SpiceAbberation;

    NavTime::Observer = ui->Observer->currentText();
    ConstSpiceChar *SpiceObserver = ui->Observer->currentText().toStdString().c_str();
    qDebug() << "Observer: " << SpiceObserver;

    if (NavTime::Target == NavTime::Observer)
    {
        qApp->beep();
        QMessageBox msgBox;
        msgBox.setText("Spice Error");
        msgBox.setInformativeText("The Target and Observer are the same");
        msgBox.exec();
        return;
    }

    if (NavTime::Target == "")
    {
        qApp->beep();
        QMessageBox msgBox;
        msgBox.setText("Spice Error");
        msgBox.setInformativeText("No Target has been assigned");
        msgBox.exec();
        return;
    }

    if (NavTime::Observer == "")
    {
        qApp->beep();
        QMessageBox msgBox;
        msgBox.setText("Spice Error");
        msgBox.setInformativeText("No Observer has been assigned");
        msgBox.exec();
        return;
    }

    if (SpiceET == 0)
    {
        qApp->beep();
        QMessageBox msgBox;
        msgBox.setText("Spice Error");
        msgBox.setInformativeText("No Ephemeris time has been set");
        msgBox.exec();
        return;
    }

    if (NavTime::Frame == "")
    {
        qApp->beep();
        QMessageBox msgBox;
        msgBox.setText("Spice Error");
        msgBox.setInformativeText("No frame has been set");
        msgBox.exec();
        return;
    }

    if (NavTime::Abberation == "")
    {
        qApp->beep();
        QMessageBox msgBox;
        msgBox.setText("Spice Error");
        msgBox.setInformativeText("No aberration correction has been set");
        msgBox.exec();
        return;
    }

    spkezr_c(SpiceTarget, SpiceET, SpiceFrame, SpiceAbberation, SpiceObserver, SpiceState, &SpiceLightTime );

    QString LightTime;
    ui->LT->setText(LightTime.setNum(SpiceLightTime));
    qDebug() << "spkezr: " << "LTS: " << SpiceLightTime;
    qDebug() << "State: "  << SpiceState[0] << SpiceState[1] << SpiceState[2] << SpiceState[3] << SpiceState[4] << SpiceState[5];

}

void NavTime::SetTarget (void)
{

}

void NavTime::Exit (void)
{
    kclear_c();
    this->close();
}
