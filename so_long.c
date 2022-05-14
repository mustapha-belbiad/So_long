/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelbiad <mbelbiad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:33:11 by mbelbiad          #+#    #+#             */
/*   Updated: 2022/05/08 12:08:43 by mbelbiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_characters(t_kky *kky, char p)
{
	int	i;
	int	j;
	int	per;

	i = -1;
	per = 0;
	while (kky->map[++i] != NULL)
	{
		j = -1;
		while (kky->map[i][++j])
		{
			if (kky->map[i][j] == p)
			{
				if (p == 'P')
				{
					kky->p_x = j;
					kky->p_y = i;
					kky->map[i][j] = '0';
				}
				per++;
			}
		}
	}
	return (per);
}

char	*map_name(char *map)
{
	int		i;
	char	*check;
	char	*ber;

	i = 0;
	ber = ".ber";
	check = ft_strchr(map, '.');
	if (ft_strlen(check) != ft_strlen(ber))
	{
		ft_putstrr("error in map name\n");
		return (0);
	}
	while (ber[i])
	{
		if (check[i] != ber[i])
		{
			ft_putstrr("error in map name\n");
			return (0);
		}
		i++;
	}
	return (map);
}

char	*map(char *av[])
{
	int		fd;
	char	*w;
	char	*s;
	int		i;

	i = -1;
	w = NULL;
	fd = open(av[1], O_RDONLY);
	while (++i > -1)
	{
		s = get_next_line(fd);
		if (s)
		{
			w = ft_strjoin(w, s);
			free(s);
		}
		else
			break ;
	}
	return (w);
}

int	main(int ac, char *av[])
{	
	char	*w;
	t_kky	*a;

	if (ac == 2)
	{
		if (!map_name(av[1]))
			return (0);
		a = malloc(sizeof(t_kky));
		w = map(av);
		a->map = ft_split(w, '\n');
		if (a->map == NULL)
		{
			ft_putstrr("map mza3eze3a\n");
			return (0);
		}
		if (!check_map(a))
			return (0);
		draw(a);
	}
	ft_putstrr("EROR404\n");
}
