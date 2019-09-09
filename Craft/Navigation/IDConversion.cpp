#include "IDConversion.hpp"
#include "ui_IDConversion.h"

/*   void bodn2c_c ( ConstSpiceChar  * name,
                   SpiceInt        * code,
                   SpiceBoolean    * found )

     void bodc2n_c ( SpiceInt        code,
                   SpiceInt        lenout,
                   SpiceChar     * name,
                   SpiceBoolean  * found   )

*/


    QString IDConversion::FileName("");

IDConversion::IDConversion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IDConversion)
{
    ui->setupUi(this);

    ui->Code->clear();
    ui->Name->clear();
    this->setWindowFlags(Qt::FramelessWindowHint);
}

IDConversion::~IDConversion()
{
    delete ui;
}

void IDConversion::Convert (void)
{
    if(ui->Code->text() == "" && ui->Name->text() == "")
    {
        qApp->beep();
        QMessageBox msgBox;
        msgBox.setText("Conversion Error");
        msgBox.setInformativeText("No ID or Name is set.");
        msgBox.exec();
        return;
    }

    if(ui->Code->text() != "" && ui->Name->text() != "")
    {
        qApp->beep();
        QMessageBox msgBox;
        msgBox.setText("Conversion Error");
        msgBox.setInformativeText("Both ID and name are set.");
        msgBox.exec();
        return;
    }

    if(ui->Code->text() != "")
    {
        ui->Name->clear();
        SpiceInt Code = ui->Code->text().toInt();
        SpiceInt MaxLength = 36;
        SpiceBoolean found;
        SpiceChar body[MaxLength];

        bodc2n_c ( Code, MaxLength, body, &found );

        ui->Name->setText(QString(body));
        ui->Code->clear();

        return;
    }

    if(ui->Name->text() != "")
    {
        ui->Code->clear();
        QString Name;
        Name = ui->Name->text();

        SpiceBoolean found = 0;
        SpiceInt Code;
        bodn2c_c (Name.toStdString().c_str(), &Code, &found );

        QString IDCode;
        IDCode = IDCode.setNum(Code);
        ui->Code->setText(IDCode);
        ui->Name->clear();

        return;
    }

}

void IDConversion::CreateList (void)
{
    QString PreviousName;
    SpiceInt MaxLength = 36;
    SpiceBoolean found;
    SpiceChar body[MaxLength];

    QString FileName;
    FileName = ui->FileName->text() + ".objlist";
    QFile SPKData(FileName);

    if (SPKData.exists() == true)
    {
        qApp->beep();
        QMessageBox msgBox;
        msgBox.setText("File Exists");
        msgBox.setInformativeText(qApp->tr("%1 file already exits. Do you want to overwrite it?").arg(FileName));
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret = msgBox.exec();

        switch (ret)
        {
          case QMessageBox::Yes:
              break;
          case QMessageBox::No:
              return;
              break;
          default:
              // should never be reached
              break;
        }
    }

    SPKData.open(QIODevice::Append | QIODevice::Text);

    for(int i=1; i <= 2000; i++)
    {
        QString IDCode;
        bodc2n_c ( i, MaxLength, body, &found );
        if (QString(body) != PreviousName)
        {

            ui->Data->appendPlainText(IDCode.setNum(i) + "   " + QString(body));
            PreviousName = QString(body);

            if (ui->Savetofile->isChecked() == true)
            {
                QString Line;
                QChar NewLine = '\n';
                Line = NewLine;
                SPKData.write(Line.toLatin1());
                //qDebug() << IDCode.setNum(i) + QString(body);
                Line = IDCode.setNum(i) + "   " + QString(body);
                SPKData.write(Line.toLatin1());
            }
        }
    }
}

void IDConversion::WriteToFile (void)
{
    QString FileName;
    FileName = ui->FileName->text() + "objlist";
    QFile SPKData(FileName);
    SPKData.open(QIODevice::Append | QIODevice::Text);

    QString Line;
    QChar NewLine = '\n';
    Line = NewLine;
    SPKData.write(Line.toLatin1());
    //Line = ui->Data->appendPlainText(IDCode.setNum(i) + "   " + QString(body));
    SPKData.write(Line.toLatin1());
}

void IDConversion::Exit(void)
{
    this->close();
}
