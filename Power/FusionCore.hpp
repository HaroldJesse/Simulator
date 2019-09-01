#ifndef FUSIONCORE_HPP
#define FUSIONCORE_HPP

#include <QDialog>
#include <QtTextToSpeech>
#include <QTimer>

#include "Power.hpp"
#include "BoronInjector.hpp"

namespace Ui {
class FusionCore;
}

class FusionCore : public QDialog
{
    Q_OBJECT

public:
    explicit FusionCore(QWidget *parent = 0);

    static bool BoronInjectionOn;
    static bool AlphaInjectionOn;
    static bool BoronPlasmaFieldOn;
    static bool AlphaPlasmaFieldOn;
    static bool AcceleratorFieldOn;
    static bool CollectorFieldOn;
    static bool Dc2AcConverterOn;

    ~FusionCore();

private:
    Ui::FusionCore *ui;

private slots:

    void BoronInjection (void);
    void AlphaInjection (void);
    void BoronPlasmaField (void);
    void AlphaPlasmaField (void);
    void AcceleratorField (void);
    void CollectorField (void);
    void Dc2AcConverter (void);
};

#endif // FUSIONCORE_HPP
