/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:59:55 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/08 01:00:15 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	flag_dispatcher(t_list **stack_a, t_list **stack_b ,t_data *data)
{
	if (data->strategy == STRAT_SIMPLE)
		simple_sort(stack_a, stack_b, data);
	else if (data->strategy == STRAT_MEDIUM)
		medium_sort(stack_a, stack_b, data);
	else if (data->strategy == STRAT_COMPLEX)
        complex_sort(stack_a, stack_b, data);
	else if (data->strategy == STRAT_ADAPTIVE)
	{
		if (data->disorder < 0.2f)
			simple_sort(stack_a, stack_b, data);
		else if (data->disorder < 0.5f)
			medium_sort(stack_a, stack_b, data);
		else
			complex_sort(stack_a, stack_b, data);
	}
}

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
	data.len_stack = count_node(stack_a);
	if (!stack_a)
		return (write(2,"Error\n",6));
	d = disorder(stack_a);
	data.disorder = d;
	flag_dispatcher(&stack_a, &stack_b, &data);
	if (data.bench)
		print_bench(&data);
	ft_lstclear(&stack_a, data.len_stack);
	stack_b = NULL;
	return (0);
}
