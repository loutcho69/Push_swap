/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:29:17 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/07 18:14:09 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "../push_swap.h"
#include <stdio.h>

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

static int build_stack_from_array(t_list **stack, int *arr, size_t n)
{
	size_t  i;
	t_list  *node;

	*stack = NULL;
	i = 0;
	while (i < n)
	{
		node = node_new(arr[i]);
		if (!node)
		{
			stack_clear(stack);
			return (0); /* échec allocation */
		}
		/* pour ce checker simple on assigne l'index séquentiellement */
		node->index = (int)i;
		ft_node_add_back(stack, node);
		i++;
	}
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


int main(void)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*cur;
	int		arr[] = {1, 2, 3};
	int		ok;

	stack_a = NULL;
	stack_b = NULL;
	cur = stack_a;

	if (!build_stack_from_array(&stack_a, arr, 3))
		return (1);
	if (!read_stdout(&stack_a, &stack_b))
		return (1);

	cur = stack_a;
	ok = 1;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
		{
			ok = 0;
			break ;
		}
		cur = cur->next;
	}
	if (ok)
		printf("OK\n");
	else
		printf("KO\n");

	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}

