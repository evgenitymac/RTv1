/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_additional_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:54:07 by maheiden          #+#    #+#             */
/*   Updated: 2019/03/02 20:32:20 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void		init_nb_objects(t_render *render)
{
	render->plane_nb = 0;
	render->sphere_nb = 0;
	render->cylinder_nb = 0;
	render->cone_nb = 0;
	render->light_nb = 0;
}

void		init_figure_atributs(t_render *render, int current, int type)
{
	if (type == 0)
		render->plane[current] = (t_triangle){
			.a = (t_vector){0, 0, 0, 1},
			.b = (t_vector){0, 0, 0, 1},
			.c = (t_vector){0, 0, 0, 1},
			.color = 0xFFFFFF, .specular = 0};
	else if (type == 1)
		render->sphere[current] = (t_sphere){
			.center = (t_vector){0, 0, 0, 1},
			.r = 0,
			.color = 0xFFFFFF, .specular = 0};
	else if (type == 2)
		render->cylinder[current] = (t_cylinder){
			.center = (t_vector){0, 0, 0, 1},
			.r = 0,
			.direction = (t_vector){0, 0, 0, 1},
			.color = 0xFFFFFF, .specular = 0};
	else if (type == 3)
		render->cone[current] = (t_cone){
			.tip = (t_vector){0, 0, 0, 1},
			.direction = (t_vector){0, 0, 1, 1},
			.angle = 0,
			.color = 0xFFFFFF, .specular = 0};
}

void		parse_light(t_render *render, int fd, int current)
{
	char	*line;

	render->light[current].position = (t_vector){0, 0, 0, 1};
	render->light[current].intensity = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_strstr(line, "position = "))
			render->light[current].position = parse_vector(line);
		if (ft_strstr(line, "intensity = "))
			render->light[current].intensity = parse_double(line);
		if (ft_strchr(line, '\\') != 0)
		{
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
}
