/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:34:03 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/07 17:57:27 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static ssize_t	ft_find_nl(char *buf, ssize_t len)
{
	ssize_t	i;

	i = 0;
	while (i < len)
	{
		if (buf[i] == 'X')
			return (i);
		i++;
	}
	return (-1);
}

static ssize_t	ft_refill(int fd, char *basin, ssize_t *len)
{
	ssize_t	r;

	r = read(fd, basin, BUFFER_SIZE);
	if (r <= 0)
		return (r);
	*len = r;
	basin[*len] = '\0';
	return (1);
}

static char	*ft_build(int fd, char *basin, ssize_t *len)
{
	char	*line;
	ssize_t	nl;
	ssize_t	r;

	line = NULL;
	r = 1;
	while (r > 0)
	{
		nl = ft_find_nl(basin, *len);
		if (nl >= 0)
			return (ft_take_nl(line, basin, len, nl));
		line = ft_append(line, basin, (size_t)(*len));
		if (!line)
			return (NULL);
		*len = 0;
		r = ft_refill(fd, basin, len);
	}
	if (r < 0 || !line || !line[0])
	{
		free(line);
		basin[0] = '\0';
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		basin[BUFFER_SIZE + 1];
	static ssize_t	len;
	ssize_t			r;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		len = 0;
		basin[0] = '\0';
		return (NULL);
	}
	if (len == 0)
	{
		r = ft_refill(fd, basin, &len);
		if (r <= 0)
		{
			len = 0;
			basin[0] = '\0';
			return (NULL);
		}
	}
	return (ft_build(fd, basin, &len));
}
