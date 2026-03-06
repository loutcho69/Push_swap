/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:20:28 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/06 22:19:34 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_nth_content(t_list *stack, size_t i)
{
	size_t	k;

	k = 0;
	if (!stack)
		return (0);
	while (k < i)
	{
		stack = stack->next;
		k++;
		if (!stack)
			return (0);
	}
	return (stack->value);
}

size_t	stack_len(t_list *stack)
{
	size_t	len;
	t_list	*head;

	if (!stack)
		return (0);
	head = stack;
	len = 1;
	while (stack->next && stack->next != head)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

static void	count_mistakes_and_pairs(float *mistakes,
	float *total_pairs, size_t len, t_list *stack)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			(*total_pairs)++;
			if (get_nth_content(stack, i) > get_nth_content(stack, j))
				(*mistakes)++;
			j++;
		}
		i++;
	}
}

float	disorder(t_list *stack)
{
	float	mistakes;
	float	total_pairs;
	size_t	len;
	float	result;

	if (!stack)
		return (0.0f);
	total_pairs = 0;
	mistakes = 0;
	len = stack_len(stack);
	if (len < 2)
		return (0.0f);
	count_mistakes_and_pairs(&mistakes, &total_pairs, len, stack);
	result = mistakes / total_pairs;
	return (result);
}
