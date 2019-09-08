#ifndef IDPORT_HPP
#define IDPORT_HPP

#include "SimGlobals.hpp"

namespace Ui {
class IDPort;
}

class IDPort : public QDialog
{
    Q_OBJECT

public:
    explicit IDPort(QWidget *parent = 0);



    ~IDPort();

public slots:
    void ConnectPort (void);

private:
    Ui::IDPort *ui;

    QTextToSpeech *Verbalize = new QTextToSpeech;

};

#endif // IDPORT_HPP
