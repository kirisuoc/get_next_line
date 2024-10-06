/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:35:13 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/06 12:04:35 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// La función permite leer el contenido del archivo hacia el que apunta el
// file descriptor, línea a línea, hasta el final.

// Devuelve la línea que se acaba de leer. Si no hay nada más que leer o hay
// un error, devuelve NULL.

// Lee de un archivo y lee de stdin (?)

// La línea devuelta tiene que terminar con el caracter n, excepto si ha
// llegado al final y el archivo no termina con un caracter n

// Se considera que la función tiene un comportamiento indeterminado si el
// archivo al que apunta el fd ha cambiado desde la última vez que se llamó,
// siempre que read() no haya llegado al final del archivo.

// Se considera que tiene un comportamiento indeterminado cuando se lee un
// archivo binario. Si quieres, se puede implementar alguna forma de sortear
// este problema.

// ** Intenta leer lo menos posible cada vez que se llame a get_next_line().
// Devuelve la línea actual cada vez que te encuentres
// un salto de línea. No leas el archivo entero y después proceses cada línea.

char	*get_next_line(int fd)
{
	char		*buffer;
	static int	fdd;
	int			contador;

	read(fd, buffer, BUFFER_SIZE);
}
