#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> edades(10);
    int suma = 0;
    int mayores = 0;
    int menoresIguales = 0;
    for (int i = 0; i < 10; i++) {
        cout << "Ingrese la edad " << i + 1 << ": ";
        cin >> edades[i];
        suma = suma + edades[i]; 
    }
    int promedio = suma / 10;
    for (int i = 0; i < 10; i++) {
        if (edades[i] > promedio) {
            mayores = mayores + 1;
        } else {
            menoresIguales = menoresIguales + 1;
        }
    }
    cout << "\nPromedio de edades: " << promedio << endl;
    cout << "Cantidad de edades mayores al promedio: " << mayores << endl;
    cout << "Cantidad de edades menores o iguales al promedio: " << menoresIguales << endl;

    return 0;
}
