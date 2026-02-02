#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QInputDialog>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QHBoxLayout>
// ---------- ESTILOS GENERALES ----------


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tblDatos->setColumnCount(5);
    ui->tblDatos->setHorizontalHeaderLabels(
        {"Código", "Nombre", "Servicio", "Año", "Estado"}
        );

    cargarArchivo();
    // ---------- ESTILOS GENERALES ----------
    this->setStyleSheet(R"(

/* Ventana principal */
QMainWindow {
    background-color: #f4f6f8;
}

/* Labels */
QLabel {
    color: #2c3e50;
    font-size: 14px;
    font-weight: bold;
}

/* LineEdit, ComboBox, SpinBox */
QLineEdit, QComboBox, QSpinBox {
    border: 2px solid #3498db;
    border-radius: 8px;
    padding: 6px;
    font-size: 13px;
    background-color: white;
}

QLineEdit:focus, QComboBox:focus, QSpinBox:focus {
    border: 2px solid #1abc9c;
}

/* Tabla */
QTableWidget {
    border: 2px solid #2c3e50;
    border-radius: 10px;
    background-color: white;
    gridline-color: #bdc3c7;
    font-size: 13px;
}

QHeaderView::section {
    background-color: #2c3e50;
    color: white;
    padding: 6px;
    border: none;
    font-weight: bold;
}

/* Filas seleccionadas */
QTableWidget::item:selected {
    background-color: #3498db;
    color: white;
}

/* Botones */
QPushButton {
    background-color: #3498db;
    color: white;
    border-radius: 10px;
    padding: 8px 14px;
    font-size: 13px;
    font-weight: bold;
}

QPushButton:hover {
    background-color: #1abc9c;
}

QPushButton:pressed {
    background-color: #2980b9;
}

)");

}

MainWindow::~MainWindow()
{
    delete ui;
}

// ---------------- GUARDAR ----------------
void MainWindow::on_btnGuardar_clicked()
{
    if (ui->txtCodigo->text().isEmpty() || ui->txtNombre->text().isEmpty()) {
        QMessageBox::warning(this, "Error", "Complete todos los campos");
        return;
    }

    QFile file("clientes.dat");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo");
        return;
    }

    QTextStream out(&file);
    out << ui->txtCodigo->text() << ","
        << ui->txtNombre->text() << ","
        << ui->cmbTipo->currentText() << ","
        << ui->spAnio->value() << ","
        << ui->cmbEstado->currentText() << "\n";

    file.close();

    cargarArchivo();
    QMessageBox::information(this, "OK", "Cliente guardado");
}

// ---------------- ELIMINAR ----------------
void MainWindow::on_btnEliminar_clicked()
{
    bool ok;
    QString codigo = QInputDialog::getText(
        this,
        "Eliminar cliente",
        "Ingrese el código:",
        QLineEdit::Normal,
        "",
        &ok
        );

    if (!ok || codigo.trimmed().isEmpty())
        return;

    int fila = -1;

    for (int i = 0; i < ui->tblDatos->rowCount(); i++) {
        if (ui->tblDatos->item(i, 0)->text() == codigo) {
            fila = i;
            break;
        }
    }

    if (fila == -1) {
        QMessageBox::warning(this, "No encontrado", "Código no existe");
        return;
    }

    if (QMessageBox::question(this, "Confirmar",
                              "¿Eliminar el cliente?") == QMessageBox::Yes) {

        ui->tblDatos->removeRow(fila);
        guardarArchivo();

        QMessageBox::information(this, "OK", "Cliente eliminado");
    }
}

