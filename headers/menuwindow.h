#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QDialog>
#include "headers/Usuario.h"
#include "headers/MyVector.h"
#include "headers/sessao.h"
#include "headers/novocompromissowindow.h"

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = 0);
    MenuWindow(MyVector<Usuario> *usuarios, QWidget *parent = 0);
    ~MenuWindow();

private slots:
    void on_pushButtonSair_clicked();

    void on_pushButtonVoltar_clicked();

    void on_pushButtonPerfil_clicked();

    void on_pushButtonCompromissos_clicked();

    void on_pushButtonNovo_clicked();

    void on_pushButtonRemover_clicked();

private:
    Ui::MenuWindow *ui;
    MyVector<Usuario> *ptr_usuarios;
    QDialog *ptr_window;
};

#endif // MENUWINDOW_H
