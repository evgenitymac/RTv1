/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_additional.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:55:30 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/27 17:17:46 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_vector		parse_vector(char *line)
{
	t_vector 	vec;
	int		coord_flag;
	
	vec = (t_vector){0, 0, 0, 1};
	coord_flag = 0;
	while (*line != '(')
		line++;
	line++;
	while (*line != ')')
	{
		if (coord_flag == 0)
		{
			vec.x = ft_atoi(line);
			while (*line)
			{
				if (*line == ',')
				{
					line++;
					break;
				}
				line++;
			}
			coord_flag++;
		}
		if (coord_flag == 1)
		{
			vec.y = ft_atoi(line);
			coord_flag++;
			while (*line)
			{
				if (*line == ',')
				{
					line++;
					break;
				}
				line++;
			}
		}
		if (coord_flag == 2)
		{
			vec.z = ft_atoi(line);
			coord_flag++;
		}
		line++;
	}
	return (vec);
	// put error if not 3 coord read
}

int		parse_color(char *line)
{
	int 	i;
	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	return (ft_atoi_base(&line[i], 16));
}

double		parse_double(char *line)
{
	int 	i;
	
	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	return (ft_atof(&line[i]));
}

void		parse_camera(t_render *render, int fd)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		if (ft_strstr(line, "position = "))
			render->cam.position = parse_vector(line);
		if (ft_strstr(line, "horizontal_angle = "))
		{
			render->cam.hor = parse_double(line) * M_PI / 180;
			render->cam.focus = tan(render->cam.hor) * render->win_width / 2;
		}
		if (ft_strstr(line, "vertical_angle = "))
			render->cam.vert = parse_double(line) * M_PI / 180;
		if (ft_strchr(line, '\\') != 0)
		{
			ft_strdel(&line);
			break;
		}
		ft_strdel(&line);
	}
}

void		parse_plane(t_render *render, int fd, int current)
{
	char	*line;

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
			break;	
		}
		ft_strdel(&line);
	}
}

void		parse_sphere(t_render *render, int fd, int current)
{
	char	*line;

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
			break;	
		}
		ft_strdel(&line);
	}
}


void		parse_cylinder(t_render *render, int fd, int current)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		if (ft_strstr(line, "center = "))
			render->cylinder[current].center = parse_vector(line);
		if (ft_strstr(line, "radius = "))
			render->cylinder[current].r = parse_double(line);
		if (ft_strstr(line, "direction = "))
			render->cylinder[current].direction = parse_vector(line);
		if (ft_strstr(line, "color = "))
			render->cylinder[current].color = parse_color(line);
		if (ft_strstr(line, "specular = "))
			render->cylinder[current].specular = parse_double(line);	
		if (ft_strchr(line, '\\') != 0)
		{
			ft_strdel(&line);
			break;	
		}
		ft_strdel(&line);
	}
}

void		parse_cone(t_render *render, int fd, int current)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		if (ft_strstr(line, "tip = "))
			render->cone[current].tip = parse_vector(line);
		if (ft_strstr(line, "direction = "))
			render->cone[current].direction = parse_vector(line);
		if (ft_strstr(line, "angle = "))
			render->cone[current].angle = parse_double(line) * M_PI / 180;	
		//if angle = 0 return error cause float. point exeption will be
		if (ft_strstr(line, "color = "))
			render->cone[current].color = parse_color(line);
		if (ft_strstr(line, "specular = "))
			render->cone[current].specular = parse_double(line);	
		if (ft_strchr(line, '\\') != 0)
		{
			ft_strdel(&line);
			break;	
		}
		ft_strdel(&line);
	}
}

void		parse_light(t_render *render, int fd, int current)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		if (ft_strstr(line, "position = "))
			render->light[current].position = parse_vector(line);
		if (ft_strstr(line, "intensity = "))
			render->light[current].intensity = parse_double(line);	
		if (ft_strchr(line, '\\') != 0)
		{
			ft_strdel(&line);
			break;	
		}
		ft_strdel(&line);
	}
}
