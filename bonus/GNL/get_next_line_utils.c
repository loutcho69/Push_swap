/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:26:34 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/10 01:42:12 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	ft_memmove(char *dst, char *src, size_t n)
{
	size_t	i;

	if (dst < src)
	{
		i = 0;
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
		return ;
	}
	i = n;
	while (i > 0)
	{
		i--;
		dst[i] = src[i];
	}
}

char	*ft_append(char *line, char *buf, size_t n)
{
	char	*new_line;
	size_t	len;

	if (!buf || n == 0)
		return (line);
	len = gnl_strlen(line);
	new_line = malloc(len + n + 1);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	if (line)
		ft_memmove(new_line, line, len);
	ft_memmove(new_line + len, buf, n);
	new_line[len + n] = '\0';
	free(line);
	return (new_line);
}

void	ft_shift(char *basin, ssize_t *len, ssize_t cut)
{
	ssize_t	rest;

	rest = *len - cut;
	if (rest > 0)
		ft_memmove(basin, basin + cut, (size_t)rest);
	*len = rest;
	basin[*len] = '\0';
}

char	*ft_take_nl(char *line, char *basin, ssize_t *len, ssize_t nl)
{
	line = ft_append(line, basin, (size_t)(nl + 1));
	if (!line)
	{
		*len = 0;
		basin[0] = '\0';
		return (NULL);
	}
	ft_shift(basin, len, nl + 1);
	return (line);
}
