#ifndef IDCONVERSION_HPP
#define IDCONVERSION_HPP

#include "SimGlobals.hpp"

namespace Ui {
class IDConversion;
}

class IDConversion : public QWidget
{
    Q_OBJECT

public:
    explicit IDConversion(QWidget *parent = 0);
    ~IDConversion();

    //File
    static QString FileName;

private:
    Ui::IDConversion *ui;
    void WriteToFile (void);

private slots:
    void CreateList (void);
    void Convert (void);
    void Exit (void);

};

#endif // IDCONVERSION_HPP
