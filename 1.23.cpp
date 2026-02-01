#include <iostream>
using namespace std;

int main() {
    float sueldos[10];
    float suma = 0;
    int encimaPromedio = 0;
    int debajoPromedio = 0;
    for (int i = 0; i < 10; i++) {
        cout << "Ingrese el sueldo " << i + 1 << ": ";
        cin >> sueldos[i];
        suma = suma + sueldos[i]; 
    }
    
    float promedio = suma / 10;


    for (int i = 0; i < 10; i++) {
        if (sueldos[i] > promedio) {
            encimaPromedio = encimaPromedio + 1;
        } else if (sueldos[i] < promedio) {
            debajoPromedio = debajoPromedio + 1;
        }
    }
    cout << "\nSueldo promedio: $" << promedio << endl;
    cout << "Cantidad de sueldos por encima del promedio: " << encimaPromedio << endl;
    cout << "Cantidad de sueldos por debajo del promedio: " << debajoPromedio << endl;

    return 0;
}
