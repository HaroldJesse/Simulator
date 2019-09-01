#include "Voice.hpp"
#include "ui_Voice.h"

Voice::Voice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Voice)
{
    ui->setupUi(this);
    QStringList engines = QTextToSpeech::availableEngines();
    qDebug() << "Engines: " << engines;
}

Voice::~Voice()
{
    delete ui;
}

void Voice::Setup (void)
{

}
