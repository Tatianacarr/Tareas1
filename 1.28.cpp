#include <iostream>
using namespace std;

int main() {
    int matriz[3][3];
    int sumaFila, sumaTotal = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Ingrese el valor para la posición [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        sumaFila = 0;
        for (int j = 0; j < 3; j++) {
            sumaFila += matriz[i][j];
        }
        cout << "Suma de la fila " << i + 1 << ": " << sumaFila << endl;
        sumaTotal += sumaFila;
    }

    cout << "Suma total de la matriz: " << sumaTotal << endl;

    return 0;
}
