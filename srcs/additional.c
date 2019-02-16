/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:07:19 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/16 18:53:15 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void			ray_cast(t_render *render)
{
	int			i;

	i = -1;
	while (++i < render->win_width * render->win_height)
	{
		render->rays[i].origin = render->cam.position;
		render->rays[i].direction = vector_normalize((t_vector)
				{
				(i % render->win_width - render->win_width / 2),
				render->cam.focus,
				-(i / render->win_width - render->win_height / 2),
				0.
				});
	}
}

#include "stdio.h"
void			dli_pixel(t_render *render, double dli, int i, int color)
{
	if (dli > 2.)
		dli = 2.;
	if (dli <= 1.)
		set_pixel(render->surface, i % render->win_width, i / render->win_width,
				get_color(0x000000, color, dli));
	else
	{
		printf("%f\n", dli - 1);
		set_pixel(render->surface, i % render->win_width, i / render->win_width,
				get_color(color, 0xFFFFFF, dli - 1.));
	}
}

double			quandratic_solve(double k1, double k2, double k3)
{
	double		diskr;
	double		t1;
	double		t2;
	double		tmp;

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
