#include "headers/novocompromissowindow.h"
#include "ui_novocompromissowindow.h"

NovoCompromissoWindow::NovoCompromissoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NovoCompromissoWindow)
{
    ui->setupUi(this);
    
}

NovoCompromissoWindow::NovoCompromissoWindow(MyVector<Usuario> *usuarios, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NovoCompromissoWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("NOVO COMPROMISSO");

    ptr_usuarios = usuarios;

    QString label;
    label.append(QString::fromLatin1("Ola "));
    label.append(QString::fromStdString(Sessao::getUsername()));
    ui->labelOla->setText(label);
}

NovoCompromissoWindow::~NovoCompromissoWindow()
{
    delete ui;
}

void NovoCompromissoWindow::on_pushButtonSair_clicked()
{
    this->close();
    qApp->quit();
}

void NovoCompromissoWindow::on_pushButtonVoltar_clicked()
{
    this->parentWidget()->show();
    this->close();
}

void NovoCompromissoWindow::on_pushButtonAdicionar_clicked()
{
    Data data(ui->lineEditAno->text().toInt(),
              ui->lineEditMes->text().toInt(),
              ui->lineEditDia->text().toInt());

    Horario horario(ui->lineEditHora->text().toInt(),
                    ui->lineEditMinuto->text().toInt(),
                    ui->lineEditSegundo->text().toInt());

    Compromisso compromisso(data,horario,ui->lineEditTitulo->text().toStdString());
    compromisso.setLocal(ui->lineEditLocal->text().toStdString());
    compromisso.setDescricao(ui->plainTextEditDescricao->toPlainText().toStdString());

    ptr_usuarios->contentAt(Sessao::getPosicao()).compromissos.insertInOrder(compromisso);

    ui->lineEditAno->setText("");
    ui->lineEditMes->setText("");
    ui->lineEditHora->setText("");
    ui->lineEditMinuto->setText("");
    ui->lineEditSegundo->setText("");
    ui->lineEditLocal->setText("");
    ui->lineEditTitulo->setText("");
    ui->plainTextEditDescricao->document()->clear();

    this->parentWidget()->show();
    this->close();
}
