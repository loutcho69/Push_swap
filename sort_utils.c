/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:36:39 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/03 23:05:44 by lobroue          ###   ########.fr       */
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
bool	r_or_rv(size_t target, size_t len)
{
	size_t	i;

	len >>= 1;
	i = 0;
	while (target != i)
		i++;
	if (i < len)
		return (true);
	else
		return (false);
}
static bool	rotate_check(t_list *stack, size_t target_min, size_t target_max)
{
	size_t	i;
	size_t	j;
	t_list	*tmp;

	tmp = stack;
	i = 0;
	j = 1;
	if (target_min < 0)
		target_min = 0;
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
void	push_opti(t_list **stack_a, t_list **stack_b, size_t len)
{
	size_t	index;

	index = len -1;
	while ((*stack_b))
	{
		if (rotate_check((*stack_b), index, (index + 1)))
		{
			while ((*stack_b)->index != index)
				rotate_b(stack_b);
		}
		else
			while ((*stack_b)->index != index)
				rev_rotate_b(stack_b);
		push_a(stack_a, stack_b);
		index--;
	}
}
void	rotate_opti(t_list **stack_a, t_list **stack_b, size_t target_min,
		size_t target_max)
{
	if (rotate_check((*stack_a), target_min, target_max))
		rotate_a(stack_a);
	else
		rev_rotate_a(stack_a);
}
// ici faire que les fonctions soit modulaires
