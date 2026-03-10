/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:59:27 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/10 14:01:48 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flag_dispatcher(t_list **stack_a, t_list **stack_b, t_data *data)
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

int	is_flag(const char *s)
{
	return (s && s[0] == '-' && s[1] == '-');
}

int	set_strategy(t_data *data, t_strategy s)
{
	if (data->strat_forced)
		return (0);
	data->strategy = s;
	data->strat_forced = 1;
	return (1);
}

int	parse_one_flag(const char *s, t_data *data)
{
	if (!s || !data)
		return (0);
	if (ft_strcmp(s, "--bench") == 0 && data->bench != 1)
	{
		data->bench = 1;
		return (1);
	}
	if (ft_strcmp(s, "--simple") == 0)
		return (set_strategy(data, STRAT_SIMPLE));
	if (ft_strcmp(s, "--medium") == 0)
		return (set_strategy(data, STRAT_MEDIUM));
	if (ft_strcmp(s, "--complex") == 0)
		return (set_strategy(data, STRAT_COMPLEX));
	if (ft_strcmp(s, "--adaptive") == 0)
		return (set_strategy(data, STRAT_ADAPTIVE));
	return (0);
}
