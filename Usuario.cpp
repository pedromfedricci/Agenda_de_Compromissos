//
// Created by pedro on 21/03/18.
//

#include "Usuario.h"

/**
 *
 * @param username
 * @param nome
 */
Usuario::Usuario(const string &username, const string &nome)
{
    this->username = username;
    this->nome = nome;
}

/**
 *
 */
Usuario::Usuario()=default;
/**
 *
 */
Usuario::~Usuario()=default;

/**
 *
 * @return
 */
string Usuario::getUsername() const {
    return username;
}

/**
 *
 * @param username
 */
void Usuario::setUsername(const string &username) {
    this->username = username;
}

/**
 *
 * @return
 */
string Usuario::getNome() const {
    return nome;
}

/**
 *
 * @param nome
 */
void Usuario::setNome(const string &nome) {
    this->nome = nome;
}

/**
 *
 * @param usuario
 * @return
 */
bool Usuario::operator==(const Usuario &usuario)
{
    return Usuario::getUsername() == usuario.getUsername();
}

/**
 *
 * @param usuario
 * @return
 */
bool Usuario::operator!=(const Usuario &usuario)
{
    return Usuario::getUsername() != usuario.getUsername();
}

/**
 *
 * @param usuario
 * @return
 */
bool Usuario::operator>=(const Usuario &usuario)
{
    return Usuario::getUsername() >= usuario.getUsername();
}

/**
 *
 * @param usuario
 * @return
 */
bool Usuario::operator>(const Usuario &usuario)
{
    return Usuario::getUsername() > usuario.getUsername();
}

/**
 *
 * @param usuario
 * @return
 */
bool Usuario::operator<=(const Usuario &usuario)
{
    return Usuario::getUsername() <= usuario.getUsername();
}

/**
 *
 * @param usuario
 * @return
 */
bool Usuario::operator<(const Usuario &usuario)
{
    return Usuario::getUsername() < usuario.getUsername();
}

/**
 *
 * @param os
 * @param usuario
 * @return
 */
ostream& operator<<(ostream &os, const Usuario &usuario)
{
    os << "Username: " << usuario.getUsername() << endl
       << "Nome: " << usuario.getNome() << endl;

    return os;
}

/**
 *
 * @param usuario
 * @return
 */
Usuario& Usuario::operator=(const Usuario &usuario)
{
    Usuario::username = usuario.username;
    Usuario::nome = usuario.nome;
    Usuario::compromissos = usuario.compromissos;
}

