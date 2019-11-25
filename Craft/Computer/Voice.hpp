//#pragma once
#ifndef VOICE_HPP
#define VOICE_HPP
//#endif // VOICE_HPP

#include <QDialog>
#include <QTextToSpeech>
#include <QDebug>

namespace Ui
{
    class Voice;
}

class Voice : public QDialog
{
    Q_OBJECT

public:
    explicit Voice(QWidget *parent = nullptr);
    ~Voice();

private:
    Ui::Voice *ui;

    void SetVoice (void);
    void SetLocale (void);
    void SetGender (void);

private slots:
    void Setup (void);
};

#endif // VOICE_HPP
