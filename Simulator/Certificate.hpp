//#pragma once
#ifndef CERTIFICATE_HPP
#define CERTIFICATE_HPP
//#endif // CERTIFICATE_HPP

#include <QDialog>
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QDebug>
#include <QDir>
#include <QString>

#include "IDCheck.hpp"

namespace Ui {
class Certificate;
}

class Certificate : public QDialog
{
    Q_OBJECT

public:
    explicit Certificate(QWidget *parent = nullptr);
    ~Certificate();

    static QString CertificateStatus;

private:
    Ui::Certificate *ui;

    QSqlTableModel *model;
    QSortFilterProxyModel *Cmodel;

    void GetID (void);
    void GetCertificates (void);
    void GetSimulators (void);

private slots:

    void Quit (void);
};

#endif // CERTIFICATE_HPP
