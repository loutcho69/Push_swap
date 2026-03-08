/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:31:40 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/08 01:16:47 by lobroue          ###   ########.fr       */
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

void	ft_cpy_char(int c, t_buffer *buffer)
{
	ft_flush(buffer, (char)c);
}
