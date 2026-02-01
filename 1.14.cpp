#include <iostream>
using namespace std;

int main() {
    int numeros[15];
    int sumaPositivos = 0;
    int sumaNegativos = 0;
    int contadorPositivos = 0;
    int contadorNegativos = 0;
    
    for (int i = 0; i < 15; i++) {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> numeros[i];
        if (numeros[i] > 0) {
            sumaPositivos = sumaPositivos + numeros[i];
            contadorPositivos = contadorPositivos + 1;
        }
        else if (numeros[i] < 0) {
            sumaNegativos = sumaNegativos + numeros[i];
            contadorNegativos = contadorNegativos + 1;
        }
    }
    if (contadorPositivos > 0) {
        cout << "Promedio de números positivos: " << sumaPositivos / contadorPositivos << endl;
    } else {
        cout << "No se ingresaron números positivos." << endl;
    }

    if (contadorNegativos > 0) {
        cout << "Promedio de números negativos: " << sumaNegativos / contadorNegativos << endl;
    } else {
        cout << "No se ingresaron números negativos." << endl;
    }

    return 0;
}
