/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelbiad <mbelbiad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:00:34 by mbelbiad          #+#    #+#             */
/*   Updated: 2022/05/08 11:42:32 by mbelbiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**check_wall(char	**map)
{
	int	i;
	int	j;

	if (!jenab(map))
	{
		write (1, "map mza3eze3a\n", 15);
		return (0);
	}
	i = 0;
	j = 0;
	while (map[i])
	{
		if (!check_char(map[i]))
			return (0);
		i++;
	}
	return (map);
}

char	**check_map(t_kky *kky)
{
	if (!check_wall(kky->map))
		return (0);
	if (check_characters(kky, 'P') != 1)
	{	
		write (1, "l3aba ghaltine\n", 16);
		return (0);
	}
	if (check_characters(kky, 'C') == 0)
	{
		write (1, "collectible na9sin\n", 20);
		return (0);
	}
	else
		kky->cole = check_characters(kky, 'C');
	if (check_characters(kky, 'E') == 0)
	{
		write (1, "lbab makaynch \n", 16);
		return (0);
	}
	if (!check(kky->map))
		return (0);
	return (kky->map);
}

char	*check(char	**line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[0][j + 1] && line[0][j] == '1')
		j++;
	if (line[i][j] != '\n' && line[i][j] != '1')
	{
		write (1, "se9af khaser\n", 14);
		return (0);
	}
	while (line[i + 1] != '\0')
		i++;
	j = 0;
	while (line[i][j] && line[i][j] == '1')
		j++;
	if (line[i][j] != '\0' && line[i][j] != '1')
	{
		write (1, "l9a3e khaser\n", 14);
		return (0);
	}
	return (line[i]);
}

char	*check_char(char	*line)
{
	int	j;

	j = 0;
	if (!line)
		return (0);
	while (line[j])
	{
		if (line[j] != '0' && line [j] != 'C'
			&& line[j] != 'E' && line[j] != 'P' && line[j] != '1')
		{
			write (1, "makhedamch hadchi\n", 19);
			return (NULL);
		}
		j++;
	}
	return (line);
}

char	**jenab(char **map)
{
	int	i;
	int	j;
	int	g;

	i = 0;
	j = 0;
	g = strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != g)
			return (0);
		if (map[i][0] != '1')
			return (0);
		while (map[i][j])
			j++;
		if (map[i][j - 1] != '1')
			return (0);
		i++;
	}
	return (map);
}
