/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:26:59 by btheveny          #+#    #+#             */
/*   Updated: 2026/02/11 15:35:31 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
void	ft_memmove(char *dst, char *src, size_t n);
char	*ft_append(char *line, char *buf, size_t n);
void	ft_shift(char *basin, ssize_t *len, ssize_t cut);
char	*ft_take_nl(char *line, char *basin, ssize_t *len, ssize_t nl);

#endif
