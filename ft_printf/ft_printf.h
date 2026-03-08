/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobroue <lobroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:31:59 by lobroue           #+#    #+#             */
/*   Updated: 2026/03/09 00:21:29 by lobroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUFFER_SIZE 4096

# include <stdarg.h>
# include <unistd.h>

typedef struct s_buffer
{
	size_t	count;
	size_t	index;
	char	res[BUFFER_SIZE];
}			t_buffer;

int			ft_printf(const char *format, ...);
void		ft_check_type2(va_list *args, char c, t_buffer *buffer);
void		ft_check_type(va_list *args, char c, t_buffer *buffer);
void		ft_flush(t_buffer *buffer, char c);
void		ft_putnbr_cpy(long nb, t_buffer *buffer);
void		ft_putstr_cpy(char *string, t_buffer *buffer);
void		ft_put_hexa(unsigned long nb, char *digit, t_buffer *buffer);
void		ft_hexa_cpy(unsigned long nb, t_buffer *buffer, char *digit);
void	ft_putfloat_cpy(double n, int precision, t_buffer *buffer);


#endif