#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QString"
#include "QMessageBox"
#include "Usuario.h"
#include "MyVector.h"
#include "headers/sessao.h"
#include "headers/menuwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    MainWindow(MyVector<Usuario> &usuarios, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonEntrar_clicked();

    void on_pushButtonSair_clicked();

private:
    Ui::MainWindow *ui;
    MyVector<Usuario> *ptr_usuarios;
    QDialog *ptr_window;
};

#endif // MAINWINDOW_H
