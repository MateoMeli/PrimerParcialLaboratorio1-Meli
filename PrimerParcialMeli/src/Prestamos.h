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

int initArrayPrestamos(Prestamo* lista, int largo);
int indiceVacioPrestamo(Prestamo* lista, int largo, int* nuevoIndice);
int altaPrestamo(Prestamo* lista, int largo, int indice, int idCliente, float importe, int cuotas);
int buscarPrestamoPorId(Prestamo* lista, int largo, int id);
int reanudarPrestamo(Prestamo* lista, int largo, int id);


#endif /* PRESTAMO_H_ */
