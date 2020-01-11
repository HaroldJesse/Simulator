/*!

    Copyright (C) 2020, the Sim Development Team

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

*/

#include "Setup.hpp"
#include "ui_Setup.h"


QString Setup::SimType;
QString Setup::SimBranch;
QString Setup::SimClass;
QString Setup::SimCraftType;
QString Setup::SimCraftName;
QString Setup::SimQuadrant;
QString Setup::SimSector;
QString Setup::SimLocation;
QString Setup::SimObject;


QStringList Setup::SimTypeList;
QStringList Setup::SimBranchList;
QStringList Setup::SimCraftTypeList;
QStringList Setup::SimCraftNameList;
QStringList Setup::SimQuadranList;
QStringList Setup::SimSectorList;
QStringList Setup::SimLocationList;
QStringList Setup::SimObjectList;


Setup::Setup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setup)
{
    ui->setupUi(this);

    //this->setWindowFlags(Qt::WindowStaysOnTopHint||Qt::FramelessWindowHint);
    this->setWindowFlags(Qt::FramelessWindowHint);



    Setup::SimTypeList << ""  << "Training" << "Simulation" << "Deployment";

    // we  hide all the group boxes
    ui->Type->clear();
    ui->Type->addItems(Setup::SimTypeList);
    ui->Branch->hide();
    ui->Branchlbl->hide();
    ui->Class->hide();
    ui->Classlbl->hide();
    ui->Sector->hide();
    ui->Sectorlbl->hide();
    ui->Quadrant->hide();
    ui->Quadrantlbl->hide();
    ui->Location->hide();
    ui->Locationlbl->hide();
    ui->Object->hide();
    ui->Objectlbl->hide();

    ui->SimCraft->hide();
    ui->CraftType->hide();
    ui->CraftTypelbl->hide();
    ui->CraftName->hide();
    ui->CraftNamelbl->hide();



    QTime Time;
    Time.start();
    QString number = Time.toString("hh:mm:ss");
    number.remove(QChar (':'));



    ui->CraftType->hide();
    ui->CraftTypelbl->hide();

    ui->CraftName->hide();
    ui->CraftNamelbl->hide();

   // Now show the first Setup Group Box
    ui->Type->show();
    ui->SimTypelbl->show();

    //Prompt user
    ui->SimTypeInstruction->setPlainText("You must set up the simulator for the type of simulation you want to run. "
                                    "To select a simulation click on the type listed in the box for simulation type. "
                                    "Once you have selected a simulation type you will need to select a branch type and then a class type");

    Verbalize->say(ui->SimTypeInstruction->toPlainText());

    Setup::SimQuadranList << "" << "Alpha" << "Beta" << "Gama" << "Delta";
    ui->Quadrant->clear();
    ui->Quadrant->addItems(Setup::SimQuadranList);

    Verbalize->say("Choose a Simulation type");
}

Setup::~Setup()
{
    delete ui;
}

void Setup::TypeChanged (void)
{
    ui->SimTypeInstruction->hide();
    Setup::SimBranch = ui->Type->currentText();


    if(ui->Type->currentText() == "Training")
    {
       QStringList BranchList;
       BranchList << ""  << "Basic Training" << "Advanced Training" << "Leadership Training";
       ui->Branch->clear();
       ui->Branch->addItems(BranchList);
       ui->Branch->show();
       ui->Branchlbl->show();
    }

    if(ui->Type->currentText() == "Simulation")
    {

        QStringList BranchList;
        BranchList << ""  << "Space Craft" << "Extra Vehicular Activity" << "Space Station";
        ui->Branch->clear();
        ui->Branch->addItems(BranchList);
        ui->Branch->show();
        ui->Branchlbl->show();
    }

    if(ui->Type->currentText() == "Deployment")
    {
        QStringList BranchList;
        BranchList << ""  << "Space Craft" << "Extra Vehicular Activity" << "Space Station";
        ui->Branch->clear();
        ui->Branch->addItems(BranchList);
        ui->Branch->show();
        ui->Branchlbl->show();
    }

    Verbalize->say("You have chosen the simulation type  " +  ui->Type->currentText());
    SimType = ui->Type->currentText();

    Verbalize->say("Choose a branch type");
}

