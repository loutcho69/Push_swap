/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:29:17 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/10 01:29:55 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "../push_swap.h"
#include <stdio.h>

static int	parse_opps(char *opps, t_list **stack_a,
	t_list **stack_b, t_data *data)
{
	if (!(ft_strcmp(opps, "sa\n")))
		swap_a(stack_a, data);
	else if (!(ft_strcmp(opps, "sb\n")))
		swap_b(stack_b, data);
	else if (!(ft_strcmp(opps, "ss\n")))
		swap_ab(stack_a, stack_b, data);
	else if (!(ft_strcmp(opps, "pa\n")))
		push_a(stack_a, stack_b, data);
	else if (!(ft_strcmp(opps, "pb\n")))
		push_b(stack_b, stack_a, data);
	else if (!(ft_strcmp(opps, "ra\n")))
		rotate_a(stack_a, data);
	else if (!(ft_strcmp(opps, "rb\n")))
		rotate_b(stack_b, data);
	else if (!(ft_strcmp(opps, "rr\n")))
		rotate_ab(stack_a, stack_b, data);
	else if (!(ft_strcmp(opps, "rra\n")))
		rev_rotate_a(stack_a, data);
	else if (!(ft_strcmp(opps, "rrb\n")))
		rev_rotate_b(stack_b, data);
	else if (!(ft_strcmp(opps, "rrr\n")))
		rev_rotate_ab(stack_a, stack_b, data);
	else if (opps)
		return (0);
	return (1);
}

static int	read_stdout(t_list **stack_a, t_list **stack_b, t_data *data)
{
	char	*opps;

	opps = get_next_line(0);
	while (opps)
	{
		if (!parse_opps(opps, stack_a, stack_b, data))
		{
			write(2, "Error\n", 6);
			free(opps);
			ft_lstclear(stack_a, count_node(*stack_a));
			ft_lstclear(stack_b, count_node(*stack_b));
			return (0);
		}
		free(opps);
		opps = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	data;

	stack_a = NULL;
	stack_b = NULL;
	data_init(&data);
	if (!parse_input_bonus(argc, argv, &stack_a, &data))
		return (1);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!read_stdout(&stack_a, &stack_b, &data))
		return (1);
	if (is_sorted(stack_a, count_node(stack_a))
		&& (!stack_b || count_node(stack_b) == 0))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack_a, count_node(stack_a));
	ft_lstclear(&stack_b, count_node(stack_b));
	return (0);
}
