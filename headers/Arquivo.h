//
// Created by pedro on 29/03/18.
//

#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "iostream"
#include "fstream"
#include "../json/json.h"
#include "MyVector.h"
using namespace std;

template <class T>
class Arquivo {

public:
    explicit Arquivo(const char[]);
    explicit Arquivo(const string &);

    bool writeFileFrom(MyVector<T> &);
    bool readFileTo(MyVector<T> &);

private:
    string path;
};

/**
 *
 * @tparam T
 * @param path
 * @param vector
 */
template<class T>
Arquivo<T>::Arquivo(const char *path) {
    Arquivo::path = path;
}

/**
 *
 * @tparam T
 * @param txt
 * @param vector
 */
template<class T>
Arquivo<T>::Arquivo(const string & path) {
    Arquivo::path = path;
}

/**
 *
 * @tparam T
 * @return
 */
template<class T>
bool Arquivo<T>::writeFileFrom(MyVector<T> &vector)
{
    fstream file(path, ostream::out);

    if (file.fail()) {
        cout << "Deu ruim"<< endl;
        return false;
    }

    Json::Value jsonValue;

    for(int i=1; i < vector.getSize(); i++)
        jsonValue["usuarios"].append(vector.contentAt(i).toJson());

    file << jsonValue;

    file.close();
    return true;
}

/**
 *
 * @tparam T
 * @return
 */
template<class T>
bool Arquivo<T>::readFileTo(MyVector<T> &vector)
{
    fstream file(path, istream::in);

    if (file.fail())
    {
        cout << "Deu ruim"<< endl;
        return false;
    }

    Json::Value jsonValue;
    file >> jsonValue;

    for(int i=0; i < jsonValue["usuarios"].size(); i++)
    {
        Usuario temp;
        temp.fromJson(jsonValue["usuarios"][i]);
        vector.insertInOrder(temp);
    }

    file.close();
    return true;
}

#endif //ARQUIVO_H
