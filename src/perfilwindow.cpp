#include "headers/perfilwindow.h"
#include "ui_perfilwindow.h"
#include "headers/sessao.h"

PerfilWindow::PerfilWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PerfilWindow)
{
    ui->setupUi(this);
}

PerfilWindow::PerfilWindow(MyVector<Usuario> *usuarios, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PerfilWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("PERFIL");
    ptr_usuarios = usuarios;

    QString label;
    label.append(QString::fromLatin1("Ola "));
    label.append(QString::fromStdString(Sessao::getUsername()));
    ui->labelOla->setText(label);

    ui->lineEditNome->setText(QString::fromStdString(Sessao::getNome()));
    ui->lineEditEmail->setText(QString::fromStdString(Sessao::getEmail()));
    ui->lineEditIdade->setText(QString::number(Sessao::getIdade()));
}

PerfilWindow::~PerfilWindow()
{
    delete ui;
}

void PerfilWindow::on_pushButtonSair_clicked()
{
    this->close();
    qApp->quit();
}

void PerfilWindow::on_pushButtonVoltar_clicked()
{
    this->parentWidget()->show();
    this->close();
}

void PerfilWindow::on_pushButtonOk_clicked()
{
    Usuario usuario(Sessao::getUsername(),
                    ui->lineEditNome->text().toStdString(),
                    ui->lineEditEmail->text().toStdString(),
                    ui->lineEditIdade->text().toInt());

    ptr_usuarios->contentAt(Sessao::getPosicao()).setNome(usuario.getNome());
    ptr_usuarios->contentAt(Sessao::getPosicao()).setEmail(usuario.getEmail());
    ptr_usuarios->contentAt(Sessao::getPosicao()).setIdade(usuario.getIdade());
    Sessao::setSessao(usuario,Sessao::getPosicao());

    this->parentWidget()->show();
    this->close();
}
