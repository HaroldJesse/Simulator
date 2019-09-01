#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "SimGlobals.hpp"

namespace Ui {
class Clock;
}

class Clock : public QDialog
{
    Q_OBJECT

public:
    explicit Clock(QWidget *parent = 0);
    QString GetClock (void);
    //void SetDateTime (qint64 DateTime);

    static QString ShipTime;


    /** AdjustLunarLanding
       Lunar Landing July 20, 1969, 20:17:40 UTC
       Seconds 20 = 20
       Minutes 42 = 2520
       Hours 3 = 10800
       Days 10 = 864000 //Days 11 = 950400
       August       31 days = 26784000
       September    30 days = 25920000
       October      31 days = 26784000
       November     30 days = 25920000
       December     31 days = 26784000
       */
       static const long int AdjustLunarLanding = 20+2520+10800+864000+26784000+25920000+26784000+25920000+26784000;

       /**
       AdjustLunarFirstStep
       Lunar first step July 21 02:56:15 UTC
       Seconds 20 = 45
       Minutes 3 = 180
       Hours 22 = 79200
       Days 9 = 777600 //Days 10 = 864000
       August       31 days = 26784000
       September    30 days = 25920000
       October      31 days = 26784000
       November     30 days = 25920000
       December     31 days = 26784000
       */
       static const long int AdjustLunarFirstStep = 45+180+79200+777600+26784000+25920000+26784000+25920000+26784000;

    ~Clock();

private:
    Ui::Clock *ui;
    QTimer *Timer;

private slots:
        void ClockUpdate (void);
};

#endif // CLOCK_HPP
