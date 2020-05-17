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

int initArrayClientes(Cliente* lista, int largo);
int altaCliente(Cliente* lista, int largo, char* nombre, char* apellido, char* cuil, int indice);
int indiceVacioCliente(Cliente* lista, int largo, int* nuevoIndice);
int imprimirCliente(Cliente* lista, int largo, int id);
int buscarClientePorId(Cliente* lista, int largo, int id);
int imprimirClientes(Cliente* lista, int largo);
#endif /* CLIENTES_H_ */
