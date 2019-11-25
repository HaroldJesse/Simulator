//#pragma once
#ifndef COMPUTERCONTROL_HPP
#define COMPUTERCONTROL_HPP
//#endif // COMPUTERCONTROL_HPP

#include <QDialog>

namespace Ui {
class ComputerControl;
}

class ComputerControl : public QDialog
{
    Q_OBJECT

public:
    explicit ComputerControl(QWidget *parent = nullptr);
    ~ComputerControl();

    ComputerControl (void);

private:
    Ui::ComputerControl *ui;

private slots:

};

#endif // COMPUTERCONTROL_HPP
