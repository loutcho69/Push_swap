/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:36:39 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/02 08:42:47 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t  get_max_bit(size_t len)
{
    size_t  count;
    count = 0;
    len = len - 1;
    while (len > 0)
    {
        len >>= 1;
        count++;
    }
    return(count);
}
