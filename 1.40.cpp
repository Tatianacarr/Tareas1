#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void ingresarCalificaciones(vector<float> &notas, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Ingrese la calificacion " << i + 1 << ": ";
        cin >> notas[i];
    }
}
void guardarArchivo(vector<float> notas) {
    ofstream archivo("calificaciones.txt");
    for (int i = 0; i < notas.size(); i++) {
        archivo << notas[i] << endl;
    }
    archivo.close();
}

void leerArchivo(vector<float> &notas) {
    ifstream archivo("calificaciones.txt");
    float valor;
    int i = 0;

    while (archivo >> valor) {
        notas[i] = valor;
        i++;
    }
    archivo.close();
}

float calcularTotal(vector<float> notas) {
    float total = 0;
    for (int i = 0; i < notas.size(); i++) {
        total += notas[i];
    }
    return total;
}

void contarRespectoPromedio(vector<float> notas, float promedio,
                            int &mayores, int &menores) {
    mayores = 0;
    menores = 0;

    for (int i = 0; i < notas.size(); i++) {
        if (notas[i] > promedio) {
            mayores++;
        } else if (notas[i] < promedio) {
            menores++;
        }
    }
}

int main() {
    int n;
    cout << "Ingrese la cantidad de calificaciones: ";
    cin >> n;

    vector<float> calificaciones(n);
    ingresarCalificaciones(calificaciones, n);
    guardarArchivo(calificaciones);
    leerArchivo(calificaciones);
    float total = calcularTotal(calificaciones);
    float promedio = total / n;

    int mayores, menores;
    contarRespectoPromedio(calificaciones, promedio, mayores, menores);
    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Total de calificaciones: " << total << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Calificaciones por encima del promedio: " << mayores << endl;
    cout << "Calificaciones por debajo del promedio: " << menores << endl;

    return 0;
}
