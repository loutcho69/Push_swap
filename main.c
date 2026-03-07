/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:59:55 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/07 23:05:47 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	flag_dispatcher(t_list **stack_a, t_list **stack_b,
	t_opts *opts, t_data *data)
{
	if (opts->strategy == STRAT_SIMPLE)
		simple_sort(stack_a, stack_b, data);
	else if (opts->strategy == STRAT_MEDIUM)
		medium_sort(stack_a, stack_b, data);
	else if (opts->strategy == STRAT_COMPLEX)
        complex_sort(stack_a, stack_b, data);
	else if (opts->strategy == STRAT_ADAPTIVE)
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
	t_opts	opts;
	t_data	data;
	float	d;

	stack_a = NULL;
	stack_b = NULL;
	parse_input(argc, argv, &stack_a, &opts, &data);
	if (!stack_a)
		return (0);
	d = disorder(stack_a);
	data.disorder = d;
	flag_dispatcher(&stack_a, &stack_b, &opts, &data);
	if (opts.bench)
		print_bench(&data, &opts);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
