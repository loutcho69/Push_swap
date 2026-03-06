/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:36:39 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/06 02:14:49 by lobroue          ###   ########.fr       */
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
void	rotate_opti(t_list **stack, char c, size_t target_min,
		size_t target_max)
{
	if (c == 'a')
    {
        if (rotate_check((*stack), target_min, target_max))
            rotate_a(stack);
        else
            rev_rotate_a(stack);
    }
    if (c == 'b')
    {
        if (rotate_check((*stack), target_min, target_max))
            rotate_b(stack);
        else
            rev_rotate_b(stack);
    }
}

void	simple_sort_three(t_list **stack_a)
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
		swap_a(stack_a);
	else if (a > b && b > c)
	{
		swap_a(stack_a);
		rev_rotate_a(stack_a);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack_a);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (a < b && b > c && a > c)
		rev_rotate_a(stack_a);
}
void	simple_sort_two(t_list **stack_a)
{
	if((*stack_a)->index == 0)
		return;
	else
		swap_a(stack_a);
}

void	simple_sort_five(t_list **stack_a, t_list **stack_b)
{
	size_t	min;

	min = 0;
	while(min < 2)
        {
            while((*stack_a)->index != min)
                rotate_opti(stack_a, 'a', min,(min +1));
            push_b(stack_b, stack_a);
            min++;
        }
	simple_sort_three(stack_a);
	while(min != 0)
        {
            push_a(stack_a, stack_b);
            min--;
        }
}
// ici faire que les fonctions soit modulaires
