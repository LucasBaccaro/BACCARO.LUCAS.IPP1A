#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "servicio.h"

void mostrarServicio(int id, char descripcion[], float precio)
{
    printf("%d   %s   %.2f\n", id, descripcion, precio);
}

void mostrarServicios(eServicio servicios[], int tamServ)
{
    {
        printf("ID    Descripcion   Precio\n");
        for(int i = 0; i < tamServ; i++)
        {
            mostrarServicio(servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }
    }
}

int buscarServicio(eServicio servicios[], int tamServ, int idServ)
{
    int indice = -1;

    for(int i = 0; i < tamServ; i++)
    {
        if(idServ == servicios[i].id)
        {
            indice = i;
        }
    }

    return indice;
}

