#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"

void mostrarCliente(int id, char descripcion[])
{
    printf("%d      %s\n", id, descripcion);
}

void mostrarClientes(eCliente clientes[], int tamClientes)
{
    {
        printf("ID    CLIENTE\n");
        for(int i = 0; i < tamClientes; i++)
        {
            mostrarCliente(clientes[i].id, clientes[i].nombre);
        }
    }
}

int validarCliente(eCliente clientes[], int tam, int id)
{
    int error = 1;

    for(int i = 0; i < tam; i++)
    {
        if(id == clientes[i].id)
        {
            error = 0;
        }
    }

    return error;
}
