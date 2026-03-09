/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:30:53 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/09 23:35:19 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	sign_checker(const char *s, const char **p)
{
	int	sign;

	sign = 1;
	*p = s;
	if (**p == '+' || **p == '-')
	{
		if (**p == '-')
			sign = -1;
		(*p)++;
	}
	return (sign);
}

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	parse_error(t_list **stack, char **tokens)
{
	if (tokens)
		free_tokens(tokens);
	if (stack)
		ft_lstclear(stack, count_node((*stack)));
	write(2, "Error\n", 6);
	return (0);
}
