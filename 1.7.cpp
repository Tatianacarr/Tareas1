#include <iostream>
using namespace std;

int main() {
    int numero;
    int positivos = 0;
    int negativos = 0;
    int ceros = 0;
    for (int i = 1; i <= 10; i++) {
        cout << "Ingrese el número " << i << ": ";
        cin >> numero;
        if (numero > 0) {
            positivos++;
        } else if (numero < 0) {
            negativos++;
        } else {
            ceros++;
        }
    }

    cout << "Cantidad de números positivos: " << positivos << endl;
    cout << "Cantidad de números negativos: " << negativos << endl;
    cout << "Cantidad de números iguales a cero: " << ceros << endl;

    return 0;
}
