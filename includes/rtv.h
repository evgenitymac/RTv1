/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 19:08:42 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/12 19:18:18 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV_H
# define RTV_H

# include <SDL2/SDL.h>
# include "../libft/libft.h"
# include <OpenCL/opencl.h>
# include "../vectorlib/vector.h"

typedef	struct	s_camera
{
	t_vector		position;
	double				vert;
	double				hor;
	double				focus;
}					t_camera;
/*
typedef	struct	s_ray
{
	t_vector	origin;
	t_vector	direction;
}				t_ray;
*/
typedef struct	s_light
{
	t_vector	position;
	double		intensity;
}				t_light;

typedef	struct	s_intersection
{
	double			u;
	double			v;
	double			z;
}				t_intersection;

typedef	struct	s_render
{
	SDL_Window			*window;
	SDL_Event			event;
	SDL_Surface			*surface;
	t_camera			cam;
	t_ray				*rays; //in vector lib
	double				specular;
	int					light_nb;
	t_light 			*light;
	int					triangle_nb;
	t_triangle			*triangle;
	int					sphere_nb;
	t_sphere			*sphere;
	int					win_width;
	int					win_height;
}				t_render;

void				sphere_render(t_render *render);
void				init(t_render *render);
void				ray_cast(t_render *render);
t_intersection				triangle_intersection(t_ray ray, t_triangle triangle);
double				sphere_intersection(t_ray ray, t_sphere sphere);
void				triangle_render(t_render *render);
double				compute_lightning(t_render *render, t_vector P, t_vector N, t_vector V);

#endif
