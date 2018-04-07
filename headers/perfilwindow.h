#ifndef PERFILWINDOW_H
#define PERFILWINDOW_H

#include <QDialog>
#include "headers/Usuario.h"
#include "headers/MyVector.h"

namespace Ui {
class PerfilWindow;
}

class PerfilWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PerfilWindow(QWidget *parent = 0);
    PerfilWindow(MyVector<Usuario> *usuarios, QWidget *parent = 0);
    ~PerfilWindow();

private slots:
    void on_pushButtonSair_clicked();

    void on_pushButtonVoltar_clicked();

    void on_pushButtonOk_clicked();

private:
    Ui::PerfilWindow *ui;
    MyVector<Usuario> *ptr_usuarios;
};

#endif // PERFILWINDOW_H
