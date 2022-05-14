/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelbiad <mbelbiad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:33:02 by mbelbiad          #+#    #+#             */
/*   Updated: 2022/05/08 12:01:40 by mbelbiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*wee;

	if (!s)
	{
		free(s);
		return (0);
	}
	slen = ft_strlen(s);
	if (slen < start)
		return (ft_strdup(""));
	i = 0;
	if (slen - start >= len)
		wee = malloc(len + 1);
	else
		wee = malloc(slen - start + 1);
	if (!wee)
		return (NULL);
	ft_strlcpy(wee, (s + start), len + 1);
	return (wee);
}

char	*ft_check(char	*deep)
{
	char	*end;
	int		i;

	i = 0;
	while (deep[i] != '\n' && deep[i])
		i++;
	end = ft_substr(deep, 0, (i + 1));
	if (*end == '\0')
	{
		free(end);
		return (0);
	}
	return (end);
}

char	*ft_update(char	*deep)
{
	char	*swp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (deep[i] != '\n' && deep[i] != '\0')
		i++;
	if (deep[i] == '\n')
		i++;
	swp = malloc((ft_strlen(deep) - i) + 1);
	if (swp == NULL)
		return (NULL);
	while (deep[i] != 0)
	{
		swp[j] = deep[i];
		i++;
		j++;
	}
	swp[j] = '\0';
	free(deep);
	return (swp);
}

char	*ft_line(int fd, char *deep)
{
	char	*box;
	int		i;

	box = malloc(10 + 1);
	i = 1;
	box[0] = '\0';
	while (i != 0 && !ft_strchr(box, '\n'))
	{
		i = read(fd, box, 10);
		if (i == -1)
		{
			free(box);
			return (0);
		}
		box[i] = '\0';
		deep = ft_strjoin(deep, box);
	}
	free(box);
	return (deep);
}

char	*get_next_line(int fd)
{
	static char	*deep;
	char		*end;

	if (fd < 0)
		return (NULL);
	deep = ft_line(fd, deep);
	if (!deep)
		return (NULL);
	end = ft_check(deep);
	deep = ft_update(deep);
	if (!end)
	{
		free(deep);
		deep = NULL;
	}
	return (end);
}
//  int main ()
//  {	
// 	int fd;
// 	char *s;
// 	int i;

// 	i = 0;
// 	fd = open("map", O_RDONLY);
// 	s = "test";
// 	while(s != NULL)
// 	{
// 		s = get_next_line(fd);
// 		if (s == NULL)
// 			break;
// 		printf("%s", s);
// 		i++;
// 	}
// }
