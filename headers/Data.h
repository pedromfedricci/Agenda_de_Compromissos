#ifndef DATA_H
#define DATA_H

#include <iostream>
#include "../json/json.h"
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

    Json::Value toJson();
    void fromJson(Json::Value);

    static const int diasPorMes[];
    static const string nomeMes[];

private:
    int mes;
    int dia;
    int ano;
};

#endif //DATA_H
