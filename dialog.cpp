#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnIngresar_clicked()
{
    // Login simple
    if (ui->txtUsuario->text() == "admin" &&
        ui->txtClave->text() == "1234") {

        accept(); // ✅ ABRE EL MAINWINDOW
    } else {
        QMessageBox::warning(this, "Error", "Usuario o clave incorrectos");
    }
}

