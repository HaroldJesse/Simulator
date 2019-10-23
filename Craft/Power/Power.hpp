#ifndef POWER_HPP
#define POWER_HPP

#include <QDialog>
#include <QTimer>

#include "FusionCore.hpp"

namespace Ui {
class Power;
}

class Power : public QDialog
{
    Q_OBJECT

public:
    explicit Power(QDialog *parent = nullptr);
    static QString TitleName;
    static QString Type;

    ~Power();

private:
    Ui::Power *ui;
    static bool Seg1;
    static bool Seg2;
    static bool Seg3;
    static bool Seg4;
    static bool Seg5;
    static bool Seg6;
    static bool Seg7;
    static bool Seg8;
    static bool Seg9;
    static bool Seg10;

    QTimer *Timer = new QTimer(this);

    static bool AutoFusion1On;
    static bool ManualFusion1On;
    static bool AutoFusion2On;
    static bool ManualFusion2On;
    static bool AutoFusion3On;
    static bool ManualFusion3On;





private  slots:
    void AutoStart (void);
    void MasterUpdate (void);
    void AutoStartup1 (void);
    void ManualStartup1 (void);
    void AutoStartup2 (void);
    void ManualStartup2 (void);
    void AutoStartup3 (void);
    void ManualStartup3 (void);
    void Done (void);

};

#endif // POWER_HPP
