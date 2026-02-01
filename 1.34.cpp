#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Estructura Cliente
struct Cliente {
    string nombre;
    int edad;
    float consumoMensual;
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
        cout << "Consumo mensual: ";
        cin >> c.consumoMensual;

        clientes.push_back(c);
    }

    ofstream archivo("clientes.txt");
    for (int i = 0; i < clientes.size(); i++) {
        archivo << clientes[i].nombre << " "
                << clientes[i].edad << " "
                << clientes[i].consumoMensual << endl;
    }
    archivo.close();

    cout << "\nDatos guardados en el archivo clientes.txt\n";

    vector<Cliente> clientesLeidos;
    ifstream archivoLeer("clientes.txt");

    while (archivoLeer >> c.nombre >> c.edad >> c.consumoMensual) {
        clientesLeidos.push_back(c);
    }
    archivoLeer.close();
    float consumoTotal = 0;
    float mayorConsumo = clientesLeidos[0].consumoMensual;
    string clienteMayor = clientesLeidos[0].nombre;

    for (int i = 0; i < clientesLeidos.size(); i++) {
        consumoTotal += clientesLeidos[i].consumoMensual;

        if (clientesLeidos[i].consumoMensual > mayorConsumo) {
            mayorConsumo = clientesLeidos[i].consumoMensual;
            clienteMayor = clientesLeidos[i].nombre;
        }
    }

    float consumoPromedio = consumoTotal / clientesLeidos.size();
    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Consumo total: " << consumoTotal << endl;
    cout << "Consumo promedio: " << consumoPromedio << endl;
    cout << "Cliente con mayor consumo: " << clienteMayor << endl;
    cout << "Mayor consumo: " << mayorConsumo << endl;

    return 0;
}
