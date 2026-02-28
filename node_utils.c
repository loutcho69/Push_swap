/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:50:43 by lobroue           #+#    #+#             */
/*   Updated: 2026/02/28 03:09:26 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// tous les utils pour la manipulation de node ici
#include "push_swap.h"


int	count_node(t_list *stack)
{
	size_t	count;
    t_list *tmp;

	count = 0;
	while (tmp->value != tmp->next->value)
	{
		++count;
		tmp = tmp->next;
	}
    // ici c est return count ou count +1 jsp??
	return (count);
}
void	ft_lstadd_front(t_list **stack, t_list *new_node)
{
	printf("addfront appelée, stack: %p, new_node: %p\n", *stack, new_node);
	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		(*stack)->next = (*stack);
		(*stack)->prev = (*stack);
	}
	else
	{
		new_node->prev = (*stack)->prev;
		new_node->next = *stack;
		(*stack)->prev->next = new_node;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

t_list	*ft_lstnew(int content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->prev = res;
	res->next = res;
	res->value = content;
	return (res);
}

