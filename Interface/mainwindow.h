#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>

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

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
