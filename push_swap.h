/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:01:01 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/09 13:39:38 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	size_t			index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_data
{
	size_t			len_stack;
	float			disorder;
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
	///////////FLAGS/////////////////////////////////
	int				bench;
	int				strat_forced;
	t_strategy		strategy;
}					t_data;
////////////////////PARSING//////////////////////////////////
int			parse_input(int argc, char **argv, t_list **stack, t_data *data);
int			parse_error(t_list **stack, char **tokens);
char		**ft_split(char const *s, char c);
void		free_tokens(char **tokens);
int			sign_checker(const char *s, const char **p);
int			is_token_int(const char *s);
int			is_token_in_int_range(const char *s);
int			is_flag(const char *s);
int			parse_one_flag(const char *s, t_data *data);
int			set_strategy(t_data *data, t_strategy s);
void		opts_init(t_data *data);
void		flag_dispatcher(t_list **stack_a, t_list **stack_b, t_data *data);
int			is_sorted(t_list *stack, size_t len);

////////////////////OPPS/////////////////////////////////////
void		swap_a(t_list **stack_a, t_data *data);
void		swap_b(t_list **stack_b, t_data *data);
void		push_b(t_list **stack_b, t_list **stack_a, t_data *data);
void		push_a(t_list **stack_a, t_list **stack_b, t_data *data);
void		rotate_a(t_list **stack_a, t_data *data);
void		rotate_b(t_list **stack_b, t_data *data);
void		rotate_ab(t_list **stack_a, t_list **stack_b, t_data *data);
void		rev_rotate_a(t_list **stack_a, t_data *data);
void		rev_rotate_b(t_list **stack_b, t_data *data);
void		rev_rotate_ab(t_list **stack_a, t_list **stack_b,
				t_data *data);
/////////////////ALGO///////////////////////////////////////
void		simple_sort(t_list **stack_a, t_list **stack_b, t_data *data);
void		medium_sort(t_list **stack_a, t_list **stack_b, t_data *data);
void		complex_sort(t_list **stack_a, t_list **stack_b, t_data *data);
/////////////////STR_UTILS//////////////////////////////////
int			ft_atoi(const char *s);
int			ft_isdigit(char c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strcmp_10(const char *s1, const char *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
/////////////////NODE_UTILS/////////////////////////////////
t_list		*ft_lstnew(int content);
int			count_node(t_list *stack);
void		ft_lstadd_front(t_list **stack, t_list *new_node);
void		ft_lstadd_back(t_list **stack, t_list *new_node);
void		ft_lstclear(t_list **lst, int len);
int			has_duplicate(t_list *stack, int value);
/////////////////ALGO_UTILS////////////////////////////////
size_t		get_max_bit(size_t len);
size_t		my_sqrt(size_t n);
void		rotate_opti(t_list **stack, char c, t_data *data);
void		push_opti(t_list **stack_a, t_list **stack_b, t_data *data);
void		index_sort(t_list **stack, size_t len);
void		simple_sort_three(t_list **stack_a, t_data *data);
void		simple_sort_two(t_list **stack_a, t_data *data);
void		simple_sort_four(t_list **stack_a, t_list **stack_b,
				t_data *data);
void		simple_sort_five(t_list **stack_a, t_list **stack_b,
				t_data *data);
void		simple_sort_generic(t_list **stack_a, t_list **stack_b,
				t_data *data);
////////////////STRCUT_UTILS////////////////////////////////
void		init_values_data(t_list **stack, t_data *data);
void		init_chunk_value(t_data *data);
void		init_target(t_data *data);
void		init_other(t_data *data);

/* algorithm helpers */
float		disorder(t_list *stack);

/* bench / printing */
void		print_bench(t_data *data);

#endif
