#ifndef AUTO_H_INCLUDED
typedef struct
{
    int id;
    int patente;
    int idMarca; //  Validar
    int idColor;  //Validar
    int modelo; //(a�o de fabricaci�n)
    int idCliente;
    int isEmpty;

} eAuto;
#define AUTO_H_INCLUDED

#include "marca.h"
#include "color.h"
#include "cliente.h"

#endif // AUTO_H_INCLUDED

/** \brief Inicia campo autos
 *
 * \param autos[] eAuto recibe array autos
 * \param tam int tama�o autos
 * \return void nada
 *
 */
void inicializarAutos(eAuto autos[], int tam);
/** \brief harcodea autos
 *
 * \param autos[] eAuto array autos
 * \param tam int tama�o autos
 * \param cant int cantidad de autos
 * \return int devuelve entero
 *
 */
int harcodearAuto(eAuto autos[], int tam, int cant);
/** \brief busca campo libre
 *
 * \param array autos
 * \param tam int tama�o
 * \return int entero
 *
 */
int buscarLibre(eAuto autos[], int tam);

/** \brief carga autos
 *
 * \param marcas[] eMarca array marcas
 * \param tamMarca int tama�o marcas
 * \param colores[] eColor array color
 * \param tamColor int tama�o color
 * \param idAuto int id de auto
 * \param clientes[] eCliente array cliente
 * \param tamClientes int tama�o cliente
 * \return eAuto devuelve estructura cargar auto
 *
 */
eAuto cargarAuto(eMarca marcas[], int tamMarca, eColor colores[], int tamColor, int idAuto,eCliente clientes[],int tamClientes);
/** \brief a�adir auto
 *
 * \param autos[] eAuto array auto
 * \param tamAuto int tama�o auto
 * \param marcas[] eMarca array marca
 * \param tamMarca int tama�o marca
 * \param colores[] eColor array colores
 * \param tamColor int tama�o color
 * \param idAuto int id del auto
 * \param clientes[] eCliente array cliente
 * \param tamClientes int tama�o cliente
 * \return int retorna estruc add auto
 *
 */
int addAuto(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, int idAuto,eCliente clientes[],int tamClientes);
/** \brief busca campo
 *
 * \param autos[] eAuto array auto
 * \param tamAuto int tama�o auto
 * \param patente int patente
 * \return int devuelve entero
 *
 */
int buscarPatente(eAuto autos[], int tamAuto, int patente);
/** \brief baja logica
 *
 * \param autos[] eAuto array auto
 * \param tamAuto int tama�o auto
 * \param marcas[] eMarca array marca
 * \param tamMarca int tama�o marca
 * \param colores[] eColor array colores
 * \param tamColor int tama�o color
 * \param clientes[] eCliente array cliente
 * \param tamClientes int tama�o cliente
 * \return int retorna entero
 *
 */
int bajaAuto(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes);
/** \brief modificar campo auto
 *
 * \param autos[] eAuto array autos
 * \param tam int tama�o auto
 * \param marcas[] eMarca array marcas
 * \param tamMarca int tama�o marcas
 * \param colores[] eColor array colores
 * \param tamColor int tama�o colores
 * \param clientes[] eCliente array clientes
 * \param tamClientes int tama�o clientes
 * \return int retorna entero
 *
 */
int modificarAuto(eAuto autos[], int tam, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes);
/** \brief submenu modificar
 *
 * \param autos[] eAuto array autos
 * \param indice int tama�o autos
 * \param marcas[] eMarca array marcas
 * \param tamMarca int tama�o marcas
 * \param colores[] eColor array colores
 * \param tamColor int tama�o colores
 * \param clientes[] eCliente array clientes
 * \param tamClientes int tama�o clientes
 * \return int retorna entero
 *
 */
int menuModificar(eAuto autos[], int indice, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamClientes);

/** \brief muestra auto color
 *
 * \param autos[] eAuto array autos
 * \param tamA int tama�o autos
 * \param marcas[] eMarca array marcas
 * \param tamM int tama�o marcas
 * \param colores[] eColor array colores
 * \param tamC int tama�o colores
 * \param clientes[] eCliente array cientes
 * \param tamClientes int tama�o clientes
 * \return void nada
 *
 */
void mostrarAutoPorColor(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClientes);
/** \brief muestra por marca
 *
 * \param autos[] eAuto array autos
 * \param tamA int tama�o autos
 * \param marcas[] eMarca array marcas
 * \param tamM int tama�o marcas
 * \param colores[] eColor array colores
 * \param tamC int tama�o colores
 * \param clientes[] eCliente array clientes
 * \param tamClientes int tama�o clientes
 * \return void nada
 *
 */
void mostrarAutoPorMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClientes);
/** \brief marca mas elegita
 *
 * \param autos[] eAuto array autas
 * \param tam int tama�o autos
 * \param marcas[] eMarca array marca
 * \param tamM int tama�o marca
 * \return int entero
 *
 */
int marcaMasElegida(eAuto autos[],int tam,eMarca marcas[],int tamM);


/** \brief contador de color y marca
 *
 * \param autos[] eAuto array autos
 * \param tam int tama�o autos
 * \param colores[] eColor array clores
 * \param tamC int tama�o colores
 * \param marcas[] eMarca array marcas
 * \param tamM int tama�o marcas
 * \return int entero
 *
 */
int contadorColoryMarca(eAuto autos[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM);

/** \brief muestra campo autos
 *
 * \param id int id de auto
 * \param patente int patente de auto
 * \param idMarca int id de la estruct marca
 * \param idColor int id de la estruc color
 * \param modelo int modelo del auto
 * \param idCliente int id de la estruc cliente
 * \param marcas[] eMarca array marcas
 * \param tamMarca int tama�o marcas
 * \param colores[] eColor array color
 * \param tamColor int tama�o color
 * \param clientes[] eCliente array clientes
 * \param tamCliente int tama�o clientes
 * \return void nada
 *
 */
void mostrarAuto(int id, int patente, int idMarca, int idColor, int modelo, int idCliente, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[],int tamCliente);
/** \brief mostrar autos
 *
 * \param autos[] eAuto array autos
 * \param tam int tama�o autos
 * \param marcas[] eMarca array marcas
 * \param tamMarca int tama�o marca
 * \param colores[] eColor array colores
 * \param tamColores int tama�o color
 * \param clientes[] eCliente array clientes
 * \param tamCliente int tama�o clientes
 * \return void nada
 *
 */
void mostrarAutos(eAuto autos[], int tam, eMarca marcas[], int tamMarca, eColor colores[], int tamColores,eCliente clientes[],int tamCliente);

