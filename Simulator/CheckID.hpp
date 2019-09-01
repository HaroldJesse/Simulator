#ifndef CHECKID_HPP
#define CHECKID_HPP

#include "SimGlobals.hpp"

namespace Ui {
class CheckID;
}

class CheckID : public QDialog
{
    Q_OBJECT

public:
    explicit CheckID(QWidget *parent = 0);
    ~CheckID();

    static QString SimFile;

public slots:
    void DeviceConnected (void);
    void Simulator (void);

private:
    Ui::CheckID *ui;

    bool GetIDFile (void);
    void CreateID (QString Port);
    void SetAllCorners(int Radius);
    void SetRoundedCorners(int Radius_tl, int Radius_tr, int Radius_bl, int Radius_br);
    void SetRectHole (int PosX, int PosY, int H, int W);


};

#endif // CHECKID_HPP
