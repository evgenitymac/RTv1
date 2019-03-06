/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 19:08:42 by maheiden          #+#    #+#             */
/*   Updated: 2019/03/04 15:56:06 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV_H
# define RTV_H
# include <SDL.h>
# include "libft.h"
# include <OpenCL/opencl.h>
# include "vector.h"

typedef	struct	s_camera
{
	t_vector	position;
	double		vert;
	double		hor;
	double		focus;
}				t_camera;

typedef	struct	s_ray
{
	t_vector	origin;
	t_vector	direction;
}				t_ray;

typedef struct	s_light
{
	t_vector	position;
	double		intensity;
}				t_light;

typedef	struct	s_count
{
	int			current_plane;
	int			current_sphere;
	int			current_cylinder;
	int			current_cone;
	int			current_light;
}				t_count;

typedef	struct	s_cache_vectrors
{
	t_vector		point;
	t_vector		normal;
	t_vector		redirection;
}				t_cache_vectors;

typedef	struct	s_render
{
	SDL_Window			*window;
	SDL_Event			event;
	SDL_Surface			*surface;
	t_camera			cam;
	t_ray				*rays;
	int					light_nb;
	t_light				*light;
	int					cylinder_nb;
	t_cylinder			*cylinder;
	int					plane_nb;
	t_triangle			*plane;
	int					sphere_nb;
	t_sphere			*sphere;
	int					cone_nb;
	t_cone				*cone;
	double				closest;
	int					win_width;
	int					win_height;
}				t_render;

void			ray_cast(t_render *render);
t_vector		cone_normalize(t_vector point, t_cone cone);
t_vector		normalize_init_helper(t_render *render, t_vector point,
						int type, int t);
void			dli_pixel(t_render *render, double dli, int i, int color);
double			quandratic_solve(double k1, double k2, double k3);

void			parse_camera(t_render *render, int fd);
void			parse_plane(t_render *render, int fd, int current);
void			parse_sphere(t_render *render, int fd, int current);
void			parse_cylinder(t_render *render, int fd, int current);
void			parse_cone(t_render *render, int fd, int current);
void			parse_light(t_render *render, int fd, int current);

void			keyboard(t_render	*render, int *quit);

void			set_pixel(SDL_Surface *surface, int x, int y,
					unsigned int pixel);
void			clear_surface(SDL_Surface *surface);
int				ft_lepri(int first, int second, double percent);
int				get_color(int start, int end, double percent);

void			init(t_render *render);

double			sphere_intersection(t_ray ray, t_sphere sphere);
double			cone_intersection(t_ray ray, t_cone cone);
double			cylinder_intersection(t_ray ray, t_cylinder cylinder);
double			plane_intersection(t_ray ray, t_triangle triangle);

int				is_shadow(t_render *render, t_vector point, int j);
double			specular_dot(t_cache_vectors *vectors,
				t_vector light_vector);
double			light_intense_giver(t_cache_vectors *vectors,
				t_vector light_vector, t_light light);
double			glare_intense_giver(t_cache_vectors *vectors,
				t_vector light_vector, t_light lihgt, double specular);

int				shadow_figure_iteration(t_render *render,
						t_ray light_ray, double ray_len);
int				is_shadow(t_render *render, t_vector point, int j);
double			compute_lightning(t_render *render,
						t_cache_vectors *vectors, double specular);

void			display_error(int cond, char *str);

void			parse(char *name, t_render *render);
int				parse_color(char *line);
double			parse_double(char *line);
t_vector		parse_vector(char *line);

void			init_figure_atributs(t_render *render, int current,
					int type);
void			init_nb_objects(t_render *render);
void			start_render(t_render *render);

#endif
