#include "headers/menuwindow.h"
#include "headers/perfilwindow.h"
#include "headers/compromissoswindow.h"
#include "ui_menuwindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
}

MenuWindow::MenuWindow(MyVector<Usuario> *usuarios, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("MENU");

    ptr_usuarios = usuarios;

    QString label;
    label.append(QString::fromStdString("Ola "));
    label.append(QString::fromStdString(Sessao::getUsername()));
    ui->labelOla->setText(label);
}

MenuWindow::~MenuWindow()
{
    delete ui;
    Sessao::reset();
}

void MenuWindow::on_pushButtonSair_clicked()
{
    this->close();
    qApp->quit();
}

void MenuWindow::on_pushButtonVoltar_clicked()
{
    this->parentWidget()->show();
    this->close();
}


void MenuWindow::on_pushButtonPerfil_clicked()
{
    ptr_window = new PerfilWindow(ptr_usuarios,this);
    ptr_window->setAttribute(Qt::WA_DeleteOnClose);
    //connect(ptr_window, &QDialog::destroyed, this, &MenuWindow::show);

    ptr_window->show();
    this->hide();
}

void MenuWindow::on_pushButtonCompromissos_clicked()
{
    ptr_window = new CompromissosWindow(ptr_usuarios, this);
    ptr_window->setAttribute(Qt::WA_DeleteOnClose);


    ptr_window->show();
    this->hide();
}

void MenuWindow::on_pushButtonNovo_clicked()
{
    ptr_window = new NovoCompromissoWindow(ptr_usuarios, this);
    ptr_window->setAttribute(Qt::WA_DeleteOnClose);


    ptr_window->show();
    this->hide();
}

void MenuWindow::on_pushButtonRemover_clicked()
{
    Usuario usuario(Sessao::getUsername());
    ptr_usuarios->removeOne(usuario);
    Sessao::reset();

    this->parentWidget()->show();
    this->close();
}

