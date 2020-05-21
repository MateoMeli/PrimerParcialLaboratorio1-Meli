/*
 * Informes.h
 *
 *  Created on: 17 may. 2020
 *      Author: pc
 */

#ifndef INFORMES_H_
#define INFORMES_H_

/*brief imrprime los datos del prestamo con el nombre y apellido de su dueño por su id
 * listaP es el array de prestamos
 * largoP es el tamaño del array de prestamos
 * listaC es el array de clientes
 * idPrestamo es el id del prestamo a mostrar
 * return 0 si esta ok -1 si algo salio mal
 */
int imprimirPrestamo(Prestamo* listaP, int largoP, Cliente* listaC, int idPrestamo);

/*brief imprime todos los prestamos activos existentes
 * listaP es el array de prestamos
 * largoP es el tamaño del array de prestamos
 * listaC es el array de clientes
 *return 0 si esta ok -1 si algo salio mal
 */
int imprimirPrestamos(Prestamo* lista, int largo, Cliente* listaC);

/*brief da de baja un cliente seleccionado por id y todos sus prestamos poniendo su campo isEmpty en EMPTY
 * listaC es el array de clientes
 * largoC es el tamaño del array de clientes
 * idCliente es el id del cliente a dar de baja
 * listaP es el array de prestamos
 * largoP es el tamaño del array de prestamos
 *return 0 si esta ok -1 si algo salio mal
 */
int bajaCliente(Cliente* listaC, int largoC, int idCliente, Prestamo* listaP, int largoP);

/*brief imrprime todos los prestamos de un cliente seleccionado por su id
 * listaP es el array de prestamos
 * largoP es el tamaño del array de prestamos
 * idCliente es el id del cliente a imprimir sus prestamos
 * listaC  es el array de cliente
 * largoC es el tamañao del array de clientes
 *return 0 si esta ok -1 si algo salio mal
 */
int imprimirPrestamoPorCliente(Prestamo* listaP, int largoP, int idCliente, Cliente* listaC, int largoC);

/*brief imprime todos los clientes con la cantidad de prestamos activos que poseen
 * listaC es el array de clientes
 * largoC es el tamaño del array de clientes
 * listaP es el array de prestamos
 * largoP es el tamaño del array de prestamos
 *return 0 si esta ok -1 si algo salio mal
 */
int imprimirClientesConPrestamosActivos(Cliente* listaC, int largoC, Prestamo* listaP, int largoP);

/*brief Imprime todos los prestamos activos junto con el cuil del cliente al que pertenecen
 * listaC es el array de clientes
 * largoC es el tamaño del array de clientes
 * listaP es el array de prestamos
 * largoP es el tamaño del array de prestamos
 *return 0 si esta ok -1 si algo salio mal
 */
int imprimirPrestamosConCuil(Cliente* listaC, int largoC, Prestamo* listaP, int largoP);

/*brief imprime los datos del cliente que mas prestamos activos tenga e informa cuantos son
 * listaC es el array de clientes
 * largoC es el tamaño del array de clientes
 * listaP es el array de prestamos
 * largoP es el tamaño del array de prestamos
 *return 0 si esta ok -1 si algo salio mal
 */
int clienteConMasPrestamosActivos(Cliente* listaC, int largoC, Prestamo* listaP, int largoP);

/*brief imprime los datos del cliente con mas prestamos saldados e informa cuantos son
 * listaC es el array de clientes
 * largoC es el tamaño del array de clientes
 * listaP es el array de prestamos
 * largoP es el tamaño del array de prestamos
 *return 0 si esta ok -1 si algo salio mal
 */
int clienteConMasPrestamosSaldados(Cliente* listaC, int largoC, Prestamo* listaP, int largoP);

/* pide un importe para buscar e imprimir la cantidad de prestamos activos mayores a ese importe que existan
 * listaP es el array de prestamos
 * largoP es el tamaño del array de prestamos
 * importe es el importe a comparar
 *return 0 si esta ok -1 si algo salio mal
 */
int cantidadPrestamosMayorA(Prestamo* listaP, int largoP, float importe);

int clienteConMasPrestamos(Prestamo* listaP, int largoP, Cliente* listaC, int largoC);

int prestamosDeDoceCuotasSaldados(Prestamo* listaP, int largoP);

int prestamosPorCuotas(Prestamo* listaP, int largoP, int cuotas);
#endif /* INFORMES_H_ */
