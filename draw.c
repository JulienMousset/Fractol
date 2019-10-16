/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:30:04 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/16 13:34:21 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(t_color *color, int max_it, int i, t_complex new)
{
	t_color	colors;
	double	n;

	if (i == max_it)
		return (0x000000);
	if (color->relief == 0)
		n = i + 1 + ((log(2) / fabs(new.r * new.r + new.i * new.i))) / log(2);
	if (color->relief == 1)
		n = i + 1 - (log(2) / 2 * (new.r * new.r + new.i * new.i)) / log(2);
	colors.r = sin(color->freq * n + color->phase_1) * 127.5 + 127.5;
	colors.g = sin(color->freq * n + color->phase_2) * 127.5 + 127.5;
	colors.b = sin(color->freq * n + color->phase_3) * 127.5 + 127.5;
	return (rgb_to_int(colors.r, colors.g, colors.b));
}

void	put_pixel(t_env *env, t_coord p, int n, t_complex new)
{
	int		color;
	int		i;

	i = 0;
	color = get_color(env->color, env->max_it, n, new);
	if ((p.x >= 0 && p.x <= WIDTH) && (p.y >= 0 && p.y <= HEIGHT))
	{
		i = ((p.x * (env->bpp / 8)) + (p.y * env->s_l));
		env->img_data_ptr[i] = color;
		env->img_data_ptr[++i] = color >> 8;
		env->img_data_ptr[++i] = color >> 16;
	}
}

void	free_t(t_thread *t)
{
	int		i;

	i = 0;
	while (i < THREADS)
	{
		t[i].env = NULL;
		i++;
	}
	ft_memdel((void **)&(t));
}

void	*draw(void *vt)
{
	t_coord		p;
	t_thread	*t;
	int			y_max;

	t = (t_thread *)vt;
	p.y = HEIGHT * t->n / THREADS;
	y_max = HEIGHT * (t->n + 1) / THREADS;
	while (p.y < y_max)
	{
		p.x = 0;
		while (p.x < WIDTH)
		{
			choose_fractal(t->env, p);
			p.x++;
		}
		p.y++;
	}
	return (0);
}

void	create_threads(t_env *env)
{
	t_thread	*t;
	int			i;

	t = (t_thread *)malloc(sizeof(t_thread) * THREADS);
	i = 0;
	while (i < THREADS)
	{
		t[i].n = i;
		t[i].env = env;
		pthread_create(&t[i].t, NULL, draw, &t[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(t[i].t, NULL);
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	free_t(t);
}
