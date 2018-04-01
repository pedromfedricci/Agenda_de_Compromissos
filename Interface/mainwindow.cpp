#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(updateUsers(bool)));
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

    ui->textEdit->setText(buffer);
}

void MainWindow::on_pushButton_7_clicked()
{
    if(ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty())
        return;
    using namespace std;
    ofstream fout("C:\\Users\\Pedro\\Desktop\\usuarios.txt", ios::app);

    fout <<ui->lineEdit->text().toStdString() <<endl;
    fout <<ui->lineEdit_2->text().toStdString() <<endl;
    fout <<ui->lineEdit_3->text().toStdString() <<endl;

    fout <<" ---- " <<endl;

    updateUsers(true);
}

void MainWindow::on_pushButton_6_clicked()
{
    qApp->quit();
}


