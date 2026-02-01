#include <iostream>
using namespace std;

int main() {
    int numeros[12];
    int sumaPares = 0;
    int sumaImpares = 0;
    for (int i = 0; i < 12; i++) {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> numeros[i];

        if (numeros[i] % 2 == 0) {
            sumaPares = sumaPares + numeros[i];
        } else {
            sumaImpares = sumaImpares + numeros[i];
        }
    }

    cout << "\nSuma de los números pares: " << sumaPares << endl;
    cout << "Suma de los números impares: " << sumaImpares << endl;
    if (sumaPares > sumaImpares) {
        cout << "La suma de los números pares es mayor." << endl;
    } else if (sumaImpares > sumaPares) {
        cout << "La suma de los números impares es mayor." << endl;
    } else {
        cout << "Ambas sumas son iguales." << endl;
    }

    return 0;
}
