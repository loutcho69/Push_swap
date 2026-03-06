/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:36:39 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/06 04:16:45 by lobroue          ###   ########.fr       */
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

void	simple_sort_three(t_list **stack_a, t_data *data)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	c = (*stack_a)->next->next->index;
	if (a < b && b < c)
		return ;
	if (a > b && b < c && a < c)
		swap_a(stack_a, data);
	else if (a > b && b > c)
	{
		swap_a(stack_a, data);
		rev_rotate_a(stack_a, data);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack_a, data);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack_a, data);
		rotate_a(stack_a, data);
	}
	else if (a < b && b > c && a > c)
		rev_rotate_a(stack_a, data);
}
void	simple_sort_two(t_list **stack_a, t_data *data)
{
	if ((*stack_a)->index == 0)
		return ;
	else
		swap_a(stack_a, data);
}

void	simple_sort_five(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while (data->target_min < 2)
	{
		while ((*stack_a)->index != data->target_min)
			rotate_opti(stack_a, 'a', data);
		push_b(stack_b, stack_a, data);
		data->target_min++;
		data->target_max++;
	}
	simple_sort_three(stack_a, data);
	while (data->target_min != 0)
	{
		push_a(stack_a, stack_b, data);
		data->target_min--;
	}
}
// ici faire que les fonctions soit modulaires
