#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros(10);
    int sumaCuadrados = 0;
    for (int i = 0; i < 10; i++) {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> numeros[i];
    }

    cout << "\nCuadrados de los números:" << endl;
    for (int i = 0; i < 10; i++) {
        int cuadrado = numeros[i] * numeros[i];
        cout << "Número " << numeros[i] << " al cuadrado: " << cuadrado << endl;
        sumaCuadrados = sumaCuadrados + cuadrado;
    }
    int promedioCuadrados = sumaCuadrados / 10;
    cout << "\nSuma de los cuadrados: " << sumaCuadrados << endl;
    cout << "Promedio de los cuadrados: " << promedioCuadrados << endl;

    return 0;
}
