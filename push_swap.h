/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:01:01 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/03 18:30:31 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// structure for stack A & B
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

// structure for datas
typedef struct s_data
{
	size_t			len_list;

}					t_data;

t_list				*ft_lstnew(int content);
void				swap_a(t_list **stack_a);
void				swap_b(t_list **stack_b);
void				push_b(t_list **stack_b, t_list **stack_a);
void				push_a(t_list **stack_a, t_list **stack_b);
void				rotate_a(t_list **stack_a);
void    rotate_b(t_list **stack_b);
void    rotate_ab(t_list **stack_a, t_list **stack_b);
void    rev_rotate_a(t_list **stack_a);
void    rev_rotate_b(t_list **stack_b);
void    rev_rotate_ab(t_list **stack_a, t_list **stack_b);
int					count_node(t_list *stack);
void				ft_lstadd_front(t_list **stack, t_list *new_node);
void				index_sort(t_list **stack, size_t len);
void				ft_lstclear(t_list **lst, int len);
size_t				get_max_bit(size_t len);
size_t				my_sqrt(size_t n);
bool	r_or_rv(size_t target, size_t len);


#endif

// il faut que le parsing fasse une indexation pour avoir ca pour les 3 algos( qui nous simplifira la vie et donnera la len de la list)
