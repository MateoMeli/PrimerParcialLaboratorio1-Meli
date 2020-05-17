/*
 * Informes.h
 *
 *  Created on: 17 may. 2020
 *      Author: pc
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int imprimirPrestamo(Prestamo* listaP, int largoP, Cliente* listaC, int idPrestamo);
int imprimirPrestamos(Prestamo* lista, int largo, Cliente* listaC);
int bajaCliente(Cliente* listaC, int largoC, int idCliente, Prestamo* listaP, int largoP);
int imprimirPrestamoPorCliente(Prestamo* listaP, int largoP, int idCliente, Cliente* listaC, int largoC);
void imprimirClientesConPrestamosActivos(Cliente* listaC, int largoC, Prestamo* listaP, int largoP);
int imprimirPrestamosConCuil(Cliente* listaC, int largoC, Prestamo* listaP, int largoP);
#endif /* INFORMES_H_ */
