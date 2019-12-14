//#pragma once
#ifndef NAV_HPP
#define NAV_HPP

#include <QWidget>
#include <QtTextToSpeech>
#include <QMessageBox>

#include "Initialize.hpp"
#include "Setup.hpp"
#include "Spice.hpp"

namespace Ui {
class Nav;
}

class Nav : public QWidget
{
    Q_OBJECT

public:
    explicit Nav(QWidget *parent = nullptr);
    ~Nav();

    bool LoadNavigation (void);
    bool UnLoadNavigation (void);

public slots:
    void Exit (void);

signals:
    void CloseNav();

private:
    Ui::Nav *ui;

    QTextToSpeech *Verbalize = new QTextToSpeech;

private slots:
    void ID (void);
    void SetNavTime();
};

#endif // NAV_HPP
