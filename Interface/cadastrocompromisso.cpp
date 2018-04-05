#include "cadastrocompromisso.h"
#include "ui_cadastrocompromisso.h"

cadastrocompromisso::cadastrocompromisso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastrocompromisso)
{
    ui->setupUi(this);
}

cadastrocompromisso::~cadastrocompromisso()
{
    delete ui;
}
