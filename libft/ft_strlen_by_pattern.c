/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_by_pattern.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:08:53 by maheiden          #+#    #+#             */
/*   Updated: 2019/01/16 19:39:05 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_by_pattern(const char *s, char c)
{
	int	i;
	int	cnt;
	int	flag;

	i = -1;
	cnt = 0;
	flag = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == c)
			flag = 0;
		else if (s[i] != c && flag == 0)
		{
			flag = 1;
			cnt++;
		}
	}
	return (cnt);
}
