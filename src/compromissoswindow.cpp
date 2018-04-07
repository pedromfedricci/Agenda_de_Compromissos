#include "headers/compromissoswindow.h"
#include "ui_compromissoswindow.h"

CompromissosWindow::CompromissosWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompromissosWindow)
{
    ui->setupUi(this);
}

CompromissosWindow::CompromissosWindow(MyVector<Usuario> *usuarios, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompromissosWindow)
{
    ui->setupUi(this);
    ptr_usuarios = usuarios;

    QString label;
    label.append(QString::fromLatin1("Ola "));
    label.append(QString::fromStdString(Sessao::getUsername()));
    ui->labelOla->setText(label);

    posicao = 1;
    carregarDaPosicao(posicao);
}

void CompromissosWindow::carregarDaPosicao(long pos)
{
    Compromisso temp;
    bool valid = ptr_usuarios->contentAt(Sessao::getPosicao()).compromissos.iterate(temp ,pos);

    if (valid)
    {
        ui->lineEditAno->setText(QString::number(temp.data.getAno()));
        ui->lineEditMes->setText(QString::number(temp.data.getMes()));
        ui->lineEditDia->setText(QString::number(temp.data.getDia()));

        ui->lineEditHora->setText(QString::number(temp.horario.getHora()));
        ui->lineEditMinuto->setText(QString::number(temp.horario.getMinuto()));
        ui->lineEditSegundo->setText(QString::number(temp.horario.getSegundo()));

        ui->lineEditTitulo->setText(QString::fromStdString(temp.getTitulo()));
        ui->lineEditLocal->setText(QString::fromStdString(temp.getLocal()));
        ui->plainTextEditDescricao->document()->setPlainText(QString::fromStdString(temp.getDescricao()));
    }
}

long CompromissosWindow::andarParaFrente(bool b)
{
    long temp;
    long size = ptr_usuarios->contentAt(Sessao::getPosicao()).compromissos.getSize();
    if (b) temp = 1;
    else temp = -1;

    posicao = posicao + temp;
    if (posicao > size) posicao = 1;
    else if (posicao <= 0) posicao = size;

    return posicao;
}

CompromissosWindow::~CompromissosWindow()
{
    delete ui;
}

void CompromissosWindow::on_pushButtonVoltar_clicked()
{
    this->parentWidget()->show();
    this->close();
}

void CompromissosWindow::on_pushButtonSair_clicked()
{
    this->close();
    qApp->quit();
}

void CompromissosWindow::on_pushButtonAnterior_clicked()
{
    carregarDaPosicao(andarParaFrente(false));
}

void CompromissosWindow::on_pushButtonProximo_clicked()
{
    carregarDaPosicao(andarParaFrente(true));
}

void CompromissosWindow::on_pushButtonRemover_clicked()
{
    Compromisso temp;
    ptr_usuarios->contentAt(Sessao::getPosicao()).compromissos.iterate(temp ,this->posicao);
    ptr_usuarios->contentAt(Sessao::getPosicao()).compromissos.removeOne(temp);
    CompromissosWindow::carregarDaPosicao(andarParaFrente(true));
}
