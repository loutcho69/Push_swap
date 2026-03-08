/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 01:33:55 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/09 00:47:34 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flush(t_buffer *buffer, char c)
{
	if (buffer->index >= BUFFER_SIZE)
	{
		write(2, buffer->res, BUFFER_SIZE);
		buffer->count += BUFFER_SIZE;
		buffer->index = 0;
	}
	buffer->res[buffer->index] = c;
	++buffer->index;
}

void	ft_check_type2(va_list *args, char c, t_buffer *buffer)
{
	unsigned long	tmp;

	if (c == 'p')
	{
		tmp = va_arg(*args, unsigned long);
		if (!tmp)
		{
			ft_putstr_cpy("(nil)", buffer);
			return ;
		}
		ft_putstr_cpy("0x", buffer);
		ft_hexa_cpy(tmp, buffer, "0123456789abcdef");
	}
	else if (c == 'x')
		ft_hexa_cpy(va_arg(*args, unsigned int), buffer, "0123456789abcdef");
	else if (c == 'X')
		ft_hexa_cpy(va_arg(*args, unsigned int), buffer, "0123456789ABCDEF");
	else if (c == 'u')
		ft_putnbr_cpy(va_arg(*args, unsigned int), buffer);
	else if (c == 'f')
   		ft_putfloat_cpy(va_arg(*args, double), 3, buffer);
	else
		ft_flush(buffer, 'p');
}

void	ft_check_type(va_list *args, char c, t_buffer *buffer)
{
	if (c == 'c')
		ft_flush(buffer, va_arg(*args, int));
	else if (c == 'd' || c == 'i')
		ft_putnbr_cpy(va_arg(*args, int), buffer);
	else if (c == 's')
		ft_putstr_cpy(va_arg(*args, char *), buffer);
	else if (c == '%')
		ft_flush(buffer, '%');
	else if (c == 'p' || c == 'x' || c == 'X' || c == 'u' || c == 'f')
		ft_check_type2(args, c, buffer);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	t_buffer	buffer;
	va_list		args;

	i = 0;
	buffer.index = 0;
	buffer.count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			ft_check_type(&args, format[++i], &buffer);
		else
			ft_flush(&buffer, format[i]);
		i++;
	}
	va_end(args);
	write(2, buffer.res, buffer.index);
	return (buffer.index + buffer.count);
}
