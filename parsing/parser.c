/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:08:44 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/09 13:51:49 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_token(char *token, t_list **stack, char **tokens)
{
	int		value;
	t_list	*new_node;

	if (!is_token_int(token) || !is_token_in_int_range(token))
		return (parse_error(stack, tokens));
	value = ft_atoi(token);
	if (has_duplicate(*stack, value))
		return (parse_error(stack, tokens));
	new_node = ft_lstnew(value);
	if (!new_node)
		return (parse_error(stack, tokens));
	ft_lstadd_back(stack, new_node);
	return (1);
}

static int	parse_one_arg(char *arg, t_list **stack)
{
	char	**tokens;
	int		j;

	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
		return (parse_error(stack, tokens), 0);
	j = 0;
	while (tokens[j])
	{
		if (!parse_token(tokens[j], stack, tokens))
			return (0);
		j++;
	}
	free_tokens(tokens);
	return (1);
}

int	parse_input(int argc, char **argv, t_list **stack, t_data *data)
{
	int		i;

	if (argc <= 1 || !stack)
		return (0);
	i = 1;
	init_other(data);
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			if (!parse_one_flag(argv[i], data))
				return (parse_error(stack, NULL));
		}
		else if (!parse_one_arg(argv[i], stack))
			return (0);
		i++;
	}
	init_values_data(stack, data);
	if (*stack)
		index_sort(stack, data->len_stack);
	return (0);
}
