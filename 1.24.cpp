#include <iostream>
using namespace std;

int main() {
    float notas[10];
    float suma = 0;
    float notaMaxima, notaMinima;
    int aprobados = 0;
    int reprobados = 0;
    for (int i = 0; i < 10; i++) {
        cout << "Ingrese la nota final del estudiante " << i + 1 << " (0-10): ";
        cin >> notas[i];
        suma = suma + notas[i];
        if (i == 0) {
            notaMaxima = notas[i];
            notaMinima = notas[i];
        } else {
            if (notas[i] > notaMaxima) {
                notaMaxima = notas[i];
            }
            if (notas[i] < notaMinima) {
                notaMinima = notas[i];
            }
        }
        if (notas[i] >= 7) {
            aprobados = aprobados + 1;
        } else {
            reprobados = reprobados + 1;
        }
    }
    float promedio = suma / 10;
    float porcentajeAprobados = (aprobados * 100) / 10.0;
    float porcentajeReprobados = (reprobados * 100) / 10.0;
    cout << "\n----- RESUMEN FINAL -----" << endl;
    cout << "Promedio general: " << promedio << endl;
    cout << "Nota más alta: " << notaMaxima << endl;
    cout << "Nota más baja: " << notaMinima << endl;
    cout << "Porcentaje de aprobados: " << porcentajeAprobados << "%" << endl;
    cout << "Porcentaje de reprobados: " << porcentajeReprobados << "%" << endl;

    return 0;
}
