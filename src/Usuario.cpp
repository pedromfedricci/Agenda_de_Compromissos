#include "headers/Usuario.h"

Usuario::Usuario(const string &username, const string &nome,
                 const string &email, const int idade)
{
    this->username = username;
    this->nome = nome;
    this->idade = idade;
    this->email = email;
}
Usuario::Usuario(const string &username) {
    Usuario::username = username;
    Usuario::nome = "";
    Usuario::idade = 0;
    Usuario::email = "";
}
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
int Usuario::getIdade() const {
    return idade;
}
string Usuario::getIdadeString() {
    return to_string(getIdade());
}
void Usuario::setIdade(int idade) {
    Usuario::idade = idade;
}
string Usuario::getEmail() const {
    return email;
}
void Usuario::setEmail(const string &email) {
    Usuario::email = email;
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
    os << "Username: " << usuario.getUsername() << endl;
    return os;
}
Usuario& Usuario::operator=(const Usuario &usuario)
{
    Usuario::username = usuario.username;
    Usuario::nome = usuario.nome;
    Usuario::idade = usuario.idade;
    Usuario::email = usuario.email;
    Usuario::compromissos = usuario.compromissos;

    return *this;
}
Json::Value Usuario::toJson()
{
    Json::Value obj;
    obj["username"] = getUsername();
    obj["nome"] = getNome();
    obj["email"] = getEmail();
    obj["idade"] = getIdade();

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
    setEmail(obj["email"].asString());
    setIdade(obj["idade"].asInt());

    Compromisso temp;

    for (unsigned int i=0; i < obj["compromissos"].size(); i++)
    {
        temp.fromJson(obj["compromissos"][i]);
        Usuario::compromissos.insertInOrder(temp);
    }
}