void Setup::BranchChanged (void)
{
    Setup::SimBranch = ui->Branch->currentText();

    if(ui->Branch->currentText() == "Basic Training")
    {
       QStringList ClassList;
       ClassList << ""  << "Astronomy" << "Astrogeology" << "Mathematics";
       ui->Class->clear();
       ui->Class->addItems(ClassList);
       ui->Class->show();
       ui->Classlbl->show();
    }

    if(ui->Branch->currentText() == "Space Craft")
    {
       QStringList ClassList;
       ClassList << ""  << "Pilot" << "Navigator" << "Communications ";
       ui->Class->clear();
       ui->Class->addItems(ClassList);
       ui->Class->show();
       ui->Classlbl->show();
    }

    if(ui->Branch->currentText() == "Extra Vehicular Activity")
    {
       QStringList ClassList;
       ClassList << ""  << "Station Outside Support" << "Craft Outside Support" << "Surface  Research";
       ui->Class->clear();
       ui->Class->addItems(ClassList);
       ui->Class->show();
       ui->Classlbl->show();
    }

    Verbalize->say("You have chosen the branch type  " +  ui->Branch->currentText());
    SimBranch = ui->Branch->currentText();

    //Verbalize->stop();
    Verbalize->say("Choose a class type");
}

void Setup::ClassChanged (void)
{


    Setup::SimClass = ui->Class->currentText();

    if(ui->Class->currentText() == "Astronomy")
    {
        Verbalize->say("You have chosen the class type  " +  ui->Class->currentText());
        SimClass = ui->Class->currentText();
        Verbalize->say("Choose a Quadrant");
    }

    if(ui->Class->currentText() == "Astrogeology")
    {

    }

    if(ui->Class->currentText() == "Mathematics")
    {

    }


    //Prompt user
    if(ui->Branch->currentText() == "Basic Training")
    {
        ui->SimTypeInstruction->setPlainText("You must set up the class location. Select the Quadrant, Sector, Location, and Object you wish to study");
    }


    if(ui->Branch->currentText() == "Space Craft")
    {
        ui->SimTypeInstruction->setPlainText("You must set up the class location. Select the Quadrant, Sector, Location, Object and Craft");
        ui->SimCraft->show();
        ui->CraftTypelbl->show();
        ui->CraftNamelbl->show();
        ui->CraftType->show();
        ui->CraftName->show();

        Verbalize->say("You have chosen the class type  " +  ui->Class->currentText());
        SimClass = ui->Class->currentText();
        Verbalize->say(ui->SimTypeInstruction->toPlainText());
        Verbalize->say("Choose a Quadrant");
    }

    if(ui->Branch->currentText() == "Extra Vehicular Activity")
    {
        Verbalize->say(ui->SimTypeInstruction->toPlainText());
    }

    ui->SimTypeInstruction->show();
    //ui->SimLocation->show();
    ui->Quadrant->show();
    ui->Quadrantlbl->show();

}

