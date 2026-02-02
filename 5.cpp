#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


struct Helado {
    int codigo;
    char sabor[20];
    float precio;
};

int main() {
    Helado h;
    ofstream archivoSalida;
    ifstream archivoEntrada;

    archivoSalida.open("helados.txt", ios::binary);

    if (!archivoSalida) {
        cout << "Error al crear el archivo." << endl;
        return 1;
    }

    cout << "INGRESO DE DATOS DE HELADOS\n";
    for (int i = 0; i < 10; i++) {
        cout << "\nHelado " << i + 1 << endl;
        cout << "Codigo: ";
        cin >> h.codigo;
        cin.ignore();

        cout << "Sabor: ";
        cin.getline(h.sabor, 20);

        cout << "Precio: ";
        cin >> h.precio;

        archivoSalida.write((char*)&h, sizeof(Helado));
    }

    archivoSalida.close();

    archivoEntrada.open("helados.txt", ios::binary);

    if (!archivoEntrada) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    Helado heladoBarato;
    bool primero = true;
    bool encontradoMora = false;
    float sumaPrecios = 0;

    cout << "\nLISTA DE HELADOS REGISTRADOS\n";

    while (archivoEntrada.read((char*)&h, sizeof(Helado))) {
        cout << "\nCodigo: " << h.codigo
             << "\nSabor: " << h.sabor
             << "\nPrecio: $" << h.precio << endl;

        sumaPrecios += h.precio;


        if (primero || h.precio < heladoBarato.precio) {
            heladoBarato = h;
            primero = false;
        }
        if (strcmp(h.sabor, "mora") == 0) {
            cout << "\n*** Helado de sabor MORA encontrado ***\n";
            encontradoMora = true;
        }
    }

    archivoEntrada.close();
    cout << "\nHELADO CON EL PRECIO MAS BAJO\n";
    cout << "Codigo: " << heladoBarato.codigo
         << "\nSabor: " << heladoBarato.sabor
         << "\nPrecio: $" << heladoBarato.precio << endl;

    if (!encontradoMora) {
        cout << "\nNo se encontro ningun helado de sabor mora." << endl;
    }

    cout << "\nSUMA TOTAL DE PRECIOS: $" << sumaPrecios << endl;

    return 0;
}
