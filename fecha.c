#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fecha.h"

int validarFecha(eFecha fecha)
{
    int error = 0;

    if(fecha.dia < 1 || fecha.dia > 31 || fecha.mes < 1 || fecha.mes > 12 || fecha.anio < 1900 || fecha.anio > 2020)
    {
        error = 1;
    }

    return error;
}
