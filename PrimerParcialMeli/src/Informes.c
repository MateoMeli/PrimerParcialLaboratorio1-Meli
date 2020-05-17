/*
 * Informes.c
 *
 *  Created on: 17 may. 2020
 *      Author: pc
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Prestamos.h"
#include "Clientes.h"
#include "utn.h"
#include "Informes.h"

int imprimirPrestamos(Prestamo *lista, int largo, Cliente *listaC) {
	int retorno = -1;
	int i;

	for (i = 0; i < largo; i++) {

	}
	return retorno;
}

int imprimirPrestamo(Prestamo *listaP, int largoP, Cliente *listaC,
		int idPrestamo) {
	int retorno = 0;
	int i;

	for (i = 0; i < largoP; i++) {
		if (listaP[i].idPrestamo
				== idPrestamo&& listaP[i].isEmpty == OCCUPIED && listaP[i].estado == ACTIVO) {
			printf(
					"ID Prestamo: %d---Importe: %.2f---Cuotas: %d---Cliente: %s %s.\n",
					listaP[i].idPrestamo, listaP[i].importe, listaP[i].cuotas,
					listaC[(listaP[i].idCliente) - 1].nombre,
					listaC[(listaP[i].idCliente) - 1].apellido);
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int bajaCliente(Cliente *listaC, int largoC, int idCliente, Prestamo *listaP,
		int largoP) {
	int retorno = -1;
	char confirma;
	int i;

	if (!imprimirPrestamoPorCliente(listaP, largoP, idCliente, listaC,
			largoC)) {

	}
	printf(
			"Seguro que desea eliminar al cliente con todos sus prestamos? s/n: ");
	fflush(stdin);
	scanf("%c", &confirma);
	if (confirma == 's') {
		for (i = 0; i < largoP; i++) {
			if (listaP[i].idCliente == idCliente) {
				listaP[i].estado = ELIMINADO;
				listaP[i].isEmpty = EMPTY;
			}

		}
		listaC[idCliente - 1].isEmpty = EMPTY;
		retorno = 0;
	}

	return retorno;
}

int imprimirPrestamoPorCliente(Prestamo *listaP, int largoP, int idCliente,
		Cliente *listaC, int largoC) {
	int retorno = -1;
	int i;
	for (i = 0; i < largoP; i++) {
		if (listaP[i].idCliente	== idCliente&& listaP[i].estado == ACTIVO && listaP[i].isEmpty == OCCUPIED) {
			if (!imprimirPrestamo(listaP, largoP, listaC,
					listaP[i].idPrestamo)) {

			}
		}
	}

	return retorno;
}


int imprimirPrestamosConCuil(Cliente* listaC, int largoC, Prestamo* listaP, int largoP)
{
	int retorno = -1;
	int i;
	for(i = 0; i < largoP; i ++)
	{
		if(listaP[i].estado == ACTIVO && listaP[i].isEmpty == OCCUPIED)
		{
			retorno = 0;
			printf("ID: %d--Importe: %f--Cuotas:%d--Cuil:%s.\n", listaP[i].idPrestamo, listaP[i].importe, listaP[i].cuotas, listaC[listaP[i].idCliente-1].cuil);
		}
	}



	return retorno;
}


void imprimirClientesConPrestamosActivos(Cliente* listaC, int largoC, Prestamo* listaP, int largoP)
{
	int i;
	int j;
	int contador = 0;
	for(j = 0; j < largoC; j ++)
	{
		for(i = 0; i < largoP; i ++)
		{
			if(listaP[i].isEmpty == OCCUPIED && listaP[i].estado == ACTIVO && listaP[i].idCliente == listaC[j].id)
			{
				contador ++;
			}
		}
		printf("ID: %d---Nombre: %s---Apellido: %s---Cuil: %s---Cantidad de prestamos activos: %d.\n", listaC[i].id, listaC[i].nombre, listaC[i].apellido, listaC[i].cuil, contador);
		contador = 0;
	}

}

















