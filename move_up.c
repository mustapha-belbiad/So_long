/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelbiad <mbelbiad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:34:08 by mbelbiad          #+#    #+#             */
/*   Updated: 2022/05/08 11:29:43 by mbelbiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(int keycode, t_kky *kky)
{
	kky->code = keycode;
	if (kky->cole == 0 && kky->map[kky->p_y - 1][kky->p_x] == 'E')
		exit(0);
	if (kky->map[kky->p_y - 1][kky->p_x] != '1'
		&& kky->map[kky->p_y - 1][kky->p_x] != 'E')
	{
		if (kky->map[kky->p_y - 1][kky->p_x] == 'C')
		{
			kky->map[kky->p_y - 1][kky->p_x] = '0';
			kky->cole--;
		}
		kky->p_y--;
		kky->moves++;
	}
	the_perfect_image(kky);
}
