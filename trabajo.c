#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "fecha.h"

#include "trabajo.h"


void inicializarTrabajos(eTrabajo trabajos[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        trabajos[i].isEmpty = 0;
    }
}

void mostrarTrabajo(int id, int patente, int idServicio, eFecha fecha)
{

    printf("%d         %d         %d           %d/%d/%d\n", id, patente, idServicio, fecha.mes,fecha.mes,fecha.anio);
}

void mostrarTrabajos(eTrabajo trabajos[], int tam)
{
    {
        printf("ID      Patente       ID servicio         Fecha\n");
        for(int i = 0; i < tam; i++)
        {
            if(trabajos[i].isEmpty == 1)
            {
                mostrarTrabajo(trabajos[i].id, trabajos[i].patente, trabajos[i].idServicio, trabajos[i].fecha);
            }
        }
    }
}

int addTrabajo(eTrabajo trabajos[], int tamTrabajo, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, int idTrabajo, eMarca marcas[], int tamMarca, eColor colores[], int tamColor,eCliente clientes[],int tamClientes)
{
    int error = 1;
    int indice;

    system("cls");

    indice = buscarTrabajoLibre(trabajos, tamTrabajo);

    if(indice == -1)
    {
        printf("Error. Sistema completo.\n");
    }
    else
    {
        trabajos[indice] = cargarTrabajo(trabajos, tamTrabajo, servicios, tamServ, autos, tamAuto, idTrabajo, marcas, tamMarca, colores, tamColor,clientes,tamClientes);
        error = 0;
    }

    return error;
}

eTrabajo cargarTrabajo(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServ, eAuto autos[], int tamAuto, int idTrabajo, eMarca marcas[], int tamMarca, eColor colores[], int tamColor,eCliente clientes[],int tamClientes)
{
    eTrabajo auxTrabajo;

    printf("*** ALTA DE TRABAJO ***\n\n");

    auxTrabajo.id = idTrabajo;

    mostrarAutos(autos, tamAuto, marcas, tamMarca, colores, tamColor,clientes,tamClientes);

    printf("Ingrese la patente del auto elegido: ");
    scanf("%d", &auxTrabajo.patente);

    while(buscarPatente(autos, tamAuto, auxTrabajo.patente) == -1)
    {
        printf("Patente invalida, reingrese: ");
        scanf("%d", &auxTrabajo.patente);
    }

    mostrarServicios(servicios, tamServ);

    printf("Ingrese el id del servicio elegido: ");
    scanf("%d", &auxTrabajo.idServicio);

    while(buscarServicio(servicios, tamServ, auxTrabajo.idServicio) == -1)
    {
        printf("Id invalido, reingrese: ");
        scanf("%d", &auxTrabajo.idServicio);
    }

    printf("Ingrese fecha del trabajo: ");
    scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);

    while(validarFecha(auxTrabajo.fecha) == 1)
    {
        printf("Error. Reingrese fecha del trabajo: ");
        scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
    }

    auxTrabajo.isEmpty = 1;

    return auxTrabajo;
}

int buscarTrabajoLibre(eTrabajo trabajos[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(trabajos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

