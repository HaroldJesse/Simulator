#ifndef ADDOBJECTBASIC_HPP
#define ADDOBJECTBASIC_HPP

//#include "MainWindow.hpp"
#include "SimGlobals.hpp"

namespace Ui {
class AddObjectBasic;
}

class AddObjectBasic : public QDialog
{
    Q_OBJECT

public:
    explicit AddObjectBasic(QWidget *parent = nullptr);
    ~AddObjectBasic();

private:
    Ui::AddObjectBasic *ui;

private slots:
    void SetData (void);
    void AddBasicData (void);
    void Exit (void);

};

#endif // ADDOBJECTBASIC_HPP
