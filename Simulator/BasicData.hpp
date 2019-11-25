#pragma once
#ifndef BASICDATA_HPP
#define BASICDATA_HPP
//#endif // BASICDATA_HPP

#include <QDialog>
#include <QTextToSpeech>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

#include "Initialize.hpp"

namespace Ui {
class BasicData;
}

class BasicData : public QDialog
{
    Q_OBJECT

public:
    explicit BasicData(QWidget *parent = nullptr);
    ~BasicData();

    static QString Choice;

    void ClearAll (void);


public slots:
    void Exit (void);
    //void LoadTextFile (void);

private:
    Ui::BasicData *ui;
    QTextToSpeech *Verbalize = new QTextToSpeech;
    void Display (void);


private slots:
    void Basic (void);
    void Orbital (void);
    void Environmental (void);

};

#endif // BASICDATA_HPP
