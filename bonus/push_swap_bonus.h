/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:44:42 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/05 18:46:55 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>

/*GNL and its utils*/

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
void	ft_memmove(char *dst, char *src, size_t n);
char	*ft_append(char *line, char *buf, size_t n);
void	ft_shift(char *basin, ssize_t *len, ssize_t cut);
char	*ft_take_nl(char *line, char *basin, ssize_t *len, ssize_t nl);

#endif
