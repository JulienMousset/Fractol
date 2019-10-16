/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:40:42 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/16 13:33:21 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	choose_fractal(t_env *env, t_coord p)
{
	if (ft_strcmp(env->av, "julia") == 0)
		julia(env, p);
	if (ft_strcmp(env->av, "mandelbrot") == 0)
		mandelbrot(env, p);
	if (ft_strcmp(env->av, "burning_ship") == 0)
		burning_ship(env, p);
	if (ft_strcmp(env->av, "tricorn") == 0)
		tricorn(env, p);
	if (ft_strcmp(env->av, "celtic_mandelbar") == 0)
		celtic_mandelbar(env, p);
	if (ft_strcmp(env->av, "celtic_mandelbrot") == 0)
		celtic_mandelbrot(env, p);
	if (ft_strcmp(env->av, "buffalo") == 0)
		buffalo(env, p);
	if (ft_strcmp(env->av, "celtic_heart") == 0)
		celtic_heart(env, p);
}

void	init_fractal(t_env *env)
{
	if (ft_strcmp(env->av, "mandelbrot") == 0
			|| ft_strcmp(env->av, "celtic_mandelbar") == 0)
		env->x = -0.5;
	else if (ft_strcmp(env->av, "burning_ship") == 0)
		env->x = -0.25;
	else
		env->x = 0;
	if (ft_strcmp(env->av, "burning_ship") == 0)
		env->y = -0.5;
	else if (ft_strcmp(env->av, "buffalo") == 0)
		env->y = -0.25;
	else
		env->y = 0;
}

int		init_structure(t_env *env, char *av)
{
	if (!(env->mlx_ptr = mlx_init())
	|| !(env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "FRACTOL"))
	|| !(env->img_ptr = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT))
	|| !(env->img_data_ptr = mlx_get_data_addr(env->img_ptr, &(env->bpp),
	&(env->s_l), &(env->endian)))
	|| !(env->color = (t_color *)malloc(sizeof(t_color))))
		return (0);
	env->color->relief = 0;
	env->color->freq = 0.1;
	env->color->phase_1 = 4;
	env->color->phase_2 = 2;
	env->color->phase_3 = 1;
	env->av = av;
	env->menu = 0;
	env->julia = 0;
	env->mandelbrot = 0;
	env->psyche = 0;
	env->zoom = 1;
	env->max_it = 50;
	env->r_c = -0.7;
	env->i_c = 0.27015;
	init_fractal(env);
	return (1);
}

int		fractol(char *av)
{
	t_env *env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	init_structure(env, av);
	create_threads(env);
	mlx_hook(env->win_ptr, 6, (1L << 6), mouse_move, env);
	mlx_hook(env->win_ptr, 4, (1L << 2), mouse_press, env);
	mlx_hook(env->win_ptr, 5, (1L << 3), mouse_release, env);
	mlx_hook(env->win_ptr, 2, (1L << 0), deal_key, env);
	mlx_loop(env->mlx_ptr);
	return (1);
}
