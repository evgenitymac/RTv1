/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:18:13 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/20 21:36:58 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

//if fd is empty folder

void	allocate_objects(t_render *render)
{
	render->rays = (t_ray *)malloc(sizeof(t_ray) * render->win_width * render->win_height);
	render->plane = (t_triangle *)malloc(sizeof(t_triangle) * render->plane_nb);
	render->sphere = (t_sphere *)malloc(sizeof(t_sphere) * render->sphere_nb);
	render->cylinder = (t_cylinder *)malloc(sizeof(t_cylinder) * render->cylinder_nb);
	render->cone = (t_cone *)malloc(sizeof(t_cone) * render->cone_nb);
	render->light = (t_light *)malloc(sizeof(t_light) * render->light_nb);
}



void	count_objects(int fd, t_render *render)
{
	char *line;

	render->plane_nb = 0;
	render->sphere_nb = 0;
	render->cylinder_nb = 0;
	render->cone_nb = 0;
	render->light_nb = 0;

	while (get_next_line(fd, &line))
	{
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
}
/*
t_vector	parse_vector(char *str)
{
	t_vector vector;
	int i = 0;
	
	vector = (t_vector){0, 0, 0, 1};
	while (*str)
	{
		str++;
	}
	return (vector);
*/

void	parse_atribut(char *str, t_render *render)
{
	int i = 0;
	if (ft_strn(str, "color") != 0)
	{
		while (*str)
		{
			if (*str == '=')
			{
				str++;
				render->planeft_atoi(*str);
			}
			i++;
		}	
	}


}

void	parse_object(int fd, t_render *render)
{
	char *line;
	while (get_next_line(fd, &line))
	{
		if (ft_strnequ(line, "/plane", ft_strlen("/plane")) == 0)
		{
			ft_strdel(line);
			while (get_next_line(fd, &line))
			{
				if ((ft_strchr(line, '\\') != 0));
				{
					ft_strdel(line);
					break;
				}
				parse_atribut(line);
			 ft_strdel(line)
			}	
		}
		ft_strdel(line);
	}	
}
*/
void	parse(int fd, t_render *render)
{
	count_objects(fd, render);
	allocate_objects(render);
	close(fd);
	parse_object(fd, render);

}
