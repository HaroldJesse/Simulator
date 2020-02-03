#pragma once
#ifndef COMPUTERCONTROLS_HPP
#define COMPUTERCONTROLS_HPP

#include <QWidget>
#include <QDebug>

#include "Initialize.hpp"
namespace Ui {
class ComputerControls;
}

class ComputerControls : public QDialog
{
    Q_OBJECT

public:
    explicit ComputerControls(QWidget *parent = nullptr);
    ~ComputerControls();


    static QSize Size;
    static int Height;
    static int Width;

private:
    Ui::ComputerControls *ui;

private slots:

    void Exit (void);
};

#endif // COMPUTERCONTROLS_HPP
