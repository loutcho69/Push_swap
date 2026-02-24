/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:03:20 by btheveny          #+#    #+#             */
/*   Updated: 2026/02/24 17:33:05 by btheveny         ###   ########.fr       */
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
void	ft_lstadd_front(t_list **stack, t_list *node);
void	stack_clear(t_list **stack);
t_list	*ft_lstpop_front(t_list **stack);
char	**ft_split(char const *s, char c);
int		parse_input(int argc, char **argv, t_list **a);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char	*str);
int		ft_atoi(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_isdigit(char c);
void	sign_checker(const char *s);
int		ft_strcmp_10(const char *a, const char *b);
void	free_tokens(char **tokens);
int		parse_error(t_list **a, char **tokens);
size_t  stack_len(t_list *a);
float   disorder(t_list *a);

/* only to debug */
void	stack_print(t_list *stack);

#endif