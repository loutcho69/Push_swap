/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:29:17 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/07 18:34:35 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "../push_swap.h"
#include <stdio.h>

//pour lutilisation il faut soit rentrer les operations dans lordre dans le terminal soit
// pipe le resultat de notre push swap dans le checker genre
// ./push_swap 3 2 1 5 4 | ./checker 3 2 1 5 4

static int	parse_opps(char *opps, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(opps, "sa\n")))
		sa(stack_a);
	else if (!(ft_strcmp(opps, "sb\n")))
		sb(stack_b);
	else if (!(ft_strcmp(opps, "ss\n")))
		ss(stack_a, stack_b);
	else if (!(ft_strcmp(opps, "pa\n")))
		pa(stack_a, stack_b);
	else if (!(ft_strcmp(opps, "pb\n")))
		pb(stack_a, stack_b);
	else if (!(ft_strcmp(opps, "ra\n")))
		ra(stack_a);
	else if (!(ft_strcmp(opps, "rb\n")))
		rb(stack_b);
	else if (!(ft_strcmp(opps, "rr\n")))
		rr(stack_a, stack_b);
	else if (!(ft_strcmp(opps, "rra\n")))
		rra(stack_a);
	else if (!(ft_strcmp(opps, "rrb\n")))
		rrb(stack_b);
	else if (!(ft_strcmp(opps, "rrr\n")))
		rrr(stack_a, stack_b);
	else if (opps)
		return (0);
	return (1);
}

static int	read_stdout(t_list **stack_a, t_list **stack_b) //je vais renvoyer des int pour savoir si ca marche ou pas
{
	char	*opps;

	opps = get_next_line(0);
	printf("%s\n", opps);
	while (opps)
	{
		if (!parse_opps(opps, stack_a, stack_b))
		{
			printf("Error\n"); //tjrs printf en stderr
			free(opps);
			stack_clear(stack_a);
			stack_clear(stack_b);
			return (0);
		}
		free(opps);
		opps = get_next_line(0);
		printf("%s\n", opps);
	}
	return (1);
}


int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_opts	*opts;
	t_data	*data;

	stack_a = NULL;
	stack_b = NULL;
	(void)opts;
	(void)data;
	parse_input_bonus(argc, argv, stack_a);
	if (!read_stdout(&stack_a, &stack_b))
		return (1);

	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}

