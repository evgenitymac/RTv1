/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:18:13 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/21 21:19:35 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

bool	start_finish_ok(char *str)
{
	int i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '{')
		return (1);
	return (0);
}

bool	brackets_count(char *str)
{
	int  brackets = 0;
	int  braces = 0;
	int  i = 0;

	while (str[i])
	{
		if (str[i] == '{')
			brackets++;
		if (str[i] == '}')
			brackets--;
		if (str[i] == '[')
			braces++;
		if (str[i] == ']')
			braces--;
		i++;
	}
	if (brackets == 0 && braces == 0)
		return (1);
	return (0);
}

#include <stdio.h>
int		characters_in_file(char *name)
{
	int		fd = open(name, O_RDONLY);
	char buff[1];
	int	 count = 0;
	while (read(fd, buff, 1) > 0)
		count++;
	close(fd);	
	return (count);
}

void	parse(char *name, t_render *render)
{
	int		count = characters_in_file(name);
	char	buff[count];
	int		fd = open(name, O_RDONLY);
	read(fd, buff, count);
	if (brackets_count(buff) && start_finish_ok(buff))
		ft_putnbr(1);
	else
		ft_putnbr(0);
	render->plane_nb++;
}
