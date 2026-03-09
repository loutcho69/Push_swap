/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:31:40 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/09 13:50:33 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_cpy(long nb, t_buffer *buffer)
{
	if (nb < 0)
	{
		ft_flush(buffer, '-');
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr_cpy(nb / 10, buffer);
	ft_flush(buffer, ((nb % 10) + '0'));
}

void	ft_putstr_cpy(char *string, t_buffer *buffer)
{
	int	c;

	if (!string)
		string = "(null)";
	c = 0;
	while (string[c])
		ft_flush(buffer, string[c++]);
}

void	ft_put_hexa(unsigned long nb, char *digit, t_buffer *buffer)
{
	if (nb >= 16)
		ft_put_hexa(nb / 16, digit, buffer);
	ft_flush(buffer, digit[nb % 16]);
}

void	ft_hexa_cpy(unsigned long nb, t_buffer *buffer, char *digit)
{
	if (nb == 0)
	{
		ft_flush(buffer, '0');
		return ;
	}
	ft_put_hexa(nb, digit, buffer);
}

void	ft_putfloat_cpy(double n, int precision, t_buffer *buffer)
{
	long	int_part;
	long	dec_part;
	double	mult;
	int		i;

	if (n < 0)
	{
		ft_flush(buffer, '-');
		n = -n;
	}
	int_part = (long)n;
	ft_putnbr_cpy(int_part, buffer);
	ft_flush(buffer, '.');
	mult = 1;
	i = 0;
	while (i < precision)
	{
		mult *= 10;
		i++;
	}
	dec_part = (long)((n - int_part) * mult);
	ft_putnbr_cpy(dec_part, buffer);
}
