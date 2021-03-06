#pragma once
#ifndef IDADD_HPP
#define IDADD_HPP
//#endif // IDADD_HPP

#include <QDialog>
#include <QMessageBox>
#include <QDir>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTextToSpeech>
#include <QSqlField>

#include "CraftControls.hpp"
#include "IDCheck.hpp"

namespace Ui {
class IDAdd;
}

class IDAdd : public QDialog
{
    Q_OBJECT

public:
    explicit IDAdd(QWidget *parent = nullptr);
    ~IDAdd();

    static int RecordNumber;
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

    void CertificateAdd (void);

public slots:


private:
    Ui::IDAdd *ui;

    QSqlTableModel *Edit;
    QTextToSpeech *Verbalize = new QTextToSpeech;

    void CreateID (void);
    void CreateCertificates (void);

private slots:
    void Accept (void);
    void Cancel (void);

};

#endif // IDADD_HPP
