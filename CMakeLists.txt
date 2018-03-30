cmake_minimum_required(VERSION 3.9)
project(Agenda_de_Compromissos)

set(CMAKE_CXX_STANDARD 17)

add_executable(Agenda_de_Compromissos main.cpp headers/DoublyLinkedList.h headers/Node.h src/Horario.cpp
        headers/Horario.h src/Data.cpp headers/Data.h src/Compromisso.cpp headers/Compromisso.h headers/Usuario.h
        src/Usuario.cpp headers/MyVector.h json/json.h json/json-forwards.h json/jsoncpp.cpp headers/Arquivo.h)