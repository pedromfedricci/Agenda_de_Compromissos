#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(MyVector<Usuario> &usuarios, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("LOGIN");
    MainWindow::ptr_usuarios = &usuarios;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonEntrar_clicked()
{
    string username = ui->lineEditUsername->text().toStdString();

    if (username == "" || username.size() < 4)
    {
        QMessageBox msgBox;
        msgBox.setText("Username inválido");
        msgBox.exec();
    }
    else
    {
        Usuario usuario(username);
        ptr_usuarios->insertInOrder(usuario);
        long pos = ptr_usuarios->searchIndex(usuario);
        Sessao::setSessao(ptr_usuarios->contentAt(pos), pos);

        ptr_window = new MenuWindow(ptr_usuarios,this);
        ptr_window->setAttribute(Qt::WA_DeleteOnClose);
        //connect(ptr_window,&QDialog::destroyed, this, &MainWindow::activateWindow);

        ptr_window->show();
        this->hide();
    }

    ui->lineEditUsername->setText("");
}

void MainWindow::on_pushButtonSair_clicked()
{
    qApp->quit();
}
