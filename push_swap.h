/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:03:20 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/06 22:33:39 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_opts
{
	int			bench;
	int			strat_forced;
	t_strategy	strategy;
}	t_opts;

/* node / stack utils */
t_list		*node_new(int value);
void		ft_node_add_back(t_list **stack, t_list *new_node);
void		ft_node_add_front(t_list **stack, t_list *new_node);
void		stack_clear(t_list **stack);
size_t		stack_len(t_list *stack);
int			has_duplicate(t_list *stack, int value);

/* parsing / options */
int			parse_input(int argc, char **argv, t_list **stack,
				t_opts *opts, t_data *data);
int			parse_error(t_list **stack, char **tokens);
char		**ft_split(char const *s, char c);
void		free_tokens(char **tokens);
int			sign_checker(const char *s, const char **p);
int			is_token_int(const char *s);
int			is_token_in_int_range(const char *s);
int			is_flag(const char *s);
int			parse_one_flag(const char *s, t_opts *o);
int			set_strategy(t_opts *o, t_strategy s);
void		opts_init(t_opts *o);

/* string / helpers */
int			ft_atoi(const char *s);
int			ft_isdigit(char c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strcmp_10(const char *s1, const char *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);

/* algorithm helpers */
float		disorder(t_list *stack);

/* bench / printing */
int			print_bench(t_data *data, t_opts *opts);

#endif