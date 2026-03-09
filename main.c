/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:59:55 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/09 01:24:58 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	data;
	float	d;

	stack_a = NULL;
	stack_b = NULL;
	init_values_data(&stack_a, &data);
	parse_input(argc, argv, &stack_a, &data);
	if (!stack_a)
		return (1);
	data.len_stack = count_node(stack_a);
	d = disorder(stack_a);
	data.disorder = d;
	flag_dispatcher(&stack_a, &stack_b, &data);
	if (data.bench)
		print_bench(&data);
	ft_lstclear(&stack_a, data.len_stack);
	stack_b = NULL;
	return (0);
}
