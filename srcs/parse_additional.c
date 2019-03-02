/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_additional.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:55:30 by maheiden          #+#    #+#             */
/*   Updated: 2019/03/02 20:30:57 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void		parse_camera(t_render *render, int fd)
{
	char	*line;

	render->cam.position = (t_vector){0, 0, 0, 1};
	render->cam.hor = 0;
	render->cam.focus = render->win_width / tan(70 * M_PI / 180);
	render->cam.vert = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_strstr(line, "position = "))
			render->cam.position = parse_vector(line);
		if (ft_strstr(line, "horizontal_angle = "))
		{
			render->cam.hor = parse_double(line) * M_PI / 180;
		}
		if (ft_strstr(line, "vertical_angle = "))
			render->cam.vert = parse_double(line) * M_PI / 180;
		if (ft_strchr(line, '\\') != 0)
		{
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
}

void		parse_plane(t_render *render, int fd, int current)
{
	char	*line;

	init_figure_atributs(render, current, 0);
	while (get_next_line(fd, &line))
	{
		if (ft_strstr(line, "a = "))
			render->plane[current].a = parse_vector(line);
		if (ft_strstr(line, "b = "))
			render->plane[current].b = parse_vector(line);
		if (ft_strstr(line, "c = "))
			render->plane[current].c = parse_vector(line);
		if (ft_strstr(line, "color = "))
			render->plane[current].color = parse_color(line);
		if (ft_strstr(line, "specular = "))
			render->plane[current].specular = parse_double(line);
		if (ft_strchr(line, '\\') != 0)
		{
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
}

void		parse_sphere(t_render *render, int fd, int current)
{
	char	*line;

	init_figure_atributs(render, current, 1);
	while (get_next_line(fd, &line))
	{
		if (ft_strstr(line, "center = "))
			render->sphere[current].center = parse_vector(line);
		if (ft_strstr(line, "radius = "))
			render->sphere[current].r = parse_double(line);
		if (ft_strstr(line, "color = "))
			render->sphere[current].color = parse_color(line);
		if (ft_strstr(line, "specular = "))
			render->sphere[current].specular = parse_double(line);
		if (ft_strchr(line, '\\') != 0)
		{
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
}

void		parse_cylinder(t_render *render, int fd, int current)
{
	char	*line;

	init_figure_atributs(render, current, 2);
	while (get_next_line(fd, &line))
	{
		if (ft_strstr(line, "center = "))
			render->cylinder[current].center = parse_vector(line);
		if (ft_strstr(line, "radius = "))
			render->cylinder[current].r = parse_double(line);
		if (ft_strstr(line, "direction = "))
			render->cylinder[current].direction =
				vector_normalize(parse_vector(line));
		if (ft_strstr(line, "color = "))
			render->cylinder[current].color = parse_color(line);
		if (ft_strstr(line, "specular = "))
			render->cylinder[current].specular = parse_double(line);
		if (ft_strchr(line, '\\') != 0)
		{
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
}

void		parse_cone(t_render *render, int fd, int current)
{
	char	*line;

	init_figure_atributs(render, current, 3);
	while (get_next_line(fd, &line))
	{
		if (ft_strstr(line, "tip = "))
			render->cone[current].tip = parse_vector(line);
		if (ft_strstr(line, "direction = "))
			render->cone[current].direction =
				vector_normalize(parse_vector(line));
		if (ft_strstr(line, "angle = "))
			render->cone[current].angle = parse_double(line) * M_PI / 180;
		if (ft_strstr(line, "color = "))
			render->cone[current].color = parse_color(line);
		if (ft_strstr(line, "specular = "))
			render->cone[current].specular = parse_double(line);
		if (ft_strchr(line, '\\') != 0)
		{
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
}
