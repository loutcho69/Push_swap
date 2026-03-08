/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:43:12 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/08 04:43:44 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	neg_counter;
	int	result;

	i = 0;
	neg_counter = 0;
	result = 0;
	while ((s[i] && (s[i] >= 9 && s[i] <= 13)) || (s[i] == ' '))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg_counter += 1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result *= 10;
		result += s[i] - '0';
		i++;
	}
	if ((neg_counter % 2) == 1)
		result = -result;
	return (result);
}

// int	has_duplicate(t_list *stack, int value)
// {
// 	t_list	*head;
// 	t_list	*cur;

// 	if (stack == NULL)
// 		return (1);
// 	head = stack;
// 	cur = head;
// 	while (cur != NULL)
// 	{
// 		if (cur->value == value)
// 			return (0);
// 		cur = cur->next;
// 		if (cur == head)
// 			break ;
// 	}
// 	return (1);
// }
int	has_duplicate(t_list *stack, int value)
{
	t_list	*head;
	t_list	*cur;

	if (stack == NULL)
		return (0);
	head = stack;
	cur = head;
	while (cur != NULL)
	{
		if (cur->value == value)
			return (1);
		cur = cur->next;
		if (cur == head)
			break ;
	}
	return (0);
}

int	is_token_in_int_range(const char *s)
{
	int			sign;
	int			len;
	const char	*p;
	const char	*limit;

	if (!s)
		return (0);
	sign = sign_checker(s, &p);
	if (*p == '\0')
		return (0);
	if (p[0] == '0' && p[1] != '\0')
		return (0);
	len = 0;
	while (p[len] && ft_isdigit(p[len]))
		len++;
	if (len != 10)
		return (len < 10);
	if (sign == 1)
		limit = "2147483647";
	else
		limit = "2147483648";
	if (ft_strcmp_10(p, limit) > 0)
		return (0);
	return (1);
}

int	is_token_int(const char *s)
{
	int	i;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}