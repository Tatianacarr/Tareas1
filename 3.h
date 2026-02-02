#ifndef PUBLICACIONES_H
#define PUBLICACIONES_H

#include <string>
using namespace std;

struct Publicacion {
    int codigo;
    string titulo;
    int anio;
    string tipo;
    string estado;
};

// Declaraciones de funciones
Publicacion registrarPublicacion();
void prestarPublicacion(Publicacion &p);
void devolverPublicacion(Publicacion &p);
string mostrarPublicacion(Publicacion p);
void guardarEnArchivos(Publicacion p);
void leerArchivo(string nombreArchivo);   // ?? ESTA LÍNEA ES CLAVE

#endif

