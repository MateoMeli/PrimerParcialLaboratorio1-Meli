#ifndef PRESTAMO_H_
#define PRESTAMO_H_
#define EMPTY 0
#define OCCUPIED 1
#define ACTIVO 0
#define SALDADO 1
#define PAUSADO 2
#define ELIMINADO 3
#include "Clientes.h"

typedef struct
{
	int idPrestamo;
	int idCliente;
	float importe;
	int estado;
	int cuotas;
	int isEmpty;
}Prestamo;

/*brief inicializa el array de prestamos poniendo el campo isEmpty en EMPTY
 * lista es el array de prestamos
 * largo es el tamaño del array de prestamos
 *return 0 si esta ok -1 si algo salio mal
 */
int initArrayPrestamos(Prestamo* lista, int largo);

/* brief busca el primer indice vacio dentro del array y lo guarda
 * lista es el array de prestamos
 * largo es el tamaño del array de prestamos
 * nuevoIndice la direccion de memoria para guardar el nuevo indice
 *return 0 si esta ok -1 si algo salio mal
 */
int indiceVacioPrestamo(Prestamo* lista, int largo, int* nuevoIndice);

/*brief recibe por parametro los daros para crear un nuevo prestamo
 * lista es el array de prestamos
 * largo es el tamaño del array de prestamos
 *return 0 si esta ok -1 si algo salio mal
 */
int altaPrestamo(Prestamo* lista, int largo, int indice, int idCliente, float importe, int cuotas);

/*brief busca un prestamo por su id y devuelve su indice
 * lista es el array de prestamos
 * largo es el tamaño del array de prestamos
 * id el id para buscar
 *return el indice buscado si esta bien o -1 si fallo
 */
int buscarPrestamoPorId(Prestamo* lista, int largo, int id);

/*brief reanuda el prestamo si estaba ACTIVO
 * lista es el array de prestamos
 * largo es el tamaño del array de prestamos
 * id es el id del prestamo a reanudar
 *return 0 si esta ok -1 si algo salio mal
 */
int reanudarPrestamo(Prestamo* lista, int largo, int id);


int saldarPrestamo(Prestamo* lista, int largo, int indice);

#endif /* PRESTAMO_H_ */
