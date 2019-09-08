#ifndef PTHRUSTER_HPP
#define PTHRUSTER_HPP

#include "SimGlobals.hpp"

namespace Ui {
class PThruster;
}

class PThruster : public QDialog
{
    Q_OBJECT

public:
    explicit PThruster (QDialog *parent = 0);
    ~PThruster();

    static double FwdRevThrust;
    static double PrtSrbThrust;
    static double UpDwnThrust;

    static double FwdRevThrottle;
    static double PrtSrbThrottle;
    static double UpDwnThrottle;

    static QSize Size;

private:
    Ui::PThruster *ui;

private slots:
    void Exit (void);
    void SetUpDwnValue(void);
    void UpDwnRange (void);
    void PrtSrbRange (void);
    void FwdRevRange (void);
    void SetPrtSrbValue(void);
    void SetFwdRevValue(void);
};

#endif // PTHRUSTER_HPP
