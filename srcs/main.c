/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:41:14 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/12 19:43:14 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv.h"


void	ray_cast(t_render *render)
{
	int		i;

	i =  -1;
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

void	sdl_loop(t_render *render)
{
	int		quit;

	quit = 0;
	while (!quit)
	{
		while (SDL_PollEvent(&render->event))
		{
			if (render->event.type == SDL_QUIT)
				quit = 1;
			//if (render->event.window.event = SDL_WINDOWEVENT_RESIZED)
			//	resize_sdl(render);
		}
	}
}


int		main()
{
	t_render	render;
	
	render.win_width = 1280;
	render.win_height = 720;
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	render.window = SDL_CreateWindow("RT", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, render.win_width,
			render.win_height, SDL_WINDOW_RESIZABLE);
	render.surface = SDL_GetWindowSurface(render.window);
	init(&render);
	triangle_render(&render);
	//sphere_render(&render);
	sdl_loop(&render);
	SDL_DestroyWindow(render.window);
	SDL_Quit();
	return (0);
}
