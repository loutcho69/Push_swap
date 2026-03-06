/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:01:01 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/06 04:53:55 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// structure for stack A & B
typedef struct s_list
{
	int				value;
	size_t			index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

// structure for datas
typedef struct s_data
{
	size_t			len_stack;
	size_t			target_min;
	size_t			target_max;
	///////////////CHUNK//////////////////////////////
	size_t			chunk_start;
	size_t			chunk_end;
	size_t			chunk_count;
	size_t			chunk_size;
	//////////////OPPS_COUNT//////////////////////////
	size_t			opps_count;
	size_t			sa_count;
	size_t			sb_count;
	size_t			ss_count;
	size_t			pa_count;
	size_t			pb_count;
	size_t			ra_count;
	size_t			rb_count;
	size_t			rr_count;
	size_t			rra_count;
	size_t			rrb_count;
	size_t			rrr_count;
}					t_data;
////////////////////OPPS/////////////////////////////////////
void				swap_a(t_list **stack_a, t_data *data);
void				swap_b(t_list **stack_b, t_data *data);
void				push_b(t_list **stack_b, t_list **stack_a, t_data *data);
void				push_a(t_list **stack_a, t_list **stack_b, t_data *data);
void				rotate_a(t_list **stack_a, t_data *data);
void				rotate_b(t_list **stack_b, t_data *data);
void				rotate_ab(t_list **stack_a, t_list **stack_b, t_data *data);
void				rev_rotate_a(t_list **stack_a, t_data *data);
void				rev_rotate_b(t_list **stack_b, t_data *data);
void				rev_rotate_ab(t_list **stack_a, t_list **stack_b,
						t_data *data);
/////////////////NODE_UTILS/////////////////////////////////
t_list				*ft_lstnew(int content);
int					count_node(t_list *stack);
void				ft_lstadd_front(t_list **stack, t_list *new_node);
void				ft_lstclear(t_list **lst, int len);
/////////////////ALGO_UTILS////////////////////////////////
size_t				get_max_bit(size_t len);
size_t				my_sqrt(size_t n);
void				rotate_opti(t_list **stack, char c, t_data *data);
void				push_opti(t_list **stack_a, t_list **stack_b, t_data *data);
void				index_sort(t_list **stack, size_t len);
void				simple_sort_three(t_list **stack_a, t_data *data);
void				simple_sort_two(t_list **stack_a, t_data *data);
void				simple_sort_four(t_list **stack_a, t_list **stack_b,
						t_data *data);
void				simple_sort_five(t_list **stack_a, t_list **stack_b,
						t_data *data);
void				simple_sort_generic(t_list **stack_a, t_list **stack_b,
						t_data *data);
////////////////STRCUT_UTILS////////////////////////////////
void				init_values_data(t_list **stack, t_data *data);
void				init_chunk_value(t_data *data);
void				init_target(t_data *data);
#endif