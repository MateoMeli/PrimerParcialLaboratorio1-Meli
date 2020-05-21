#ifndef CLIENTES_H_
#define CLIENTES_H_
#define EMPTY 0
#define OCCUPIED 1
#include "Prestamos.h"


typedef struct
{
	int id;
	char nombre [50];
	char apellido [50];
	char cuil[15];
	int isEmpty;
}Cliente;

/*brief inicializa el array de clientes poniendo su campo isEmpty en EMPTY
 * lista es el array de clientes
 * largo es el tamaño del array de clientes
 * return 0 si esta ok -1 si algo salio mal
 */
int initArrayClientes(Cliente* lista, int largo);

/*brief Recibe por parametro los datos para dar de alta un nuevo cliente
 * lista es el array de clientes
 * largo es el tamaño del array de clientes
 * nombre es el nombre para el nuevo cliente
 * apellido es el apellido para el nuevo cliente
 * cuil es el cuil para el nuevo cliente
 * indice es el indice donde se va a guardar en el array ese cliente
 *return 0 si esta ok -1 si algo salio mal
 */
int altaCliente(Cliente* lista, int largo, char* nombre, char* apellido, char* cuil, int indice);

/*brief busca el primer indice vacio dentro del array y lo guarda
 * lista es el array de clientes
 * largo es el tamaño del array de clientes
 * nuevoIndice es la direccion de memoria donde se va a guardar el indice vacio
 *return 0 si esta ok -1 si algo salio mal
 */
int indiceVacioCliente(Cliente* lista, int largo, int* nuevoIndice);

/*brief imprime los datos del cliente indicado por id
 * lista es el array de clientes
 * largo es el tamaño del array de clientes
 * id es el id del cliente a imprimir
 *return 0 si esta ok -1 si algo salio mal
 */
int imprimirCliente(Cliente* lista, int largo, int id);

/*brief se le pasa un id y devuelve el indice de ese cliente
 * lista es el array de clientes
 * largo es el tamaño del array de clientes
 * id es el id a del cliente a buscar
 *return el indice del cliente si esta bien o -1 si salio mal
 */
int buscarClientePorId(Cliente* lista, int largo, int id);

/*brief imprime todos los clientes que no esten vacios
 * lista es el array de clientes
 * largo es el tamaño del array de clientes
 *return 0 si esta ok -1 si algo salio mal
 */
int imprimirClientes(Cliente* lista, int largo);
#endif /* CLIENTES_H_ */
