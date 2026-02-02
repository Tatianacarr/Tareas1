#include <iostream>
#include <fstream>
#include <string>
#include "3.h"
using namespace std;


Publicacion registrarPublicacion() {
    Publicacion p;

    cout << "Ingrese codigo: ";
    cin >> p.codigo;
    cin.ignore();

    cout << "Ingrese titulo: ";
    getline(cin, p.titulo);

    cout << "Ingrese anio de publicacion: ";
    cin >> p.anio;

    cout << "Ingrese tipo (Libro / Revista): ";
    cin >> p.tipo;

    p.estado = "No Prestado";
    return p;
}

void prestarPublicacion(Publicacion &p) {
    p.estado = "Prestado";
}

void devolverPublicacion(Publicacion &p) {
    p.estado = "No Prestado";
}

string mostrarPublicacion(Publicacion p) {
    return "Codigo: " + to_string(p.codigo) +
           " | Titulo: " + p.titulo +
           " | Anio: " + to_string(p.anio) +
           " | Tipo: " + p.tipo +
           " | Estado: " + p.estado;
}

void guardarPublicacion(Publicacion p) {
    ofstream archivo;

    if (p.estado == "Prestado") {
        archivo.open("LibrosPrestados.txt", ios::app);
    } else {
        archivo.open("LibrosEnStock.txt", ios::app);
    }

    archivo << p.codigo << ","
            << p.titulo << ","
            << p.anio << ","
            << p.estado << endl;

    archivo.close();
}

void leerArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }

    string linea;
    cout << "\nContenido de " << nombreArchivo << ":\n";

    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}
