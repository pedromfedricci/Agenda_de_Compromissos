#-------------------------------------------------
#
# Project created by QtCreator 2018-04-03T17:35:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Agenda_de_Compromissos
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


SOURCES += \
    src/main.cpp \
    src/jsoncpp.cpp \
    src/Compromisso.cpp \
    src/Data.cpp \
    src/Horario.cpp \
    src/Usuario.cpp \
    src/mainwindow.cpp \
    src/sessao.cpp \
    src/arquivo.cpp \
    src/menuwindow.cpp \
    src/perfilwindow.cpp \
    src/novocompromissowindow.cpp \
    src/compromissoswindow.cpp

HEADERS += \
    headers/json.h \
    headers/Arquivo.h \
    headers/Compromisso.h \
    headers/Data.h \
    headers/DoublyLinkedList.h \
    headers/Horario.h \
    headers/MyVector.h \
    headers/Node.h \
    headers/Usuario.h \
    headers/mainwindow.h \
    headers/sessao.h \
    headers/menuwindow.h \
    headers/perfilwindow.h \
    headers/novocompromissowindow.h \
    headers/compromissoswindow.h

FORMS += \
    forms/mainwindow.ui \
    forms/menuwindow.ui \
    forms/perfilwindow.ui \
    forms/novocompromissowindow.ui \
    forms/compromissoswindow.ui

DISTFILES += \
    README.md \
    Arquivo/arquivo.json
