

#include "headers/Compromisso.h"

/**
 *
 * @param data
 * @param horario
 * @param titulo
 */
Compromisso::Compromisso(Data &data, Horario &horario, const string & titulo)
{
    this->data = data;
    this->horario = horario;
    this->titulo = titulo;
}

/**
 *
 * @return
 */
string Compromisso::getDescricao() const {
    return descricao;
}

/**
 *
 * @param descricao
 */
void Compromisso::setDescricao(const string & descricao) {
    this->descricao = descricao;
}

/**
 *
 * @return
 */
string Compromisso::getTitulo() const {
    return titulo;
}

/**
 *
 * @param titulo
 */
void Compromisso::setTitulo(const string & titulo) {
    this->titulo = titulo;
}

/**
 *
 * @return
 */
string Compromisso::getLocal() const {
    return local;
}

/**
 *
 * @param local
 */
void Compromisso::setLocal(const string & local) {
    this->local = local;
}

/**
 *
 * @return
 */
bool Compromisso::operator==(const Compromisso & compromisso)
{
    return (Compromisso::getTitulo() == compromisso.getTitulo())
           && (Compromisso::data == compromisso.data)
           && (Compromisso::horario == compromisso.horario);
}

/**
 *
 * @return
 */
bool Compromisso::operator!=(const Compromisso & compromisso)
{
    return (Compromisso::getTitulo() != compromisso.getTitulo())
           || (Compromisso::data != compromisso.data)
           || (Compromisso::horario != compromisso.horario);
}

/**
 *
 * @return
 */
bool Compromisso::operator>=(const Compromisso & compromisso)
{
    return ( Compromisso::data > compromisso.data )
           || ( (Compromisso::data == compromisso.data)
                && (Compromisso::horario >= compromisso.horario) );
}

/**
 *
 * @return
 */
bool Compromisso::operator>(const Compromisso & compromisso)
{
    return ( Compromisso::data > compromisso.data )
           || ( (Compromisso::data == compromisso.data)
                && (Compromisso::horario > compromisso.horario) );
}

/**
 *
 * @return
 */
bool Compromisso::operator<=(const Compromisso & compromisso)
{
    return ( Compromisso::data < compromisso.data )
           || ( (Compromisso::data == compromisso.data)
                && (Compromisso::horario <= compromisso.horario) );
}

/**
 *
 * @return
 */
bool Compromisso::operator<(const Compromisso & compromisso)
{
    return ( Compromisso::data < compromisso.data )
           || ( (Compromisso::data == compromisso.data)
                && (Compromisso::horario < compromisso.horario) );
}

/**
 *
 * @param compromisso
 * @return
 */
Compromisso& Compromisso::operator=(const Compromisso & compromisso)
{
    Compromisso::titulo = compromisso.titulo;
    Compromisso::horario = compromisso.horario;
    Compromisso::data = compromisso.data;
    Compromisso::local = compromisso.local;
    Compromisso::descricao = compromisso.descricao;

    return *this;
}

/**
 *
 * @param os
 * @param compromisso
 * @return
 */
ostream& operator<<(ostream & os, const Compromisso & compromisso)
{
    os << "Compromisso:" << endl
       << compromisso.getTitulo() << endl
       << compromisso.data << endl
       << compromisso.horario << endl
       << compromisso.getLocal() << endl
       << compromisso.getDescricao() << endl;

    return os;
}

/**
 *
 * @param descricao
 */
void Compromisso::setDescricao(const char *descricao)
{
    string temp(descricao);
    setDescricao(temp);
}

/**
 *
 * @param titulo
 */
void Compromisso::setTitulo(const char *titulo)
{
    string temp(titulo);
    setTitulo(temp);
}

/**
 *
 * @param local
 */
void Compromisso::setLocal(const char *local)
{
    string temp(local);
    setLocal(temp);
}

/**
 *
 * @return
 */
Json::Value Compromisso::toJson()
{
    Json::Value obj;
    obj["titulo"] = getTitulo();
    obj["local"] = getLocal();
    obj["data"] = Compromisso::data.toJson();
    obj["horario"] = Compromisso::horario.toJson();
    obj["descricao"] = getDescricao();

    return obj;
}

/**
 *
 * @param obj
 */
void Compromisso::fromJson(Json::Value obj)
{
    setTitulo(obj["titulo"].asString());
    setDescricao(obj["descricao"].asString());
    setLocal(obj["local"].asString());
    Compromisso::data.fromJson(obj["data"]);
    Compromisso::horario.fromJson(obj["horario"]);
}
