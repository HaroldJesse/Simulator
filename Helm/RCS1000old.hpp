#ifndef RCS1000_HPP
#define RCS1000_HPP

#include "SimGlobals.hpp"

namespace Ui {
class RCS1000;
}

class RCS1000 : public QWidget
{
    Q_OBJECT

public:
    explicit RCS1000(Qt3DCore::QCamera *CameraEntity, QWidget *parent = 0);
    ~RCS1000();

public slots:
        void Exit (void);

private:

    Ui::RCS1000 *ui;

    QTimer *Timer = new QTimer(this);

    Qt3DCore::QCamera *Camera;
    void UpDateSphericalPosition (void);
    void UpDateCartesianPosition (void);

    void UpDatePositionThrust (void);
    void UpDateAttitudeThrust (void);

private slots:

    void PitchUp(void);
    void PitchDown(void);
    void YawLeft(void);
    void YawRight(void);
    void RollCounterClockWise(void);
    void RollClockWise(void);

    void TranslateUp(void);
    void TranslateDown(void);
    void TranslatePort(void);
    void TranslateStarboard(void);
    void TranslateForward(void);
    void TranslateReverse(void);

    void SetUpDwnValue(void);
    void SetPrtSrbValue(void);
    void SetFwdRvrValue(void);

    void SetPitchValue(void);
    void SetYawValue(void);
    void SetRollValue(void);

    void MasterUpdate (void);


};

#endif // RCS1000_HPP
