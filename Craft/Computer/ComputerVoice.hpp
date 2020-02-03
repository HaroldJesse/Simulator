#ifndef COMPUTERVOICE_HPP
#define COMPUTERVOICE_HPP

#include <QWidget>
#include <QTextToSpeech>

namespace Ui {
class ComputerVoice;
}

class ComputerVoice : public QWidget
{
    Q_OBJECT

public:
    explicit ComputerVoice(QWidget *parent = nullptr);
    ~ComputerVoice();

    static QStringList Engines;

    void AvailableEngines (void);
    void AvailableLocale (void);
    void AvailableVoice (void);

    void Locale (void);
    void Pitch (void);
    void Rate (void);
    void State (void);
    void Voice (void);
    void Volume (void);

private:
    Ui::ComputerVoice *ui;
};

#endif // COMPUTERVOICE_HPP
