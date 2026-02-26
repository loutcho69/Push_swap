/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:01:01 by lobroue           #+#    #+#             */
/*   Updated: 2026/02/26 02:03:55 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
#define _PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//structure for stack A & B
typedef struct s_list
{
    int value;
    struct s_list *next;
    struct s_list *prev;
}           t_list;

//structure for datas
typedef struct s_data
{
    size_t len_list;






}           t_data;

t_list	*ft_lstnew(int content);
void    swap_a(t_list *stack_a);
void    swap_b(t_list *stack_b);
void    push_b(t_list   *stack_a, t_list *stack_b);
void    push_a(t_list   *stack_a, t_list *stack_b);
void    rotate_a(t_list *stack_a);
void	ft_lstdelone(t_list *stack);
int	count_node(t_list *stack);
void	ft_lstadd_front(t_list **stack, t_list *new_node);
t_list	*lstcpy(t_list *node);


# endif

// il faut que le parsing fasse une indexation pour avoir ca pour les 3 algos( qui nous simplifira la vie et donnera la len de la list)
