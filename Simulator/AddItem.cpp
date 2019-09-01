#include "AddItem.hpp"
#include "ui_AddItem.h"

QString AddItem::Entry ("");

AddItem::AddItem(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::AddItem)
{
    ui->setupUi(this);
    ui->Label->setText("");
    ui->AddItem->text();
}

AddItem::~AddItem()
{
    delete ui;
}

void Exit (void)
{
    AddItem::Entry =
}
