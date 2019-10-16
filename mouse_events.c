/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:51:27 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/16 13:53:08 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int x, int y, t_env *env)
{
	double		move;

	move = 0.15 / env->zoom;
	if (WIDTH / 2 < x)
		env->x += move;
	else if (WIDTH / 2 > x)
		env->x -= move;
	if (HEIGHT / 2 < y)
		env->y += move;
	else if (HEIGHT / 2 > y)
		env->y -= move;
}

void	mandelbrot_select(int button, int x, int y, t_env *env)
{
	clear_window(env);
	env->zoom = 1;
	env->max_it = 50;
	env->r_c = 2 * (double)x / WIDTH - 1;
	env->i_c = 2 * (double)y / HEIGHT - 1;
	env->x = 0;
	env->y = 0;
	env->av = "julia";
	print_mandelbrot_screen(env);
	if (button == 2)
	{
		create_threads(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	}
}

int		mouse_release(int button, int x, int y, t_env *env)
{
	if (ft_strcmp(env->av, "mandelbrot") == 0 && button == 1 && env->menu == 0)
		mandelbrot_select(button, x, y, env);
	if (ft_strcmp(env->av, "julia") == 0 && button == 2 && env->menu == 0)
	{
		clear_window(env);
		env->mandelbrot = 0;
		if (env->julia == 0)
			env->julia = 1;
		else
			env->julia = 0;
		create_threads(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	}
	return (0);
}

int		mouse_press(int button, int x, int y, t_env *env)
{
	if (env->menu == 0 && env->mandelbrot == 0)
	{
		clear_window(env);
		if (button == 4)
		{
			zoom(x, y, env);
			env->zoom += 0.2 * env->zoom;
			env->max_it++;
			if (env->psyche == 1)
				change_freq_phases(1, env);
		}
		if (button == 5 && env->menu == 0 && env->mandelbrot == 0)
		{
			if (env->zoom <= 0.05)
				return (0);
			zoom(x, y, env);
			env->zoom += 0.2 * -env->zoom;
			env->max_it--;
			if (env->psyche == 1)
				change_freq_phases(-1, env);
		}
		create_threads(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	}
	return (0);
}

int		mouse_move(int x, int y, t_env *env)
{
	if (env->julia == 0 && ft_strcmp(env->av, "julia") == 0 && env->menu == 0 &&
	env->mandelbrot == 0)
	{
		clear_window(env);
		env->r_c = 2 * (double)x / WIDTH - 1;
		env->i_c = 2 * (double)y / HEIGHT - 1;
		create_threads(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	}
	return (0);
}
