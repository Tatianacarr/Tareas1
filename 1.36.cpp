#include <iostream>
#include <vector>
using namespace std;


void llenarVector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> v[i];
    }
}


void calcularSuma(vector<int> &v, int &suma) {
    suma = 0;
    for (int i = 0; i < v.size(); i++) {
        suma += v[i];
    }
}

void calcularMayorMenor(vector<int> &v, int &mayor, int &menor) {
    mayor = v[0];
    menor = v[0];

    for (int i = 1; i < v.size(); i++) {
        if (v[i] > mayor) {
            mayor = v[i];
        }
        if (v[i] < menor) {
            menor = v[i];
        }
    }
}

int main() {
    vector<int> numeros(10); 
    int suma;
    int mayor, menor;
    float promedio;
    llenarVector(numeros);
    calcularSuma(numeros, suma);
    promedio = suma / 10.0;

    calcularMayorMenor(numeros, mayor, menor);

    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Suma: " << suma << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Mayor: " << mayor << endl;
    cout << "Menor: " << menor << endl;

    return 0;
}
