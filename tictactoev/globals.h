#ifndef GLOBALS_H
#define GLOBALS_H

#include "mainwindow.h"
#include <QMediaPlayer>
#include <QAudioOutput>

extern User *player1;
extern User *player2;

inline QMediaPlayer *musicPlayer = new QMediaPlayer;
inline QAudioOutput *audioOutput = new QAudioOutput;

#endif  // GLOBALS_H
