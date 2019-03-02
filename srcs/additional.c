/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:07:19 by maheiden          #+#    #+#             */
/*   Updated: 2019/03/02 21:02:32 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void				ray_cast(t_render *render)
{
	int				i;
	t_matrix_4x4	rotation;

	i = -1;
	rotation = matrix_multiply(
			x_rotation_matrix(-render->cam.vert),
			z_rotation_matrix(render->cam.hor));
	while (++i < render->win_width * render->win_height)
	{
		render->rays[i].origin = render->cam.position;
		render->rays[i].direction = vector_matrix_multiply(
				vector_normalize((t_vector)
				{
				(i % render->win_width - render->win_width / 2),
				render->cam.focus,
				-(i / render->win_width - render->win_height / 2),
				0.
				}), rotation);
	}
}

void				dli_pixel(t_render *render, double dli, int i, int color)
{
	if (dli > 2.)
		dli = 2.;
	if (dli <= 1.)
		set_pixel(render->surface, i % render->win_width, i / render->win_width,
				get_color(0x000000, color, dli));
	else
		set_pixel(render->surface, i % render->win_width, i / render->win_width,
				get_color(color, 0xFFFFFF, dli - 1.));
}

double				quandratic_solve(double k1, double k2, double k3)
{
	double			diskr;
	double			t1;
	double			t2;
	double			tmp;

	diskr = k2 * k2 - 4 * k1 * k3;
	if (diskr < 0)
		return (0);
	t1 = (-k2 + sqrt(diskr)) / (2 * k1);
	t2 = (-k2 - sqrt(diskr)) / (2 * k1);
	if (t1 > t2)
	{
		tmp = t1;
		t1 = t2;
		t2 = tmp;
	}
	if (t1 < 0)
		t1 = t2;
	if (t1 < 0)
		return (-1.);
	return (t1);
}

t_vector			cone_normalize(t_vector point, t_cone cone)
{
	double			len;

	len = vector_length(vector_sub(point, cone.tip));
	if (dot_product(vector_sub(cone.tip, point), cone.direction) > 0)
		len *= -1;
	return (vector_normalize(vector_sub(point, vector_sum(cone.tip,
			vector_scalar_multiply(cone.direction, len)))));
}

t_vector			normalize_init_helper(t_render *render,
		t_vector point, int type, int t)
{
	if (type == 0)
	{
		return (vector_normalize(cross_product(vector_sub(render->plane[t].b,
				render->plane[t].a), vector_sub(render->plane[t].c,
				render->plane[t].a))));
	}
	if (type == 1)
		return (vector_normalize(vector_sub(point, render->sphere[t].center)));
	if (type == 2)
	{
		return (vector_normalize(cross_product(cross_product(vector_sub(point,
				render->cylinder[t].center), render->cylinder[t].direction),
				render->cylinder[t].direction)));
	}
	if (type == 3)
		return (cone_normalize(point, render->cone[t]));
	return ((t_vector){0, 0, 0, 0});
}
