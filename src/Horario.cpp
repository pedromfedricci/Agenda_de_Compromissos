

#include "headers/Horario.h"

/**
 *
 * @param hora
 * @param minuto
 * @param segundo
 */
Horario::Horario(int hora, int minuto, int segundo)
{
    setHora(hora);
    setMinuto(minuto);
    setSegundo(segundo);
}

/**
 *
 */
Horario::Horario()
{
    setHora(0);
    setMinuto(0);
    setSegundo(0);
}

/**
 *
 * @param hora
 */
Horario::Horario(int hora)
{
    setHora(hora);
    setMinuto(0);
    setSegundo(0);
}

/**
 *
 * @param hora
 * @param minuto
 */
Horario::Horario(int hora, int minuto)
{
    setHora(hora);
    setMinuto(minuto);
    setSegundo(0);
}

/**
 *
 * @param hora
 * @param minuto
 * @param segundo
 */
void Horario::setHorario(int hora, int minuto, int segundo)
{
    setHora(hora);
    setMinuto(minuto);
    setSegundo(segundo);
}

/**
 *
 * @return
 */
int Horario::getHora() const {
    return hora;
}

/**
 *
 * @param hora
 */
void Horario::setHora(int hora) {
    this->hora = ( (hora >= 0 && hora < 24) ? hora : 0 );
}

/**
 *
 * @return
 */
string Horario::getHoraString() const
{
    if (getHora() >= 0 && getHora() <= 9)
        return to_string(0).append(to_string(getHora()));

    else return to_string(getHora());
}

/**
 *
 * @return
 */
int Horario::getMinuto() const {
    return minuto;
}

/**
 *
 * @param minuto
 */
void Horario::setMinuto(int minuto) {
    this->minuto = ( (minuto >= 0 && minuto < 60) ? minuto : 0 );
}

/**
 *
 * @return
 */
string Horario::getMinutoString() const
{
    if (getMinuto() >= 0 && getMinuto() <= 9)
        return to_string(0).append(to_string(getMinuto()));

    else return to_string(getMinuto());
}

/**
 *
 * @return
 */
int Horario::getSegundo() const {
    return segundo;
}

/**
 *
 * @param segundo
 */
void Horario::setSegundo(int segundo) {
    this->segundo = ( (segundo >= 0 && segundo < 60) ? segundo : 0 );
}

string Horario::getSegundoString() const
{
    if (getSegundo() >= 0 && getSegundo() <= 9)
        return to_string(0).append(to_string(getSegundo()));

    else return to_string(getSegundo());
}

/**
 *
 * @param horario
 * @return
 */
bool Horario::operator==(const Horario & horario)
{
    return (Horario::getHora() == horario.getHora())
           && (Horario::getMinuto() == horario.getMinuto())
           && (Horario::getSegundo() == horario.getSegundo());
}

/**
 *
 * @param horario
 * @return
 */
bool Horario::operator!=(const Horario & horario)
{
    return (Horario::getHora() != horario.getHora())
           || (Horario::getMinuto() != horario.getMinuto())
           || (Horario::getSegundo() != horario.getSegundo());
}

/**
 *
 * @param horario
 * @return
 */
bool Horario::operator>=(const Horario & horario)
{
    return ( Horario::getHora() > horario.getHora() )
           || ( (Horario::getHora() == horario.getHora())
                && (Horario::getMinuto() > horario.getMinuto()) )
           ||( (Horario::getHora() == horario.getHora())
               && (Horario::getMinuto() == horario.getMinuto())
               && (Horario::getSegundo() >= horario.getSegundo()) );
}

/**
 *
 * @param horario
 * @return
 */
bool Horario::operator>(const Horario & horario)
{
    return ( Horario::getHora() > horario.getHora() )
           || ( (Horario::getHora() == horario.getHora())
                && (Horario::getMinuto() > horario.getMinuto()) )
           ||( (Horario::getHora() == horario.getHora())
               && (Horario::getMinuto() == horario.getMinuto())
               && (Horario::getSegundo() > horario.getSegundo()) );
}

/**
 *
 * @param horario
 * @return
 */
bool Horario::operator<=(const Horario & horario)
{
    return ( Horario::getHora() < horario.getHora() )
           || ( (Horario::getHora() == horario.getHora())
                && (Horario::getMinuto() < horario.getMinuto()) )
           ||( (Horario::getHora() == horario.getHora())
               && (Horario::getMinuto() == horario.getMinuto())
               && (Horario::getSegundo() <= horario.getSegundo()) );
}

/**
 *
 * @param horario
 * @return
 */
bool Horario::operator<(const Horario & horario)
{
    return ( Horario::getHora() < horario.getHora() )
           || ( (Horario::getHora() == horario.getHora())
                && (Horario::getMinuto() < horario.getMinuto()) )
           ||( (Horario::getHora() == horario.getHora())
               && (Horario::getMinuto() == horario.getMinuto())
               && (Horario::getSegundo() < horario.getSegundo()) );
}

/**
 *
 * @return
 */
ostream & operator<<(ostream & os, const Horario & horario)
{
    os << horario.getHoraString() << ":"
       << horario.getMinutoString() << "."
       << horario.getSegundoString();

    return os;
}

/**
 *
 * @param horario
 * @return
 */
Horario& Horario::operator=(const Horario &horario)
{
    this->hora = horario.hora;
    this->minuto = horario.minuto;
    this->segundo = horario.segundo;

    return *this;
}

/**
 *
 * @return
 */
Json::Value Horario::toJson()
{
    Json::Value obj;
    obj["hora"] = getHora();
    obj["minuto"] = getMinuto();
    obj["segundo"] = getSegundo();

    return obj;
}

/**
 *
 * @param obj
 */
void Horario::fromJson(Json::Value obj)
{
    setHora(obj["hora"].asInt());
    setMinuto(obj["minuto"].asInt());
    setSegundo(obj["segundo"].asInt());
}
