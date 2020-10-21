#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "marca.h"
void mostrarMarcaColor(int id, char desc[])
{
    printf("%d   %s\n", id, desc);

}

void mostrarMarcasColores(eMarca marcas[], int tamMarca, eColor colores[], int tamColor, char parametro)
{
    if(parametro == 'm')
    {   printf("################\n");
        printf("# ID  |  MARCA #\n");
        printf("################\n\n");
        for(int i = 0; i < tamMarca; i++)
        {
            mostrarMarcaColor(marcas[i].id, marcas[i].descripcion);
        }
    }
    else
    {   printf("#################\n");
        printf("# ID   |  COLOR #\n");
        printf("#################\n\n");
        for(int i = 0; i < tamMarca; i++)
        {
            mostrarMarcaColor(colores[i].id, colores[i].nombreColor);
        }
    }
}

int validarMarca(eMarca marcas[], int tam, int id)
{
    int error = 1;

    for(int i = 0; i < tam; i++)
    {
        if(id == marcas[i].id)
        {
            error = 0;
        }
    }

    return error;
}
