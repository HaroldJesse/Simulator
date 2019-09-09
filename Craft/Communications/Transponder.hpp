#ifndef TRANSPONDER_HPP
#define TRANSPONDER_HPP

#include <QDialog>
#include <QUdpSocket>

#include <QtNetwork>

namespace Ui {
class Transponder;
}

class Transponder : public QDialog
{
    Q_OBJECT

public:
    explicit Transponder(QWidget *parent = 0);
    void StartBroadcast(void);

    static QByteArray TransponderData;
    static QByteArray TransponderDataSend;

    ~Transponder();

public slots:
    void ActivateDisplay (void);
    void DeactivateDisplay (void);


private:
    Ui::Transponder *ui;    
    void Stop(void);

    QTimer *Timer;
    QUdpSocket *UDPSocket;

private slots:
    void Listen (void);

};

#endif // TRANSPONDER_HPP
