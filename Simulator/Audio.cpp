/*!
    \legalese
    Copyright (C) 2020, the Sim Development Team

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.
    \endlegalese
*/


#include "Audio.hpp"

Audio::Audio()
{

}

bool Audio::PlayAudio (QString AudioFile)
{
    if(AudioFile == "")
    {
        return false;
    }

    Play = new QMediaPlayer;
    Play->setMedia(QUrl::fromLocalFile(AudioFile));
    Play->play();
    return true;
}

void Audio::StopAudio (void)
{
    Play->stop();
}
