#include <iostream>
#include <vector>
using namespace std;
struct Cliente {
    string nombre;
    int edad;
};
int main() {
    vector<Cliente> clientes;
    Cliente c;
    int cantidad;

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
    cout << "\n--- Lista de Clientes Registrados ---" << endl;
    for (int i = 0; i < clientes.size(); i++) {
        cout << "Cliente " << i + 1 << endl;
        cout << "Nombre: " << clientes[i].nombre << endl;
        cout << "Edad: " << clientes[i].edad << endl;
    }

    return 0;
}
