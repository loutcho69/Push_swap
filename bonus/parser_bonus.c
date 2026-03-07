/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:24:17 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/07 19:10:00 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	parse_one_arg(char *arg, t_list **stack)
{
	char	**tokens;
	int		j;
	int		value;
	t_list	*new_node;

	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
		return (parse_error(stack, tokens));
	j = 0;
	while (tokens[j])
	{
		if (!is_token_int(tokens[j]) || !is_token_in_int_range(tokens[j]))
			return (parse_error(stack, tokens));
		value = ft_atoi(tokens[j]);
		if (!has_duplicate(*stack, value))
			return (parse_error(stack, tokens));
		new_node = node_new(value);
		if (!new_node)
			return (parse_error(stack, tokens));
		ft_node_add_back(stack, new_node);
		j++;
	}
	free_tokens(tokens);
	return (1);
}

int	parse_input(int argc, char **argv, t_list **stack,
	t_opts *opts, t_data *data)
{
	int		i;
	size_t	len;

	if (argc <= 1 || !stack || !opts)
		return (0);
	opts_init(opts);
	data_init(data);
	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			if (!parse_one_flag(argv[i], opts))
				return (parse_error(stack, NULL));
		}
		else if (!parse_one_arg(argv[i], stack))
			return (0);
		i++;
	}
	if (*stack)
	{
		len = stack_len(*stack);
		index_sort(stack, len);
	}
	return (0);
}

/* wrapper for bonus checker: expose simpler API */
int	parse_input_bonus(int argc, char **argv, t_list **stack)
{
	t_opts opts;
	t_data data;

	if (!stack)
		return (0);
	opts_init(&opts);
	data_init(&data);
	return (parse_input(argc, argv, stack, &opts, &data));
}
