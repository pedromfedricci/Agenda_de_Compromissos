#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QInputDialog>

#include <iostream>
#include <cstdlib>
#include "MyVector.h"
#include "DoublyLinkedList.h"
#include "Horario.h"
#include "Usuario.h"
#include "Data.h"

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void updateUsers(bool);

    void on_btnCadastrar_clicked();

    void on_btnSair_clicked();

    void on_btnLogar_clicked();

    void on_btnCadastrarCompromisso_clicked();

    void on_btnRemoverCompromisso_clicked();

    void on_btnAnt_clicked();

    void on_btnProx_clicked();

private:
    Ui::MainWindow *ui;
    int ind;
    MyVector<Usuario>Cadastrados;
};

#endif // MAINWINDOW_H
