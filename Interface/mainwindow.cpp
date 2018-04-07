#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QWidget>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->btnAtualizar, SIGNAL(clicked(bool)), this, SLOT(updateUsers(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::updateUsers(bool)
{
    using namespace std;
    ifstream fin("C:\\Users\\Pedro\\Desktop\\usuarios.txt");
    char temp;
    QString buffer;
    while(fin.get(temp))
        buffer.push_back(QChar(temp));

    //ui->textEdit->setText(buffer);
}

void MainWindow::on_btnCadastrar_clicked()
{
    if(ui->lName->text().isEmpty() || ui->lLogin->text().isEmpty())
        return;
    using namespace std;
    ofstream fout("C:\\Users\\Pedro\\Desktop\\usuarios.txt", ios::app);

    fout <<ui->lName->text().toStdString() <<endl;
    fout <<ui->lLogin->text().toStdString() <<endl;
    fout <<ui->lSenha->text().toStdString() <<endl;

    fout <<" ---- " <<endl;


   updateUsers(true);
   ui->show->setText("Usuário Cadastrado");
}

void MainWindow::on_btnSair_clicked()
{
    qApp->quit();
}



void MainWindow::on_btnLogar_clicked()
{
    bool entrou = false;
    MyVector<Usuario> u = Cadastrados;
    string usuario = (ui->lLogin->text()).toStdString();
    string senha = (ui->lSenha->text()).toStdString();
    for(int i =0;i<=u.getSize();i++)
        if(u[i]->getUsername() == usuario){
            if(u[i]->getPassword() == senha){
                ind = i;
                entrou = true;
            }
        }
    if(ind == -1)
    {
        QMessageBox message;
        message.setText("Dados incorretos");
        message.exec();
    }
    updateUsers(entrou);
}

void MainWindow::on_btnCadastrarCompromisso_clicked()
{

}

void MainWindow::on_btnRemoverCompromisso_clicked()
{

}

void MainWindow::on_btnAnt_clicked()
{

}

void MainWindow::on_btnProx_clicked()
{

}
