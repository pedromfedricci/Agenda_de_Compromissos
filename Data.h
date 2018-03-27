//
// Created by pedro on 19/03/18.
//

#ifndef DATA_H
#define DATA_H

#include <iostream>
using namespace std;

class Data {

public:
    Data();
    Data(int,int,int);
    Data(int, int);
    explicit Data(int);

    void setData(int,int,int);
    void setAno(int);
    int getAno() const;
    string getAnoString() const;
    void setMes(int);
    int getMes() const;
    string getMesString() const;
    void setDia(int);
    int getDia() const;
    string getDiaString() const;

    bool operator==(const Data &);
    bool operator!=(const Data &);
    bool operator>=(const Data &);
    bool operator>(const Data &);
    bool operator<=(const Data &);
    bool operator<(const Data &);
    Data& operator=(const Data &);

    friend ostream& operator<<(ostream &, const Data &);

    static const int diasPorMes[];
    static const string nomeMes[];

private:
    int mes;
    int dia;
    int ano;
};

#endif //DATA_H
