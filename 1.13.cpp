#include <iostream>
using namespace std;

int main() {
    int calificaciones[10];
    int suma = 0;
    int aprobados = 0;
    int reprobados = 0;
    for (int i = 0; i < 10; i++) {
        cout << "Ingrese la calificación del estudiante " << i + 1 << " (0-10): ";
        cin >> calificaciones[i];
        suma = suma + calificaciones[i];

        if (calificaciones[i] >= 7) {
            aprobados = aprobados + 1;
        } else {
            reprobados = reprobados + 1;
        }
    }
    int promedio = suma / 10;

    cout << "\nPromedio general: " << promedio << endl;
    cout << "Cantidad de estudiantes aprobados: " << aprobados << endl;
    cout << "Cantidad de estudiantes reprobados: " << reprobados << endl;

    return 0;
}
