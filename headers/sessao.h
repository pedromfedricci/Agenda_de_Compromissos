#ifndef SESSAO_H
#define SESSAO_H

#include <iostream>
#include "headers/Usuario.h"
using namespace std;

class Sessao {
private:
    static string username;
    static string nome;
    static string email;
    static int idade;
    static long posicao;

public:
    static long getPosicao();
    static void setPosicao(long pos);
    static string getUsername();
    static void setUsername(string&);
    static void setNome(string&);
    static string getNome();
    static string getEmail();
    static void setEmail(string&);
    static int getIdade();
    static void setIdade(int);
    static void setSessao(Usuario &usuario, int pos);
    static void reset();
};

#endif // SESSAO_H
