#include "headers/Arquivo.h"

/**
 *
 * @param path
 * @param vector
 */
Arquivo::Arquivo(const char *path) {
    Arquivo::path = path;
}

/**
 *
 * @param txt
 * @param vector
 */
Arquivo::Arquivo(const string & path) {
    Arquivo::path = path;
}



/**
 *
 * @return
 */
bool Arquivo::writeFileFrom(MyVector<Usuario> &vector)
{
    fstream file(path, ostream::out);

    if (file.fail()) {
        cout << "path nao encontrado"<< endl;
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
 * @return
 */
bool Arquivo::readFileTo(MyVector<Usuario> &vector)
{
    fstream file(path, istream::in);

    if (file.fail())
    {
        cout << "Novo arquivo"<< endl;
        file.open(path,istream::in);
        return false;
    }

    Json::Value jsonValue;
    file >> jsonValue;

    for(unsigned int i=0; i < jsonValue["usuarios"].size(); i++)
    {
        Usuario temp;
        temp.fromJson(jsonValue["usuarios"][i]);
        vector.insertInOrder(temp);
    }

    file.close();
    return true;
}
