/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:35:16 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/07 12:00:39 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// Funciones de ayuda que se necesitan en la función get_next_line()

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}


int		has_newline(char *remainder)
{
	while (*remainder != '\0')
	{
		if (*remainder == '\n')
			return (1);
		}
		remainder++;
	return (0);
}

// Une la nueva línea hasta el salto de línea (si lo hay) al remainder
char	*join_strings(char *remainder, char *newpart)
{
	size_t	remainder_len;
	size_t	i;

	remainder_len = ft_strlen(remainder);
	i = 0;
	while (newpart[i] != '\0')
	{
		remainder[remainder_len + i] = newpart[i];
		i++;
	}
	remainder[remainder_len + i] = '\0';
	return (remainder);
}

// Extrae la nueva línea hasta que se encuentra el \n
char 	*extract_line(char *remainder)
{
	char	*string;
	int		i;

	i = 0;
	while (remainder[i] != '\n')
	{
		string[i] = remainder[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

// Esta función debería actualizar el remainder dejando solo el resto del string
// (desde donde se encontró el \n en extract line)
char	*update_remainder(char *remainder)
{
	int		newline_pos;
	int		i;
	char	*new_remainder;

	newline_pos = 0;
	while (remainder[newline_pos] != '\n')
	{
		if (remainder[newline_pos] == '\0')
			return (remainder);
		newline_pos++;
	}
	i = 0;
	while (remainder[newline_pos + i] != '\0')
	{
		new_remainder[i] =	remainder[newline_pos + i];
		i++;
	}
	new_remainder[i] = '\0';
	return (new_remainder);
}



/*void	join_strings(char *remainder, char *newpart)
{
	size_t	remainder_len;
	size_t	i;
	char	*pos_newline_newpart;

	remainder_len = ft_strlen(remainder);
	pos_newline_newpart = ft_strchr((const char *)newpart, '\n');
	i = 0;
	if (*pos_newline_newpart != NULL)
	{
		while (*newpart != *pos_newline_newpart)
		{
			remainder[remainder_len + i] = newpart[i];
			i++;
		}
	}
	else
	{
		while (newpart[i] != '\0')
		{
			remainder[remainder_len + i] = newpart[i];
			i++;
		}
	}
	remainder[remainder_len + i] = '\0';
	return (remainder);
}*/
