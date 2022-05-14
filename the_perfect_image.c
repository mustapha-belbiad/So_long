/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_perfect_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelbiad <mbelbiad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:24:54 by mbelbiad          #+#    #+#             */
/*   Updated: 2022/05/08 13:14:44 by mbelbiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall(t_kky *kky, int i, int j)
{
	void	*check;

	check = mlx_xpm_file_to_image(kky->ptr, "maps/wall2.xpm", &kky->y, &kky->x);
	mlx_put_image_to_window(kky->ptr, kky->mlx, check, j * 50, i * 50);
}

void	back_ground(t_kky *kky, int i, int j)
{
	void	*check;

	check = mlx_xpm_file_to_image(kky->ptr, "maps/back.xpm", &kky->y, &kky->x);
	mlx_put_image_to_window(kky->ptr, kky->mlx, check, j * 50, i * 50);
}

void	sonic_ring(t_kky *kky, int i, int j)
{
	void	*check;

	check = mlx_xpm_file_to_image(kky->ptr, "maps/back.xpm", &kky->y, &kky->x);
	mlx_put_image_to_window(kky->ptr, kky->mlx, check, j * 50, i * 50);
	check = mlx_xpm_file_to_image(kky->ptr,
			"maps/sonic_ring.xpm", &kky->y, &kky->x);
	mlx_put_image_to_window(kky->ptr, kky->mlx, check, j * 50, i * 50);
}

void	door(t_kky *kky, int i, int j)
{
	void	*check;

	check = mlx_xpm_file_to_image(kky->ptr, "maps/back.xpm", &kky->y, &kky->x);
	mlx_put_image_to_window(kky->ptr, kky->mlx, check, j * 50, i * 50);
	check = mlx_xpm_file_to_image(kky->ptr, "maps/poor.xpm", &kky->y, &kky->x);
	mlx_put_image_to_window(kky->ptr, kky->mlx, check, j * 50, i * 50);
}
