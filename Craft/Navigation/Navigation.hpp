#pragma once
#ifndef NAVIGATION_HPP
#define NAVIGATION_HPP
//#endif // NAVIGATION_HPP

#include <QDialog>
#include <QtTextToSpeech>
#include <QMessageBox>

#include "Initialize.hpp"
#include "Setup.hpp"
#include "Spice.hpp"


namespace Ui {
class Navigation;
}

class Navigation : public QDialog
{
    Q_OBJECT

public:
    explicit Navigation(QDialog *parent = nullptr);
    ~Navigation();

    bool LoadNavigation (void);
    bool UnLoadNavigation (void);

public slots:
    void Exit (void);

signals:
    void CloseNavigation();

private:
    Ui::Navigation *ui;

    QTextToSpeech *Verbalize = new QTextToSpeech;

private slots:
    void ID (void);
    void SetNavTime();

};

#endif // NAVIGATION_HPP
