#include <iostream>
using namespace std;

int main() {
    int numeros[8];
    int mayor, menor;
    for (int i = 0; i < 8; i++) {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> numeros[i];
        if (i == 0) {
            mayor = numeros[i];
            menor = numeros[i];
        } else {
            if (numeros[i] > mayor) {
                mayor = numeros[i];
            }
            if (numeros[i] < menor) {
                menor = numeros[i];
            }
        }
    }
    int diferencia = mayor - menor;
    cout << "\nNúmero mayor: " << mayor << endl;
    cout << "Número menor: " << menor << endl;
    cout << "Diferencia entre mayor y menor: " << diferencia << endl;

    return 0;
}
