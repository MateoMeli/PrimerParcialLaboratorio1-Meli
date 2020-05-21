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

	if (!imprimirCliente(listaC, largoC, idCliente)) {
	}
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
		if (listaP[i].idCliente
				== idCliente&& listaP[i].estado == ACTIVO && listaP[i].isEmpty == OCCUPIED) {
			if (!imprimirPrestamo(listaP, largoP, listaC,
					listaP[i].idPrestamo)) {

			}
		}
	}

	return retorno;
}

int imprimirPrestamosConCuil(Cliente *listaC, int largoC, Prestamo *listaP,
		int largoP) {
	int retorno = -1;
	int i;
	for (i = 0; i < largoP; i++) {
		if (listaP[i].estado == ACTIVO && listaP[i].isEmpty == OCCUPIED) {
			retorno = 0;
			printf("ID: %d--Importe: %f--Cuotas:%d--Cuil:%s.\n",
					listaP[i].idPrestamo, listaP[i].importe, listaP[i].cuotas,
					listaC[listaP[i].idCliente - 1].cuil);
		}
	}

	return retorno;
}

int imprimirClientesConPrestamosActivos(Cliente *listaC, int largoC,
		Prestamo *listaP, int largoP) {
	int i;
	int j;
	int retorno = -1;

	for (i = 0; i < largoC; i++) {
		if (listaC[i].isEmpty == OCCUPIED) {
			int contador = 0;
			for (j = 0; j < largoP; j++) {
				if (listaC[i].id == listaP[j].idCliente&& listaP[j].estado == ACTIVO && listaP[j].isEmpty == OCCUPIED) {
					contador++;
					retorno = 0;
				}
			}
			printf(	"ID: %d---Nombre: %s---Apellido: %s---Cuil: %s---Prestamos activos: %d.\n",	listaC[i].id, listaC[i].nombre, listaC[i].apellido,	listaC[i].cuil, contador);
		}

	}
	return retorno;
}


int clienteConMasPrestamosActivos(Cliente* listaC, int largoC, Prestamo* listaP, int largoP)
{
	int retorno = -1;
	int i;
	int j;
	int max;
	int idMax;
	int flagPrimera = 1;

	for(i = 0; i < largoC; i ++)
	{
		if(listaC[i].isEmpty == OCCUPIED)
		{
			int contador = 0;
			for(j = 0; j < largoP; j++)
			{
				if(listaC[i].id == listaP[j].idCliente && listaP[j].estado == ACTIVO && listaP[j].isEmpty == OCCUPIED)
				{
					contador ++;
					retorno = 0;
				}
			}
			if(flagPrimera == 1)
			{
				max = contador;
				idMax = listaC[i].id;
				flagPrimera = 0;
			}
			if(contador > max)
			{
				max = contador;
				idMax = listaC[i].id;			}

		}
	}
	if(retorno == 0)
	{
		printf("El cliente con mas prestamos activos es: %s %s y tiene: %d prestamo/s activo/s.\n", listaC[idMax-1].nombre, listaC[idMax-1].apellido, max);
	}


	return retorno;
}

int clienteConMasPrestamosSaldados(Cliente* listaC, int largoC, Prestamo* listaP, int largoP)
{
	int retorno = -1;
	int i;
	int j;
	int max;
	int idMax;
	int flagPrimera = 1;

	for(i = 0; i < largoC; i ++)
		{
			if(listaC[i].isEmpty == OCCUPIED)
			{
				int contador = 0;
				for(j = 0; j < largoP; j++)
				{
					if(listaC[i].id == listaP[j].idCliente && listaP[j].estado == SALDADO && listaP[j].isEmpty == OCCUPIED)
					{
						contador ++;
						retorno = 0;
					}
				}
				if(flagPrimera == 1)
				{
					max = contador;
					idMax = listaC[i].id;
					flagPrimera = 0;
				}
				if(contador > max)
				{
					max = contador;
					idMax = listaC[i].id;			}

			}
		}
	if(retorno == 0)
	{
		printf("El cliente con mas prestamos saldados es: %s %s y tiene: %d prestamo/s saldado/s.\n", listaC[idMax-1].nombre, listaC[idMax-1].apellido, max);
	}



	return retorno;
}


int cantidadPrestamosMayorA(Prestamo* listaP, int largoP, float importe)
{
	int retorno = -1;
	int contador = 0;
	int i;

	for( i = 0; i < largoP; i ++)
	{
		if(listaP[i].isEmpty == OCCUPIED && listaP[i].estado == ACTIVO && listaP[i].importe >= importe)
		{
			contador ++;
			retorno = 0;
		}
	}
	if(retorno == 0)
	{
		printf("La cantidad de prestamos activos con importe mayor a %2.f es: %d.\n", importe, contador);
	}


	return retorno;
}

int clienteConMasPrestamos(Prestamo* listaP, int largoP, Cliente* listaC, int largoC)
{
	int retorno = -1;
	int i;
	int j;
	int contador;
	int idMax;
	int max;
	int flag = 1;

	for(i = 0; i < largoC; i ++)
	{
		if(listaC[i].isEmpty == OCCUPIED)
		{
			contador = 0;
			for(j = 0; j < largoP; j ++)
			{
				if(listaP[j].isEmpty == OCCUPIED && listaC[i].id == listaP[j].idCliente)
				{
					contador ++;
					retorno = 0;
				}
			}
			if(flag == 1)
			{
				max = contador;
				idMax = listaC[i].id;
				flag = 0;
			}
			if(contador > max)
			{
				max = contador;
				idMax = listaC[i].id;
			}
		}
	}
	if(retorno == 0)
	{
		printf("El cliente con mas prestamos es %s %s y tiene %d prestamo/s.\n", listaC[idMax-1].nombre, listaC[idMax-1].apellido, max);
	}

	return retorno;
}

int prestamosDeDoceCuotasSaldados(Prestamo* listaP, int largoP)
{
	int retorno = 0;
	int i;
	int contador = 0;
	for ( i = 0; i < largoP; i ++)
	{
		if(listaP[i].isEmpty == OCCUPIED && listaP[i].cuotas == 12 && listaP[i].estado == SALDADO)
		{
			contador ++;
			retorno = 0;
		}
	}
	if(retorno == 0)
	{
		printf("La cantidad de prestamos de doce cuotas que se encuentran saldados es: %d.\n", contador);
	}



	return retorno;
}

int prestamosPorCuotas(Prestamo* listaP, int largoP, int cuotas)
{
	int retorno = -1;
	int i;
	int contador = 0;
	for(i = 0; i < largoP; i ++)
	{
		if(listaP[i].isEmpty == OCCUPIED && listaP[i].estado == ACTIVO && listaP[i].cuotas == cuotas)
		{
			contador ++;
			retorno = 0;
		}
	}
	if( retorno == 0)
	{
		printf("La cantidad de prestamos activos con %d cuotas es %d.\n", cuotas, contador);
	}



	return retorno;
}






