#include "headers/sessao.h"

long Sessao::posicao = -1;
int Sessao::idade = 0;
string Sessao::username = "";
string Sessao::nome = "";
string Sessao::email = "";

/**
 * @brief Sessao::setPosicao
 * @param pos
 */
void Sessao::setPosicao(long pos) {
    posicao = pos;
}

/**
 * @brief Sessao::getPosicao
 * @return
 */
long Sessao::getPosicao() {
    return Sessao::posicao;
}

/**
 * @brief Sessao::getNome
 */
string Sessao::getNome() {
    return Sessao::nome;
}

/**
 * @brief Sessao::setNome
 * @param nome
 */
void Sessao::setNome(string &nome) {
    Sessao::nome = nome;
}

/**
 * @brief Sessao::getUsername
 */
string Sessao::getUsername() {
    return Sessao::username;
}

/**
 * @brief Sessao::getUsername
 * @param username
 */
void Sessao::setUsername(string &username) {
    Sessao::username = username;
}

/**
 * @brief Sessao::getEmail
 * @return
 */
string Sessao::getEmail() {
    return email;
}

/**
 * @brief Sessao::setEmail
 * @param email
 */
void Sessao::setEmail(string &email) {
    Sessao::email = email;
}

/**
 * @brief Sessao::getIdade
 * @return
 */
int Sessao::getIdade() {
    return idade;
}

/**
 * @brief Sessao::setIdade
 * @param idade
 */
void Sessao::setIdade(int idade) {
    Sessao::idade = idade;
}

/**
 * @brief Sessao::setSessao
 * @param pos
 * @param usuario
 */
void Sessao::setSessao(Usuario &usuario, int pos) {
    Sessao::posicao = pos;
    Sessao::username = usuario.getUsername();
    Sessao::nome = usuario.getNome();
    Sessao::email = usuario.getEmail();
    Sessao::idade = usuario.getIdade();
}

/**
 * @brief Sessao::resetSessao
 */
void Sessao::reset()
{
    Sessao::posicao = -1;
    Sessao::nome = "";
    Sessao::username = "";
    Sessao::idade = 0;
    Sessao::email = "";
}
