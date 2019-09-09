#include "Spice.hpp"
#include "ui_Spice.h"

/*  ConstSpiceChar     *targ,
    SpiceDouble        *et,
    ConstSpiceChar     *ref,
    ConstSpiceChar     *abcorr,
    ConstSpiceChar     *obs,
    SpiceDouble        *starg[6],
    SpiceDouble        *lt
*/


/*   Generic LSK and PCK files listed in a meta-kernel named
   "mykernels.furnsh" and containing

      \begindata
         KERNELS_TO_LOAD = (
                            '/kernels/gen/lsk/naif0008.tls'
                            '/kernels/gen/pck/pck00008.tps'
                           )
      \begintext
*/

    QString Spice::Target("");
    double  Spice::Epoch(0);
    QString Spice::Frame("");
    QString Spice::Abberation("");
    QString Spice::Observer("");
    double  Spice::TargetState[6];
    double  Spice::LightTime(0);
    QString Spice::FileName("");
    int Spice::StepSize (1);
    int Spice::Steps (1);


Spice::Spice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Spice)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    ui->LocalDate->setReadOnly(true);
    ui->LocalTime->setReadOnly(true);
    ui->UTCTime->setReadOnly(true);
    ui->FileName->setText(QString ("SPKData"));
    ui->KernelFiles->hide();
    ui->KernelFileslbl->hide();
    ui->UseUTC->hide();
    ui->UseEntered->hide();
    ui->Calculate->hide();
    ui->KernelFiles->setText(QString("MK/Furnish.mkf"));
    ui->StepSize->setValue(1);
    ui->StepSize->setMaximum(84600);  // one day
    ui->Steps->setValue(1);
    ui->Steps->setMaximum(100);
    LocalTime();
    UTCTime();

    connect(Timer, SIGNAL(timeout()), this, SLOT(MasterUpdate()));
    Timer->start(1000);
}

Spice::~Spice()
{
    delete ui;
}

void Spice::LocalTime (void)
{
    QDate *Date = new QDate();
    QTime *Time = new QTime();

    QString time = Time->currentTime().toString("hh:mm:ss");
    QString date = Date->currentDate().toString("yyyy MM dd");

    //time = "Time: " + time;
    //date = "Date: " + date;

    //qDebug() << "Time:" << time;
    //Debug() << "Date:" << date;

    ui->LocalTime->setText(time);
    ui->LocalDate->setText(date);
    //qDebug() << "DateTimeString: " << date + time;
}

void Spice::UTCTime (void)
{
    QString UTCString = QDateTime::currentDateTimeUtc().toString();
    ui->UTCTime->setText(UTCString);

    //qDebug() << "UTC Time:" << UTCString;
}

void Spice::UseUTC (void)
{
    //Get datetime and convert to QString and then to c_string
    //ConstSpiceChar *UTCString ("");
    //UTCString = QDateTime::currentDateTimeUtc().toString("MM dd yyyy hh:mm:ss").toStdString().c_str();
    //qDebug() << "Current Date Time: " << UTCString;
    //utc2et_c (UTCString, &Epoch);
    QString EphemerisTime;
    ui->EphemerisTime->setText(EphemerisTime.setNum(Spice::Epoch));
    //qDebug() << "Epoch: " << Epoch;
    ui->Calculate->show();
}

void Spice::UseEntered (void)
{
    QString DateTime;
    DateTime = ui->Month->currentText() + " " + ui->Day->currentText() + " " + ui->Year->currentText() + " " +
    ui->Hours->currentText() + ":" + ui->Minutes->currentText() + ":" + ui->Seconds->currentText();
    //qDebug() << "DateTime: " << DateTime;

    //ConstSpiceChar *DT = DateTime.toStdString().c_str();
    //utc2et_c (DT, &Epoch);
    //qDebug() << "Epoch: " << Spice::Epoch;
    QString EphemerisTime;
    ui->EphemerisTime->setText(EphemerisTime.setNum(Spice::Epoch));
    ui->Calculate->show();

}

void Spice::LoadKernels (void)
{
    //furnsh_c ("de421AllPlanets.bsp");
    //furnsh_c ("L1_de341.bsp");
    //furnsh_c ("naif0012.tls.pc");  //Load leap second file
    ui->UseUTC->show();
    ui->UseEntered->show();
    ui->KernelFiles->setText("kernels loaded");
    ui->KernelFiles->show();
    ui->KernelFileslbl->show();
}

void Spice::SetSteps (void)
{
    Steps = ui->Steps->value();
}

