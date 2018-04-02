#ifndef HORARIO_H
#define HORARIO_H

#include <iostream>
#include "../json/json.h"
using namespace std;

class Horario {

public:
    Horario(int, int, int);
    Horario();
    explicit Horario(int);
    Horario(int, int);
    void setHorario(int,int,int);
    void setHora(int);
    int getHora() const;
    string getHoraString() const;
    void setMinuto(int);
    int getMinuto() const;
    string getMinutoString() const;
    void setSegundo(int);
    int getSegundo() const;
    string getSegundoString() const;

    bool operator==(const Horario &);
    bool operator!=(const Horario &);
    bool operator>=(const Horario &);
    bool operator>(const Horario &);
    bool operator<=(const Horario &);
    bool operator<(const Horario &);
    Horario& operator=(const Horario &);
    friend ostream& operator<<(ostream &, const Horario &);

    Json::Value toJson();
    void fromJson(Json::Value);

private:
    int hora;
    int minuto;
    int segundo;
};

#endif //HORARIO_H
