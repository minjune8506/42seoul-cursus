/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:08:47 by minjkim2          #+#    #+#             */
/*   Updated: 2021/05/10 10:29:09 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			count_word(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (*s == '\0')
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

int			count_ch(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

char		**malloc_error(char **ret, int i)
{
	int		j;

	j = 0;
	while (j < i)
		free(ret[j++]);
	free(ret);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**ret;
	int		count_wd;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	count_wd = count_word(s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * (count_wd + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		j = 0;
		while (*s && *s == c)
			s++;
		if (!(ret[i] = (char *)malloc(sizeof(char) * (count_ch(s, c) + 1))))
			return (malloc_error(ret, i));
		while (*s && *s != c)
			ret[i][j++] = *s++;
		ret[i++][j] = '\0';
	}
	ret[i] = NULL;
	return (ret);
}