void Spice::SetStepSize (void)
{
    StepSize = ui->StepSize->value();
}
//Do not modify this code. There is a bug in the conversion to ConstSpiceChar. The only way to do the conversion is in the spkezr call.
void Spice::SPKRead (void)
{
    Spice::Target = ui->Target->currentText();
    Spice::Frame = ui->Frame->currentText();
    Spice::Abberation = ui->AberrationCorrection->currentText();
    Spice::Observer = ui->Observer->currentText();

    if (Spice::Target == Spice::Observer)
    {
        qApp->beep();
        QMessageBox msgBox;
        msgBox.setText("The Target and Observer are the same");
        Verbalize->say(msgBox.text());
        msgBox.show();
        return;
    }

        if (Spice::Target == "")
        {
            qApp->beep();
            QMessageBox msgBox;
            msgBox.setText("No Target has been assigned");
            Verbalize->say(msgBox.text());
            msgBox.show();
            return;
        }

        if (Spice::Observer == "")
        {
            qApp->beep();
            QMessageBox msgBox;
            msgBox.setText("No Observer has been assigned");
            Verbalize->say(msgBox.text());
            msgBox.show();
            return;
        }

        if (Spice::Epoch == 0.0)
        {
            qApp->beep();
            QMessageBox msgBox;
            msgBox.setText("No Ephemeris time has been set");
            Verbalize->say(msgBox.text());
            msgBox.show();
            return;
        }

        if (Spice::Frame == "")
        {
            qApp->beep();
            QMessageBox msgBox;
            msgBox.setText("No frame has been set");
            Verbalize->say(msgBox.text());
            msgBox.show();
            return;
        }

        if (Spice::Abberation == "")
        {
            qApp->beep();
            QMessageBox msgBox;
            msgBox.setText("No aberration correction has been set");
            Verbalize->say(msgBox.text());
            msgBox.show();
            return;
        }

        if (ui->Steps->value() > 1)
        {
            //qDebug() << "Ste Size = " << ui->StepSize->value();

            if (ui->StepSize->value() == 0)
            {
                qApp->beep();
                QMessageBox msgBox;
                msgBox.setText("No STEPS SIZE value has been set");
                Verbalize->say(msgBox.text());
                msgBox.show();
                return;
            }

            if (ui->StepHours->isChecked() && ui->StepDays->isChecked())
            {
                qApp->beep();
                QMessageBox msgBox;
                msgBox.setText("Both STEPS SIZE value has been set. Please uncheck one of the choices");
                Verbalize->say(msgBox.text());
                msgBox.show();
                return;
            }

            if (ui->Steps->value() == 0)
            {
                qApp->beep();
                QMessageBox msgBox;
                msgBox.setText("No STEPS value has been set");
                Verbalize->say(msgBox.text());
                msgBox.show();
                return;
            }

            int Steps = ui->Steps->value();


            for (int steps = 1; steps <= Steps; steps++)
            {
                //qDebug() << "steps: " << steps;
                //qDebug() << "Spice: " << Spice::Target << Spice::Epoch << Spice::Frame << Spice::Abberation << Spice::Observer;

                //spkezr_c(Target.toStdString().c_str(), Epoch, Frame.toStdString().c_str(),
                //Abberation.toStdString().c_str(), Observer.toStdString().c_str(), TargetState, &LightTime );
                QString LTime;
                ui->LT->setText(LTime.setNum(LightTime));

                QString Position;
                ui->PositionX->setText(Position.setNum(TargetState[0]));
                ui->PositionY->setText(Position.setNum(TargetState[1]));
                ui->PositionZ->setText(Position.setNum(TargetState[2]));

                QString Velocity;
                ui->VelocityX->setText(Velocity.setNum(TargetState[3]));
                ui->VelocityY->setText(Velocity.setNum(TargetState[4]));
                ui->VelocityZ->setText(Velocity.setNum(TargetState[5]));

                //SpiceChar utcstr[36];
                //et2utc_c (  Epoch , "C", 6, 35, utcstr );
                //QString UTCSTR = QString(utcstr);
                //ui->EphemerisTime->setText(QString(utcstr));
                //ui->Data->appendPlainText("Ephemeris Time: " + UTCSTR);

                QString PosX = "  Pos X = " + Position.setNum(TargetState[0]);
                QString PosY = "  Pos Y = " + Position.setNum(TargetState[1]);
                QString PosZ = "  Pos Z = " + Position.setNum(TargetState[2]);

                QString VelX = "  Vel X = " + Position.setNum(TargetState[3]);
                QString VelY = "  Vel Y = " + Position.setNum(TargetState[4]);
                QString VelZ = "  Vel Z = " + Position.setNum(TargetState[5]);

                ui->Data->appendPlainText(PosX + PosY +PosZ);
                ui->Data->appendPlainText(VelX + VelY +VelZ);

                ui->Data->appendPlainText("Light Time: " + LTime.setNum(LightTime));
                ui->Data->appendPlainText("Frame: " + Spice::Frame);

                if (ui->Savetofile->isChecked() == true)
                {
                    FileName = ui->FileName->text() + ".SPKData";
                    WriteToFile();
                }

                Epoch += ui->StepSize->value();
                //qDebug() << "Epoch: " << Epoch << Steps;
            }

        }

        else

        {
        //spkezr_c(Target.toStdString().c_str(), Epoch, Frame.toStdString().c_str(),
        //Abberation.toStdString().c_str(), Observer.toStdString().c_str(), TargetState, &LightTime );
        QString LTime;
        ui->LT->setText(LTime.setNum(LightTime));

        QString Position;
        ui->PositionX->setText(Position.setNum(TargetState[0]));
        ui->PositionY->setText(Position.setNum(TargetState[1]));
        ui->PositionZ->setText(Position.setNum(TargetState[2]));

        QString Velocity;
        ui->VelocityX->setText(Velocity.setNum(TargetState[3]));
        ui->VelocityY->setText(Velocity.setNum(TargetState[4]));
        ui->VelocityZ->setText(Velocity.setNum(TargetState[5]));

        //SpiceChar utcstr[36];
        //et2utc_c (  Epoch , "C", 6, 35, utcstr );
        //QString UTCSTR = QString(utcstr);
        //ui->EphemerisTime->setText(QString(utcstr));
        //ui->Data->appendPlainText("Ephemeris Time: " + UTCSTR);

        ui->Data->appendPlainText("Frame " + Spice::Frame);

        QString PosX = "Pos X = " + Position.setNum(TargetState[0]);
        QString PosY = "  Pos Y = " + Position.setNum(TargetState[1]);
        QString PosZ = "  Pos Z = " + Position.setNum(TargetState[2]);

        QString VelX = "Vel X = " + Position.setNum(TargetState[3]);
        QString VelY = "  Vel Y = " + Position.setNum(TargetState[4]);
        QString VelZ = "  Vel Z = " + Position.setNum(TargetState[5]);

        ui->Data->appendPlainText(PosX + PosY +PosZ);
        ui->Data->appendPlainText(VelX + VelY +VelZ);
        ui->Data->appendPlainText("Light Time: " + LTime.setNum(LightTime));
        ui->Data->appendPlainText(" ");

        if (ui->Savetofile->isChecked() == true)
        {
            FileName = ui->FileName->text() + ".SPKData";
            WriteToFile();
        }

    }

}

