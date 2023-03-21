/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:44:40 by samartin          #+#    #+#             */
/*   Updated: 2022/12/02 15:39:24 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prints.h"

static unsigned int	process_data(const char ftype, va_list f_args)
{
	unsigned int	chrs_wrtn;

	if (ftype == 'c')
		chrs_wrtn = pf_putchar(va_arg(f_args, int));
	else if (ftype == 's')
		chrs_wrtn = pf_putstr(va_arg(f_args, char *));
	else if (ftype == 'p')
		chrs_wrtn = pf_putaddr(va_arg(f_args, void *));
	else if (ftype == 'd' || ftype == 'i')
		chrs_wrtn = pf_putint(va_arg(f_args, int), 's');
	else if (ftype == 'u')
		chrs_wrtn = pf_putint(va_arg(f_args, int), 'u');
	else if (ftype == 'x')
		chrs_wrtn = pf_puthex(va_arg(f_args, unsigned int), "0123456789abcdef");
	else if (ftype == 'X')
		chrs_wrtn = pf_puthex(va_arg(f_args, unsigned int), "0123456789ABCDEF");
	else
		chrs_wrtn = pf_putchar((int)ftype);
	return (chrs_wrtn);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	i;
	unsigned int	chr_cnt;
	va_list			f_args;

	va_start(f_args, format);
	i = 0;
	chr_cnt = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			chr_cnt += process_data(format[i + 1], f_args);
			i++;
		}
		else
		{
			write (1, &format[i], 1);
			chr_cnt++;
		}
		i++;
	}
	va_end(f_args);
	return ((int)chr_cnt);
}
