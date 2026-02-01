#include <iostream>
using namespace std;

int main() {
    int opcion;
    int num1 = 0, num2 = 0; 
    bool numerosIngresados = false; 

    do {
        cout << "\n----- MENÚ -----" << endl;
        cout << "1. Ingresar dos números" << endl;
        cout << "2. Mostrar la suma y la resta" << endl;
        cout << "3. Mostrar el mayor de los dos números" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingrese el primer número: ";
                cin >> num1;
                cout << "Ingrese el segundo número: ";
                cin >> num2;
                numerosIngresados = true;
                break;

            case 2:
                if (numerosIngresados) {
                    cout << "Suma: " << num1 + num2 << endl;
                    cout << "Resta: " << num1 - num2 << endl;
                } else {
                    cout << "Primero debe ingresar los números (opción 1)." << endl;
                }
                break;

            case 3:
                if (numerosIngresados) {
                    if (num1 > num2) {
                        cout << "El mayor es: " << num1 << endl;
                    } else if (num2 > num1) {
                        cout << "El mayor es: " << num2 << endl;
                    } else {
                        cout << "Ambos números son iguales." << endl;
                    }
                } else {
                    cout << "Primero debe ingresar los números (opción 1)." << endl;
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
