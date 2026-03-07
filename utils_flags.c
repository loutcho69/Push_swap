/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:59:27 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/08 00:15:51 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (ft_strcmp(s, "--bench") == 0)
	{
		data->bench = 1;
		printf("%d", data->bench);
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