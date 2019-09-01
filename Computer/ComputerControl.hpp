#ifndef COMPUTERCONTROL_HPP
#define COMPUTERCONTROL_HPP

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

private:
    Ui::ComputerControl *ui;

private slots:
        //void SetVoice (void);
};

#endif // COMPUTERCONTROL_HPP
