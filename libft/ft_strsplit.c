/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 23:50:14 by maheiden          #+#    #+#             */
/*   Updated: 2018/12/23 14:52:01 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_words(const char *s, char c)
{
	int		count;
	int		flag;

	flag = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		if (*s == c && flag == 1)
			flag = 0;
		s++;
	}
	return (count);
}

static	char	*ft_allocateword(const char *s, char c)
{
	size_t	count;
	char	*res;

	count = 0;
	if (!s)
		return (NULL);
	while (s[count] && s[count] != c)
		count++;
	if (!(res = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	count = 0;
	while (*s && *s != c)
	{
		res[count++] = *s;
		s++;
	}
	res[count] = '\0';
	return (res);
}

static void		ft_freearr(char **arr, int len)
{
	while (--len > -1)
		free(arr[len]);
	free(arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	j;

	if (!s || !(res = (char **)malloc(sizeof(char *)
					* (count_words(s, c) + 1))))
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			if (!(res[j++] = ft_allocateword(s, c)))
			{
				ft_freearr(res, --j);
				free(res);
				return (NULL);
			}
			while (*s != c && *s)
				s++;
		}
	}
	res[j] = NULL;
	return (res);
}
