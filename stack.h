/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:03:20 by btheveny          #+#    #+#             */
/*   Updated: 2026/02/19 16:23:31 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

t_list	*node_new(int value);
void	stack_push_front(t_list **stack, t_list *node);
void	stack_clear(t_list **stack);
t_list *stack_pop_front(t_list **stack);
char	**ft_split(char const *s, char c);
int parse_input(int argc, char **argv, t_list **a);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char	*str);
int	ft_atoi(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);

/* debug only */
void	stack_print(t_list *stack);

#endif