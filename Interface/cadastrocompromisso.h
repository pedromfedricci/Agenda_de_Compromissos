#ifndef CADASTROCOMPROMISSO_H
#define CADASTROCOMPROMISSO_H

#include <QDialog>

namespace Ui {
class cadastrocompromisso;
}

class cadastrocompromisso : public QDialog
{
    Q_OBJECT

public:
    explicit cadastrocompromisso(QWidget *parent = 0);
    ~cadastrocompromisso();

private:
    Ui::cadastrocompromisso *ui;
};

#endif // CADASTROCOMPROMISSO_H
