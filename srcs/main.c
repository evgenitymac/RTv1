/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:41:14 by maheiden          #+#    #+#             */
/*   Updated: 2019/03/02 19:07:50 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void			display_error(int cond, char *str)
{
	if (cond)
	{
		ft_putendl(str);
		exit(0);
	}
}

void			resize_sdl(t_render *render)
{
	render->surface = SDL_GetWindowSurface(render->window);
	clear_surface(render->surface);
	render->win_width = render->event.window.data1;
	render->win_height = render->event.window.data2;
	free(render->rays);
	render->cam.focus = render->win_width / 2. / tan(60 * M_PI / 180);
	render->rays = (t_ray *)malloc(sizeof(t_ray) *
			render->win_width * render->win_height);
	start_render(render);
}

void			sdl_loop(t_render *render)
{
	int			quit;

	quit = 0;
	while (!quit)
	{
		while (SDL_PollEvent(&render->event))
		{
			if (render->event.type == SDL_QUIT)
				quit = 1;
			if (render->event.type == SDL_KEYDOWN)
				keyboard(render, &quit);
			if (render->event.window.event == SDL_WINDOWEVENT_RESIZED)
				resize_sdl(render);
		}
	}
}

int				main(int argc, char **argv)
{
	t_render	render;

	display_error(argc != 2, "where is file mazafaka");
	render.win_width = 1280;
	render.win_height = 720;
	parse(argv[argc - 1], &render);
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	render.window = SDL_CreateWindow("RT", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, render.win_width,
			render.win_height, SDL_WINDOW_RESIZABLE);
	render.surface = SDL_GetWindowSurface(render.window);
	start_render(&render);
	sdl_loop(&render);
	SDL_DestroyWindow(render.window);
	SDL_Quit();
	return (0);
}
