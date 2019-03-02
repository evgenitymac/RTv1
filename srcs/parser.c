/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:18:13 by maheiden          #+#    #+#             */
/*   Updated: 2019/03/02 19:53:03 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void		allocate_objects(t_render *render)
{
	render->rays = (t_ray *)malloc(sizeof(t_ray) *
			render->win_width * render->win_height);
	render->plane = (t_triangle *)malloc(sizeof(t_triangle) * render->plane_nb);
	render->sphere = (t_sphere *)malloc(sizeof(t_sphere) * render->sphere_nb);
	render->cylinder = (t_cylinder *)malloc(sizeof(t_cylinder)
			* render->cylinder_nb);
	render->cone = (t_cone *)malloc(sizeof(t_cone) * render->cone_nb);
	render->light = (t_light *)malloc(sizeof(t_light) * render->light_nb);
}

void		count_objects(char *file_name, t_render *render)
{
	char	*line;
	int		fd;
	int		camera_count;

	init_nb_objects(render);
	display_error(((fd = open(file_name, O_RDWR)) <= 0), "file not found");
	camera_count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, "/camera") != 0)
			camera_count++;
		if (ft_strstr(line, "/plane") != 0)
			render->plane_nb++;
		if (ft_strstr(line, "/sphere") != 0)
			render->sphere_nb++;
		if (ft_strstr(line, "/cylinder") != 0)
			render->cylinder_nb++;
		if (ft_strstr(line, "/cone") != 0)
			render->cone_nb++;
		if (ft_strstr(line, "/light") != 0)
			render->light_nb++;
		ft_strdel(&line);
	}
	display_error((camera_count != 1), "camera count error");
	close(fd);
}

void		count_init(t_count *count)
{
	count->current_plane = 0;
	count->current_sphere = 0;
	count->current_cylinder = 0;
	count->current_cone = 0;
	count->current_light = 0;
}

void		type_of_object(char *file_name, t_render *render)
{
	char	*line;
	int		fd;
	t_count count;

	fd = open(file_name, O_RDONLY);
	count_init(&count);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, "/camera") != 0)
			parse_camera(render, fd);
		else if (ft_strstr(line, "/plane") != 0)
			parse_plane(render, fd, count.current_plane++);
		else if (ft_strstr(line, "/sphere") != 0)
			parse_sphere(render, fd, count.current_sphere++);
		else if (ft_strstr(line, "/cylinder") != 0)
			parse_cylinder(render, fd, count.current_cylinder++);
		else if (ft_strstr(line, "/cone") != 0)
			parse_cone(render, fd, count.current_cone++);
		else if (ft_strstr(line, "/light") != 0)
			parse_light(render, fd, count.current_light++);
		ft_strdel(&line);
	}
	close(fd);
}

void		parse(char *name, t_render *render)
{
	count_objects(name, render);
	allocate_objects(render);
	type_of_object(name, render);
}
