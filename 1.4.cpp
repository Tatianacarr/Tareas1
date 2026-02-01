#include <iostream>
using namespace std;

int main() {
    int numero;
    int suma = 0; 
   
    cout << "Ingrese un número entero positivo: ";
    cin >> numero;

    if (numero <= 0) {
        cout << "¡Error! Debe ingresar un número positivo." << endl;
        return 1; 
    }

    cout << "Tabla de multiplicar del " << numero << ":" << endl;

    for (int i = 1; i <= 10; i++) {
        int resultado = numero * i;
        cout << numero << " x " << i << " = " << resultado << endl;
        suma += resultado; 
    }

    cout << "La suma de los resultados es: " << suma << endl;

    return 0;
}
