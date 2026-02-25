/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:01:01 by lobroue           #+#    #+#             */
/*   Updated: 2026/02/25 22:24:39 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
#define _PUSH_SWAP_H

#include <unistd.h>

//structure for stack A & B
typedef struct s_list
{
    int value;
    struct s_list *next;
    struct s_list *prev;
}           t_list;

//structure for datas
typedef struct s_data
{
    size_t len_list;






}           t_data;

# endif

// il faut que le parsing fasse une indexation pour avoir ca pour les 3 algos( qui nous simplifira la vie et donnera la len de la list)