void Setup::QuadrantChanged (void)
{
    if(ui->Quadrant->currentText() == "Alpha")
    {
       QStringList Sector;
       Setup::SimSectorList << ""  << "Sol";
       ui->Sector->clear();
       ui->Sector->addItems(SimSectorList);
       ui->Sector->show();
       ui->Sectorlbl->show();

       Verbalize->say("You have chosen the quadrant" +  ui->Quadrant->currentText());
       SimQuadrant = ui->Quadrant->currentText();
       Verbalize->say("Choose a Sector");
     }
     
     if(ui->Quadrant->currentText() == "Beta")
     {
        QStringList Sector;
        Setup::SimSectorList << ""  << "Carng";
        ui->Sector->clear();
        ui->Sector->addItems(SimSectorList);
        ui->Sector->show();
        ui->Sectorlbl->show();

        Verbalize->say("You have chosen the quadrant" +  ui->Quadrant->currentText());
        SimQuadrant = ui->Quadrant->currentText();
      }

      
      if(ui->Quadrant->currentText() == "Gamma")
      {
         QStringList Sector;
         Setup::SimSectorList << ""  << "Solio";
         ui->Sector->clear();
         ui->Sector->addItems(SimSectorList);
         ui->Sector->show();
         ui->Sectorlbl->show();

         Verbalize->say("You have chosen the quadrant" +  ui->Quadrant->currentText());
         SimQuadrant = ui->Quadrant->currentText();
       }

       
       if(ui->Quadrant->currentText() == "Delta")
       {
          QStringList Sector;
          Setup::SimSectorList << ""  << "Zxio";
          ui->Sector->clear();
          ui->Sector->addItems(SimSectorList);
          ui->Sector->show();
          ui->Sectorlbl->show();

          Verbalize->say("You have chosen the quadrant" +  ui->Quadrant->currentText());
          SimQuadrant = ui->Quadrant->currentText();
        }

        //Verbalize->stop();
        //Verbalize->say("Choose a Sector");
        
}
void Setup::SectorChanged (void)
{


    if(ui->Sector->currentText() == "Sol")
    {
        SimLocationList << ""  << "Sun" << "Mercury" << "Venus" << "Earth" << "Mars" << "Jupiter" << "Asteroid Belt" << "Saturn"  << "Uranus" << "Neptune" << "Kuiper Belt" << "Oort Cloud";
        ui->Location->clear();
        ui->Location->addItems(SimLocationList);
    }

    Verbalize->say("You have chosen the sector" +  ui->Sector->currentText());
    SimSector = ui->Sector->currentText();

    //Verbalize->stop();
    Verbalize->say("Choose a Location");

    ui->Location->show();
    ui->Locationlbl->show();

}

