#ifndef OThruster_HPP
#define OThruster_HPP

#include <QDialog>
#include "Initialize.hpp"

namespace Ui {
class OThruster;
}

class OThruster : public QDialog
{
    Q_OBJECT

public:
    explicit OThruster(QDialog *parent = 0);
    ~OThruster();

    static double PitchThrust;
    static double YawThrust;
    static double RollThrust;

    static double PitchThrottle;
    static int   PitchDirection;
    static bool  PitchThrusterOn;

    static double YawThrottle;
    static int   YawDirection;
    static bool  YawThrusterOn;

    static double RollThrottle;
    static int   RollDirection;
    static bool  RollThrusterOn;

    static QSize Size;

public slots:
        void Exit (void);

private:
    Ui::OThruster *ui;

private slots:
        void SetPitchValue(void);
        void SetYawValue(void);
        void SetRollValue(void);
        void PitchRange(void);
        void YawRange(void);
        void RollRange(void);


};

#endif // OThruster_HPP
