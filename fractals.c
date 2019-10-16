/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:23:53 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/14 18:28:15 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_env *env, t_coord p)
{
	t_complex	old;
	t_complex	new;
	int			i;

	i = 0;
	new.r = 1.5 * (p.x - WIDTH / 2) / (0.5 * env->zoom * WIDTH) + env->x;
	new.i = (p.y - HEIGHT / 2) / (0.5 * env->zoom * HEIGHT) + env->y;
	while ((i < env->max_it) && (new.r * new.r + new.i * new.i < 4))
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + env->r_c;
		new.i = 2 * old.r * old.i + env->i_c;
		i++;
	}
	put_pixel(env, p, i, new);
}

void	mandelbrot(t_env *env, t_coord p)
{
	t_complex	old;
	t_complex	new;
	t_complex	c;
	int			i;

	i = 0;
	old.r = 0;
	old.i = 0;
	new.r = 0;
	new.i = 0;
	c.r = 1.5 * (p.x - WIDTH / 2) / (0.5 * env->zoom * WIDTH) + env->x;
	c.i = (p.y - HEIGHT / 2) / (0.5 * env->zoom * HEIGHT) + env->y;
	while ((i < env->max_it) && (new.r * new.r + new.i * new.i < 4))
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + c.r;
		new.i = 2 * old.r * old.i + c.i;
		i++;
	}
	put_pixel(env, p, i, new);
}

void	burning_ship(t_env *env, t_coord p)
{
	t_complex	old;
	t_complex	new;
	t_complex	c;
	int			i;

	i = 0;
	old.r = 0;
	old.i = 0;
	new.r = 0;
	new.i = 0;
	c.r = 1.75 * (p.x - WIDTH / 2) / (0.5 * env->zoom * WIDTH) + env->x;
	c.i = 1.25 * (p.y - HEIGHT / 2) / (0.5 * env->zoom * HEIGHT) + env->y;
	while ((i < env->max_it) && (new.r * new.r + new.i * new.i < 4))
	{
		old.r = new.r;
		old.i = new.i;
		new.r = fabs((old.r * old.r - old.i * old.i + c.r));
		new.i = fabs((2 * old.r * old.i + c.i));
		i++;
	}
	put_pixel(env, p, i, new);
}

void	tricorn(t_env *env, t_coord p)
{
	t_complex	old;
	t_complex	new;
	t_complex	c;
	int			i;

	i = 0;
	old.r = 0;
	old.i = 0;
	new.r = 0;
	new.i = 0;
	c.r = 2 * (p.x - WIDTH / 2) / (0.5 * env->zoom * WIDTH) + env->x;
	c.i = 1.5 * (p.y - HEIGHT / 2) / (0.5 * env->zoom * HEIGHT) + env->y;
	while ((i < env->max_it) && (new.r * new.r + new.i * new.i < 4))
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + c.r;
		new.i = -2 * old.r * old.i + c.i;
		i++;
	}
	put_pixel(env, p, i, new);
}