void Setup::LocationChanged (void)
{


    if(ui->Location->currentText() == "Sun")
    {
        QStringList Object;
        Object << "Sun";
        ui->Object->clear();
        ui->Object->addItems(Object);;
    }

    else

    if(ui->Location->currentText() == "Mercury")
    {
        QStringList Object;
        Object << "Mercury";
        ui->Object->clear();
        ui->Object->addItems(Object);
    }

    else

    if(ui->Location->currentText() == "Venus")
    {
        QStringList Object;
        Object << "Venus";
        ui->Object->clear();
        ui->Object->addItems(Object);
    }

    else

    if(ui->Location->currentText() == "Earth")
    {
        QStringList Object;
        Object << ""  << "Earth" << "Moon" << "L1" << "L2" << "L3" << "L4" << "L5";                ;
        ui->Object->clear();
        ui->Object->addItems(Object);

    }

    else

    if(ui->Location->currentText() == "Mars")
    {
        QStringList Object;
        Object << "Mars" << "Phobos" << "Deimos" ;
        ui->Object->clear();
        ui->Object->addItems(Object);
    }

    else

    if(ui->Location->currentText() == "Asteroid Belt")
    {
        QStringList Object;
        Object << "Ceres" << "Gerimenchencko";
        ui->Object->clear();
        ui->Object->addItems(Object);
    }

    else

    if(ui->Location->currentText() == "Jupiter")
    {
        QStringList Object;
        Object << ""  << "Jupiter" << "Metis" << "Adrastrea" << "Io" << "Europa" << "Ganymede" << "Callisto"
               << "Amalthea" << "Himalia" << "Elara (7)" << "Metis" << "Sinope" << "Lysithea" << "Carme" << "Ananke"
               << "Leda" << "Thebe" << "Carpo" << "Callirrhoe" << "Themisto"
               << "Agamemnon (Trojan)" << "Diomedes (Trojan)" << "Äneas (Trojan)" << "Patroclus (Trojan)" << "Achilles (Trojan)" << "Deiphobus (Trojan)" << "Paris (Trojan)"
               << "Makhaon (Trojan)" << "Alcathous (Trojan)" << "Nestor (Trojan)" << "Troilus (Trojan)" << "Euforbo (Trojan)" << "Antilochus (Trojan)" << "Elara (Trojan"
               << "Hektor (Trojan L4)" << "Odysseus (Trojan L4)" << "Teucerv(Trojan L4)" << "Automedon (Trojan L4)";
        ui->Object->clear();
        ui->Object->addItems(Object);
    }

    else

    if(ui->Location->currentText() == "Saturn")
    {
        QStringList Object;
        Object << ""  << "Saturn" << "Mimas" << "Enceladus"<< "Tethys"  << "Dione"  << "Rhea"
               << "Titan" << "Hyperion" << "Iapetus" << "Phoebe" << "Janus" << "Epimetheus" << "Helene" << "Telesto" << "Calypso"
               << "Atlas" << "Prometheus" << "Pandora" <<  "Pan" << "Ymir" << "Paaliaq" << "Tarvos" << "Ijiraq" << "Aegaeon"
               << "Kiviuq" << "Mundilfari" << "Atlas" << "Skathi" << "Erriapus"  << "Siarnaq" << "Thrymr" << "Narvi"  << "Methone"
               << "Pallene" << "Polydeuces" << "Daphnis" << "Aegir" << "Bebhionn" << "Bergelmir" << "Bestla" << "Farbauti" << "Fenrir"
               << "Fornjot" << "Hati" << "Hyrrokkin" << "Kari" << "Loge" << "Skoll" << "Surtur" <<  "Anthe" << "Jarnsaxa";


        ui->Object->clear();
        ui->Object->addItems(Object);
    }

    else

    if(ui->Location->currentText() == "Uranus")
    {
        QStringList Object;
        Object << ""  << "Uranus" << "Ariel" << "Umbriel" << "Oberon" << "Titania" << "Oberon"  << "Miranda"
               << "Cordelia" << "Ophelia" << "Bianca" << "Cressida" << "Desdemona" << "Juliet" << "Portia"<< "Rosalind" << "Belinda"
               << "Puck" << "Caliban" << "Sycorax" << "Prospero" << "Setebos" << "Stephano" << "Trinculo" << "Perdita" << "Margaret"
               << "Ferdinand" << "Perdita" << "Mab" << "Cupid";

        ui->Object->clear();
        ui->Object->addItems(Object);
    }

    else

    if(ui->Location->currentText() == "Neptune")
    {
        QStringList Object;
        Object << ""  << "Neptune" << "Triton" << "Nereid" << "Naiad" << "Thalassa" << "Despina"
               << "Galatea" << "Larissa" << "Proteus" << "Halimede" << "Psamathe" << "Sao" << "Laomedeia" << "Neso"  ;
        ui->Object->clear();
        ui->Object->addItems(Object);
    }

    else

    if(ui->Location->currentText() == "Kuiper Belt")
    {
        QStringList Object;
        Object << ""  << "Pluto" << "Charon" << "Nix" << "Hydra" << "Kerberos" << "Styx";
        ui->Object->clear();
        ui->Object->addItems(Object);
    }

    else

        if(ui->Location->currentText() == "Oort Cloud")
        {
            QStringList Object;
            Object << "XXXXX";
            ui->Object->clear();
            ui->Object->addItems(Object);
        }

    Verbalize->say("You have set the location to  " + ui->Location->currentText());
    SimLocation = ui->Location->currentText();

    //Verbalize->stop();
    Verbalize->say("Choose an Object");



    ui->Object->show();
    ui->Objectlbl->show();

}

void Setup::ObjectChanged (void)
{
    ui->SimTypeInstruction->hide();
    Verbalize->say("You have set the object to  " +  ui->Object->currentText());
    SimObject = ui->Object->currentText();

    if (SimType == "Simulation")
    {
        //Verbalize->stop();
        Verbalize->say("Choose a Craft type");

        QStringList CraftList;
        CraftList << ""  << "CargoShortHaul" << "CargoLongHaul" << "TransportShortHaul" << "TransportLongHaul" << "Research" << "Prospector";
        ui->CraftType->clear();
        ui->CraftType->addItems(CraftList);
        ui->CraftType->show();
        ui->CraftTypelbl->show();

    }

}

