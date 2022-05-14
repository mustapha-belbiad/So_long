/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelbiad <mbelbiad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:32:33 by mbelbiad          #+#    #+#             */
/*   Updated: 2022/05/08 12:01:20 by mbelbiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checke(va_list olya, char vd)
{
	int	plus;

	plus = 0;
	if (vd == 'c')
		plus += ft_putchar(va_arg(olya, int));
	else if (vd == 's')
		plus += ft_putstrr(va_arg(olya, char *));
	else if (vd == 'i' || vd == 'd')
		plus += ft_putnbr(va_arg(olya, int));
	else if (vd == '%')
		plus += ft_putchar('%');
	else
		plus += ft_putchar(vd);
	return (plus);
}

int	ft_printf(const char *vd, ...)
{
	int		i;
	int		plus;
	va_list	olya;

	va_start (olya, vd);
	i = 0;
	plus = 0;
	while (vd[i])
	{
		if (vd[i] == '%')
		{
			i++;
			plus += ft_checke(olya, vd[i]);
			if (vd[i] == '\0')
				break ;
		}
		else
			plus += ft_putchar(vd[i]);
		i++;
	}
	va_end (olya);
	return (plus);
}
