/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:39:11 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/16 15:47:56 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		close_program(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	ft_memdel((void **)&(env->color));
	ft_memdel((void **)&(env));
	exit(EXIT_SUCCESS);
}

void	clear_window(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT);
	env->img_data_ptr = mlx_get_data_addr(env->img_ptr, &(env->bpp),
	&(env->s_l), &(env->endian));
}

void	display_usage(void)
{
	ft_putstr("Usage : ./fractol [fractal_name] : [julia], [mandelbrot], ");
	ft_putstr("[burning_ship], [tricorn], [celtic_mandelbar], ");
	ft_putstr("[celtic_mandelbrot], [buffalo], [celtic_heart].\n\n");
	ft_putstr("[TAB] : Print menu.");
	exit(EXIT_FAILURE);
}

void	check_arg(char *av)
{
	if (ft_strcmp(av, "julia") == 0)
		fractol("julia");
	else if (ft_strcmp(av, "mandelbrot") == 0)
		fractol("mandelbrot");
	else if (ft_strcmp(av, "burning_ship") == 0)
		fractol("burning_ship");
	else if (ft_strcmp(av, "tricorn") == 0)
		fractol("tricorn");
	else if (ft_strcmp(av, "celtic_mandelbar") == 0)
		fractol("celtic_mandelbar");
	else if (ft_strcmp(av, "celtic_mandelbrot") == 0)
		fractol("celtic_mandelbrot");
	else if (ft_strcmp(av, "buffalo") == 0)
		fractol("buffalo");
	else if (ft_strcmp(av, "celtic_heart") == 0)
		fractol("celtic_heart");
	else
		display_usage();
}

int		main(int ac, char **av)
{
	if (ac == 2)
		check_arg(av[1]);
	else
		display_usage();
	exit(EXIT_SUCCESS);
}
