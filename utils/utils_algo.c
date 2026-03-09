/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:36:39 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/09 13:52:04 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_max_bit(size_t len)
{
	size_t	count;

	count = 0;
	len = len - 1;
	while (len > 0)
	{
		len >>= 1;
		count++;
	}
	return (count);
}

size_t	my_sqrt(size_t n)
{
	size_t	i;

	i = 1;
	if (n < 5)
		return ((n / 2) + 1);
	while ((i * i) <= n)
		i++;
	return (i - 1);
}

static bool	rotate_check(t_list *stack, size_t target_min, size_t target_max)
{
	size_t	i;
	size_t	j;
	t_list	*tmp;

	tmp = stack;
	i = 0;
	j = 1;
	while (!(stack->index >= target_min && stack->index < target_max))
	{
		stack = stack->next;
		i++;
	}
	while (!(tmp->index >= target_min && tmp->index < target_max))
	{
		tmp = tmp->prev;
		j++;
	}
	if (i < j)
		return (true);
	else
		return (false);
}

void	push_opti(t_list **stack_a, t_list **stack_b, t_data *data)
{
	size_t	index;

	index = data->len_stack - 1;
	while ((*stack_b))
	{
		if (rotate_check((*stack_b), index, (index + 1)))
		{
			while ((*stack_b)->index != index)
				rotate_b(stack_b, data);
		}
		else
			while ((*stack_b)->index != index)
				rev_rotate_b(stack_b, data);
		push_a(stack_a, stack_b, data);
		index--;
	}
}

void	rotate_opti(t_list **stack, char c, t_data *data)
{
	if (c == 'a')
	{
		if (rotate_check((*stack), data->target_min, data->target_max))
			rotate_a(stack, data);
		else
			rev_rotate_a(stack, data);
	}
	if (c == 'b')
	{
		if (rotate_check((*stack), data->target_min, data->target_max))
			rotate_b(stack, data);
		else
			rev_rotate_b(stack, data);
	}
}
