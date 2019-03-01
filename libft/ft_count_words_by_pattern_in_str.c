/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words_by_pattern_in_str.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:26:41 by maheiden          #+#    #+#             */
/*   Updated: 2018/12/03 00:04:26 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words_by_pattern_in_str(char const *s, char c)
{
	int		count;
	int		flag;
	int		i;

	count = 0;
	flag = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 1;
		if (flag == 1 && s[i] != c)
		{
			flag = 0;
			count++;
		}
		i++;
	}
	return (count);
}
