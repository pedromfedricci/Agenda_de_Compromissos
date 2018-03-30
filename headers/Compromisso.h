

#ifndef COMPROMISSO_H
#define COMPROMISSO_H

#include "Data.h"
#include "Horario.h"
#include <iostream>
using namespace std;

class Compromisso {

public:
    Compromisso();
    Compromisso(Data&, Horario&, const string &);
    Compromisso(Data, Horario, const string &);
    string getDescricao() const;
    void setDescricao(string &);
    void setDescricao(const char[]);
    string getTitulo() const;
    void setTitulo(string &);
    void setTitulo(const char[]);
    string getLocal() const;
    void setLocal(string &);
    void setLocal(const char[]);

    bool operator==(const Compromisso &);
    bool operator!=(const Compromisso &);
    bool operator>=(const Compromisso &);
    bool operator>(const Compromisso &);
    bool operator<=(const Compromisso &);
    bool operator<(const Compromisso &);
    Compromisso& operator=(const Compromisso &);

    friend ostream& operator<<(ostream &, const Compromisso &);

    Data data;
    Horario horario;

private:
    string descricao;
    string local;
    string titulo;
};


#endif //COMPROMISSO_H
