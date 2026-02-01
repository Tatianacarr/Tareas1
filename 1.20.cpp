#include <iostream>
using namespace std;

int main() {
    int numeros[10];
    int dentroRango = 0;
    int fueraRango = 0;
    for (int i = 0; i < 10; i++) {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> numeros[i];
        if (numeros[i] >= 20 && numeros[i] <= 80) {
            dentroRango = dentroRango + 1;
        } else {
            fueraRango = fueraRango + 1;
        }
    }
    int porcentajeDentro = (dentroRango * 100) / 10;
    int porcentajeFuera = (fueraRango * 100) / 10;
    cout << "\nCantidad de números dentro del rango (20 a 80): " << dentroRango << endl;
    cout << "Cantidad de números fuera del rango: " << fueraRango << endl;
    cout << "Porcentaje dentro del rango: " << porcentajeDentro << "%" << endl;
    cout << "Porcentaje fuera del rango: " << porcentajeFuera << "%" << endl;

    return 0;
}
