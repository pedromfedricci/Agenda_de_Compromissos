#ifndef COMPROMISSOSWINDOW_H
#define COMPROMISSOSWINDOW_H

#include <QDialog>
#include "headers/Usuario.h"
#include "headers/MyVector.h"
#include "headers/sessao.h"
#include "headers/Compromisso.h"

namespace Ui {
class CompromissosWindow;
}

class CompromissosWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CompromissosWindow(QWidget *parent = 0);
    CompromissosWindow(MyVector<Usuario> *usuarios, QWidget *parent = 0);
    ~CompromissosWindow();

private slots:
    void on_pushButtonVoltar_clicked();

    void on_pushButtonSair_clicked();

    void on_pushButtonAnterior_clicked();

    void on_pushButtonProximo_clicked();

    void on_pushButtonRemover_clicked();

private:
    Ui::CompromissosWindow *ui;
    MyVector<Usuario> *ptr_usuarios;
    long posicao;

    void carregarDaPosicao(long pos);
    long andarParaFrente(bool b = true);
};

#endif 
