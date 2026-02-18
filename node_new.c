/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:04:52 by btheveny          #+#    #+#             */
/*   Updated: 2026/02/18 14:14:00 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list *node_new(int value)
{
    t_list *node;

    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->content = value;
    node->next = NULL;
    return (node);
}