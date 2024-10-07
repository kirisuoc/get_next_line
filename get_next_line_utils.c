/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:35:16 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/07 16:56:21 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// Funciones de ayuda que se necesitan en la función get_next_line()

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s && s[length])
		length++;
	return (length);
}

int	has_newline(char *remainder)
{
	while (remainder && *remainder)
	{
		if (*remainder == '\n')
			return (1);
		remainder++;
	}
	return (0);
}

// Une la nueva línea hasta el salto de línea (si lo hay) al remainder
char	*join_strings(char *remainder, char *new_part)
{
	size_t	remainder_len;
	size_t	newpart_len;
	char	*new_str;
	size_t	i;

	remainder_len = ft_strlen(remainder);
	newpart_len = ft_strlen(new_part);
	new_str = malloc((remainder_len + newpart_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	if (remainder)
	{
		while (i < remainder_len)
		{
			new_str[i] = remainder[i];
			i++;
		}
	}
	i = 0;
	while (i < newpart_len)
	{
		new_str[remainder_len + i] = new_part[i];
		i++;
	}
	new_str[remainder_len + i] = '\0';
	free(remainder);
	return (new_str);
}

// Extrae la nueva línea hasta que se encuentra el \n
char	*extract_line(char *remainder)
{
	char	*string;
	int		i;
	int		j;

	if (!remainder)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	string = malloc((i + (remainder[i] == '\n') + 1) * sizeof(char));
	if (!string)
		return (NULL);
	j = 0;
	while (j < i)
	{
		string[j] = remainder[j];
		j++;
	}
	if (remainder[i] == '\n')
		string[i++] = '\n';
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

	if (!remainder)
		return (NULL);
	newline_pos = 0;
	while (remainder[newline_pos] && remainder[newline_pos] != '\n')
		newline_pos++;
	if (remainder[newline_pos] == '\0')
	{
		free(remainder);
		return (NULL);
	}
	new_remainder = malloc((ft_strlen(remainder) - newline_pos + 1)
			* sizeof(char));
	if (!new_remainder)
	{
		free(remainder);
		return (NULL);
	}
	newline_pos++;
	i = 0;
	while (remainder[newline_pos + i] != '\0')
	{
		new_remainder[i] = remainder[newline_pos + i];
		i++;
	}
	new_remainder[i] = '\0';
	free(remainder);
	return (new_remainder);
}
