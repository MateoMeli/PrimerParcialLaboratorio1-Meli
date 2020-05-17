#include <stdio.h>
#include <stdlib.h>
#include "Clientes.h"
#include "utn.h"
#include "Prestamos.h"
#include <string.h>


int initArrayClientes(Cliente* lista, int largo)
{
	int i;
	for(i = 0; i < largo; i ++)
	{
		if(lista != NULL)
		{
			lista[i].isEmpty = EMPTY;
		}
	}
	return 0;
}


int altaCliente(Cliente* lista, int largo, char* nombre, char* apellido, char* cuil, int indice)
{
	int retorno = -1;
	if(lista != NULL && nombre != NULL && apellido != NULL && cuil != NULL){
		if(lista[indice].isEmpty == EMPTY)
		{
			lista[indice].id = indice + 1;
			strncpy(lista[indice].nombre, nombre, 50);
			strncpy(lista[indice].apellido, apellido, 50);
			strncpy(lista[indice].cuil, cuil, 15);
			lista[indice].isEmpty = OCCUPIED;
			retorno = 0;

		}

	}
	return retorno;
}

int indiceVacioCliente(Cliente* lista, int largo, int* nuevoIndice)
{
	int retorno = -1;
	int i;
	for(i = 0; i < largo; i ++)
	{
		if(lista[i].isEmpty == EMPTY)
		{
			*nuevoIndice = i;
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int imprimirCliente(Cliente* lista, int largo, int id)
{
	int retorno = -1;
	int i;
	for(i = 0; i < largo; i ++)
	{
		if(lista[i].id == id && lista[i].isEmpty == OCCUPIED)
		{
			printf("ID: %d---Nombre: %s---Apellido: %s---Cuil: %s.\n", lista[i].id, lista[i].nombre, lista[i].apellido, lista[i].cuil);
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int buscarClientePorId(Cliente* lista, int largo, int id)
{
	int retorno = -1;
	int i;

	for(i = 0; i < largo; i ++)
	{
		if(lista[id-1].isEmpty == OCCUPIED)
		{
			retorno = id-1;
		}
	}

	return retorno;

}

int imprimirClientes(Cliente* lista, int largo)
{
	int retorno = -1;
	int i;

	if(lista != NULL)
	{
		retorno = 0;
		for(i = 0; i < largo; i++)
		{
			if(lista[i].isEmpty == OCCUPIED)
			{
				printf("ID: %d---Nombre: %s---Apellido: %s---Cuil: %s.\n", lista[i].id, lista[i].nombre, lista[i].apellido, lista[i].cuil);
			}
		}
	}


	return retorno;
}







