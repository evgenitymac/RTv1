/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:30:14 by maheiden          #+#    #+#             */
/*   Updated: 2018/12/05 17:03:02 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(sjoin = (ft_strnew(ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	while (s1[i])
	{
		sjoin[k] = s1[i];
		i++;
		k++;
	}
	i = 0;
	while (s2[i])
	{
		sjoin[k] = s2[i];
		i++;
		k++;
	}
	sjoin[k] = '\0';
	return (sjoin);
}
