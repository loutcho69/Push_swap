/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:30:53 by btheveny          #+#    #+#             */
/*   Updated: 2026/02/23 13:44:18 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_lstadd_front(t_list **stack, t_list *node)
{
    if (!stack || !node)
        return ;
    node->next = *stack;
    *stack = node;
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strcmp_10(const char *a, const char *b)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (a[i] != b[i])
			return ((unsigned char)a[i] - (unsigned char)b[i]);
		i++;
	}
	return (0);
}

void sign_checker(const char *s, int sign)
{
if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
}