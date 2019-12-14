#include "Nav.hpp"
#include "ui_Nav.h"

Nav::Nav(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Nav)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setFocus();
    //this->grabMouse();
    int Width = this->width();
    this->move(Initialize::WindowWidth/2 - Width/2,0);
}

Nav::~Nav()
{
    delete ui;
}

bool Nav::LoadNavigation (void)
{
    //Camera = CameraEntity;

    if (Setup::SimCraftClass == "Unknown")
    {
        qApp->beep();
        QMessageBox msgBox;
        msgBox.setText("The Craft type is unknown");
        Verbalize->say(msgBox.text());
        msgBox.exec();
        return (false);
    }

    else

    if (Setup::SimCraftClass == "CargoShortHaul")
    {
        Navigation *Nav1 =  new Navigation();
        connect (this, SIGNAL(CloseNavigation()), Nav1,SLOT(Exit()));
        Nav1->setFocus();
        Nav1->show();
    }

    if (Setup::SimCraftClass == "CargoLongHaul")
    {
        qDebug() << "Nav: ";
        Navigation *Nav1 =  new Navigation();
        connect (this, SIGNAL(CloseNavigation()), Nav1,SLOT(Exit()));
        Nav1->show();
    }

    if (Setup::SimCraftClass == "TransportShortHaul")
    {
        Navigation *Nav1 =  new Navigation();
        connect (this, SIGNAL(CloseNavigation()), Nav1,SLOT(Exit()));
        Nav1->exec();
    }

    if (Setup::SimCraftClass == "TransportLongHaul")
    {
        Navigation *Nav1 =  new Navigation();
        connect (this, SIGNAL(CloseNavigation()), Nav1,SLOT(Exit()));
        Nav1->show();
    }
    return (true);
}

bool Nav::UnLoadNavigation (void)
{
    return (true);
}

void Nav::SetNavTime (void)
{
    Spice *CSpice = new Spice();
    //CSpice->show();
    CSpice->exec();
}


void Nav::Exit (void)
{
    //qDebug() << "Nav Exit";
    emit CloseNav();
    this->close();
}


void Nav::ID (void)
{

    qDebug() << "ID";
    //IDConversion *ID = new IDConversion();
    //ID->show();
}

