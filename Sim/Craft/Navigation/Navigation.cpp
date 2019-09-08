#include "Navigation.hpp"
#include "ui_Navigation.h"

Navigation::Navigation(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Navigation)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setFocus();
    //this->grabMouse();
    int Width = this->width();
    this->move(Initialize::WindowWidth/2 - Width/2,0);
}

Navigation::~Navigation()
{
    delete ui;
}


bool Navigation::LoadNavigation (void)
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

bool Navigation::UnLoadNavigation (void)
{
    return (true);
}

void Navigation::SetNavTime (void)
{
    Spice *CSpice = new Spice();
    //CSpice->show();
    CSpice->exec();
}


void Navigation::Exit (void)
{
    //qDebug() << "Nav Exit";
    emit CloseNavigation();
    this->close();
}


void Navigation::ID (void)
{

    qDebug() << "ID";
    //IDConversion *ID = new IDConversion();
    //ID->show();
}

