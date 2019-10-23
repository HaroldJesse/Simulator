#ifndef PTHRUSTER_HPP
#define PTHRUSTER_HPP

#include <QDialog>

#include "Initialize.hpp"

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
    static double HeadingThrust;
    static double  MarkThrust;

    static double FwdRevThrottle;
    static double HeadingThrottle;
    static double MarkThrottle;

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
