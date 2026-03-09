/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 02:38:28 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/09 02:21:12 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ici l indexation du parsing se fait ainsi que  envoie de la len de la satck dans la strcut data

#include "push_swap.h"

void	index_sort(t_list **stack, size_t len)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	int		tmp;

	len1 = len;
	while (len1 > 0)
	{
		i = 0;
		tmp = (*stack)->value;
		len2 = len;
		while (len2 > 0)
		{
			if (tmp > (*stack)->next->value)
				i++;
			len2--;
			(*stack) = (*stack)->next;
		}
		(*stack)->index = i;
		(*stack) = (*stack)->next;
		len1--;
	}
}
