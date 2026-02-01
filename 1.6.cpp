#include <iostream>
using namespace std;

int main() {
    int multiplos3 = 0; 
    int noMultiplos3 = 0; 

    for (int i = 1; i <= 50; i++) {
        if (i % 3 == 0) {
            multiplos3++;
        } else {
            noMultiplos3++; 
        }
    }
    cout << "Cantidad de múltiplos de 3: " << multiplos3 << endl;
    cout << "Cantidad de números que no son múltiplos de 3: " << noMultiplos3 << endl;

    return 0;
}
