#pragma once
#ifndef LOGS_HPP
#define LOGS_HPP
#endif // LOGS_HPP

#include <QDialog>
#include <QtTextToSpeech>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QListView>
#include <qtableview.h>

#include "IDCheck.hpp"
#include "Initialize.hpp"

namespace Ui {
class Logs;
}

class Logs : public QDialog
{
    Q_OBJECT

public:
    explicit Logs(QWidget *parent = nullptr);
    ~Logs();

    QString MasterLog = ("Master.log");
    QString SimulatorLog  = ("Simulator.log");
    QString EngineeringLog = ("Engineering.log");
    QString HelmLog = ("Helm.log");
    QString CommunicationsLog = ("Communications.log");

    QString Info = ("INFO");
    QString Warning = ("WARNING");
    QString Critical = "CRITICAL";
    QString Fatal = "FATAL";


    void Initialize (void);
    bool CreateLog (QString LogsName);
    bool WriteLog (QString LogsName,QString Type, const QString Source, const QString Text);
    bool ReadLog (QString LogsName);

private:
    Ui::Logs *ui;
    QTextToSpeech *Verbalize = new QTextToSpeech;
    QSqlTableModel *model = new QSqlTableModel;

public slots:
    void Exit(void);
    //bool ReadLog (QString LogsName);
    void Name(void);

signals:

};
