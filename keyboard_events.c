/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:53:16 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/16 13:48:59 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	switch_fractals(int key, t_env *env)
{
	clear_window(env);
	env->zoom = 1;
	env->max_it = 50;
	if (key == ONE)
		env->av = "julia";
	if (key == TWO)
		env->av = "mandelbrot";
	if (key == THREE)
		env->av = "burning_ship";
	if (key == FOUR)
		env->av = "tricorn";
	if (key == FIVE)
		env->av = "celtic_mandelbar";
	if (key == SIX)
		env->av = "celtic_mandelbrot";
	if (key == SEVEN)
		env->av = "buffalo";
	if (key == EIGHT)
		env->av = "celtic_heart";
	init_fractal(env);
	create_threads(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

void	move(int key, t_env *env)
{
	clear_window(env);
	if (key == UP)
		env->y += 0.05 / env->zoom;
	if (key == DOWN)
		env->y -= 0.05 / env->zoom;
	if (key == LEFT)
		env->x += 0.05 / env->zoom;
	if (key == RIGHT)
		env->x -= 0.05 / env->zoom;
	create_threads(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

void	change_max_it(int key, t_env *env)
{
	clear_window(env);
	if (env->max_it <= 0)
		env->max_it = 0;
	if (key == LEFT_ARROW)
		env->max_it -= 2;
	if (key == RIGHT_ARROW)
		env->max_it += 2;
	create_threads(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

int		center_zoom(int key, t_env *env)
{
	clear_window(env);
	if (key == Q)
	{
		if (env->zoom <= 0.05)
			return (0);
		env->zoom *= 0.9;
		env->max_it--;
		if (env->psyche == 1)
			change_freq_phases(-1, env);
	}
	if (key == E)
	{
		env->zoom *= 1.1;
		env->max_it++;
		if (env->psyche == 1)
			change_freq_phases(1, env);
	}
	create_threads(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	return (0);
}

int		deal_key(int key, t_env *env)
{
	if (key == TAB)
		print_menu(env);
	if (key == ESC)
		close_program(env);
	if ((key == ONE || key == TWO || key == THREE || key == FOUR || key == FIVE
	|| key == SIX || key == SEVEN || key == EIGHT) && env->menu == 0
	&& env->mandelbrot == 0)
		switch_fractals(key, env);
	if ((key == UP || key == DOWN || key == LEFT || key == RIGHT)
	&& env->menu == 0 && env->mandelbrot == 0)
		move(key, env);
	if ((key == LEFT_ARROW || key == RIGHT_ARROW) && env->menu == 0
	&& env->mandelbrot == 0)
		change_max_it(key, env);
	if ((key == Q || key == E) && env->menu == 0 && env->mandelbrot == 0)
		center_zoom(key, env);
	if ((key == O || key == P) && env->menu == 0 && env->mandelbrot == 0)
		relief_mode(key, env);
	if ((key == W || key == S || key == A || key == D) && env->menu == 0
	&& env->mandelbrot == 0)
		change_color(key, env);
	if (key == R && env->menu == 0 && env->mandelbrot == 0)
		reset(env);
	return (0);
}
