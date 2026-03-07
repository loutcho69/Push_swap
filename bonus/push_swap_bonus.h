/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:44:42 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/07 20:43:25 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*tmporary opps*/

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
# include <stdlib.h>
# include <unistd.h>
# include "../push_swap.h"

/*GNL and its utils*/

char	*get_next_line(int fd);
//size_t	ft_strlen(char *s);
void	ft_memmove(char *dst, char *src, size_t n);
char	*ft_append(char *line, char *buf, size_t n);
void	ft_shift(char *basin, ssize_t *len, ssize_t cut);
char	*ft_take_nl(char *line, char *basin, ssize_t *len, ssize_t nl);

/* temporary prototypes for ops in bonus/opps/opps.c */
void	push_a(t_list **stack_a, t_list **stack_b, t_data *data);
void	push_b(t_list **stack_b, t_list **stack_a, t_data *data);
void	rev_rotate_a(t_list **stack_a, t_data *data);
void	rev_rotate_b(t_list **stack_b, t_data *data);
void	rev_rotate_ab(t_list **stack_a, t_list **stack_b, t_data *data);
void	rotate_a(t_list **stack_a, t_data *data);
void	rotate_b(t_list **stack_b, t_data *data);
void	rotate_ab(t_list **stack_a, t_list **stack_b, t_data *data);
void	swap_a(t_list **stack_a, t_data *data);
void	swap_b(t_list **stack_b, t_data *data);
void	swap_ab(t_list **stack_a, t_list **stack_b, t_data *data);
void	init_values_data(t_list **stack, t_data *data);
void	index_sort(t_list **stack, size_t len);

/* bonus parser wrapper */
// int	parse_input_bonus(int argc, char **argv, t_list **stack);
int	parse_input(int argc, char **argv, t_list **stack,
	t_opts *opts, t_data *data);

#endif
