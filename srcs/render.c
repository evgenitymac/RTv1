/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:02:54 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/09 22:45:41 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv.h"

void	set_pixel(SDL_Surface *surface, int x, int y, unsigned int pixel)
{
	*((unsigned int *)(surface->pixels + y * surface->pitch + x * 4)) = pixel;
}

void	clear_surface(SDL_Surface *surface)
{
	ft_bzero(surface->pixels, surface->h * surface->w * 4);
}

void	triangle_render(t_render *render)
{
	int 			i;
	int				t;
	double			z;
	t_intersection	bct;
	
	ray_cast(render);
	i = -1;
	while (++i < render->win_height * render->win_width)
	{
		t = -1;
		z = 1. / 0.;
		while (++t < render->triangle_nb)
		{
			bct = triangle_intersection(render->rays[i], render->triangle[t]);
			if (bct.z > 0 && bct.z < z)
			{
				z = bct.z;
				set_pixel(render->surface, i % render->win_width, i / render->win_width,
						0xFFF + t * 1);
			}
		}
	}
	SDL_UpdateWindowSurface(render->window);
}

void	sphere_render(t_render	*render)
{
	int		i;
	int		t;
	
	ray_cast(render);
	i = 1;
	while (++i < render->win_height * render->win_width)
	{
		t = -1;
		while (++t < render->sphere_nb)
		{
			double closest_t = sphere_intersection(render->rays[i], render->sphere[t]);
			if (closest_t > 0.)
			{
				t_vector P = vector_sum(render->rays[i].origin, vector_scalar_multiply(render->rays[i].direction, closest_t));
				t_vector N = vector_sub(P, render->sphere[t].center);
				N = vector_normalize(N);
				set_pixel(render->surface, i % render->win_width, i / render->win_width,
						0xFFF * compute_lightning(render, P, N));
			}
		}
	}
	SDL_UpdateWindowSurface(render->window);
}	