// ---------------- BUSCAR ----------------
void MainWindow::on_btnBuscar_clicked()
{
    bool ok;
    QString codigo = QInputDialog::getText(
        this,
        "Buscar cliente",
        "Ingrese el código:",
        QLineEdit::Normal,
        "",
        &ok
        );

    if (!ok || codigo.trimmed().isEmpty())
        return;

    for (int i = 0; i < ui->tblDatos->rowCount(); i++) {
        if (ui->tblDatos->item(i, 0)->text() == codigo) {

            QString info =
                "Código: " + ui->tblDatos->item(i, 0)->text() + "\n" +
                "Nombre: " + ui->tblDatos->item(i, 1)->text() + "\n" +
                "Servicio: " + ui->tblDatos->item(i, 2)->text() + "\n" +
                "Año: " + ui->tblDatos->item(i, 3)->text() + "\n" +
                "Estado: " + ui->tblDatos->item(i, 4)->text();

            QMessageBox::information(this, "Cliente encontrado", info);
            return;
        }
    }

    QMessageBox::warning(this, "No encontrado", "Cliente no existe");
}

// ---------------- ACTUALIZAR ----------------
void MainWindow::on_btnActualizar_clicked()
{
    bool ok;
    QString codigo = QInputDialog::getText(
        this,
        "Actualizar cliente",
        "Ingrese el código:",
        QLineEdit::Normal,
        "",
        &ok
        );

    if (!ok || codigo.trimmed().isEmpty())
        return;

    int fila = -1;

    for (int i = 0; i < ui->tblDatos->rowCount(); i++) {
        if (ui->tblDatos->item(i, 0)->text() == codigo) {
            fila = i;
            break;
        }
    }

    if (fila == -1) {
        QMessageBox::warning(this, "Error", "Cliente no encontrado");
        return;
    }

    QDialog dialog(this);
    dialog.setWindowTitle("Actualizar cliente");

    QFormLayout form(&dialog);

    QLineEdit txtNombre;
    QComboBox cmbTipo;
    QSpinBox spAnio;
    QComboBox cmbEstado;

    cmbTipo.addItems({"Internet", "Telefonía", "Combo"});
    cmbEstado.addItems({"Activo", "Suspendido"});

    txtNombre.setText(ui->tblDatos->item(fila, 1)->text());
    cmbTipo.setCurrentText(ui->tblDatos->item(fila, 2)->text());
    spAnio.setValue(ui->tblDatos->item(fila, 3)->text().toInt());
    cmbEstado.setCurrentText(ui->tblDatos->item(fila, 4)->text());

    form.addRow("Nombre:", &txtNombre);
    form.addRow("Servicio:", &cmbTipo);
    form.addRow("Año:", &spAnio);
    form.addRow("Estado:", &cmbEstado);

    QPushButton btnGuardar("Guardar");
    QPushButton btnCancelar("Cancelar");

    QHBoxLayout botones;
    botones.addWidget(&btnGuardar);
    botones.addWidget(&btnCancelar);

    form.addRow(&botones);

    connect(&btnGuardar, &QPushButton::clicked, &dialog, &QDialog::accept);
    connect(&btnCancelar, &QPushButton::clicked, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {

        ui->tblDatos->setItem(fila, 1, new QTableWidgetItem(txtNombre.text()));
        ui->tblDatos->setItem(fila, 2, new QTableWidgetItem(cmbTipo.currentText()));
        ui->tblDatos->setItem(fila, 3, new QTableWidgetItem(QString::number(spAnio.value())));
        ui->tblDatos->setItem(fila, 4, new QTableWidgetItem(cmbEstado.currentText()));

        guardarArchivo();

        QMessageBox::information(this, "OK", "Cliente actualizado");
    }
}

// ---------------- ARCHIVOS ----------------
void MainWindow::cargarArchivo()
{
    QFile file("clientes.dat");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    ui->tblDatos->setRowCount(0);

    while (!in.atEnd()) {
        QStringList datos = in.readLine().split(",");

        int fila = ui->tblDatos->rowCount();
        ui->tblDatos->insertRow(fila);

        for (int i = 0; i < datos.size(); i++) {
            ui->tblDatos->setItem(fila, i, new QTableWidgetItem(datos[i]));
        }
    }

    file.close();
}

void MainWindow::guardarArchivo()
{
    QFile file("clientes.dat");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);

    for (int i = 0; i < ui->tblDatos->rowCount(); i++) {
        for (int j = 0; j < ui->tblDatos->columnCount(); j++) {
            out << ui->tblDatos->item(i, j)->text();
            if (j < 4) out << ",";
        }
        out << "\n";
    }

    file.close();
}

