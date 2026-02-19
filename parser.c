/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:24:17 by btheveny          #+#    #+#             */
/*   Updated: 2026/02/19 17:09:07 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h> //replace printf with our ft_printf do not forget

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

//idk if we need to check if there are zeros before our ints
static int	is_token_int(const char *s)
{
	int	i;

	if (!s || s[0] == '\0')
		return (printf("Error\n"));
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

static int	ft_strcmp_10(const char *a, const char *b)
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

int	is_token_in_int_range(const char *s)
{
	int			sign;
	int			len;
	const char	*limit;

	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (s[0] == 0 && s[1] != '\0') //here theres a pb, I wanted 00 to cause an error but it does not it writes 0
		return (0);
	if (*s == '\0')
        return (0);
	len = 0;
	while (s[len] && ft_isdigit(s[len]))
		len++;
	if (len > 10)
		return (0);
	if (len < 10)
		return (1);
	if (sign == 1)
		limit = "2147483647";
	else
		limit = "2147483648";
	if (ft_strcmp_10(s, limit) > 0)
		return (0);
	return (1);
}

/*static int	has_duplicate(t_list *a, int value)
{

    if (a == NULL)
        return (1);
    while (a)
	{
		if (a->content == value)
			return (0);
		a = a->next;
	}
	return (1);
}*/
void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
static int	parse_error(t_list **a, char **tokens)
{
	if (tokens)
		free_tokens(tokens);
	if (a)
		stack_clear(a);
	write(2, "Error\n", 6);
	return (1);
}

int parse_input(int argc, char **argv, t_list **a)
{
    int i;
    int j;
    int		value;
	char	**tokens;
	t_list	*node;
      
    i = 1;
    j = 0;
    if (argc <= 1)
        return (0);
    if (!a)
		return (0);
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
        printf("Split ok\n");
		if (!tokens || !tokens[0])
			return (parse_error(a, tokens));
		j = 0;
		while (tokens[j])
		{
			if (!is_token_int(tokens[j]))
				return (parse_error(a, tokens));
                printf("is token int ok %d\n", j);
			if (!is_token_in_int_range(tokens[j]))
				return (parse_error(a, tokens));
                printf("is token int range ok %d\n", j);
			value = ft_atoi(tokens[j]);
            printf("atoi ok %d\n", j);
		//	if (has_duplicate(*a, value))
		//		return (parse_error(a, tokens));
        //      printf("has duplicate ok %d\n", j);
			node = node_new(value);
			if (!node)
				return (parse_error(a, tokens));
			ft_lstadd_back(a, node);
            printf("added node to the back ok %d\n", j);
            j++;
		}
        stack_print(*a);
		free_tokens(tokens);
		i++;
	}
	return (0);   
            
        }

/* logiaue du code pour chaque tokens[j] :
           - valider format -> is_int_token(char)
           - according to the subject we only have to take int not long so just check that its between INT_MIN et INT_MAX and then atoi
            -> is token in int range
           - atoi avec pas de risque d'overflow
           - doublon ? si non creer node et ajouter a stack
*/

/*exemple de main*/

int main(int argc, char **argv)
{
    t_list *a;

    a = NULL;
    parse_input(argc, argv, &a);
    return (0);

}
