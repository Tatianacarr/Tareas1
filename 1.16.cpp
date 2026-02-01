#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros(8);
    int maximo, minimo;
    for (int i = 0; i < 8; i++) {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> numeros[i];
        if (i == 0) {
            maximo = numeros[i];
            minimo = numeros[i];
        } else {
            if (numeros[i] > maximo) {
                maximo = numeros[i];
            }
            if (numeros[i] < minimo) {
                minimo = numeros[i];
            }
        }
    }
    int rango = maximo - minimo;
    cout << "\nValor máximo: " << maximo << endl;
    cout << "Valor mínimo: " << minimo << endl;
    cout << "Rango (máximo - mínimo): " << rango << endl;

    return 0;
}
