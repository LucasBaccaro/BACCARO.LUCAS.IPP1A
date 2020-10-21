#ifndef MARCA_H_INCLUDED
typedef struct
{
    int id; //en mil
    char descripcion[20];

} eMarca;

#define MARCA_H_INCLUDED

#include "color.h"


/** \brief muestra color
 *
 * \param id int id color
 * \param desc[] char descripcion color
 * \return void nada
 *
 */
void mostrarMarcaColor(int id, char desc[]);
/** \brief muestra marcas o colores
 *
 * \param marcas[] eMarca array marcas
 * \param tamMarca int tamaño marcas
 * \param colores[] eColor array colores
 * \param tamColor int tamaño colores
 * \param parametro char M marcas calquier otra colores
 * \return void nada
 *
 */
void mostrarMarcasColores(eMarca marcas[], int tamMarca, eColor colores[], int tamColor, char parametro);
/** \brief valida marca
 *
 * \param marcas[] eMarca array marcas
 * \param tam int tamaño marcas
 * \param id int id marca
 * \return int retorna entero
 *
 */
int validarMarca(eMarca marcas[], int tam, int id);
#endif // MARCA_H_INCLUDED
