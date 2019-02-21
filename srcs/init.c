/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:12:39 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/21 17:04:43 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	init(t_render	*render)
{
	render->cam.position = (t_vector){0, -100, 20, 1};
	render->cam.hor = 30. * M_PI / 180;
	render->cam.vert = 0. * M_PI / 180;
	render->cam.focus = 1000.;

	render->plane_nb = 1;
	
	render->plane[0].a = (t_vector){0, -10, 0, 1};
	render->plane[0].b = (t_vector){10, 0 , 0 , 1};
 	render->plane[0].c = (t_vector) {0, 10, 0, 1};
	render->plane[0].color = 0xFF0000;
	render->plane[0].specular = 50;
	
	render->sphere_nb = 1;
	render->sphere[0].center = (t_vector){0, 0, 9, 1};
	render->sphere[0].r = 18;
	render->sphere[0].specular = 50;
	render->sphere[0].color = 0x0000FF;

	//render->sphere[1].center = (t_vector){0, -25, 0, 1};
	//render->sphere[1].r = 3;
	//render->sphere[1].specular = 50;
	//render->sphere[1].color = 0xFF00FF;
	
	render->cylinder_nb = 1;
	render->cylinder[0].r = 9;
	render->cylinder[0].center = (t_vector){20, 0, 0, 1};
	render->cylinder[0].direction = (t_vector){0, 0, 1, 1};
	render->cylinder[0].specular = 50;
	render->cylinder[0].color = 0x00FF00;

	render->cone_nb = 1;
	render->cone[0].tip = (t_vector){-40, 0, 10, 1};
	render->cone[0].direction = (t_vector){0, 0, 1, 1};
	render->cone[0].angle = 30. * M_PI / 180;
	render->cone[0].specular = 50;
	render->cone[0].color = 0xff69b4;


	render->light_nb = 2;

	render->light[0].position = (t_vector){35, -65, 40, 1};
	render->light[0].intensity = 0.9;

	render->light[1].position = (t_vector){-35, 60, 40, 1};
	render->light[1].intensity = 1;
}
