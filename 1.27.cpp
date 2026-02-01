#include <iostream>
using namespace std;

int main() {
    int numeros[10];
    int opcion;
    bool numerosIngresados = false;

    cout << "----- MENÚ -----" << endl;
    cout << "1. Ingresar 10 números" << endl;
    cout << "2. Mostrar el promedio" << endl;
    cout << "3. Mostrar el mayor y el menor" << endl;
    cout << "4. Contar números positivos y negativos" << endl;
    cout << "5. Salir" << endl;

    cout << "Ingrese una opción: ";
    cin >> opcion;

    while(opcion != 5) {
        switch(opcion) {
            case 1:
                for (int i = 0; i < 10; i++) {
                    cout << "Ingrese el número " << i + 1 << ": ";
                    cin >> numeros[i];
                }
                numerosIngresados = true;
                break;

            case 2:
                if (numerosIngresados) {
                    int suma = 0;
                    for (int i = 0; i < 10; i++) {
                        suma += numeros[i];
                    }
                    cout << "Promedio: " << suma / 10.0 << endl;
                } else {
                    cout << "Primero debe ingresar los números (opción 1)." << endl;
                }
                break;

            case 3:
                if (numerosIngresados) {
                    int mayor = numeros[0];
                    int menor = numeros[0];
                    for (int i = 1; i < 10; i++) {
                        if (numeros[i] > mayor) mayor = numeros[i];
                        if (numeros[i] < menor) menor = numeros[i];
                    }
                    cout << "Número mayor: " << mayor << endl;
                    cout << "Número menor: " << menor << endl;
                } else {
                    cout << "Primero debe ingresar los números (opción 1)." << endl;
                }
                break;

            case 4:
                if (numerosIngresados) {
                    int positivos = 0, negativos = 0;
                    for (int i = 0; i < 10; i++) {
                        if (numeros[i] > 0) positivos++;
                        else if (numeros[i] < 0) negativos++;
                    }
                    cout << "Números positivos: " << positivos << endl;
                    cout << "Números negativos: " << negativos << endl;
                } else {
                    cout << "Primero debe ingresar los números (opción 1)." << endl;
                }
                break;

            default:
                cout << "Opción inválida." << endl;
        }

        cout << "\n----- MENÚ -----" << endl;
        cout << "1. Ingresar 10 números" << endl;
        cout << "2. Mostrar el promedio" << endl;
        cout << "3. Mostrar el mayor y el menor" << endl;
        cout << "4. Contar números positivos y negativos" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
    }

    cout << "Saliendo del programa..." << endl;

    return 0;
}
