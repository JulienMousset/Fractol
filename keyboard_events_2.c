/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:23:15 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/16 13:49:32 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_freq_phases(int value, t_env *env)
{
	if (value == -1)
	{
		env->color->freq -= 0.2;
		env->color->phase_1 -= 1;
		env->color->phase_2 -= 1;
		env->color->phase_3 -= 1;
	}
	if (value == 1)
	{
		env->color->freq += 0.2;
		env->color->phase_1 += 1;
		env->color->phase_2 += 1;
		env->color->phase_3 += 1;
	}
}

void	reset(t_env *env)
{
	clear_window(env);
	env->color->relief = 0;
	env->color->freq = 0.1;
	env->color->phase_1 = 4;
	env->color->phase_2 = 2;
	env->color->phase_3 = 1;
	env->zoom = 1;
	env->max_it = 50;
	env->r_c = -0.7;
	env->i_c = 0.27015;
	env->psyche = 0;
	init_fractal(env);
	create_threads(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

void	change_color(int key, t_env *env)
{
	clear_window(env);
	if (key == W)
		env->color->freq += 0.02;
	if (key == S)
		env->color->freq -= 0.02;
	if (key == A)
	{
		env->color->phase_1 -= 1;
		env->color->phase_2 -= 1;
		env->color->phase_3 -= 1;
	}
	if (key == D)
	{
		env->color->phase_1 += 1;
		env->color->phase_2 += 1;
		env->color->phase_3 += 1;
	}
	create_threads(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

void	relief_mode(int key, t_env *env)
{
	clear_window(env);
	if (key == O)
	{
		if (env->color->relief == 0)
			env->color->relief = 1;
		else
			env->color->relief = 0;
	}
	if (key == P)
	{
		if (env->psyche == 0)
			env->psyche = 1;
		else
			env->psyche = 0;
	}
	create_threads(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}
