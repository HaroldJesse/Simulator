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
