#include <stdio.h>
#include <stdlib.h>
#include "Prestamos.h"
#include <string.h>
#include "utn.h"
#include "Clientes.h"



int initArrayPrestamos(Prestamo* lista, int largo)
{
	int i;
	for(i = 0; i < largo; i ++)
	{
		lista[i].isEmpty = EMPTY;
	}
	return 0;
}

int indiceVacioPrestamo(Prestamo* lista, int largo, int* nuevoIndice)
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

int altaPrestamo(Prestamo* lista, int largo, int indice, int idCliente, float importe, int cuotas)
{
	int retorno = -1;
	if(lista != NULL)
	{
		lista[indice].idPrestamo = indice + 1;
		lista[indice].idCliente = idCliente;
		lista[indice].importe = importe;
		lista[indice].cuotas = cuotas;
		lista[indice].estado = ACTIVO;
		lista[indice].isEmpty = OCCUPIED;
		retorno = 0;
	}


	return retorno;
}





int buscarPrestamoPorId(Prestamo* lista, int largo, int id)
{
	int retorno = -1;
	int i;

	for(i = 0; i < largo; i ++)
	{
		if(lista[id-1].isEmpty == OCCUPIED && lista[id-1].estado == ACTIVO)
		{
			retorno = id-1;
		}
	}

	return retorno;

}

int reanudarPrestamo(Prestamo* lista, int largo, int id)
{
	int retorno = -1;
	int i;
	for(i = 0; i < largo; i ++)
	{
		if(lista[i].estado == PAUSADO && lista[i].isEmpty == OCCUPIED)
		{
			lista[i].estado = ACTIVO;
			retorno = 0;
		}
	}

	return retorno;
}

int saldarPrestamo(Prestamo* lista, int largo, int indice)
{
	int retorno = -1;
	int i;
	char confirma;
	for(i = 0; i < largo; i ++)
	{
		if(lista[i].idPrestamo == lista[indice].idPrestamo && lista[i].isEmpty == OCCUPIED && lista[i].estado == ACTIVO)
		{
			printf("Seguro que desea saldar este prestamo?s/n.\n");
			scanf("%c", &confirma);
			if(confirma == 's')
			{
				lista[i].estado = SALDADO;
				retorno = 0;
			}

		}
	}



	return retorno;
}







