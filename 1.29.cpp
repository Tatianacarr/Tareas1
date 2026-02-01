#include <iostream>
using namespace std;

int main() {
    int matriz[2][4];
    int mayor;
    int filaMayor = 0, colMayor = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "Ingrese el valor para la posición [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
            if (i == 0 && j == 0) {
                mayor = matriz[i][j];
                filaMayor = i;
                colMayor = j;
            } else {
                if (matriz[i][j] > mayor) {
                    mayor = matriz[i][j];
                    filaMayor = i;
                    colMayor = j;
                }
            }
        }
    }
    cout << "\nNúmero mayor: " << mayor << endl;
    cout << "Posición: fila " << filaMayor + 1 << ", columna " << colMayor + 1 << endl;

    return 0;
}
