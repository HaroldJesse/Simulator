#ifndef LOG_HPP
#define LOG_HPP

#include <QDialog>

#include "SimGlobals.hpp"

namespace Ui {
class Log;
}

class Log : public QDialog
{
    Q_OBJECT

public:
    explicit Log(QWidget *parent = 0);
    ~Log();

    QString MasterLog = ("MasterLog.sim");
    QString SimulatorLog  = ("SimulatorLog.sim");
    QString EngineeringLog = ("EngineeringLog.sim");
    QString Helmlog = ("HelmLog.sim");
    QString CommunicationsLog = ("CommunicationsLog.sim");

    QString Info = ("INFO");
    QString Warning = ("WARNING");
    QString Critical = "CRITICAL";
    QString Fatal = "FATAL";


    void Initialize (void);
    void CreateLog (QString LogName);
    bool WriteLog (QString LogName,QString Type, const QString Source, const QString Text);
    bool ReadLog (QString LogName);

private:
    Ui::Log *ui;
    QTextToSpeech *Verbalize = new QTextToSpeech;
};

#endif // LOG_HPP
