#ifndef BORONINJECTOR_HPP
#define BORONINJECTOR_HPP

#include <QDialog>
#include <QTextToSpeech>
#include <QTimer>
#include <QMessageBox>

#include "BoronInjector.hpp"

namespace Ui {
class BoronInjector;
}

class BoronInjector : public QDialog
{
    Q_OBJECT

public:
    explicit BoronInjector(QWidget *parent = 0);

    static bool AlphaFieldOn;
    static bool PinchFieldOn;


    static bool BoronHeaterOn;
    static bool HeaterTempReached;
    static int  BoronTempSetpoint;
    static int  BoronTempValue;
    static int  BoronChargeSetpoint;
    static int  BoronChargeValue;


    static bool AlphaHeaterOn;
    static int  AlphaInjectionSetPoint;
    static int  AlphaInjectionValue;


    static int  BoronPlasmaFieldSetpoint;
    static int  BoronPlasmaFieldValue;


    static int  AlphaPlasmaFieldSetpoint;
    static int  AlphaPlasmaFieldValue;


    static int  AcceleratorFieldSetpoint;
    static int  AcceleratorFieldValue;


    static int  CollectorFieldSetpoint;
    static int  CollectorFieldValue;


    static int  Dc2AcConverterSetpoint;
    static int  Dc2AcConverterValue;


    ~BoronInjector();

private:
    Ui::BoronInjector *ui;
    QTimer *Timer;
    QTextToSpeech *Verbalize = new QTextToSpeech;

    void Ramp (int &Setpoint, int &Variable, int Increment);

private slots:
    void MasterUpdate (void);
    void SetBoronHeaterOn (void);
    void SetBoronHeaterSetPoint (void);
    void SetBoronChargeSetPoint (void);
    /*
    void SetAlphaHeaterSetPoint (void);
    void SetBoronFieldSetPoint (void);
    void SetAlphaFieldSetPoint (void);
    void SetPinchFieldSetPoint (void);
    void SetAcceleratorSetPoint (void);
    void SetDc2AcConverterOn (void);
    */
    void Done (void);


};

#endif // BORONINJECTOR_HPP
