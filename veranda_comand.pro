#-------------------------------------------------
#
# Project created by QtCreator 2015-04-27T02:56:45
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT       += sql
QT       += network

TARGET = veranda_comand
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

OBJECTS_DIR = compile
MOC_DIR = compile

SOURCES += main.cpp \
    controller/worker.cpp \
    model/get_db.cpp \
    model/init_mysql.cpp \
    model/save_db.cpp \
    util/parsing_fuction.cpp \
    util/util_skyw.cpp \
    model/init_memory.cpp \
    model/json/json.cpp \
    model/json/verjson.cpp

HEADERS += \
    controller/worker.h \
    model/get_db.h \
    model/init_mysql.h \
    model/save_db.h \
    util/parsing_fuction.h \
    util/utama.h \
    util/util_skyw.h \
    model/init_memory.h \
    model/json/json.h \
    model/json/verjson.h
