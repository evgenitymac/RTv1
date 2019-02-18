/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:01:57 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/18 22:01:37 by maheiden         ###   ########.fr       */
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
	t = 0;
	dli_pixel(render, compute_lightning(render, point, normal, redirection), i,
			color);
}

static	bool	is_any_figure_closer(t_render *render, double cache)
{
	if (cache > 0 && cache < render->closest)
	{
		render->closest = cache;
		return (1);
	}
	return (0);
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
			is_any_figure_closer(render, plane_intersection(render->rays[i],
						render->plane[t])) ? normilize(render, 0, i, t) : 0;
		t = -1;
		while (++t < render->sphere_nb)
			is_any_figure_closer(render, sphere_intersection(render->rays[i],
						render->sphere[t])) ? normilize(render, 1, i, t) : 0;
		t = -1;
		while (++t < render->cylinder_nb)
			is_any_figure_closer(render, cylinder_intersection(render->rays[i],
						render->cylinder[t])) ? normilize(render, 2 ,i ,t) : 0;
		t = -1;
		while (++t < render->cone_nb)
			is_any_figure_closer(render, cone_intersection(render->rays[i],
						render->cone[t])) ? normilize(render, 3, i, t) : 0;
	}
	SDL_UpdateWindowSurface(render->window);
}
