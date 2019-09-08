#ifndef ADDITEM_HPP
#define ADDITEM_HPP

#include "SimGlobals.hpp"

namespace Ui {
class AddItem;
}

class AddItem : public QDialog
{
    Q_OBJECT

public:
    explicit AddItem(QDialog *parent = 0);
    ~AddItem();

private:
    Ui::AddItem *ui;

    static QString Entry;

private slots:
    void Exit (void);
};

#endif // ADDITEM_HPP
