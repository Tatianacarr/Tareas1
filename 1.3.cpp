#include <iostream>
using namespace std;

int main() {
    int suma = 0; 

    cout << "Números pares del 2 al 20: ";

    for (int i = 2; i <= 20; i += 2) {
        cout << i << " ";
        suma += i; 
    }
    cout << "\nLa suma de los números pares es: " << suma << endl;

    return 0;
}
