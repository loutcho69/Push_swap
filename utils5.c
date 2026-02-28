/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:59:27 by btheveny          #+#    #+#             */
/*   Updated: 2026/02/28 15:51:52 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	is_flag(const char *s)
{
	return (s && s[0] == '-' && s[1] == '-');
}

int	set_strategy(t_opts *o, t_strategy s)
{
	if (o->strat_forced && o->strat != s)
		return (0);
	o->strat = s;
	o->strat_forced = 1;
	return (1);
}

int	parse_one_flag(const char *s, t_opts *o)
{
	if (!s || !o)
		return (0);
	if (ft_strcmp(s, "--bench") == 0)
	{
		o->bench = 1;
		return (1);
	}
	if (ft_strcmp(s, "--simple") == 0)
		return (set_strategy(o, STRAT_SIMPLE));
	if (ft_strcmp(s, "--medium") == 0)
		return (set_strategy(o, STRAT_MEDIUM));
	if (ft_strcmp(s, "--complex") == 0)
		return (set_strategy(o, STRAT_COMPLEX));
	if (ft_strcmp(s, "--adaptive") == 0)
		return (set_strategy(o, STRAT_ADAPTIVE));
	return (0);
}

void	opts_init(t_opts *o)
{
	o->bench = 0;
	o->strat_forced = 0;
	o->strat = STRAT_ADAPTIVE;
}

const char	*strat_name(t_strategy strategy)
{
	if (strategy == STRAT_SIMPLE)
		return ("simple");
	if (strategy == STRAT_MEDIUM)
		return ("medium");
	if (strategy == STRAT_COMPLEX)
		return ("complex");
	return ("adaptive");
}
