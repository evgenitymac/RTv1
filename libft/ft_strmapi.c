/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:42:36 by maheiden          #+#    #+#             */
/*   Updated: 2018/11/30 18:54:04 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mal_str;
	unsigned int	i;

	if (s && f)
	{
		if (!(mal_str = ft_strdup(s)))
			return (NULL);
		i = 0;
		while (s[i] && f)
		{
			mal_str[i] = f(i, s[i]);
			i++;
		}
		return (mal_str);
	}
	return (NULL);
}
