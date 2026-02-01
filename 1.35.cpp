#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct Estudiante {
    string nombre;
    float nota1;
    float nota2;
    float nota3;
};

int main() {
    vector<Estudiante> estudiantes;
    Estudiante e;
    int cantidad;
    string nombreBuscar;
    bool encontrado = false;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++) {
        cout << "\nEstudiante " << i + 1 << endl;
        cout << "Nombre: ";
        cin >> e.nombre;
        cout << "Nota 1: ";
        cin >> e.nota1;
        cout << "Nota 2: ";
        cin >> e.nota2;
        cout << "Nota 3: ";
        cin >> e.nota3;

        estudiantes.push_back(e);
    }
    ofstream archivo("estudiantes.txt");
    for (int i = 0; i < estudiantes.size(); i++) {
        archivo << estudiantes[i].nombre << " "
                << estudiantes[i].nota1 << " "
                << estudiantes[i].nota2 << " "
                << estudiantes[i].nota3 << endl;
    }
    archivo.close();

    cout << "\nDatos guardados en el archivo estudiantes.txt\n";
    vector<Estudiante> estudiantesLeidos;
    ifstream archivoLeer("estudiantes.txt");

    while (archivoLeer >> e.nombre >> e.nota1 >> e.nota2 >> e.nota3) {
        estudiantesLeidos.push_back(e);
    }
    archivoLeer.close();

    cout << "\nIngrese el nombre del estudiante a buscar: ";
    cin >> nombreBuscar;

    for (int i = 0; i < estudiantesLeidos.size(); i++) {
        if (estudiantesLeidos[i].nombre == nombreBuscar) {
            float promedio = (estudiantesLeidos[i].nota1 +
                              estudiantesLeidos[i].nota2 +
                              estudiantesLeidos[i].nota3) / 3;

            cout << "\nEstudiante encontrado" << endl;
            cout << "Nombre: " << estudiantesLeidos[i].nombre << endl;
            cout << "Nota 1: " << estudiantesLeidos[i].nota1 << endl;
            cout << "Nota 2: " << estudiantesLeidos[i].nota2 << endl;
            cout << "Nota 3: " << estudiantesLeidos[i].nota3 << endl;
            cout << "Promedio: " << promedio << endl;

            if (promedio >= 7) {
                cout << "Estado: APRUEBA" << endl;
            } else {
                cout << "Estado: REPRUEBA" << endl;
            }

            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Estudiante no encontrado." << endl;
    }

    return 0;
}
