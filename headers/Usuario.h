#ifndef USUARIO_H
#define USUARIO_H

#include "DoublyLinkedList.h"
#include "Compromisso.h"
#include "json.h"
#include <iostream>
using namespace std;

class Usuario {

public:
    DoublyLinkedList<Compromisso> compromissos;

    Usuario()=default;
    Usuario(const string &username);
    Usuario(const string &username, const string &nome,
            const string &email, const int idade);
    string getUsername() const;
    void setUsername(const string &username);
    string getNome() const;
    void setNome(const string &nome);
    string getEmail() const;
    void setEmail(const string&);
    int getIdade() const;
    string getIdadeString();
    void setIdade(int);

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
    string email;
    int idade;
};

#endif //USUARIO_H