void Setup::CraftType(void)
{
    ui->SimTypeInstruction->hide();
    Verbalize->say("You have set the craft type to  " +  ui->CraftType->currentText());
    SimCraftType = ui->CraftType->currentText();

    //Verbalize->stop();
    ui->CraftName->show();
    ui->CraftNamelbl->show();
    Verbalize->say("Choose a Craft name");

    QTime Time;
    Time.start();
    QString number = Time.toString("hh:mm:ss");
    number.remove(QChar (':'));

    QStringList CraftNameList;
    CraftNameList << ""  << "Silva " + number << "Isis " + number << "Zeus" + number << "Odin" + number;

    ui->CraftName->clear();
    ui->CraftName->addItems(CraftNameList);

}

void Setup::CraftName(void)
{
    Verbalize->say("You have set the craft name to  " +  ui->CraftName->currentText());
    SimCraftName = ui->CraftName->currentText();
}

void Setup::Exit(void)
{
    //Read setup boxes and save before exiting

    Verbalize->stop();
    SimType = ui->Type->currentText();
    SimBranch = ui->Branch->currentText();
    SimClass = ui->Class->currentText();
    SimQuadrant = ui->Quadrant->currentText();
    SimSector = ui->Sector->currentText();
    SimLocation = ui->Location->currentText();
    SimObject = ui->Object->currentText();
    SimCraftType = ui->CraftType->currentText();
    SimCraftName = ui->CraftName->currentText();

    this->close();
}

void Setup::SetRoundedCorners(int Radius_tl, int Radius_tr, int Radius_bl, int Radius_br)
{
    QRegion region(0, 0, width(), height(), QRegion::Rectangle);

    // top left
    QRegion round (0, 0, 2*Radius_tl, 2*Radius_tl, QRegion::Ellipse);
    QRegion corner(0, 0, Radius_tl, Radius_tl, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    // top right
    round = QRegion(width()-2*Radius_tr, 0, 2*Radius_tr, 2*Radius_tr, QRegion::Ellipse);
    corner = QRegion(width()-Radius_tr, 0, Radius_tr, Radius_tr, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    // bottom right
    round = QRegion(width()-2*Radius_br, height()-2*Radius_br, 2*Radius_br, 2*Radius_br, QRegion::Ellipse);
    corner = QRegion(width()-Radius_br, height()-Radius_br, Radius_br, Radius_br, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    // bottom left
    round = QRegion(0, height()-2*Radius_bl, 2*Radius_bl, 2*Radius_bl, QRegion::Ellipse);
    corner = QRegion(0, height()-Radius_bl, Radius_bl, Radius_bl, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    setMask(region);
}

void Setup::SetAllCorners(int Radius)
{
    QRegion region(0, 0, width(), height(), QRegion::Rectangle);

    // top left
    QRegion round (0, 0, 2*Radius, 2*Radius, QRegion::Ellipse);
    QRegion corner(0, 0, Radius, Radius, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    // top right
    round = QRegion(width()-2*Radius, 0, 2*Radius, 2*Radius, QRegion::Ellipse);
    corner = QRegion(width()-Radius, 0, Radius, Radius, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    // bottom right
    round = QRegion(width()-2*Radius, height()-2*Radius, 2*Radius, 2*Radius, QRegion::Ellipse);
    corner = QRegion(width()-Radius, height()-Radius, Radius, Radius, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    // bottom left
    round = QRegion(0, height()-2*Radius, 2*Radius, 2*Radius, QRegion::Ellipse);
    corner = QRegion(0, height()-Radius, Radius, Radius, QRegion::Rectangle);
    region = region.subtracted(corner.subtracted(round));

    setMask(region);
}


