/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:12:39 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/15 21:59:09 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	init(t_render	*render)
{
	render->cam.position = (t_vector){0, -100, 20, 1};
	render->cam.hor = 0. * M_PI / 180;
	render->cam.vert = 0. * M_PI / 180;
	render->cam.focus = 1000.;

	render->rays = (t_ray *)malloc(sizeof(t_ray) * render->win_width * render->win_height);

	render->plane_nb = 1;
	render->plane = (t_triangle *)malloc(sizeof(t_triangle) * render->plane_nb);
	//render->textures = (t_texture *)malloc(sizeof(t_texture) * 1);
	
	render->plane[0].a = (t_vector){0, -10, 0, 1};
	render->plane[0].b = (t_vector){10, 0 , 0 , 1};
 	render->plane[0].c = (t_vector) {0, 10, 0, 1};
	render->plane[0].color = 0xFF0000;
	
	// problem with color 0xFF0000 0xFFFF00;

	render->sphere_nb = 1;
	render->sphere = (t_sphere *)malloc(sizeof(t_sphere) * render->sphere_nb);
	render->sphere[0].center = (t_vector){0, 0, 9, 1};
	render->sphere[0].r = 9;
	render->sphere[0].specular = 50;
	render->sphere[0].color = 0x0000FF;

	render->cylinder_nb = 1;
	render->cylinder = (t_cylinder *)malloc(sizeof(t_cylinder) * render->cylinder_nb);
	render->cylinder[0].r = 9;
	render->cylinder[0].h = 10;
	render->cylinder[0].center = (t_vector){20, 0, 0, 1};
	render->cylinder[0].direction = (t_vector){0, 0, 1, 1};
	render->cylinder[0].specular = 50;
	render->cylinder[0].color = 0xFF00FF;

	render->cone_nb = 1;
	render->cone = (t_cone *)malloc(sizeof(t_cone) * render->cone_nb);
	render->cone[0].tip = (t_vector){-40, 0, 0, 1};
	render->cone[0].direction = (t_vector){0, 0, 1, 1};
	render->cone[0].angle = 30. * M_PI / 180;
	render->cone[0].h = 40;
	render->cone[0].specular = 50;
	render->cone[0].color = 0xF00F00;


	render->light_nb = 1;
	render->light = (t_light *)malloc(sizeof(t_light) * render->light_nb);

	render->light[0].position = (t_vector){35, -65, 40, 1};
	render->light[0].intensity = 0.9;

//	render->light[1].position = (t_vector){-35, 50, 100, 1};
//	render->light[1].intensity = 0.3;

//	render->light[1].position = (t_vector){10, -40, 30, 1};
//	render->light[1].intensity = 0.7;	

	//render->light[1].position = (t_vector){-10, -10, 23, 1};
	//render->light[1].intensity = 0.8;
	//no one light sensivity can be more than 1.0
}
