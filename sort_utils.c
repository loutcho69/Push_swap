/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:36:39 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/03 11:57:20 by lobroue          ###   ########.fr       */
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
	while (i * i <= n)
		i++;
	return (i - 1);
}
bool	r_or_rv(t_list *stack, size_t target, size_t len)
{
	size_t i;

	len >>= 1;
	i = 0;
	while (target != stack->value)
	{
		stack = stack->next;
		i++;
	}
	if (i < len)
		return (true);
	else
		return (false);
}