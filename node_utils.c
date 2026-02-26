/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:50:43 by lobroue           #+#    #+#             */
/*   Updated: 2026/02/26 02:07:00 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// tous les utils pour la manipulation de node ici
#include "push_swap.h"

void	ft_lstdelone(t_list *stack)
{
	// Pour del le node et son content et relier ceux autour entre eux
    free(stack->value);
	free(stack);
}

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
	if (!stack || !new_node)
		return ;
	new_node->next = *stack;
	*stack = new_node;
}
t_list	*lstcpy(t_list *node)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res = node;
	return (res);
}
