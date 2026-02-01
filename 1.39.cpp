#include <iostream>
using namespace std;

int obtenerMayor(int v[], int n) {
    int mayor = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > mayor) {
            mayor = v[i];
        }
    }
    return mayor;
}
int obtenerMenor(int v[], int n) {
    int menor = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < menor) {
            menor = v[i];
        }
    }
    return menor;
}

void contarValores(int v[], int n, int &positivos, int &negativos, int &ceros) {
    positivos = 0;
    negativos = 0;
    ceros = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] > 0) {
            positivos++;
        } else if (v[i] < 0) {
            negativos++;
        } else {
            ceros++;
        }
    }
}

int main() {
    int numeros[10];
    for (int i = 0; i < 10; i++) {
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> numeros[i];
    }
    int mayor = obtenerMayor(numeros, 10);
    int menor = obtenerMenor(numeros, 10);

    int positivos, negativos, ceros;
    contarValores(numeros, 10, positivos, negativos, ceros);

    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Mayor: " << mayor << endl;
    cout << "Menor: " << menor << endl;
    cout << "Positivos: " << positivos << endl;
    cout << "Negativos: " << negativos << endl;
    cout << "Ceros: " << ceros << endl;

    return 0;
}
