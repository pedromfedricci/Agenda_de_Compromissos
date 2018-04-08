#ifndef COMPROMISSO_H
#define COMPROMISSO_H

#include "Data.h"
#include "Horario.h"
#include "json.h"
#include <iostream>
using namespace std;

class Compromisso {

public:
    Compromisso()=default;
    Compromisso(Data&, Horario&, const string &);
    //Compromisso(Data, Horario, const string &);
    string getDescricao() const;
    void setDescricao(const string &);
    void setDescricao(const char[]);
    string getTitulo() const;
    void setTitulo(const string &);
    void setTitulo(const char[]);
    string getLocal() const;
    void setLocal(const string &);
    void setLocal(const char[]);

    bool operator==(const Compromisso &);
    bool operator!=(const Compromisso &);
    bool operator>=(const Compromisso &);
    bool operator>(const Compromisso &);
    bool operator<=(const Compromisso &);
    bool operator<(const Compromisso &);
    Compromisso& operator=(const Compromisso &);
    friend ostream& operator<<(ostream &, const Compromisso &);

    Json::Value toJson();
    void fromJson(Json::Value);

    Data data;
    Horario horario;

private:
    string descricao;
    string local;
    string titulo;
};

#endif //COMPROMISSO_H
