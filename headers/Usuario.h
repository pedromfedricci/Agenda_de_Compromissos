#ifndef USUARIO_H
#define USUARIO_H

#include "DoublyLinkedList.h"
#include "Compromisso.h"
#include "../json/json.h"
#include <iostream>
using namespace std;

class Usuario {

public:
    DoublyLinkedList<Compromisso> compromissos;

    Usuario();
    Usuario(const string&, const string&);
    ~Usuario();
    string getUsername() const;
    void setUsername(const string &username);
    string getNome() const;
    void setNome(const string &nome);

    bool operator==(const Usuario &);
    bool operator!=(const Usuario &);
    bool operator>=(const Usuario &);
    bool operator>(const Usuario &);
    bool operator<=(const Usuario &);
    bool operator<(const Usuario &);
    Usuario& operator=(const Usuario &);
    friend ostream& operator<<(ostream &, const Usuario &);

    Json::Value toJson();
    void fromJson(Json::Value);

private:
    string username;
    string nome;
};

#endif //USUARIO_H
