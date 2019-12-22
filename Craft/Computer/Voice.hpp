//#pragma once
#ifndef VOICE_HPP
#define VOICE_HPP
//#endif // VOICE_HPP

#include <QDialog>
#include <QTextToSpeech>
#include <QDebug>

#include "Craft.hpp"

namespace Ui
{
    class Voice;
}

class Voice : public QDialog
{
    Q_OBJECT

public:
    explicit Voice(QWidget *parent = nullptr);
    QTextToSpeech *Verbalize;


    ~Voice();

private:    
    Ui::Voice *ui;

    void Setup (void);
    void SetVoice (void);
    void SetLocale (void);
    void SetGender (void);

    void Alert (QString Text);
    void Error (void);
    void Warning (void);
    void Instruction (void);

private slots:

};

#endif // VOICE_HPP
