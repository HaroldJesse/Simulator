#ifndef VOICE_HPP
#define VOICE_HPP

#include <QDialog>
#include <QWidget>
#include <QTextToSpeech>
#include <QDebug>

namespace Ui {
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

private slots:

    void Setup (void);
};

#endif // VOICE_HPP
