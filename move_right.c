/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelbiad <mbelbiad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:04:28 by mbelbiad          #+#    #+#             */
/*   Updated: 2022/05/08 11:27:57 by mbelbiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(int keycode, t_kky *kky)
{
	kky->code = keycode;
	if (kky->cole == 0 && kky->map[kky->p_y][kky->p_x + 1] == 'E')
		exit(0);
	if (kky->map[kky->p_y][kky->p_x + 1] != '1'
		&& kky->map[kky->p_y][kky->p_x + 1] != 'E')
	{
		if (kky->map[kky->p_y][kky->p_x + 1] == 'C')
		{
			kky->map[kky->p_y][kky->p_x + 1] = '0';
			kky->cole--;
		}
		kky->p_x++;
		kky->moves++;
	}
	the_perfect_image(kky);
}
