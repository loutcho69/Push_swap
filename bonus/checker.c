/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:29:17 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/05 18:54:08 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*TODO : le checker doit lire les instructions donnes par notre push swap,
il doit essayer de trier la stack et de verifier si apres les operations
la stack est effectivement triee
si oui OK
Else KO
Sur le principe on a pas grande chose de plus a faire faut juste
etre capable de lire sur stdout et ensuite de faire les operations sur notre stack
et une fois que c;est lu on fait les operations sur notre stack et on regarde les index
si les index sont dans l'ordre alors on est bons*/


int	read_stdout(t_list **stack_a, t_list **stack_b) //je vais renvoyer des int pour savoir si ca marche ou pas
{
	char	*opps;

	opps = get_next_line(0);
	while (opps)
	{
		if (!parse_opps(opps, stack_a, stack_b))
		{
			ft_printf("Error\n", 2); //tjrs printf en stderr
			free(opps);
			stack_clear(stack_a);
			stack_clear(stack_b);
			return (0);
		}
		free(opps);
		opps = get_next_line(0);
	}
}




