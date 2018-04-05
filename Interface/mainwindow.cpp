#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnAtualizar, SIGNAL(clicked(bool)), this, SLOT(updateUsers(bool)));
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
   ui->textEdit->setText("Usuário Cadastrado");
}

void MainWindow::on_btnSair_clicked()
{
    qApp->quit();
}


