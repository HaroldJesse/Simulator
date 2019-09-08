#ifndef CREATECRAFT_HPP
#define CREATECRAFT_HPP

#include "SimGlobals.hpp"

namespace Ui {
class CreateCraft;
}

class CreateCraft : public QDialog
{
    Q_OBJECT

public:
    explicit CreateCraft(Qt3DRender::QCamera *CameraEntity, QDialog *parent = 0);
    static QString ShipTime;

    ~CreateCraft();

    static QSize Size;
    static bool PwrUp;
    static bool EnvUp;
    static bool HelmUp;
    static bool NavUp;
    static bool ComUp;
    static bool CompUp;
    static bool SensUp;
    static bool TranUp;

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

public slots:
    void Exit (void);

signals:
    void CloseHelm (void);
    void CloseNavigation (void);
    void CloseAll (void);


private:
    Ui::CreateCraft *ui;

    Qt3DRender::QCamera *Camera;
    QTimer *Timer;
    QUdpSocket *UDPSocket;
    QTextToSpeech *Verbalize = new QTextToSpeech;

;




private slots:
    void PowerType (void);
    void HelmType (void);
    void NavigationType (void);
    void EnvironmentType (void);
    void CommunicationType (void);
    void TransponderType (void);
    void ComputerType (void);
    void SensorArrayType (void);
    void Time (void);
    void Broadcast (void);

    void on_Cmp_clicked();
};

#endif // CREATECRAFT_HPP
