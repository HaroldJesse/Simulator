#ifndef CERTIFICATE_HPP
#define CERTIFICATE_HPP

#include "SimGlobals.hpp"

namespace Ui {
class Certificate;
}

class Certificate : public QDialog
{
    Q_OBJECT

public:
    explicit Certificate(QWidget *parent = 0);
    ~Certificate();



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
