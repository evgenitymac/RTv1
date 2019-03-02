/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:01:57 by maheiden          #+#    #+#             */
/*   Updated: 2019/03/02 18:14:11 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

static	int				color_specular_init(t_render *render, int type,
		int current, double *specular)
{
	if (type == 0)
	{
		*specular = render->plane[current].specular;
		return (render->plane[current].color);
	}
	if (type == 1)
	{
		*specular = render->sphere[current].specular;
		return (render->sphere[current].color);
	}
	if (type == 2)
	{
		*specular = render->cylinder[current].specular;
		return (render->cylinder[current].color);
	}
	if (type == 3)
	{
		*specular = render->cone[current].specular;
		return (render->cone[current].color);
	}
	return (0);
}

static	void			normilize(t_render *render, int type, int i, int t)
{
	t_cache_vectors		vectors;
	int					color;
	double				specular;

	vectors.point = vector_sum(render->rays[i].origin, vector_scalar_multiply(
				render->rays[i].direction, render->closest));
	vectors.normal = (t_vector){0, 0, 0, 0};
	vectors.redirection = vector_scalar_multiply(render->rays[i].direction, -1);
	color = color_specular_init(render, type, t, &specular);
	vectors.normal = normalize_init_helper(render, vectors.point, type, t);
	if (dot_product(render->rays[i].direction, vectors.normal) > 0)
		vectors.normal = vector_scalar_multiply(vectors.normal, -1);
	dli_pixel(render, compute_lightning(render, &vectors, specular), i,
			color);
}

static	bool			is_any_figure_closer(t_render *render, double cache)
{
	if (cache > 0 && cache < render->closest)
	{
		render->closest = cache;
		return (1);
	}
	return (0);
}

static	void			figure_iteration(t_render *render, int i)
{
	int			t;

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
					render->cylinder[t])) ? normilize(render, 2, i, t) : 0;
	t = -1;
	while (++t < render->cone_nb)
		is_any_figure_closer(render, cone_intersection(render->rays[i],
					render->cone[t])) ? normilize(render, 3, i, t) : 0;
}

void					start_render(t_render *render)
{
	int			i;

	i = -1;
	ray_cast(render);
	while (++i < render->win_height * render->win_width)
		figure_iteration(render, i);
	SDL_UpdateWindowSurface(render->window);
}
