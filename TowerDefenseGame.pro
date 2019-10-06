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
    towers/tower.cpp \
    towers/greentower.cpp \
    interfaceonrightside.cpp \
    chosenhexeffect.cpp \
    towers/yellowtower.cpp \
    towers/whitetower.cpp \
    towers/bluetower.cpp \
    towers/darkcyantower.cpp \
    bullets/bullet.cpp \
    bullets/bluebullet.cpp \
    interfaceonbottom.cpp \
    bullets/darkcyanbullet.cpp \
    bullets/greenbullet.cpp \
    bullets/whitebullet.cpp \
    bullets/yellowbullet.cpp \
    enemy.cpp \
    towerrangeattack.cpp \
    pathforenemy.cpp \
    widgettoweroptions.cpp \
    interfacewithtoweroptions.cpp \
    interfacewaitforclickhex.cpp \
    interfacetowerdetails.cpp \
    player.cpp \
    newlevelenemies.cpp \
    towersquareobject.cpp

HEADERS += \
    hex.h \
    game.h \
    global_consts.h \
    map.h \
    towers/tower.h \
    towers/greentower.h \
    interfaceonrightside.h \
    chosenhexeffect.h \
    towers/yellowtower.h \
    towers/whitetower.h \
    towers/bluetower.h \
    towers/darkcyantower.h \
    bullets/bullet.h \
    bullets/bluebullet.h \
    interfaceonbottom.h \
    bullets/darkcyanbullet.h \
    bullets/greenbullet.h \
    bullets/whitebullet.h \
    bullets/yellowbullet.h \
    enemy.h \
    towerrangeattack.h \
    pathforenemy.h \
    widgettoweroptions.h \
    interfacewithtoweroptions.h \
    interfacewaitforclickhex.h \
    interfacetowerdetails.h \
    towers_prices.h \
    player.h \
    newlevelenemies.h \
    towersquareobject.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
