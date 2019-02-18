/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:01:57 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/18 21:34:01 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

//0 - plane
//1 - sphere
//2 - cylinder
//3 - cone

static	int		color_init(t_render *render, int type, int current)
{
	if (type == 0)
		return (render->plane[current].color);
	if (type == 1)
		return (render->sphere[current].color);
	if (type == 2)
		return (render->cylinder[current].color);
	if (type == 3)
		return (render->cone[current].color);
	return (0);
}

// i current pixel
// t current figure
// z closest

static	void	normilize(t_render *render, int type, int i, int t)
{
	t_vector 	point;
	t_vector	normal;
	t_vector	redirection;
	int			color;
	double		len;

	point = vector_sum(render->rays[i].origin, vector_scalar_multiply(
				render->rays[i].direction, render->closest));
	normal = (t_vector){0, 0, 0, 0};
	redirection = vector_scalar_multiply(render->rays[i].direction, -1);
	color = color_init(render, type, t);
	len = 0;
	normal = normalize_init_helper(render, point, type, t);
	if (dot_product(render->rays[i].direction, normal) > 0)
		normal = vector_scalar_multiply(normal, -1);
	dli_pixel(render, compute_lightning(render, point, normal, redirection), i,
			color);
}

void	start_render(t_render *render)
{
	int 			i;
	int				t;
	
	ray_cast(render);
	i = -1;
	while (++i < render->win_height * render->win_width)
	{
		t = -1;
		render->closest = 1. / 0.;
		while (++t < render->plane_nb)
		{
			double closest_p = plane_intersection(render->rays[i], render->plane[t]);
			if (closest_p > 0 && closest_p < render->closest)
			{
				render->closest = closest_p;
				normilize(render, 0, i, t);
			}
		}
		t = -1;
		while (++t < render->sphere_nb)
		{
			double closest_t = sphere_intersection(render->rays[i], render->sphere[t]);
			if (closest_t > 0. && closest_t < render->closest)
			{
				render->closest = closest_t;
				normilize(render, 1, i, t);
			}
		}
		t = -1;
		while (++t < render->cylinder_nb)
		{
			double closest_c = cylinder_intersection(render->rays[i], render->cylinder[t]);
			if (closest_c > 0. && closest_c < render->closest)
			{
				render->closest = closest_c;
				normilize(render, 2, i, t);
			}
		}
		t = -1;
		while (++t < render->cone_nb)
		{
			double closest_co = cone_intersection(render->rays[i], render->cone[t]);
			if (closest_co > 0. && closest_co < render->closest)
			{
				render->closest = closest_co;
				normilize(render, 3, i, t);
			}
		}
	}
	SDL_UpdateWindowSurface(render->window);
}
