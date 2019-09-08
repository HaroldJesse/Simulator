#ifndef IDCHECK_HPP
#define IDCHECK_HPP

#include "SimGlobals.hpp"

namespace Ui {
class IDCheck;
}

class IDCheck : public QDialog
{
    Q_OBJECT

public:
    explicit IDCheck(QWidget *parent = 0);
    ~IDCheck();

    static QString SimFile;
    static QStringList Device;

    void  AddIndividual(void);

public slots:
    void ConnectDevice (void);
    void Simulator (void);
    void Quit (void);

private:
    Ui::IDCheck *ui;

    bool GetIDFile (void);
    void CreateID (QString Port);
    void SetAllCorners(int Radius);
    void SetRoundedCorners(int Radius_tl, int Radius_tr, int Radius_bl, int Radius_br);
    void SetRectHole (int PosX, int PosY, int H, int W);


    QTextToSpeech *Verbalize = new QTextToSpeech;
    QVector<QVoice> VoiceList;
};

#endif // IDCheck_HPP
