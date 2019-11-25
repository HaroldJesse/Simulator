//#pragma once
#ifndef SPICE_HPP
#define SPICE_HPP
//#endif // SPICE_HPP

#include <QDialog>
#include <QWidget>
#include <QtTextToSpeech>
#include <QTimer>
#include <QMessageBox>

namespace Ui {
class Spice;
}

class Spice : public QDialog
{
    Q_OBJECT

public:
    explicit Spice(QWidget *parent = nullptr);
    ~Spice();

    /*
    ConstSpiceChar     *targ,
    SpiceDouble         et,
    ConstSpiceChar     *ref,
    ConstSpiceChar     *abcorr,
    ConstSpiceChar     *obs,
    SpiceDouble         starg[6],
    SpiceDouble        *lt
    */

    //SPK Reader variables
    static QString   Target;
    static double    Epoch;
    static QString   Frame;
    static QString   Abberation;
    static QString   Observer;
    static double    TargetState[6];
    static double    LightTime;

    //SpiceChar        * utcstr;


    //File
    static QString FileName;
    static int StepSize;
    static int Steps;

    void LocalTime (void);

public slots:
    void LoadKernels (void);
    void UseUTC (void);
    void UseEntered (void);
    void SPKRead (void);
    void TimerStart (int Milliseconds);
    void TimerStop (void);
    void MasterUpdate (void);
    void SetStepHours (void);
    void SetStepDays (void);
    void SetSteps10 (void);
    void SetSteps100 (void);




private:
    Ui::Spice *ui;
    QTextToSpeech *Verbalize = new QTextToSpeech;

    void UTCTime (void);
    void Print (void);
    bool OpenFile (QString Name);
    void WriteToFile (void);
    QTimer *Timer = new QTimer(this);

private slots:    
    void SetSteps (void);
    void SetStepSize (void);
    void Exit (void);
};

#endif // SPICE_HPP
