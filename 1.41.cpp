#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
void ingresarVentas(vector<double> &ventas) {
    int n;
    double valor;

    cout << "Ingrese la cantidad de ventas: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el valor de la venta " << i + 1 << ": ";
        cin >> valor;
        ventas.push_back(valor);
    }
}
void guardarVentasArchivo(const vector<double> &ventas) {
    ofstream archivo("ventas.txt");

    for (double v : ventas) {
        archivo << v << endl;
    }

    archivo.close();
}
vector<double> leerVentasArchivo() {
    vector<double> ventas;
    ifstream archivo("ventas.txt");
    double valor;

    while (archivo >> valor) {
        ventas.push_back(valor);
    }

    archivo.close();
    return ventas;
}
double calcularTotal(const vector<double> &ventas) {
    double total = 0;

    for (double v : ventas) {
        total += v;
    }

    return total;
}
double calcularPromedio(const vector<double> &ventas) {
    double total = calcularTotal(ventas);
    return total / ventas.size();
}
void contarVentas(const vector<double> &ventas, double promedio,
                   int &mayores, int &menores) {
    mayores = 0;
    menores = 0;

    for (double v : ventas) {
        if (v > promedio)
            mayores++;
        else if (v < promedio)
            menores++;
    }
}
int main() {
    vector<double> ventasIngresadas;
    vector<double> ventasArchivo;
    ingresarVentas(ventasIngresadas);
    guardarVentasArchivo(ventasIngresadas);
    ventasArchivo = leerVentasArchivo();
    double total = calcularTotal(ventasArchivo);
    double promedio = calcularPromedio(ventasArchivo);

    int mayores, menores;
    contarVentas(ventasArchivo, promedio, mayores, menores);
    cout << "\n----- RESULTADOS -----\n";
    cout << "Total de ventas: " << total << endl;
    cout << "Promedio de ventas: " << promedio << endl;
    cout << "Ventas mayores al promedio: " << mayores << endl;
    cout << "Ventas menores al promedio: " << menores << endl;

    return 0;
}
