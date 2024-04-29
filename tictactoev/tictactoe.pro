QT       += core gui multimedia




greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp \
    gameslist.cpp \
    main.cpp \
    mainwindow.cpp \
    signin.cpp \
    signin2.cpp \
    signup.cpp \
    gamehistory.cpp \
    startgame.cpp \
    bcrypt.cpp \
    blowfish.cpp

HEADERS += \
    dialog.h \
    gameslist.h \
    mainwindow.h \
    signin.h \
    signin2.h \
    signup.h \
    gamehistory.h \
    startgame.h \
    bcrypt.h \
    node_blf.h \
    openbsd.h

FORMS += \
    dialog.ui \
    gameslist.ui \
    mainwindow.ui \
    signin.ui \
    signin2.ui \
    signup.ui \
    gamehistory.ui \
    startgame.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Soundeffects.qrc \
    users.qrc
