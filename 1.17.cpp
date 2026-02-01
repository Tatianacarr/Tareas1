#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros(12);
    int sumaPositivos = 0;
    int sumaNegativos = 0;
    int sumaAbsoluta = 0;
    for (int i = 0; i < 12; i++) {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> numeros[i];
        if (numeros[i] > 0) {
            sumaPositivos = sumaPositivos + numeros[i];
        }
        else if (numeros[i] < 0) {
            sumaNegativos = sumaNegativos + numeros[i];
        }
        if (numeros[i] < 0) {
            sumaAbsoluta = sumaAbsoluta - numeros[i]; 
        } else {
            sumaAbsoluta = sumaAbsoluta + numeros[i];
        }
    }
    cout << "\nSuma de los valores positivos: " << sumaPositivos << endl;
    cout << "Suma de los valores negativos: " << sumaNegativos << endl;
    cout << "Valor absoluto total acumulado: " << sumaAbsoluta << endl;

    return 0;
}
