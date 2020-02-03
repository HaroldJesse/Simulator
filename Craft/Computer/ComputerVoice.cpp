#include "ComputerVoice.hpp"
#include "ui_ComputerVoice.h"

ComputerVoice::ComputerVoice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComputerVoice)
{
    ui->setupUi(this);
}



ComputerVoice::~ComputerVoice()
{
    delete ui;
}

void ComputerVoice::AvailableEngines (void)
{
   // Engines = QTextToSpeech::availableEngines();
}

void ComputerVoice::AvailableLocale (void)
{

}

void ComputerVoice::AvailableVoice (void)
{

}

void ComputerVoice::Locale (void)
{

}

void ComputerVoice::Pitch (void)
{

}

void ComputerVoice::Rate (void)
{

}

void ComputerVoice::State (void)
{

}

void ComputerVoice::Voice (void)
{

}

void ComputerVoice::Volume (void)
{

}

