/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelbiad <mbelbiad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:01:27 by mbelbiad          #+#    #+#             */
/*   Updated: 2022/05/08 13:10:02 by mbelbiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	the_perfect_image(t_kky	*kky)
{
	void	*check;
	int		i;
	int		j;

	i = -1;
	while (kky->map[++i] != NULL)
	{
		j = -1;
		while (kky->map[i][++j] != '\0')
		{
			if (kky->map[i][j] == '1')
				wall(kky, i, j);
			if (kky->map[i][j] == '0')
				back_ground(kky, i, j);
			if (kky->map[i][j] == 'C')
				sonic_ring(kky, i, j);
			if (kky->map[i][j] == 'E')
				door(kky, i, j);
		}
	}
	check = mlx_xpm_file_to_image(kky->ptr,
			"maps/sonic_wa9ef.xpm", &kky->y, &kky->x);
	mlx_put_image_to_window(kky->ptr, kky->mlx,
		check, kky->p_x * 50, kky->p_y * 50);
}

int	key_hook(int keycode, t_kky *kky)
{
	if (keycode == 53)
	{
		mlx_destroy_window(kky->ptr, kky->mlx);
		exit(0);
	}
	if (keycode == 2)
		move_right(keycode, kky);
	if (keycode == 13)
		move_up(keycode, kky);
	if (keycode == 1)
		move_down(keycode, kky);
	if (keycode == 0)
		move_left(keycode, kky);
	ft_printf("%d\n", kky->moves);
	return (0);
}

int	ft_close(t_kky *kky)
{
	exit(0);
	mlx_destroy_window(kky->ptr, kky->mlx);
	return (0);
}

void	draw(t_kky *kky)
{
	kky->x = 0;
	kky->y = 0;
	kky->moves = 0;
	while (kky->map[0][kky->y])
		kky->y++;
	while (kky->map[kky->x])
		kky->x++;
	kky->ptr = mlx_init();
	kky->mlx = mlx_new_window(kky->ptr, kky->y * 50, kky->x * 50, "so_long");
	the_perfect_image(kky);
	mlx_key_hook(kky->mlx, key_hook, kky);
	mlx_hook(kky->mlx, 17, 0L, &ft_close, kky);
	mlx_loop(kky->ptr);
}
