/*
 ============================================================================
 Name        : PrimerParcialMeli.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Clientes.h"
#include "Prestamos.h"
#include <string.h>
#include "utn.h"
#include "Informes.h"
#define CANTIDAD_CLIENTES 100
#define CANTIDAD_PRESTAMOS 1000

int main(void) {

	setbuf(stdout, NULL);
	Cliente arrayClientes[CANTIDAD_CLIENTES];
	Prestamo arrayPrestamos[CANTIDAD_PRESTAMOS];
	int opcion;
	int indiceNuevoCliente;
	int indiceNuevoPrestamo;
	char nuevoNombre[50];
	char nuevoApellido[50];
	char nuevoCuil[15];
	int idModificacion;
	int indiceModificacion;
	int opcionModificacion;
	char nombreModificado[50];
	char apellidoModificado[50];
	char cuilModificado[15];
	float nuevoImporte;
	int nuevasCuotas;
	int idClienteNuevoPrestamo;
	int indiceClienteNuevoPrestamo;
	int idPrestamoASaldar;
	int indicePrestamoASaldar;
	char confirmacionSaldarPrestamo;
	int idClienteBaja;
	int indiceClienteBaja;
	int idPrestamoAReanudar;
	int indicePrestamoAReanudar;


	initArrayClientes(arrayClientes, CANTIDAD_CLIENTES);
	initArrayPrestamos(arrayPrestamos, CANTIDAD_PRESTAMOS);

	do {
		if (!utn_getNumero(&opcion,
				"***ADMINISTRADOR FINANCIERO***\n1.Altas.\n2.Modificar.\n3.Baja.\n4.Alta Prestamo.\n5.Saldar Prestamo.\n6.Reanudar Prestamo.\n"
				"7.Imprimir Clientes.\n8.Imprimir Prestamos.\n9.Informacion Clientes.\n10.Informar Prestamos.\n",
				"Opcion Invalida 1 a 11", 1, 11, 2)) {
			switch (opcion) {
			case 1:
				if (!indiceVacioCliente(arrayClientes, CANTIDAD_CLIENTES,
						&indiceNuevoCliente)) {
					if (!utn_getNombre(nuevoNombre, 50, "Nombre: \n",
							"Nombre invalido.\n", 2)
							&& !utn_getNombre(nuevoApellido, 50, "Apellido: \n",
									"Apellido invalido.\n", 2)
							&& !utn_getDni(nuevoCuil, 15, "Cuil: \n",
									"Cuil invalido.\n", 2)) {
						if (!altaCliente(arrayClientes, CANTIDAD_CLIENTES,
								nuevoNombre, nuevoApellido, nuevoCuil,
								indiceNuevoCliente)) {
							if (!imprimirCliente(arrayClientes,
									CANTIDAD_CLIENTES,
									arrayClientes[indiceNuevoCliente].id)) {
								printf("Agregado con exito.\n");
							}
						}
					}
				} else {
					printf("El sistema esta lleno.\n");
				}
				break;
			case 2:
				if(!utn_getNumero(&idModificacion, "Ingrese el id del empleado a modificar: ", "Id invalido.\n", 1, 100, 2))
				{
					indiceModificacion = buscarClientePorId(arrayClientes, CANTIDAD_CLIENTES, idModificacion);
					if(indiceModificacion != -1)
					{
						if(!imprimirCliente(arrayClientes, CANTIDAD_CLIENTES, idModificacion))
						if(!utn_getNumero(&opcionModificacion, "Que desea modificar?\n1.Nombre.\n2.Apellido.\n3.Cuil.\n", "Opcion invalida.\n", 1, 3, 2))
						{
							switch(opcionModificacion)
							{
								case 1:
									if(!utn_getNombre(nombreModificado, 50, "Nombre: ", "Nombre invalido.\n", 2))
									{
										strncpy(arrayClientes[indiceModificacion].nombre, nombreModificado, 50);
										printf("Modificado con exito.\n");
									}
									break;
								case 2:
									if(!utn_getNombre(apellidoModificado, 50, "Apellido: ", "Apellido invalido.\n", 2))
									{
										strncpy(arrayClientes[indiceModificacion].apellido, apellidoModificado, 50);
										printf("Modificado con exito.\n");
									}
									break;
								case 3:
									if(!utn_getDni(cuilModificado, 15, "Cuil: ", "Cuil invalido.\n", 2))
									{
										strncpy(arrayClientes[indiceModificacion].cuil, cuilModificado, 15);
										printf("Modificado con exito.\n");
									}
									break;
							}
						}
					}else{
						printf("Cliente inexistente.\n");
					}
				}
				break;
			case 3:
				if(!utn_getNumero(&idClienteBaja, "Ingrese el ID del cliente a dar de baja: ", "ID invalido, 1 a 100.\n", 1, 100, 2))
				{
					indiceClienteBaja = buscarClientePorId(arrayClientes, CANTIDAD_CLIENTES, idClienteBaja);
					if(indiceClienteBaja != -1)
					{
						if(!bajaCliente(arrayClientes, CANTIDAD_CLIENTES, idClienteBaja, arrayPrestamos, CANTIDAD_PRESTAMOS))
						{

						}
					}else{
						printf("Cliente inexistente.\n");
					}
				}
				break;
			case 4:
				if(!indiceVacioPrestamo(arrayPrestamos, CANTIDAD_PRESTAMOS, &indiceNuevoPrestamo))
				{
					if(!utn_getNumeroFlotante(&nuevoImporte, "Importe: ", "Importe invalido, 1000 a 150000.\n", 1000, 150000, 2) &&
							!utn_getNumero(&nuevasCuotas, "Cantidad de cuotas: ", "Cuotas invalidas, 1 a 12.\n", 1, 12, 2) &&
							!utn_getNumero(&idClienteNuevoPrestamo, "ID del cliente: ", "ID invalido, 1 a 100.\n", 1, 100, 2))
					{
						indiceClienteNuevoPrestamo = buscarClientePorId(arrayClientes, CANTIDAD_CLIENTES, idClienteNuevoPrestamo);
						if(indiceClienteNuevoPrestamo != -1)
						{
							if(!altaPrestamo(arrayPrestamos, CANTIDAD_PRESTAMOS, indiceNuevoPrestamo, idClienteNuevoPrestamo, nuevoImporte, nuevasCuotas))
							{
								if(!imprimirPrestamo(arrayPrestamos, CANTIDAD_PRESTAMOS, arrayClientes, arrayPrestamos[indiceNuevoPrestamo].idPrestamo))
								{
									printf("Agregado con exito.\n");
								}
							}
						} else {
							printf("No existe un cliente con ese id.\n");
						}

					}
				}
				break;
			case 5:
				if(!utn_getNumero(&idPrestamoASaldar, "ID prestamo a saldar: ", "ID invalido, 1 a 1000.\n", 1, 1000, 2))
				{
					indicePrestamoASaldar = buscarPrestamoPorId(arrayPrestamos, CANTIDAD_PRESTAMOS, idPrestamoASaldar);
					if(indicePrestamoASaldar != -1)
					{
						if(!imprimirCliente(arrayClientes, CANTIDAD_CLIENTES, arrayPrestamos[indicePrestamoASaldar].idCliente))
						{
							if(!imprimirPrestamo(arrayPrestamos, CANTIDAD_PRESTAMOS, arrayClientes, idPrestamoASaldar))
							{
								printf("Seguro que desea saldar este prestamo?s/n.\n");
								fflush(stdin);
								scanf("%c", &confirmacionSaldarPrestamo);
								if(confirmacionSaldarPrestamo == 's')
								{
									arrayPrestamos[indicePrestamoASaldar].estado = 1;
									printf("Prestamo saldado.\n");
								}
							}
						}
					}else{
						printf("Prestamo inexistente o estado no activo.\n");
					}
				}
				break;
			case 6:
				if(!utn_getNumero(&idPrestamoAReanudar, "Ingrese el ID del prestamos a reanudar: ", "ID invalido, 1 a 1000.\n", 1, 1000, 2))
				{
					indicePrestamoAReanudar = buscarPrestamoPorId(arrayPrestamos, CANTIDAD_PRESTAMOS, idPrestamoAReanudar);
					if(indicePrestamoAReanudar != -1)
					{
						if(!imprimirCliente(arrayClientes, CANTIDAD_CLIENTES, arrayPrestamos[indicePrestamoAReanudar].idCliente)){}
						if(!reanudarPrestamo(arrayPrestamos, CANTIDAD_PRESTAMOS, idPrestamoAReanudar)){}
					}else{
						printf("Prestamo inexistente.\n");
					}
				}
				break;
			case 7:
				imprimirClientesConPrestamosActivos(arrayClientes, CANTIDAD_CLIENTES, arrayPrestamos, CANTIDAD_PRESTAMOS);
				break;
			case 8:
				if(!imprimirPrestamosConCuil(arrayClientes, CANTIDAD_CLIENTES, arrayPrestamos, CANTIDAD_PRESTAMOS)){}
				break;
			case 9:
				if(!imprimirClientes(arrayClientes, CANTIDAD_CLIENTES)){}
				break;
			case 10:
				if(!imprimirPrestamos(arrayPrestamos, CANTIDAD_PRESTAMOS, arrayClientes)){}
				break;
			}
		}

	} while (opcion != 11);

	return EXIT_SUCCESS;
}
