#ifndef TRABAJO_H_INCLUDED

typedef struct
{
    int id; // autoincremental
    int patente; // validar
    int idServicio; // validar
    eFecha fecha; // validar dia mes y año
    int isEmpty;
} eTrabajo;

#define TRABAJO_H_INCLUDED
#include "servicio.h"
#include "marca.h"
#include "color.h"
#include "auto.h"
#include "cliente.h"


void inicializarTrabajos(eTrabajo trabajos[], int tam);
void mostrarTrabajo(int id, int patente, int idServicio, eFecha fecha);
void mostrarTrabajos(eTrabajo trabajos[], int tam);
int buscarTrabajoLibre(eTrabajo trabajos[], int tam);
eTrabajo cargarTrabajo(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServ, eAuto autos[], int tamAuto, int idTrabajo, eMarca marcas[], int tamMarca, eColor colores[], int tamColor,eCliente clientes[],int tamClientes);
int addTrabajo(eTrabajo trabajos[], int tamTrabajo, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, int idTrabajo, eMarca marcas[], int tamMarca, eColor colores[], int tamColor,eCliente clientes[],int tamClientes);

#endif // TRABAJO_H_INCLUDED
