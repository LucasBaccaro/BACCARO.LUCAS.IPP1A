#ifndef SERVICIO_H_INCLUDED

typedef struct //HARCODEADA
{
    int id; // comienza en 20000
    char descripcion[25];
    float precio;
} eServicio;

#define SERVICIO_H_INCLUDED

void mostrarServicio(int id, char descripcion[], float precio);
void mostrarServicios(eServicio servicios[], int tamServ);
int buscarServicio(eServicio servicios[], int tamServ, int idServ);

#endif // SERVICIO_H_INCLUDED
