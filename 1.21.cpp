#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros(15);
    int multiplos3 = 0;
    int multiplos5 = 0;
    int multiplosAmbos = 0;
    for (int i = 0; i < 15; i++) {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> numeros[i];
        if (numeros[i] % 3 == 0) {
            multiplos3 = multiplos3 + 1;
        }
        if (numeros[i] % 5 == 0) {
            multiplos5 = multiplos5 + 1;
        }
        if (numeros[i] % 3 == 0 && numeros[i] % 5 == 0) {
            multiplosAmbos = multiplosAmbos + 1;
        }
    }
    cout << "\nCantidad de números múltiplos de 3: " << multiplos3 << endl;
    cout << "Cantidad de números múltiplos de 5: " << multiplos5 << endl;
    cout << "Cantidad de números múltiplos de 3 y 5: " << multiplosAmbos << endl;

    return 0;
}
