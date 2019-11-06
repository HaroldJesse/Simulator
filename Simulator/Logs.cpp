#include "Logs.hpp"
#include "ui_Logs.h"

Logs::Logs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Logs)
{
    ui->setupUi(this);

    QStringList LogNameList;

    LogNameList << "" << "CommunicationsLog.sim"  << "EngineeringLog.sim"  << "HelmLog.sim" << "MasterLog.sim" << "SimulatorLog.sim";

    ui->LogSelection->clear();
    ui->LogSelection->addItems(LogNameList);
    ui->LogSelection->show();
    ui->LogSelectionlbl->show() ;
}

Logs::~Logs()
{
    delete ui;
}

void Logs::Initialize (void)
{
    //qDebug() << "Logs Initializeation";

    //CreateLog (Log::MasterLog);
    //CreateLog (Log::SimulatorLog);
    //CreateLog (Log::EngineeringLog);
    //CreateLog (Log::Helmlog);
    //CreateLog (Log::CommunicationsLog);

    //ReadLog(Logs::MasterLog);
}

void Logs::Name (void)
{
    ReadLog (ui->LogSelection->currentText());
    //qDebug() << "Current log Selection: " << ui->LogSelection->currentText();
}

bool Logs::CreateLog (QString LogsName)
{
    //Check for log
    //qDebug() << "Create Log" ;

    if (LogsName == "")
    {
        Verbalize->say("No create log name given");
        return false;
    }

    QDir::setCurrent(Initialize::StartupPath);
    QString SimLogFileName = Initialize::StartupPath + "/SimLogs/" + LogsName;
    QFile Log(SimLogFileName);

    if (Log.exists() == true)
    {
        qApp->beep();
        QMessageBox LogExists;
        LogExists.setText(LogsName + " Log file already exists");
        QTextToSpeech Verbalize;
        Verbalize.say(LogExists.text());
        LogExists.exec();

        Log.close();
        return true;
    }

    else

    {
        //create new Log database and check if good connection
        QSqlDatabase Logdb = QSqlDatabase::addDatabase("QSQLITE",LogsName);
        Logdb.setDatabaseName(SimLogFileName);

        if (Logdb.open() == false) //try to connect to the database
        {
            qApp->beep();
            QMessageBox LogOpen;
            LogOpen.setText(LogsName + " failed to open");
            QTextToSpeech Verbalize;
            Verbalize.say(LogOpen.text());
            LogOpen.exec();
            Log.close();
            return false ;
        }

        //qDebug() << "Start table creation";

    //QString SimLogFileName = CurrentDir  +  "SimLogs/" + LogName;
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
    //qDebug() << "SimLogFileName:" <<SimLogFileName;

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
        QSqlQuery Query("create table Log (ID integer primary key, "
                     "Type vatchar(10),"
                     "Date varchar(10),"
                     "Time varchar(10),"
                     "Source varchar(10),"
                     "Text varchar(80))", SimLog);

        if (Query.lastError().isValid())
        {
            //qDebug() << Query.lastError();
        }

        SimLog.close();
        WriteLog(SimLogFileName,Info,"Sim", qApp->tr("%1 Log Created.").arg(LogsName));

    }

    return true;
}

bool Logs::WriteLog (QString LogsName, QString Type,const QString Source,const QString Text)
{
    //qDebug() << "Write Log:";

    if (LogsName == "")
    {
        Verbalize->say("LogName is missing");
        return false;
    }

    if (Type == "")
    {
        Verbalize->say("LogType is missing");
        return false;
    }

    if (Source == "")
    {
        Verbalize->say("LogSource is missing");
        return false;
    }

    if (Text == "")
    {
        Verbalize->say("LogText is missing");
        return false;
    }

    QString FileName = LogsName;

    int Position = LogsName.indexOf("/");
    LogsName.remove(0,Position+1);
    LogsName.chop(3);
    //qDebug() << "WriteLog Name: " << LogName;

    QSqlDatabase Logdb = QSqlDatabase::addDatabase("QSQLITE",LogsName);
    Logdb.setDatabaseName(FileName);

    if (Logdb.open() == false) //try to connect to the database
    {
        qApp->beep();
        QMessageBox::critical(nullptr, qApp->tr("Failure to create log file"),
        qApp->tr("Log file %1 could not be created.").arg(LogsName));
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
        //qDebug() << query.lastError();
        return false;
    }

    Logdb.close();
    return true;
}

bool Logs::ReadLog (QString LogsName)
{
    //Check for log
    //qDebug() << "ReadLog LogName: " << LogName ;

    if (LogsName == "")
    {
        Verbalize->say("No read log name given");
        return false;
    }

    QDir::setCurrent(Initialize::StartupPath);
    QString SimLogFileName = Initialize::StartupPath + "/SimLogs/" + LogsName;
    QFile Log(SimLogFileName);
    qDebug() << "ReadLogName: " << SimLogFileName;

    if (Log.exists() == false)
    {
        qApp->beep();
        QMessageBox LogExists;
        LogExists.setText(LogsName + " Log file does not exist");
        QTextToSpeech Verbalize;
        Verbalize.say(LogExists.text());
        LogExists.exec();

        Log.close();
        return false;
    }

    else

    {
        //Read Log database and check if good connection
        QSqlDatabase Logsdb = QSqlDatabase::addDatabase("QSQLITE",LogsName);
        Logsdb.setDatabaseName(SimLogFileName);

        if (Logsdb.open() == false) //try to connect to the database
        {
            qApp->beep();
            QMessageBox LogOpen;
            LogOpen.setText(LogsName + " failed to open");
            QTextToSpeech Verbalize;
            Verbalize.say(LogOpen.text());
            LogOpen.exec();
            Log.close();
            qDebug() << "Logdb open fail";
            return false ;
        }


        //qDebug() << "Read : " << SimLogFileName;

        QSqlQuery Query(Logsdb);
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

        }

        //create new Objects.db database and check if good connection
        //QSqlDatabase Logsdb = QSqlDatabase::addDatabase("QSQLITE","LogsName");
        //Logsdb.setDatabaseName(SimLogFileName);

        if (Logsdb.open() == false) //try to connect to the database
        {
            qApp->beep();
            QMessageBox::critical(nullptr, qApp->tr("Can not connect to the database"),
            qApp->tr("Unable to establish a database connection.\n"));
            Logsdb.close();
            return false;
        }

        //qDebug()<< "Table: " << TableName;

        model = new QSqlTableModel(this, Logsdb);
        model->setTable(QString ("Log"));
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();

        ui->tableView->setModel(model);
        qDebug() << "Model: " << ui->tableView;
        //ui->tableView->setColumnHidden(model->fieldIndex("ID"), true);
        //ui->tableView->resizeColumnsToContents();

        //ui->tableView->setColumnWidth(11,30); //set surface acceleration column for 30 characters
        //ui->tableView->setSortingEnabled(model);

        //set view as read only No edits allowed
        //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        //Set rows to alternate colors
        ui->tableView->setAlternatingRowColors(true);

        //use row selection
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        //int Rowselect = ui->Inventory->currentIndex().row()
        ui->tableView->resizeColumnsToContents();
        ui->tableView->setWordWrap(true);

        ui->tableView->setShowGrid(true);


        //setWindowTitle(tr("Display - %1").arg(LogsName));

    }

    return true;
}

void Logs::Exit (void)
{
    this->close();
}



