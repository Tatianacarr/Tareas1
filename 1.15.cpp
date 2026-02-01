#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros(10);
    int suma = 0;
    int contadorEncima = 0;
    for (int i = 0; i < 10; i++) {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> numeros[i];
        suma = suma + numeros[i]; 
    }
    int promedio = suma / 10;
    for (int i = 0; i < 10; i++) {
        if (numeros[i] > promedio) {
            contadorEncima = contadorEncima + 1;
        }
    }
    cout << "\nSuma total de los números: " << suma << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Cantidad de números por encima del promedio: " << contadorEncima << endl;

    return 0;
}
