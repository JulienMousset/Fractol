/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:07:07 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/15 16:25:41 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_mandelbrot_screen(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y <= 600)
	{
		x = 0;
		while (x <= 800)
		{
			mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, 0x151515);
			x++;
		}
		y++;
	}
	mlx_string_put(env->mlx_ptr, env->win_ptr, 135, 285, 0xFFF8FF,
	"You chose a Julia fractal : RIGHT CLICK to continue.");
	env->mandelbrot = 1;
}

void	print_menu_text(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 60, YELLOW, env->av);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 120, WHITE,
	"[ESC] : close program");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 160, WHITE,
	"[TAB] : close menu");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 200, WHITE,
	"[1][2][3][4][5][6][7][8] : switch fractal");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 240, WHITE,
	"[ARROW KEYS] : move");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 280, WHITE,
	"[MOUSE WHEEL] : zoom");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 320, WHITE,
	"[Q][E] : zoom on center");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 360, WHITE,
	"[<][>] : change precision");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 400, WHITE,
	"[W][S][A][D]: change colors");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 440, WHITE,
	"[O] : switch to relief mode");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 480, WHITE,
	"[P] : switch to psyche mode (zoom)");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 60, 520, WHITE, "R : reset");
}

void	print_square(t_env *env)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 50;
	while (y <= 550)
	{
		x = 50;
		while (x <= 750)
		{
			if (x == 50 || x == 750 || y == 50 || y == 550)
				mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, 0xFFF8FF);
			else
				mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, 0x003A8E * i *
				WIDTH * HEIGHT * 1000000000000000000);
			x++;
			i++;
		}
		y++;
	}
}

void	print_menu(t_env *env)
{
	if (env->menu == 0 && env->mandelbrot == 0)
	{
		env->menu = 1;
		print_square(env);
		print_menu_text(env);
	}
	else if (env->menu == 1)
	{
		env->menu = 0;
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	}
}
