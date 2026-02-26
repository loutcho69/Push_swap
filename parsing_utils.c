/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:12:10 by lobroue           #+#    #+#             */
/*   Updated: 2026/02/26 02:00:25 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// tous les utilitaire qui servent a parsing.c (comme atoi ou split)

#include "push_swap.c"

t_list	*ft_lstnew(int content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->value = content;
	return (res);
}
