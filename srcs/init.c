/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:12:39 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/09 22:25:13 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv.h"

void	init(t_render	*render)
{
	render->cam.position = (t_vector){0, -200, 0, 1};
	render->cam.hor = 0. * M_PI / 180;
	render->cam.vert = 0. * M_PI / 180;
	render->cam.focus = 1000.;

	render->rays = (t_ray *)malloc(sizeof(t_ray) * render->win_width * render->win_height);
/*	
	render->triangle_nb = 2;
	render->triangle = (t_triangle *)malloc(sizeof(t_triangle) * render->triangle_nb);
	render->textures = (t_texture *)malloc(sizeof(t_texture) * 1);
	
	render->triangle[0].a = (t_vector){0, 0, 0, 1};
	render->triangle[0].b = (t_vector){0, 0, 40, 1};
 	render->triangle[0].c = (t_vector) {40, 0, 0, 1};
*/
	render->sphere_nb = 1;
	render->sphere = (t_sphere *)malloc(sizeof(t_sphere) * render->sphere_nb);
	render->sphere[0].center = (t_vector){0, 0, 0, 1};
	render->sphere[0].r = (t_vector){0, 40, 0, 0};

	
	render->light_nb = 3;
	render->light = (t_light *)malloc(sizeof(t_light) * render->light_nb);

	render->light[0].position = (t_vector){0, 20, 0, 1};
	render->light[0].intensity = 0.2;

	render->light[1].position = (t_vector){0, 60, 0, 1};
	render->light[1].intensity = 0.6;

	render->light[1].position = (t_vector){0, 30, 30, 1};
	render->light[1].intensity = 0.2;

	//no one light sensivity can be more than 1.0
	

}
