/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:24:13 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/05 16:29:51 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Pe faire renvoyer 1 ou 0 a cette fonction pour renvoyer une erreur si erreur

void	medium_sort(t_list **stack_a, t_list **stack_b, t_data *data) //je vais pe faire une init de data comme jai une init de opts pour tout mettre a 0 au debut
{
	size_t	i;
	data->chunk_size = my_sqrt(data->len_stack);
	data->chunk_end = data->chunk_size;
	data->chunk_start = 0;
	data->chunk_count = (data->len_stack / data->chunk_size) + 1;
	while (data->chunk_count > 0)
	{
		printf("rentre dans premier while\n");
		i = data->chunk_size;
		while (i > 0 && (*stack_a))
		{
			printf("rentre dans deuxieme while\n");
			if ((size_t)(*stack_a)->index >= data->chunk_start
				&& (size_t)(*stack_a)->index < data->chunk_end) //on a tjrs le pb ici que index est un int faut quon le mette en size_t car on le compare a len dautant que index est jamais negatif
			{
				printf("premier if \n");
				push_b(stack_b, stack_a);
				i--;
			}
			else
				rotate_opti(stack_a, 'a',
					data->chunk_start, data->chunk_end);
		}
		printf("sortie du if\n");
		data->chunk_start = data->chunk_end;
		data->chunk_end = data->chunk_end + data->chunk_size;
		data->chunk_count--; //ok mon hypothese porte sur le chunk_count peut etre je dois pas l init a 0 dans la init_data
	}
	printf("juste avant push opti\n");
	push_opti(stack_a, stack_b, data->len_stack);
}
