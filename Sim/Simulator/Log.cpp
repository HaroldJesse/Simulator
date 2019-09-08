#include "Log.hpp"
#include "ui_Log.h"

Log::Log(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Log)
{
    ui->setupUi(this);
}

Log::~Log()
{
    delete ui;
}

void Log::Initialize (void)
{
    //qDebug() << "Logs Initializeation";

    CreateLog (Log::MasterLog);
    CreateLog (Log::SimulatorLog);
    CreateLog (Log::EngineeringLog);
    CreateLog (Log::Helmlog);
    CreateLog (Log::CommunicationsLog);
}

void Log::CreateLog (QString LogName)
{

    //Check for logs
    //qDebug() << "Create Log" ;

    QDir FileName;
    QString CurrentDir = FileName.currentPath();
    QString SimLogFileName = IDCheck::Device + "/SimLogs/" + LogName;
    QFile Log(SimLogFileName);

    //qDebug() << " Log::" << IDCheck::Device +  "/SimLogs/" + LogName;

    if (Log.exists() == true)
    {
       /*
        qApp->beep();
        QMessageBox LogExists;
        LogExists.setText(LogName + " Log file already exists");
        QTextToSpeech Verbalize;
        Verbalize.say(LogExists.text());
        LogExists.exec();
        Log.close();
        */

        return ;
    }

    else

    {
        //create new Log database and check if good connection
        QSqlDatabase Logdb = QSqlDatabase::addDatabase("QSQLITE",LogName);
        Logdb.setDatabaseName(SimLogFileName);

        //qDebug() << "DatabaseName: " << Logdb.databaseName();

        if (Logdb.open() == false) //try to connect to the database
        {
            qApp->beep();
            QMessageBox LogOpen;
            LogOpen.setText(LogName + " failed to open");
            QTextToSpeech Verbalize;
            Verbalize.say(LogOpen.text());
            LogOpen.exec();
            Log.close();
            return ;
        }

        //qDebug() << "Start table creation";

    QString SimLogFileName = CurrentDir  +  "/SimLogs/" + LogName;
    QFile DatabaseFile(SimLogFileName);


    if (DatabaseFile.exists() == false) //try to connect to the database
    {
        qApp->beep();
        QMessageBox NoObjectDB;
        NoObjectDB.setText("Creating new simulator log");
        QTextToSpeech Verbalize;
        Verbalize.say(NoObjectDB.text());
        NoObjectDB.exec();
        DatabaseFile.close();
    }

    //check if good connection
    QSqlDatabase SimLog = QSqlDatabase::addDatabase("QSQLITE","SimLog");
    SimLog.setDatabaseName(SimLogFileName);

    if (SimLog.open() == false) //try to connect to the database
    {
        qApp->beep();
        QMessageBox NoConnection;
        NoConnection.setText("Could not connect to ");
        QTextToSpeech Verbalize;
        Verbalize.say(NoConnection.text());
        NoConnection.exec();
    }

        //qDebug() << "Tables: " << SimLog.tables();

    //create Customer table
        QSqlQuery Query("create table Log (ID integer primary key, "
                     "Type vatchar(10),"
                     "Date varchar(10),"
                     "Time varchar(10),"
                     "Source varchar(10),"
                     "Text varchar(80))", SimLog);

        if (Query.lastError().isValid())
        {
            qDebug() << Query.lastError();
        }

        SimLog.close();
        WriteLog(SimLogFileName,Info,"Sim", qApp->tr("%1 Log Created.").arg(LogName));

    //SimLogFileName


    }

}

bool Log::WriteLog (QString LogName, QString Type,const QString Source,const QString Text)
{
    //qDebug() << "Write Log:";

    if (LogName == "" ||Type == "" || Source == "" || Text == "")
    {
        return false;
    }

    QString FileName = LogName;

    int Position = LogName.indexOf("/");
    LogName.remove(0,Position+1);
    LogName.chop(3);
    //qDebug() << "WriteLog Name: " << LogName;

    QSqlDatabase Logdb = QSqlDatabase::addDatabase("QSQLITE",LogName);
    Logdb.setDatabaseName(FileName);

    if (Logdb.open() == false) //try to connect to the database
    {
        qApp->beep();
        QMessageBox::critical(0, qApp->tr("Failure to create log file"),
        qApp->tr("Log file %1 could not be created.").arg(LogName));
        Logdb.close();
    }

    QDate  Date;
    Date = Date.currentDate();

    QTime  Time;
    Time = Time.currentTime();

    QSqlQuery query(Logdb);
    query.prepare("INSERT INTO Log (Type, Date, Time, Source, Text) "
                  "VALUES ( :type, :date, :time, :source, :text)");

    //query.bindValue(":ID", 1);
    query.bindValue(":type", Type);
    query.bindValue(":date", Date);
    query.bindValue(":time", Time);
    query.bindValue(":source", Source);
    query.bindValue(":text", Text);
    query.exec();

    if (query.lastError().isValid())
    {
        qDebug() << query.lastError();
        return false;
    }

    Logdb.close();
    return true;
}

bool Log::ReadLog (QString LogName)
{

    qDebug() << "Read Log:";
    if (LogName == "")
    {
        return false;
    }

    QString FileName = LogName;

    int Position = LogName.indexOf("/");
    LogName.remove(0,Position+1);
    LogName.chop(3);
    //qDebug() << "WriteLog Name: " << LogName;

    QSqlDatabase Logdb = QSqlDatabase::database(LogName);
    Logdb.setDatabaseName(FileName);

    if (Logdb.open() == false) //try to connect to the database
    {
        qApp->beep();
        QMessageBox::critical(0, qApp->tr("Failure to create log file"),
        qApp->tr("Log file %1 could not be created.").arg(LogName));
        Logdb.close();
    }

    QSqlQuery Query(Logdb);
    Query.exec("SELECT * FROM LOG");

    while (Query.next())
    {
        int  type = Query.record().indexOf("Type");
        QString Type = Query.value(type).toString();
        Type = Type + "  ";
        int  date = Query.record().indexOf("Date");
        QString Date = Query.value(date).toString();
        Date = Date + "  ";
        int  time = Query.record().indexOf("Time");
        QString Time = Query.value(time).toString();
        Time = Time + "  ";
        int  source = Query.record().indexOf("Source");
        QString Source = Query.value(source).toString();
        Source = Source + "  ";
        int  text = Query.record().indexOf("Text");
        QString Text = Query.value(text).toString();

        QString LogLine = Type + Date + Time + Source + Text;

        ui->plainTextEdit->appendPlainText(LogLine);
        QString Line = ui->plainTextEdit->toPlainText();

        //qDebug() << "LogLine: " << LogLine;
        //qDebug() << "Line: " << Line;
    }

    //LogView->show();

    return true;
}
