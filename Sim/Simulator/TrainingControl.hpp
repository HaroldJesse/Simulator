#ifndef TRAININGCONTROL_HPP
#define TRAININGCONTROL_HPP

#include <QDialog>

namespace Ui {
class TrainingControl;
}

class TrainingControl : public QDialog
{
    Q_OBJECT

public:
    explicit TrainingControl(QWidget *parent = nullptr);
    ~TrainingControl();

private:
    Ui::TrainingControl *ui;
};

#endif // TRAININGCONTROL_HPP
