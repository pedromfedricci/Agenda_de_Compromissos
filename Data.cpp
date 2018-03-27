//
// Created by pedro on 19/03/18.
//

#include "Data.h"

const int Data::diasPorMes[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};

const string Data::nomeMes[13] =
        {"", "Janeiro", "Fevereiro", "Marco",
         "Abril", "Maio", "Junho", "Julho",
         "Agosto", "Setembro", "Outubro",
         "Novembro", "Dezembro"
        };
/**
 *
 */
Data::Data()
{
    ano = 1970;
    mes = 1;
    dia = 1;
}

/**
 *
 * @param ano
 */
Data::Data(int ano)
{
    setAno(ano);
    mes = 1;
    dia = 1;
}

/**
 *
 * @param ano
 * @param mes
 */
Data::Data(int ano, int mes)
{
    setAno(ano);
    setMes(mes);
    dia = 1;
}

/**
 *
 * @param ano
 * @param mes
 * @param dia
 */
Data::Data(int ano, int mes, int dia)
{
    setAno(ano);
    setMes(mes);
    setDia(dia);
}

void Data::setData(int ano, int mes, int dia)
{
    setAno(ano);
    setMes(mes);
    setDia(dia);
}

/**
 *
 * @return
 */
int Data::getAno() const {
    return ano;
}

/**
 *
 * @param ano
 */
void Data::setAno(int ano)
{
    if (ano < 1970)
        this->ano = 1970;

    else if (ano > 9999)
        this->ano = 9999;

    else this->ano = ano;
}

/**
 *
 * @return
 */
string Data::getAnoString() const
{
    return to_string(getAno());
}

/**
 *
 * @return
 */
int Data::getMes() const {
    return mes;
}

/**
 *
 * @return
 */
string Data::getMesString() const
{
    return nomeMes[getMes()];
}

/**
 *
 * @param mes
 */
void Data::setMes(int mes)
{
    if (mes >= 1 && mes <= 12)
        this->mes = mes;
    else this->mes = 1;
}

/**
 *
 * @return
 */
int Data::getDia() const {
    return dia;
}

/**
 *
 * @param dia
 */
void Data::setDia(int dia)
{
    if (dia >= 1 && dia <= diasPorMes[getMes()])
        this->dia = dia;

    else if ((mes == 2 && dia == 29)
             && ((getAno() % 400 == 0)
                 || ((getAno() % 4 == 0)
                     && (getAno() % 100 != 0))))
    { this->dia = dia; }

    else this->dia = 1;
}

string Data::getDiaString() const
{
    if (getDia() >= 1 && getDia() <= 9)
        return to_string(0).append(to_string(getDia()));

    else return to_string(getDia());
}

/**
 *
 * @param os
 * @param data
 * @return
 */
ostream & operator<<(ostream & os, const Data & data)
{
    os << data.getDiaString() << "/"
       << data.getMesString() << "/"
       << data.getAnoString();

    return os;
}

/**
 *
 * @param data
 * @return
 */
bool Data::operator==(const Data & data)
{
    return (Data::getAno() == data.getAno())
           && (Data::getMes() == data.getMes())
           && (Data::getDia() == data.getDia());
}

/**
 *
 * @param data
 * @return
 */
bool Data::operator!=(const Data & data)
{
    return (Data::getAno() != data.getAno())
           || (Data::getMes() != data.getMes())
           || (Data::getDia() != data.getDia());
}

/**
 *
 * @param data
 * @return
 */
bool Data::operator>=(const Data & data)
{
    return ( Data::getAno() > data.getAno() )
           || ( (Data::getAno() == data.getAno())
                && (Data::getMes() > data.getMes()) )
           || ( (Data::getAno() == data.getAno())
                && (Data::getMes()) == data.getMes()
                && (Data::getDia()) >= data.getDia() );
}

/**
 *
 * @param data
 * @return
 */
bool Data::operator>(const Data & data)
{
    return ( Data::getAno() > data.getAno() )
           || ( (Data::getAno() == data.getAno())
                && (Data::getMes() > data.getMes()) )
           || ( (Data::getAno() == data.getAno())
                && (Data::getMes()) == data.getMes()
                && (Data::getDia()) > data.getDia() );
}

/**
 *
 * @param data
 * @return
 */
bool Data::operator<=(const Data & data)
{
    return ( Data::getAno() < data.getAno() )
           || ( (Data::getAno() == data.getAno())
                && (Data::getMes() < data.getMes()) )
           || ( (Data::getAno() == data.getAno())
                && (Data::getMes()) == data.getMes()
                && (Data::getDia()) <= data.getDia() );
}

/**
 *
 * @param data
 * @return
 */
bool Data::operator<(const Data & data)
{
    return ( Data::getAno() < data.getAno() )
           || ( (Data::getAno() == data.getAno())
                && (Data::getMes() < data.getMes()) )
           || ( (Data::getAno() == data.getAno())
                && (Data::getMes()) == data.getMes()
                && (Data::getDia()) < data.getDia() );
}

Data& Data::operator=(const Data &data)
{
    this->ano = data.ano;
    this->mes = data.mes;
    this->dia = data.dia;
}