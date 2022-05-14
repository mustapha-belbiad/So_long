/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelbiad <mbelbiad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 21:16:56 by mbelbiad          #+#    #+#             */
/*   Updated: 2022/05/07 21:17:00 by mbelbiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putstrr(char *s)
{
	int	ko;

	if (!s)
		return (ft_putstrr("(null)"));
	ko = ft_strlen(s);
	write(1, s, ko);
	return (ko);
}

int	ft_putchar(char wr)
{
	write(1, &wr, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	unsigned int	num;
	int				i;

	i = 0;
	num = nb;
	if (nb < 0)
	{
		i += ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
	{
		i += ft_putnbr(num / 10);
		num = num % 10;
	}
	if (num < 10)
	{
		i += ft_putchar(num + 48);
	}
	return (i);
}
