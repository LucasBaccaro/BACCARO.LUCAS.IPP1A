#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "auto.h"

#include "datorharcord.h"

void inicializarAutos(eAuto autos[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        autos[i].isEmpty = 0;
    }
}

int harcodearAuto(eAuto autos[], int tam, int cant)
{
    int retorno = 0;

    for(int i = 0; i < cant; i++)
    {
        retorno++;
        autos[i].id = idAutoH[i];
        autos[i].patente = patentes[i];
        autos[i].idColor = idColor[i];
        autos[i].idMarca = idMarca[i];
        autos[i].modelo = anios[i];
        autos[i].idCliente = idCliente[i];
        autos[i].isEmpty = 1;
    }

    return retorno;
}

int buscarLibre(eAuto autos[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(autos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void mostrarAuto(int id, int patente, int idMarca, int idColor, int modelo, int idCliente, eMarca marcas[], int tamMarca, eColor colores[], int tamColor,eCliente clientes[],int tamClientes)

{
    char auxMarca[20];
    char auxColor[20];
    char auxNombre[20];

    for(int i = 0; i < tamMarca; i++)
    {
        if(marcas[i].id == idMarca)
        {
            strcpy(auxMarca, marcas[i].descripcion);
        }
    }

    for(int i = 0; i < tamColor; i++)
    {
        if(colores[i].id == idColor)
        {
            strcpy(auxColor, colores[i].nombreColor);
        }
    }

    for(int i = 0; i < tamClientes; i++)
    {
        if(clientes[i].id == idCliente)
        {
            strcpy(auxNombre, clientes[i].nombre);
        }
    }

    printf("%4d   %6d   %10s   %10s     %4d   %10s  \n", id, patente, auxMarca, auxColor, modelo,auxNombre);
}

void mostrarAutos(eAuto autos[], int tam, eMarca marcas[], int tamMarca, eColor colores[], int tamColores,eCliente clientes[],int tamClientes)
{
    system("cls");
    printf("               ############################\n");
    printf("               ######|LISTA DE AUTOS|######\n");
    printf("               ############################\n\n\n");
    printf("  ID      PATENTE     MARCA        COLOR    MODELO      NOMBRE\n");
    for(int i = 0; i < tam; i++)
    {

        if(autos[i].isEmpty == 1)
        {
            mostrarAuto(autos[i].id, autos[i].patente, autos[i].idMarca, autos[i].idColor, autos[i].modelo, autos[i].idCliente, marcas, tamMarca, colores,
                        tamColores, clientes,tamClientes);
        }
    }
}

eAuto cargarAuto(eMarca marcas[], int tamMarca, eColor colores[], int tamColor, int idAuto,eCliente clientes[],int tamClientes)
{
    eAuto auxAuto;
    printf("                           ######################\n");
    printf("                           ####|ALTA DE AUTO|####\n");
    printf("                           ######################\n\n");
    printf("\nINGRESE PATENTE (solo numeros): ");
    scanf("%d", &auxAuto.patente);
    while(auxAuto.patente<1000 || auxAuto.patente>10000)
    {
        printf("\nREINGRESE PATENTE (solo numeros): ");
        scanf("%d", &auxAuto.patente);
    }

    mostrarMarcasColores(marcas, tamMarca, colores, tamColor, 'm');

    printf("\nINGRESE ID DE LA MARCA: ");
    scanf("%d", &auxAuto.idMarca);

    while(validarMarca(marcas, tamMarca, auxAuto.idMarca) == 1)
    {
        printf("\nID INVALIDO: ");
        scanf("%d", &auxAuto.idMarca);
    }

    mostrarMarcasColores(marcas, tamMarca, colores, tamColor, 'c');

    printf("\nINGRESE ID DEL COLOR: ");
    scanf("%d", &auxAuto.idColor);

    while(validarColor(colores, tamColor, auxAuto.idColor) == 1)
    {
        printf("\nID INVALIDO ");
        scanf("%d", &auxAuto.idColor);
    }

    mostrarClientes(clientes,tamClientes);
    printf("INGRESE ID CLIENTE\n");
    scanf("%d",&auxAuto.idCliente);

    while(validarCliente(clientes,tamClientes,auxAuto.idCliente) == 1)
    {
        printf("\nID INVALIDO: ");
        scanf("%d", &auxAuto.idCliente);
    }

    printf("\nINGRESE MODELO: ");
    scanf("%d", &auxAuto.modelo);
    while(auxAuto.modelo<1900 || auxAuto.modelo>2020)
    {
        printf("\nREINGRESE MODELO: ");
        scanf("%d", &auxAuto.modelo);
    }

    printf("ALTA EXITOSA!!\n");
    auxAuto.id = idAuto;
    auxAuto.isEmpty = 1;
    system("pause");
    return auxAuto;
}

int addAuto(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, int idAuto,eCliente clientes[],int tamClientes)
{
    int error = 1;
    int indice;

    system("cls");

    indice = buscarLibre(autos, tamAuto);

    if(indice == -1)
    {
        printf("ERROR!! SISTEMA COMPLETO\n");
    }
    else
    {
        autos[indice] = cargarAuto(marcas, tamMarca, colores, tamColor, idAuto,clientes,tamClientes);
        error = 0;
    }

    return error;
}
int buscarPatente(eAuto autos[], int tamAuto, int patente)
{
    int indice = -1;

    for(int i = 0; i < tamAuto; i++)
    {
        if(patente == autos[i].patente && autos[i].isEmpty == 1)
        {
            indice = i;
        }
    }

    return indice;
}

int bajaAuto(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes)
{
    int error=1;
    int patente;
    int indice;
    char confirma = 'n';

    system("cls");
    printf("                           ######################\n");
    printf("                           ######|BAJA AUTO|#####\n");
    printf("                           ######################\n\n");


    mostrarAutos(autos, tamAuto, marcas, tamMarca, colores, tamColor, clientes, tamClientes);

    printf("\nINGRESE LA PATENTE DEL AUTO A MODIFICAR: ");
    scanf("%d", &patente);

    indice = buscarPatente(autos, tamAuto, patente);

    if(indice == -1)
    {
        printf("\nERROR!! NO SE ENCONTRO PATENTE.\n");
    }
    else
    {
        mostrarAuto(autos[indice].id,autos[indice].patente, autos[indice].idMarca, autos[indice].idColor, autos[indice].modelo, autos[indice].idCliente, marcas, tamMarca, colores, tamColor, clientes, tamClientes);

        printf("\nPRESIONE 's' PARA CONFIRMAR ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            autos[indice].isEmpty = 0;
            error=0;
        }
        else
        {
            printf("BAJA CANCELADA.\n");
        }
    }
    return error;
}
int modificarAuto(eAuto autos[], int tam, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes)
{
    int error = -1;
    int patente;
    char opcion;
    int indice;
    char seguir = 'n';

    system("cls");
    printf("                 #################################\n");
    printf("                 ##########|MODIFICAR AUTO|#######\n");
    printf("                 #################################\n\n");
    mostrarAutos(autos, tam, marcas, tamMarca, colores, tamColor,clientes,tamClientes);

    printf("\n\nINGRESE PATENTE: ");
    scanf("%d", &patente);

    indice = buscarPatente(autos, tam, patente);

    if(indice == -1)
    {
        printf("\nERROR.\n");
    }
    else
    {
        mostrarAuto(autos[indice].id, autos[indice].patente, autos[indice].idMarca, autos[indice].idColor, autos[indice].modelo, autos[indice].idCliente, marcas, tamMarca, colores, tamColor, clientes, tamClientes);
        printf("\n");

        do
        {
            switch( menuModificar(autos, indice, marcas, tamMarca, colores, tamColor,clientes,tamClientes) )
            {
            case 1:
                mostrarMarcasColores(marcas, tamMarca, colores, tamColor, 'c');

                printf("\nINGRESE EL ID DEL NUEVO COLOR: \n");
                scanf("%d", &autos[indice].idColor);

                while(validarColor(colores, tamColor, autos[indice].idColor) == 1)
                {
                    printf("\nID INVALIDO: \n");
                    scanf("%d", &autos[indice].idColor);
                }
                printf("OPERACION EXITOSA!!\n");
                system("pause");

                break;

            case 2:
                printf("\nINGRESE NUEVO MODELO: \n");
                scanf("%d", &autos[indice].modelo);
                while(autos[indice].modelo<1900 || autos[indice].modelo>2020)
                {
                    printf("\nREINGRESE NUEVO MODELO: \n");
                    scanf("%d", &autos[indice].modelo);
                }
                printf(" OPERACION EXITOSA!!\n");
                system("pause");

                break;

            case 3:
                printf("\nPRESIONE 's' PARA SALIR: \n");
                fflush(stdin);
                scanf("%c",&opcion);
                if(opcion=='s')
                {
                    seguir='s';
                }
                break;

            default:
                printf("\nOPCION INVALIDA.\n\n");
                system("pause");
                break;
            }
        }
        while(seguir != 's');
    }
    return error;
}

int menuModificar(eAuto autos[], int indice, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes)
{
    int opcion;

    system("cls");
    printf("\n");
    mostrarAuto(autos[indice].id, autos[indice].patente, autos[indice].idMarca, autos[indice].idColor, autos[indice].modelo, autos[indice].idCliente, marcas, tamMarca, colores, tamColor, clientes, tamClientes);

    printf("                   ################################\n");
    printf("                   ######|MENU MODIFICACIONES|#####\n");
    printf("                   ################################\n\n\n");
    printf("                      1 - Modificar color.\n");
    printf("                      2 - Modificar modelo.\n");
    printf("                      3 - Salir.\n\n");
    printf("                        --Ingrese opcion:-- ");
    fflush(stdin);
    scanf("%d", &opcion);
    system("cls");

    return opcion;
}

void mostrarAutoPorColor(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClientes)
{
    int opcion;

    mostrarMarcasColores(marcas, tamM, colores, tamC, 'f');

    printf("Ingrese id color: ");
    scanf("%d", &opcion);

    for(int i = 0; i < tamA; i++)
    {
        if(autos[i].isEmpty == 1 && autos[i].idColor == opcion)
        {
            mostrarAuto(autos[i].id, autos[i].patente, autos[i].idMarca, autos[i].idColor, autos[i].modelo,autos[i].idCliente, marcas, tamM, colores, tamC, clientes, tamClientes);
        }
    }
}

void mostrarAutoPorMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClientes)
{
    int opcion;

    mostrarMarcasColores(marcas,tamM,colores,tamC,'m');

    printf("Ingrese id marca: ");
    scanf("%d", &opcion);


    for(int i = 0; i < tamA; i++)
    {
        if(autos[i].isEmpty == 1 && autos[i].idMarca == opcion)
        {
            mostrarAuto(autos[i].id, autos[i].patente, autos[i].idMarca, autos[i].idColor, autos[i].modelo,autos[i].idCliente, marcas, tamM, colores, tamC, clientes, tamClientes);
        }
    }
}

int marcaMasElegida(eAuto autos[],int tam,eMarca marcas[],int tamM)
{
    int error=1;
    int contadores[tamM];
    int mayor;
    int idBuscado;
    int flag=0;

    if(autos!= NULL && marcas!=NULL && tam > 0 && tamM > 0 ) // validar vector con != de null
    {

        for(int d=0; d<tamM; d++)
        {
            contadores[d]=0;
            idBuscado=marcas[d].id;
            for(int p=0; p<tam; p++)
            {
                if(autos[p].isEmpty==1 && autos[p].idMarca==idBuscado)
                {
                    contadores[d]++;
                }
            }
        }
    }
    //busco el contador mayor sad
    for(int i=0; i<tamM; i++)
    {
        if(contadores[i]>mayor || flag==0)
        {
            mayor=contadores[i];
            flag=1;
        }
    }
    printf("Marcas favoritas son: \n");

    for(int i=0; i<tam; i++)
    {
        if(contadores[i]==mayor)
        {
            printf("%s\n",marcas[i].descripcion);
        }
    }
    printf("\n\n\n");
    error=0;

    return error;
}

int contadorColoryMarca(eAuto autos[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM)
{
    int contadorColor=0;
    int contadorMarca=0;

    char colorAux[15];
    char marcaAux[15];

    eAuto nuevoAuto;

    int hayAutos=0;

    for(int i=0; i<tam; i++)
    {
        if(autos[i].isEmpty == 1)
        {
            hayAutos=1;
        }
    }

    if(hayAutos)
    {
        mostrarMarcasColores(marcas,tamM,colores,tamC,'m');

        printf("ID MARCA: \n");
        scanf("%d",&nuevoAuto.idMarca);
        while(validarMarca(marcas,tamM,nuevoAuto.idMarca)== 1)
        {
            printf("\nID INVALIDO ");
            scanf("%d", &nuevoAuto.idMarca);
        }

        mostrarMarcasColores(marcas,tamM,colores,tamC,'f');

        printf("ID COLOR: \n");
        scanf("%d",&nuevoAuto.idColor);
        while(validarColor(colores,tamC,nuevoAuto.idColor)== 1)
        {
            printf("\nID INVALIDO ");
            scanf("%d", &nuevoAuto.idColor);
        }

        for(int i=0; i<tam; i++)
        {
            if(autos[i].idMarca ==nuevoAuto.idMarca)
            {
                contadorMarca++;
            }
        }
        for(int i=0; i<tam; i++)
        {
            if(autos[i].idColor ==nuevoAuto.idColor)
            {
                contadorColor++;
            }
        }
        for(int i=0; i<tamC; i++)
        {
            if(nuevoAuto.idColor==colores[i].id)
            {
                strcpy(colorAux, colores[i].nombreColor);
                break;
            }
        }

        for(int j=0; j<tamM; j++)
        {
            if(nuevoAuto.idMarca==marcas[j].id)
            {
                strcpy(marcaAux, marcas[j].descripcion);
                break;
            }
        }
        printf("En total %d %5s.\n", contadorMarca, marcaAux);
        printf("En total %d %5s.\n", contadorColor, colorAux);
    }
    else
    {
        printf("\nNo hay autos.\n");
    }
    return 1;
}

