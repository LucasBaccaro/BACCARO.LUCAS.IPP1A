#ifndef FECHA_H_INCLUDED
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

#define FECHA_H_INCLUDED
/** \brief validar fecha
 *
 * \param fecha eFecha
 * \return int entero
 *
 */
int validarFecha(eFecha fecha);



#endif // FECHA_H_INCLUDED
