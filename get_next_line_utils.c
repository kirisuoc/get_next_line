/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:35:16 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/06 21:10:06 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Funciones de ayuda que se necesitan en la función get_next_line()
int		has_newline(char *remainder)
{
	if (remainder != '\0')
		return (1);
	return (0);
}

// Une la nueva línea hasta el salto de línea (si lo hay) al remainder
void	join_strings(char *remainder, char *newpart)
{

}

// Extrae la nueva línea hasta que se encuentra el \n
char 	*extract_line(char *string)
{
	char	*string;

	while (*string != '\n')
	{
		*string = *string;
		string++;
		string++;
	}
	*string = '\0';
	return (string);
}

// Esta función debería actualizar el remainder dejando solo el resto del string
// (desde donde se encontró el \n en extract line)
char	*update_remainder()
{

}
