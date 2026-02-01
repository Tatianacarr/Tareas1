#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Estructura Cliente
struct Cliente {
    string nombre;
    int edad;
};

int main() {
    vector<Cliente> clientes;
    Cliente c;
    int cantidad;
    string nombreBuscar;
    bool encontrado = false;

    cout << "Ingrese la cantidad de clientes: ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++) {
        cout << "\nCliente " << i + 1 << endl;
        cout << "Nombre: ";
        cin >> c.nombre;
        cout << "Edad: ";
        cin >> c.edad;

        clientes.push_back(c);
    }
    ofstream archivo("clientes.txt");
    for (int i = 0; i < clientes.size(); i++) {
        archivo << clientes[i].nombre << " " << clientes[i].edad << endl;
    }
    archivo.close();

    cout << "\nDatos guardados en el archivo clientes.txt" << endl;
    cout << "\nIngrese el nombre del cliente a buscar: ";
    cin >> nombreBuscar;

    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i].nombre == nombreBuscar) {
            cout << "Cliente encontrado" << endl;
            cout << "Nombre: " << clientes[i].nombre << endl;
            cout << "Edad: " << clientes[i].edad << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Cliente no registrado." << endl;
    }

    return 0;
}
