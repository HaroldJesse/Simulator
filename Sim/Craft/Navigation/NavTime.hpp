#ifndef NAVTIME_HPP
#define NAVTIME_HPP

#include "SimGlobals.hpp"

namespace Ui {
class NavTime;
}

class NavTime : public QWidget
{
    Q_OBJECT

public:
    explicit NavTime(QWidget *parent = 0);
    ~NavTime();

    //SPK Reader variables
    static QString Target;
    static SpiceDouble SpiceET;
    static QString Frame;
    static QString Abberation;
    static QString Observer;
    static SpiceDouble  SpiceState[6];
    static SpiceDouble SpiceLightTime;

/*  ConstSpiceChar     *targ,
    SpiceDouble         et,
    ConstSpiceChar     *ref,
    ConstSpiceChar     *abcorr,
    ConstSpiceChar     *obs,
    SpiceDouble         starg[6],
    SpiceDouble        *lt
*/

    void LocalTime (void);

public slots:

private:
    Ui::NavTime *ui;

    void SetTarget (void);

private slots:
    void SetETTime (void);
    void SetTime (void);
    void Exit (void);
};

#endif // NAVTIME_HPP
