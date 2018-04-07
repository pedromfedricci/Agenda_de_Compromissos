#ifndef NOVOCOMPROMISSOWINDOW_H
#define NOVOCOMPROMISSOWINDOW_H

#include <QDialog>
#include "headers/Usuario.h"
#include "headers/sessao.h"
#include "headers/MyVector.h"
#include "headers/Compromisso.h"

namespace Ui {
class NovoCompromissoWindow;
}

class NovoCompromissoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NovoCompromissoWindow(QWidget *parent = 0);
    NovoCompromissoWindow(MyVector<Usuario> *usuarios, QWidget *parent = 0);
    ~NovoCompromissoWindow();

private slots:
    void on_pushButtonSair_clicked();

    void on_pushButtonVoltar_clicked();

    void on_pushButtonAdicionar_clicked();

private:
    Ui::NovoCompromissoWindow *ui;
    MyVector<Usuario> *ptr_usuarios;
};

#endif // NOVOCOMPROMISSOWINDOW_H
