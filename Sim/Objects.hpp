#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include <QDialog>

namespace Ui {
class Objects;
}

class Objects : public QDialog
{
    Q_OBJECT

public:
    explicit Objects(QWidget *parent = nullptr);
    ~Objects();

private:
    Ui::Objects *ui;
};

#endif // OBJECTS_HPP
