//
// Created by pedro on 29/03/18.
//

#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <iostream>
#include <fstream>
#include "json.h"
#include "MyVector.h"
#include "Usuario.h"
using namespace std;

class Arquivo {

public:
    explicit Arquivo(const char[]);
    explicit Arquivo(const string &);

    bool writeFileFrom(MyVector<Usuario> &);
    bool readFileTo(MyVector<Usuario> &);

private:
    string path;
};

#endif //ARQUIVO_H
