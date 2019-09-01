#include "Helm.hpp"

Helm::Helm(QWidget *parent) : QWidget(parent)
{

}

bool Helm::LoadHelm (Qt3DRender::QCamera *CameraEntity)
{

    QTextToSpeech Verbalize;
    Verbalize.say("Helm Control is online");
    //Camera = CameraEntity;

    if (Setup::SimCraftClass == "Unknown")
    {
        qDebug() << "Unknown";
        //qApp->beep();
        QMessageBox msgBox;
        msgBox.setText("Craft Creation Error The Craft type is unknown");
        //QTextToSpeech Verbalize;
        //Verbalize.say(msgBox.text());
        msgBox.exec();
    }

    else

    if (Setup::SimCraftClass == "Short Haul Freighter")

    {
        qDebug() << "Short Haul Freighter";
        PositionOrientation *PO = new PositionOrientation();
        connect (this, SIGNAL(CloseHelm()), PO,SLOT(Exit()));

        PO->show();

        //qDebug() << "HelmType  RCS2000";
        RCS2000 *RCS = new RCS2000(CameraEntity);
        connect (this, SIGNAL(CloseHelm()), RCS,SLOT(Exit()));

        RCS->show();

        //qDebug() << "HelmType OT";
        OThruster *OT = new OThruster();
        connect (this, SIGNAL(CloseHelm()), OT,SLOT(Exit()));

        OT->show();

        //qDebug() << "HelmType Pt";
        PThruster *PT = new PThruster();
        connect (this, SIGNAL(CloseHelm()), PT,SLOT(Exit()));

        PT->show();
    }

    else

    if (Setup::SimCraftClass == "Long Haul Freighter")
    {
        //qDebug() << "Long Haul Freighter";
        PositionOrientation *PO = new PositionOrientation();
        connect (this, SIGNAL(CloseHelm()), PO,SLOT(Exit()));
        PO->exec();

        RCS2000 *RCS = new RCS2000(CameraEntity);
        connect (this, SIGNAL(CloseHelm()), RCS,SLOT(Exit()));
        RCS->exec();
        //qDebug() << "HelmType";

        OThruster *OT = new OThruster();
        connect (this, SIGNAL(CloseHelm()), OT,SLOT(Exit()));
        OT->exec();
        //qDebug() << "HelmType";

        PThruster *PT = new PThruster();
        connect (this, SIGNAL(CloseHelm()), PT,SLOT(Exit()));
        PT->exec();
        //qDebug() << "HelmType";
    }

    else

     if (Setup::SimCraftClass == "LEO Shuttle")
    {
        //qDebug() << "LEO Shuttle";
        RCS1000 *RCS1 =  new RCS1000(CameraEntity);
        connect (this, SIGNAL(CloseHelm()), RCS1,SLOT(Exit()));
        RCS1->exec ();
    }

    else

    if (Setup::SimCraftClass == "HEO Shuttle")
    {
        //qDebug() << "HEO Shuttle";
        RCS1000 *RCS1 = new RCS1000(CameraEntity);
        connect (this, SIGNAL(CloseHelm()), RCS1,SLOT(Exit()));
        RCS1->exec ();
    }

    return true;
}

void Helm::ExitHelm (void)
{
    emit CloseHelm();
    this->close();
}
