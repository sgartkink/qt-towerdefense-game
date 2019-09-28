#-------------------------------------------------
#
# Project created by QtCreator 2019-08-14T08:43:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerDefenseGame
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    hex.cpp \
    game.cpp \
    map.cpp \
    tower.cpp \
    greentower.cpp \
    interfaceonrightside.cpp \
    chosenhexeffect.cpp \
    yellowtower.cpp \
    whitetower.cpp \
    bluetower.cpp \
    darkcyantower.cpp \
    bullet.cpp \
    bluebullet.cpp \
    interfaceonbottom.cpp \
    darkcyanbullet.cpp \
    greenbullet.cpp \
    whitebullet.cpp \
    yellowbullet.cpp \
    enemy.cpp \
    towerrangeattack.cpp \
    pathforenemy.cpp \
    widgettoweroptions.cpp \
    interfacewithtoweroptions.cpp \
    interfacewaitforclickhex.cpp \
    interfacetowerdetails.cpp \
    player.cpp

HEADERS += \
    hex.h \
    game.h \
    global_consts.h \
    map.h \
    tower.h \
    greentower.h \
    interfaceonrightside.h \
    chosenhexeffect.h \
    yellowtower.h \
    whitetower.h \
    bluetower.h \
    darkcyantower.h \
    bullet.h \
    bluebullet.h \
    interfaceonbottom.h \
    darkcyanbullet.h \
    greenbullet.h \
    whitebullet.h \
    yellowbullet.h \
    enemy.h \
    towerrangeattack.h \
    pathforenemy.h \
    widgettoweroptions.h \
    interfacewithtoweroptions.h \
    interfacewaitforclickhex.h \
    interfacetowerdetails.h \
    towers_prices.h \
    player.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
