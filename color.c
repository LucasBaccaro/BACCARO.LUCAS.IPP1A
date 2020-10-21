#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"
int validarColor (eColor colores[], int tam, int id)
{
    int error = 1;

    for(int i = 0; i < tam; i++)
    {
        if(id == colores[i].id)
        {
            error = 0;
        }
    }

    return error;
}
