#include "PlayerInputDialog.h"
#include "ui_PlayerInputDialog.h"

PlayerInputDialog::PlayerInputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerInputDialog)
{
    ui->setupUi(this);
}

PlayerInputDialog::~PlayerInputDialog()
{
    delete ui;
}

QString PlayerInputDialog::getPlayerID() const
{
    return ui->lineEditID->text(); // Suponiendo que se tiene un LineEdit en el formulario para ingresar la cédula
}
