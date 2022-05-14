/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelbiad <mbelbiad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:33:21 by mbelbiad          #+#    #+#             */
/*   Updated: 2022/05/08 12:48:18 by mbelbiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>

typedef struct s_so_long
{
	void	*ptr;
	void	*mlx;
	char	**map;
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		cole;
	int		code;
	int		moves;
}	t_kky;

char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_check(char *deep);
char	*ft_update(char *deep);
char	*get_next_line(int fd);
char	*ft_strchr(const char	*s, int c);
int		ft_strlen(const char *s);
char	*ft_strdup(char	*s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char	*s, char c);
char	*check_char(char *line);
char	**check_wall(char **map);
char	**check_map(t_kky *kky);
char	*check(char **line);
char	**jenab(char **map);
void	draw(t_kky *a);
int		check_characters(t_kky *kky, char p);
void	move_right(int keycode, t_kky *kky);
void	the_perfect_image(t_kky *kky);
void	move_up(int keycode, t_kky *kky);
void	move_down(int keycode, t_kky *kky);
void	move_left(int keycode, t_kky *kky);
int		ft_printf(const char *vd, ...);
int		ft_putstrr(char *s);
int		ft_checke(va_list olya, char vd);
int		ft_putchar(char wr);
int		ft_putnbr(int nb);
void	wall(t_kky *kky, int i, int j);
void	back_ground(t_kky *kky, int i, int j);
void	sonic_ring(t_kky *kky, int i, int j);
void	door(t_kky *kky, int i, int j);
char	*map_name(char *map);

#endif