void Spice::MasterUpdate (void)
{
    LocalTime();
    UTCTime();
}

bool Spice::OpenFile (QString Name)
{
    //qDebug() << "Save to file is checked";
    QDate *Date = new QDate();
    QString date = Date->currentDate().toString("yyyyMMdd");

    QFile SPKData(Name + date + ".txt");
    FileName = SPKData.fileName();
    bool FileStatus = SPKData.open(QIODevice::Append | QIODevice::Text);

    return (FileStatus);
}

void Spice::WriteToFile (void)
{
    QFile SPKData(FileName);

    if (SPKData.exists() == true)
    {
        qApp->beep();
        QMessageBox msgBox;
        msgBox.setText(qApp->tr("%1 file already exits.").arg(FileName));
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        Verbalize->say(msgBox.text());
        int ret = msgBox.exec();

        switch (ret)
        {
          case QMessageBox::Yes:
              break;
          case QMessageBox::No:
              break;
          default:
              // should never be reached
              break;
        }
    }


    SPKData.open(QIODevice::Append | QIODevice::Text);

    QString Line;
    QChar NewLine = '\n';
    Line = "Ephemeris Time: " + ui->EphemerisTime->text() + NewLine;
    SPKData.write(Line.toLatin1());
    Line = "Pos X: " + ui->PositionX->text() + "  Pos Y " + ui->PositionY->text() + "  Pos Z " + ui->PositionZ->text() + NewLine;
    SPKData.write(Line.toLatin1());
    Line = "Vel X " + ui->VelocityX->text() + "VelY" + ui->VelocityY->text() + "  Vel Z " + ui->VelocityZ->text() + NewLine;
    SPKData.write(Line.toLatin1());
    Line = "Light Time: " + ui->LT->text() + NewLine;
    SPKData.write(Line.toLatin1());
    Line = NewLine;
    SPKData.write(Line.toLatin1());
}

void Spice::TimerStart (int Milliseconds)
{
    Timer->start(Milliseconds);
}

void Spice::TimerStop (void)
{
    Timer->stop();
}
void Spice::Exit (void)
{
    //kclear_c();
    TimerStop();
    this->close();
    //qDebug() << "Spice exit";
}


void Spice::Print (void)
{
    //QTextDocument *document = ui->Data->document();
    //QPrinter Printer;

    //QPrintDialog *dlg = new QPrintDialog(&Printer, this);
    //if (dlg->show() != QDialog::Accepted)
    //{
        //return;
    //}

    //document->print(&Printer);
}

void Spice::SetStepHours (void)
{
    ui->StepSize->setSingleStep(3600);
    ui->StepHours->setChecked(true);
    ui->StepDays->setChecked(false);
}

void Spice::SetStepDays (void)
{
    ui->StepSize->setSingleStep(84600);
    ui->StepDays->setChecked(true);
    ui->StepHours->setChecked(false);
}

void Spice::SetSteps10 (void)
{
    ui->Steps->setSingleStep(10);
    ui->XSteps10->setChecked(true);
    ui->XSteps100->setChecked(false);
}

void Spice::SetSteps100 (void)
{
    ui->Steps->setSingleStep(100);
    ui->XSteps100->setChecked(true);
    ui->XSteps10->setChecked(false);
}

