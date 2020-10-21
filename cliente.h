#ifndef CLIENTE_H_INCLUDED
typedef struct
{
    int id;
    char nombre[20];
    char sexo;

} eCliente;

#define CLIENTE_H_INCLUDED

/** \brief muestra clientes
 *
 * \param clientes[] eCliente array clientes
 * \param tamClientes int tamaño clientes
 * \return void nada
 *
 */
void mostrarClientes(eCliente clientes[], int tamClientes);
/** \brief muestra cliente
 *
 * \param id int id del cliente
 * \param descripcion[] char descripcion del cliente
 * \return void nada
 *
 */
void mostrarCliente(int id, char descripcion[]);
/** \brief valida cliente
 *
 * \param clientes[] eCliente array clientes
 * \param tam int tamaño clientes
 * \param id int id
 * \return int entero
 *
 */
int validarCliente(eCliente clientes[], int tam, int id);

#endif // CLIENTE_H_INCLUDED
