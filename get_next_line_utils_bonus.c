/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:00:01 by ecousill          #+#    #+#             */
/*   Updated: 2024/10/09 11:50:08 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *string)
{
	size_t	length;

	length = 0;
	while (string && string[length])
		length++;
	return (length);
}

int	has_newline(char *string)
{
	while (string && *string != '\0')
	{
		if (*string == '\n')
			return (1);
		string++;
	}
	return (0);
}

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
	while (i < remainder_len)
	{
		new_str[i] = remainder[i];
		i++;
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

char	*update_remainder(char *remainder)
{
	size_t	newline_pos;
	size_t	i;
	char	*new_remainder;

	if (!remainder)
		return (NULL);
	newline_pos = 0;
	while (remainder[newline_pos] && remainder[newline_pos] != '\n')
		newline_pos++;
	if (remainder[newline_pos] == '\0')
		return (NULL);
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
