#include <iostream>
using namespace std;

int main() {
    int opcion;
    int numero = 0;
    bool numeroIngresado = false;

    do {
        cout << "\n----- MENÚ -----" << endl;
        cout << "1. Ingresar un número" << endl;
        cout << "2. Verificar si el número está en el rango de 1 a 100" << endl;
        cout << "3. Verificar si el número es par o impar" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingrese un número: ";
                cin >> numero;
                numeroIngresado = true;
                break;

            case 2:
                if (numeroIngresado) {
                    if (numero >= 1 && numero <= 100) {
                        cout << "El número " << numero << " está dentro del rango de 1 a 100." << endl;
                    } else {
                        cout << "El número " << numero << " está fuera del rango de 1 a 100." << endl;
                    }
                } else {
                    cout << "Primero debe ingresar un número (opción 1)." << endl;
                }
                break;

            case 3:
                if (numeroIngresado) {
                    if (numero % 2 == 0) {
                        cout << "El número " << numero << " es par." << endl;
                    } else {
                        cout << "El número " << numero << " es impar." << endl;
                    }
                } else {
                    cout << "Primero debe ingresar un número (opción 1)." << endl;
                }
                break;

            case 4:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }

    } while(opcion != 4);

    return 0;
}
