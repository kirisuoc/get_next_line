/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:29:04 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/07 12:03:50 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{

  	int fd;
    char *line;

    // Abrir el archivo "texto.txt" en modo lectura
    fd = open("texto.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error al abrir el archivo.\n");
        return (1);
    }

    // Leer línea por línea e imprimir cada línea en consola
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Liberar la memoria reservada por get_next_line
    }

    // Cerrar el archivo
    close(fd);


	return (0);
}
