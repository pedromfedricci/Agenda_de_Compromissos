#ifndef VALIDARLOGIN_H
#define VALIDARLOGIN_H
#include <string>
#include<MyVector.h>
#include<Usuario.h>
#include <QMessageBox>
using namespace std;

class validarLogin{
public:
    bool validaLogin(MyVector<usuario> &v,string nome,string usuario,string senha){
        for(int i =0;i<=v.getN();i++)
        {
            if(v[i]->getLogin() == usuario){
                QMessageBox msgBox;
                msgBox.setText("Login já utilizado");
                msgBox.exec();
                cout<<"Escolha outro login"<<endl;
                return false;
            }
        }
        v.insertInOrder(Usuario(nome,usuario,senha));
        return true;
    }
};
#endif // VALIDARLOGIN_H
