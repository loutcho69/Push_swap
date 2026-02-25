/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:50:43 by lobroue           #+#    #+#             */
/*   Updated: 2026/02/25 22:59:57 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// tous les utils pour la manipulation de node ici
#include "push_swap.h"

void	ft_lstdelone(t_list *stack, void (*del)(void *))
{
	// Pour del le node et son content
    del(stack->value);
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