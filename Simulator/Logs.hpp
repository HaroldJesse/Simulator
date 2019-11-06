#ifndef LOGS_HPP
#define LOGS_HPP

#include <QDialog>

namespace Ui {
class Logs;
}

class Logs : public QDialog
{
    Q_OBJECT

public:
    explicit Logs(QWidget *parent = nullptr);
    ~Logs();

private:
    Ui::Logs *ui;
};

#endif // LOGS_HPP
