#pragma once
#ifndef CRAFTCONTROLS_HPP
#define CRAFTCONTROLS_HPP

#include <QDialog>
#include <QWidget>
#include <Qt3DRender>
#include <QTimer>

#include "Power.hpp"
#include "Transponder.hpp"
#include "Helm.hpp"
#include "Voice.hpp"
#include "Setup.hpp"
#include "Navigation.hpp"
#include "Helm.hpp"

namespace Ui {
class CraftControls;
}

class CraftControls : public QDialog
{
    Q_OBJECT

public:
    explicit CraftControls(Qt3DRender::QCamera *CameraEntity, QWidget *parent = nullptr);

    ~CraftControls();

    static QString ShipTime;
    static QSize Size;
    static int Height;
    static int Width;

    QString RedSqr = "background-color: red;"
                     " color: white;"
                     "border-radius: 5px;";

    QString GrnSqr = "background-color: green;"
                          " color: white;"
                          "border-radius: 5px;";

    QString RedRnd = "background-color: red;"
                          " color: white;"
                          "border-radius: 20px;";

    QString GrnRnd = "background-color: green;"
                          " color: white;"
                          "border-radius: 20px;";

    QString YelRnd = "background-color: yellow;"
                          " color: white;"
                          "border-radius: 20px;";

    QString OrgRnd = "background-color: orange;"
                          " color: white;"
                          "border-radius: 20px;";

private:
    Ui::CraftControls *ui;

    Qt3DRender::QCamera *Camera;
    QTimer *Timer;
    QUdpSocket *UDPSocket;

    static bool PwrUp;
    static bool EnvUp;
    static bool HelmUp;
    static bool NavUp;
    static bool ComUp;
    static bool CompUp;
    static bool SensUp;
    static bool TranUp;

    //void Exit ();

signals:


private slots:
    void CraftPower (void);
    void CraftHelm (void);
    void CraftNavigation (void);
    void CraftEnvironment (void);
    void CraftCommunication (void);
    void CraftTransponder (void);
    void CraftComputer (void);
    void CraftSensors (void);
    void CraftSetTime (void);
    void CraftBroadcast (void);
    void CraftSetLocal (void);
    void CraftSetSolar (void);
    void CraftSetUTC (void);
    void Exit ();
    void HelmOff (void);
};

#endif // CRAFTCONTROLS_HPP
