#include <iostream>
using namespace std;

int main() {
    float precios[10];
    float subtotal = 0;
    float iva = 0;
    float total = 0;
    for (int i = 0; i < 10; i++) {
        cout << "Ingrese el precio " << i + 1 << ": ";
        cin >> precios[i];
        subtotal = subtotal + precios[i]; 
    }
    iva = subtotal * 0.12; 
    total = subtotal + iva;
    cout << "\nSubtotal: $" << subtotal << endl;
    cout << "IVA (12%): $" << iva << endl;
    cout << "Total a pagar: $" << total << endl;

    return 0;
}
