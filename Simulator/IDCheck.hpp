#pragma once
#ifndef IDCHECK_HPP
#define IDCHECK_HPP
//#endif // IDCHECK_HPP

#include <QString>
#include <QDialog>
#include <QSqlError>
#include <QDateTime>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "IDPort.hpp"
#include "IDAdd.hpp"

namespace Ui {
class IDCheck;
}

class IDCheck : public QDialog
{
    Q_OBJECT

public:
    explicit IDCheck(QWidget *parent = nullptr);
    ~IDCheck();

    static QString Device;
    static QString DeviceFolder;
    static QString File;

    static qint64  RecordNumber;
    static QString IndividualName;
    static QString FamilyName;
    static QString Department;
    static QString Level;
    static QDateTime ActivationDate;

    static int CertNumber;
    static QString Type;
    static QString SimCertificate;
    static QDateTime IssueDate;
    static QString IssuedBy;
    static QString Status;


    void  AddIndividual(void);

public slots:
    void ConnectDevice (void);
    void Simulator (void);
    void Quit (void);

private:
    Ui::IDCheck *ui;

    bool GetIDFile (void);

    void GetID (void);
    void CreateID (void);
    void SetAllCorners(int Radius);
    void SetRoundedCorners(int Radius_tl, int Radius_tr, int Radius_bl, int Radius_br);
    void SetRectHole (int PosX, int PosY, int H, int W);

    QTextToSpeech *Verbalize = new QTextToSpeech;
    QVector<QVoice> VoiceList;

};

#endif // IDCHECK_HPP
