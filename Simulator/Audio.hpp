#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <QString>
#include <QMediaPlayer>

class Audio
{
public:
    Audio();
    bool PlayAudio (QString AudioFile);
    void StopAudio (void);

private:
    QStringList AudioList;
    QMediaPlayer *Play;
};

#endif // AUDIO_HPP
