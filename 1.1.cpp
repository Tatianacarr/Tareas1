#include <iostream>
using namespace std;

int main() {
    int numero;

    cout << "Ingrese un numero entero: ";
    cin >> numero;

    if (numero >= 10 && numero <= 50) {
        cout << "El numero pertenece al rango de 10 a 50." << endl;
    } else {
        cout << "El numero NO pertenece al rango de 10 a 50." << endl;
    }

    return 0;
}
