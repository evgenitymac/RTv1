/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_additional_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 20:02:41 by maheiden          #+#    #+#             */
/*   Updated: 2019/03/02 20:53:03 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

double			give_part_of_vector(char **line)
{
	double		nb;

	nb = ft_atof(*line);
	while (**line)
	{
		if (**line == ',')
		{
			*line += 1;
			break ;
		}
		*line += 1;
	}
	return (nb);
}

t_vector		parse_vector(char *line)
{
	t_vector	vec;
	int			coord_flag;

	vec = (t_vector){0, 0, 0, 1};
	coord_flag = 0;
	while (*line != '(')
		line++;
	line++;
	while (*line != ')' && *line)
	{
		if (coord_flag++ == 0)
			vec.x = give_part_of_vector(&line);
		if (coord_flag++ == 1)
			vec.y = give_part_of_vector(&line);
		if (coord_flag++ == 2)
			vec.z = ft_atof(line);
		line++;
	}
	return (vec);
}

int				parse_color(char *line)
{
	int	i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	return (ft_atoi_base(&line[i], 16));
}

double			parse_double(char *line)
{
	int	i;

	i = 0;
	while (!ft_isdigit(line[i]) && line[i] != '-')
		i++;
	return (ft_atof(&line[i]));
}
