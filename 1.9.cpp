#include <iostream>
using namespace std;

int main() {
    int sumaPares = 0;
    int sumaImpares = 0;
    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0) {
            sumaPares += i;  
        } else {
            sumaImpares += i; 
        }
    }
    cout << "Suma de los números pares: " << sumaPares << endl;
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
