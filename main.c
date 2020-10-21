#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define TAMAUTO 11
#define TAMMARCAS 5
#define TAMCOLOR 5
#define TAMSERV 4
#define TAMTRAB 4
#define TAMCLIENTES 9

#include "fecha.h"
#include "marca.h"
#include "color.h"
#include "auto.h"
#include "trabajo.h"
#include "servicio.h"
#include "cliente.h"


char menu();
char informes();

int main()

{
    char seguir ='n';
    int idAuto=10000;
    int idTrab=1;
    eMarca marcas[TAMMARCAS]= {{1000, "Renault"},{1001, "Fiat"},{1002, "Ford"},{1003, "Chevrolet"},{1004, "Peugeot"}};
    eColor colores[TAMCOLOR]= {{5000, "Negro"},{5001, "Blanco"},{5002, "Gris"},{5003, "Rojo"},{5004, "Azul"}};
    eAuto autos[TAMAUTO];
    eServicio servicios[TAMSERV] = {{20000, "Lavado", 250},{20001, "Pulido", 300},{20002, "Encerado", 400},{20003, "Completo", 600}};
    eTrabajo trabajos[TAMTRAB];
    eCliente clientes[TAMCLIENTES]= {{1,"Lucia",'f'},{2,"Juana",'f'},{3, "Francesca",'f'},{4,"Mateo",'m'},{5,"Juan",'m'},{6,"Josefina",'f'},{7,"Lucio",'m'},{8,"Ana",'m'},{9,"Kevin",'m'}};

    inicializarAutos(autos, TAMAUTO);
    inicializarTrabajos(trabajos,TAMTRAB);
    idAuto=idAuto+1+harcodearAuto(autos,TAMAUTO,8);

    do
    {
        switch( menu() )
        {
        case 1:
            if(addAuto(autos,TAMAUTO,marcas,TAMMARCAS,colores,TAMCOLOR,idAuto,clientes,TAMCLIENTES)==0)
            {
                idAuto++;
                printf("ALTA REALIZADA! \n");
            }
            else
            {
                printf("NO SE PUDO REALIZAR EL ALTA\n");
            }
            break;

        case 2:
            if(modificarAuto(autos,TAMAUTO,marcas,TAMMARCAS,colores,TAMCOLOR,clientes,TAMCLIENTES)==0)
            {
                printf("MODIFICACION EXITOSA\n");
            }
            system("pause");
            break;

        case 3:
            if(bajaAuto(autos,TAMAUTO,marcas,TAMMARCAS,colores,TAMCOLOR,clientes,TAMCLIENTES)==0)
            {
                printf("BAJA REALIZADA\n");
            }
            else
            {
                printf("NO SE PUDO REALIZAR LA BAJA\n");
            }
            system("pause");
            break;

        case 4:
            mostrarAutos(autos,TAMAUTO,marcas,TAMMARCAS,colores,TAMCOLOR,clientes,TAMCLIENTES);
            system("pause");
            system("cls");
            break;

        case 5:
            mostrarMarcasColores(marcas,TAMMARCAS,colores,TAMCOLOR,'m');
            system("pause");
            system("cls");
            break;

        case 6:
            mostrarMarcasColores(marcas,TAMMARCAS,colores,TAMCOLOR,'f');
            system("pause");
            system("cls");
            break;

        case 7:
            mostrarServicios(servicios,TAMSERV);
            system("pause");
            break;

        case 8:
            if(addTrabajo(trabajos,TAMTRAB,autos,TAMAUTO,servicios,TAMSERV,idTrab,marcas,TAMMARCAS,colores,TAMCOLOR,clientes,TAMCLIENTES)==0)
            {
                idTrab++;
                printf("Trabajo realizado\n");
            }
            else
            {
                printf("No se pudo realizar el alta\n");
            }
            system("pause");
            break;

        case 9:
            mostrarTrabajos(trabajos,TAMTRAB);
            system("pause");
            break;

        case 10:
            switch(informes() )
            {
            case 'a':
                mostrarAutoPorColor(autos,TAMAUTO,marcas,TAMMARCAS,colores,TAMCOLOR,clientes,TAMCLIENTES);
                system("pause");
                break;
            case 'b':
                mostrarAutoPorMarca(autos,TAMAUTO,marcas,TAMMARCAS,colores,TAMCOLOR,clientes,TAMCLIENTES);
                system("pause");
                break;
            case 'c':
                contadorColoryMarca(autos,TAMAUTO,colores,TAMCOLOR,marcas,TAMMARCAS);
                system("pause");
                break;
            case 'd':
                marcaMasElegida(autos,TAMAUTO,marcas,TAMMARCAS);
                system("pause");
                break;
            case 'f':
                seguir='s';
                break;
            }
            case 11:
                seguir='s';
                break;

        }

    }
    while(seguir != 's');
    return 0;
}
char menu()
{
    int opcion;

    system("cls");

    printf("###############################|MENU DE OPCIONES|###########################\n");
    printf("#                             1 - Alta de auto.                            #\n");
    printf("#                             2 - Modificar auto.                          #\n");
    printf("#                             3 - Baja de auto.                            #\n");
    printf("#                             4 - Listar autos.                            #\n");
    printf("#                             5 - Listar marcas.                           #\n");
    printf("#                             6 - Listar colores.                          #\n");
    printf("#                             7 - Listar servicios.                        #\n");
    printf("#                             8 - Alta trabajo.                            #\n");
    printf("#                             9 - Listar trabajos.                         #\n");
    printf("#                             10 - Informes.                               #\n");
    printf("#                                                                          #\n");
    printf("#                                 11 - Salir.                              #\n");
    printf("#                              --Ingrese opcion:--                         #\n");
    printf("############################################################################\n");

    scanf("%d", &opcion);

    return opcion;
}

char informes()
{
    char opcion;
    system("cls");
    printf("a-Mostrar autos del color seleccionado\n\n");
    printf("b-Mostrar autos de la marca seleccionada\n\n");
    printf("c-Elegir un color y una marca y contar cuantos autos hay de ese color y marca\n\n");
    printf("d-Mostrar la o las marcas mas elegidas por los clientes\n\n");
    printf("f-Salir\n");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;

}
