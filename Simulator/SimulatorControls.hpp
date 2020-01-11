#pragma once
#ifndef SIMULATORCONTROLS_HPP
#define SIMULATORCONTROLS_HPP
//#endif // SIMULATORCONTROLS_HPP

#include <QDialog>
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QTextEdit>
#include <QSqlTableModel>
#include <QTextToSpeech>
#include <QTextCodec>

#include "BasicData.hpp"

namespace Ui {
class SimulatorControls;
}

class SimulatorControls : public QDialog
{
    Q_OBJECT


public:
    explicit SimulatorControls(QWidget *parent = nullptr);
    ~SimulatorControls();

    void SetText (QString);    
    QString GetText (void);

    static QString SimDescription;

    QString RedSqr5 = "background-color: red;"
                     " color: white;"
                     "border-radius: 5px;";

    QString GrnSqr5 = "background-color: green;"
                          " color: white;"
                          "border-radius: 5px;";

    QString RedRnd15 = "background-color: red;"
                          " color: white;"
                          "border-radius: 15px;";

    QString GrnRnd15 = "background-color: green;"
                          " color: white;"
                          "border-radius: 15px;";

    QString YelRnd15 = "background-color: yellow;"
                          " color: white;"
                          "border-radius: 15px;";

    QString OrgRnd15 = "background-color: orange;"
                          " color: white;"
                          "border-radius: 15px;";
public slots:
    void Name(void);
    void BasicDataDisplay (void);

private:
    Ui::SimulatorControls *ui;

    QScreen *screensize;

    static bool RunUp;
    static bool WrittenUp;
    static bool VerbalUp;

    bool Load(const QString &f);

    QTextEdit *textEdit;
    QTextToSpeech *Verbalize = new QTextToSpeech;

private slots:
    void Run (void);
    void Written (void);
    void Verbal (void);
    void Exit (void);

};

#endif // SIMULATORCONTROLS_HPP
