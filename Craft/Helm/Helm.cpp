#include "Helm.hpp"

Helm::Helm(QWidget *parent) : QWidget(parent)
{

}

Helm::~Helm()
{

}

bool Helm::LoadHelm (Qt3DRender::QCamera *CameraEntity)
{
    //qDebug() << "Helm started";
    QTextToSpeech Verbalize;

    Verbalize.say("Helm Control is online");

    //Camera = CameraEntity;

    if (Setup::SimCraftType == "Unknown")
    {
        //qApp->beep();
        QMessageBox msgBox;
        msgBox.setText("Craft Creation Error The Craft type is unknown");
        //QTextToSpeech Verbalize;
        //Verbalize.say(msgBox.text());
        msgBox.exec();
    }

    else

    if (Setup::SimCraftType == "CargoShortHaul")
    {
        PositionOrientation *PO = new PositionOrientation();
        connect (this, SIGNAL(CloseHelm()), PO,SLOT(Exit()));

        PO->show();

        OThruster *OT = new OThruster();
        connect (this, SIGNAL(CloseHelm()), OT,SLOT(Exit()));

        OT->show();

        PThruster *PT = new PThruster();
        connect (this, SIGNAL(CloseHelm()), PT,SLOT(Exit()));

        PT->show();

        RCS2000 *RCS2 = new RCS2000(CameraEntity);
        connect (this, SIGNAL(CloseHelm()), RCS2,SLOT(Exit()));
        RCS2->show();

        //RCS1000 *RCS1 =  new RCS1000(CameraEntity);
        //connect (this, SIGNAL(CloseHelm()), RCS1,SLOT(Exit()));
        //RCS1->show ();


    }

    else

    if (Setup::SimCraftType == "CargoLongHaul")
    {
        RCS1000 *RCS1 =  new RCS1000(CameraEntity);
        connect (this, SIGNAL(CloseHelm()), RCS1,SLOT(Exit()));
        RCS1->exec ();

        /*
         * PositionOrientation *PO = new PositionOrientation();
        connect (this, SIGNAL(CloseHelm()), PO,SLOT(Exit()));
        PO->exec();

        RCS2000 *RCS = new RCS2000(CameraEntity);
        connect (this, SIGNAL(CloseHelm()), RCS,SLOT(Exit()));
        RCS->exec();

        OThruster *OT = new OThruster();
        connect (this, SIGNAL(CloseHelm()), OT,SLOT(Exit()));
        OT->exec();

        PThruster *PT = new PThruster();
        connect (this, SIGNAL(CloseHelm()), PT,SLOT(Exit()));
        PT->exec();
        */
    }

    else

    if (Setup::SimCraftType == "TransportShortHaul")
    {
        RCS1000 *RCS1 =  new RCS1000(CameraEntity);
        connect (this, SIGNAL(CloseHelm()), RCS1,SLOT(Exit()));
        RCS1->exec ();
    }

    else

    if (Setup::SimCraftType == "TransportLongHaul")
    {
        RCS1000 *RCS1 = new RCS1000(CameraEntity);
        connect (this, SIGNAL(CloseHelm()), RCS1,SLOT(Exit()));
        RCS1->exec ();
    }

    return true;
}

void Helm::ExitHelm (void)
{
    emit Helmoff();
    this->close();
}
