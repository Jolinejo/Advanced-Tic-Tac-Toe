#ifndef GLOBALS_H
#define GLOBALS_H

#include <QAudioOutput>
#include <QMediaPlayer>

#include "mainwindow.h"

extern User *player1;
extern User *player2;

inline QMediaPlayer *musicPlayer = nullptr;
inline QAudioOutput *audioOutput = nullptr;
inline QMediaPlayer *musicPlayer1 = nullptr;
inline QAudioOutput *audioOutput1 = nullptr;
#endif  // GLOBALS_H
