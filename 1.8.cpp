#include <iostream>
using namespace std;

int main() {
    int numero;
    int dentroRango = 0;  
    int fueraRango = 0;  

    for (int i = 1; i <= 15; i++) {
        cout << "Ingrese el número " << i << ": ";
        cin >> numero;

        if (numero >= 20 && numero <= 80) {
            dentroRango++;
        } else {
            fueraRango++;
        }
    }
    cout << "Cantidad de números dentro del rango (20 a 80): " << dentroRango << endl;
    cout << "Cantidad de números fuera del rango: " << fueraRango << endl;

    return 0;
}
