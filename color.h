#ifndef COLOR_H_INCLUDED
typedef struct
{
    int id;
    char nombreColor[20];

} eColor;
#define COLOR_H_INCLUDED
/** \brief validar color
 *
 * \param array colores
 * \param tama�o color
 * \return entero
 *
 */
int validarColor (eColor colores[], int tam, int id);

#endif // COLOR_H_INCLUDED

