/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:00:46 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/14 18:26:25 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	celtic_mandelbar(t_env *env, t_coord p)
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
	c.i = 1 * (p.y - HEIGHT / 2) / (0.5 * env->zoom * HEIGHT) + env->y;
	while ((i < env->max_it) && (new.r * new.r + new.i * new.i < 4))
	{
		old.r = new.r;
		old.i = new.i;
		new.r = fabs(old.r * old.r - old.i * old.i) + c.r;
		new.i = -2 * old.r * old.i + c.i;
		i++;
	}
	put_pixel(env, p, i, new);
}

void	celtic_mandelbrot(t_env *env, t_coord p)
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
		new.r = fabs(old.r * old.r - old.i * old.i) + c.r;
		new.i = 2 * old.r * old.i + c.i;
		i++;
	}
	put_pixel(env, p, i, new);
}

void	buffalo(t_env *env, t_coord p)
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
		new.r = fabs(old.r * old.r - old.i * old.i) + c.r;
		new.i = 2 * fabs(old.r * old.i) + c.i;
		i++;
	}
	put_pixel(env, p, i, new);
}

void	celtic_heart(t_env *env, t_coord p)
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
		new.r = fabs(old.r * old.r - old.i * old.i) + c.r;
		new.i = 2 * fabs(old.r) * old.i + c.i;
		i++;
	}
	put_pixel(env, p, i, new);
}
