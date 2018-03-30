#include "../headers/Usuario.h"

Usuario::Usuario(const string &username, const string &nome)
{
    this->username = username;
    this->nome = nome;
}

Usuario::Usuario()=default;

Usuario::~Usuario()=default;

string Usuario::getUsername() const {
    return username;
}

void Usuario::setUsername(const string &username) {
    this->username = username;
}

string Usuario::getNome() const {
    return nome;
}

void Usuario::setNome(const string &nome) {
    this->nome = nome;
}

bool Usuario::operator==(const Usuario &usuario)
{
    return Usuario::getUsername() == usuario.getUsername();
}

bool Usuario::operator!=(const Usuario &usuario)
{
    return Usuario::getUsername() != usuario.getUsername();
}

bool Usuario::operator>=(const Usuario &usuario)
{
    return Usuario::getUsername() >= usuario.getUsername();
}

bool Usuario::operator>(const Usuario &usuario)
{
    return Usuario::getUsername() > usuario.getUsername();
}

bool Usuario::operator<=(const Usuario &usuario)
{
    return Usuario::getUsername() <= usuario.getUsername();
}

bool Usuario::operator<(const Usuario &usuario)
{
    return Usuario::getUsername() < usuario.getUsername();
}

ostream& operator<<(ostream &os, const Usuario &usuario)
{
    os << "Username: " << usuario.getUsername() << endl
       << "Nome: " << usuario.getNome() << endl;

    return os;
}

Usuario& Usuario::operator=(const Usuario &usuario)
{
    Usuario::username = usuario.username;
    Usuario::nome = usuario.nome;
    Usuario::compromissos = usuario.compromissos;
}

Json::Value Usuario::toJson()
{
    Json::Value obj;
    obj["username"] = getUsername();
    obj["nome"] = getNome();

    long posicao = 1;
    Compromisso compromisso;
    obj["compromissos"] = Json::Value(Json::arrayValue);

    while(Usuario::compromissos.iterate(compromisso, posicao++))
        obj["compromissos"].append(compromisso.toJson());

    return obj;
}

void Usuario::fromJson(Json::Value obj)
{
    setUsername(obj["username"].asString());
    setNome(obj["nome"].asString());

    Compromisso temp;

    for (int i=0; i < obj["compromissos"].size(); i++)
    {
        temp.fromJson(obj["compromissos"][i]);
        Usuario::compromissos.insertInOrder(temp);
    }
}