#include <iostream>
using namespace std;

struct Cliente {
    string nombre;
    int edad;
};

int main() {
    Cliente clientes[3];
    for (int i = 0; i < 3; i++) {
        cout << "\nCliente " << i + 1 << endl;
        cout << "Nombre: ";
        cin >> clientes[i].nombre;
        cout << "Edad: ";
        cin >> clientes[i].edad;
    }
    cout << "\n--- Clientes Mayores de Edad ---" << endl;
    for (int i = 0; i < 3; i++) {
        if (clientes[i].edad >= 18) {
            cout << "Nombre: " << clientes[i].nombre << endl;
            cout << "Edad: " << clientes[i].edad << endl;
            cout << "---------------------" << endl;
        }
    }

    return 0;
}
