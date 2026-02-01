#include <iostream>
using namespace std;

int main() {
    int numeros[10];
    int suma = 0;
    int positivos = 0;
    int negativos = 0;

    for (int i = 0; i < 10; i++) {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> numeros[i];

        suma = suma + numeros[i]; 
        if (numeros[i] > 0) {
            positivos = positivos + 1;
        } else if (numeros[i] < 0) {
            negativos = negativos + 1;
        }
    }

    int promedio = suma / 10;

    int porcentajePositivos = (positivos * 100) / 10;
    int porcentajeNegativos = (negativos * 100) / 10;

    cout << "\nSuma total de los valores: " << suma << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Porcentaje de números positivos: " << porcentajePositivos << "%" << endl;
    cout << "Porcentaje de números negativos: " << porcentajeNegativos << "%" << endl;

    return 0;
}
