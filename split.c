/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelbiad <mbelbiad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:33:47 by mbelbiad          #+#    #+#             */
/*   Updated: 2022/05/08 11:55:48 by mbelbiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_words(const char	*s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	**put_words(char	**str, char	*s, char c)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c && s[i + 1] != c)
			i++;
		if (s[i + 1] == c)
			break ;
		len = i;
		while (s[len] && s[len] != c)
			len++;
		if (s[i] && s[i] != c)
			str[j++] = ft_substr(s, i, len - i);
		i = len;
	}
	if (s[i - 1] == c || s[0] == c)
		return (NULL);
	str[j] = 0;
	return (str);
}

char	**ft_split(char	*s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	return (put_words(str, s, c));
}
