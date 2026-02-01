#include <iostream>
using namespace std;

void llenarArreglo(float ventas[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Ingrese la venta " << i + 1 << ": ";
        cin >> ventas[i];
    }
}
void calcularTotal(float ventas[], int n, float &total) {
    total = 0;
    for (int i = 0; i < n; i++) {
        total += ventas[i];
    }
}
void contarMayores(float ventas[], int n, float promedio, int &contador) {
    contador = 0;
    for (int i = 0; i < n; i++) {
        if (ventas[i] > promedio) {
            contador++;
        }
    }
}

int main() {
    int n = 10;
    float ventas[10];
    float total, promedio;
    int mayores;

    llenarArreglo(ventas, n);

    calcularTotal(ventas, n, total);


    promedio = total / n;


    contarMayores(ventas, n, promedio, mayores);

    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Total de ventas: " << total << endl;
    cout << "Promedio de ventas: " << promedio << endl;
    cout << "Ventas mayores al promedio: " << mayores << endl;

    return 0;
}
