/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:18:26 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/16 15:47:00 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>
# include "mlx.h"
# include "libft/libft.h"

# define WIDTH 800
# define HEIGHT 600
# define THREADS 8

# define TAB 48
# define ESC 53
# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21
# define FIVE 23
# define SIX 22
# define SEVEN 26
# define EIGHT 28
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define Q 12
# define E 14
# define LEFT_ARROW 43
# define RIGHT_ARROW 47
# define W 13
# define S 1
# define A 0
# define D 2
# define O 31
# define P 35
# define SHIFT 257
# define R 15

# define WHITE 0xFFF8FF
# define YELLOW 0xFFDB58

typedef struct	s_color
{
	int			relief;
	double		freq;
	int			phase_1;
	int			phase_2;
	int			phase_3;
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data_ptr;
	int			bpp;
	int			s_l;
	int			endian;
	char		*av;
	int			menu;
	int			julia;
	int			mandelbrot;
	int			psyche;
	double		zoom;
	int			max_it;
	double		r_c;
	double		i_c;
	double		x;
	double		y;
	t_color		*color;
}				t_env;

typedef struct	s_thread
{
	pthread_t	t;
	int			n;
	t_env		*env;
}				t_thread;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_complex
{
	double		r;
	double		i;
}				t_complex;

void			check_arg(char *av);
void			display_usage(void);
void			clear_window(t_env *env);
int				close_program(t_env *env);

int				fractol(char *av);
int				init_structure(t_env *env, char *av);
void			init_fractal(t_env *env);
void			choose_fractal(t_env *env, t_coord p);
int				rgb_to_int(int r, int g, int b);

void			julia(t_env *env, t_coord p);
void			mandelbrot(t_env *env, t_coord p);
void			burning_ship(t_env *env, t_coord p);
void			tricorn(t_env *env, t_coord p);

void			celtic_mandelbar(t_env *env, t_coord p);
void			celtic_mandelbrot(t_env *env, t_coord p);
void			buffalo(t_env *env, t_coord p);
void			celtic_heart(t_env *env, t_coord p);

void			create_threads(t_env *env);
void			*draw(void *vt);
void			free_t(t_thread *t);
void			put_pixel(t_env *env, t_coord p, int n, t_complex z);
int				get_color(t_color *color, int max_it, int i, t_complex new);

int				deal_key(int key, t_env *env);
void			switch_fractals(int key, t_env *env);
void			move(int key, t_env *env);
void			change_max_iterations(int key, t_env *env);
int				center_zoom(int key, t_env *env);

void			relief_mode(int key, t_env *env);
void			change_color(int key, t_env *env);
void			reset(t_env *env);
void			change_freq_phases(int value, t_env *env);

int				mouse_move(int x, int y, t_env *env);
int				mouse_press(int button, int x, int y, t_env *env);
int				mouse_release(int button, int x, int y, t_env *env);
void			mandelbrot_select(int button, int x, int y, t_env *env);
void			zoom(int x, int y, t_env *env);

void			print_menu(t_env *env);
void			print_square(t_env *env);
void			print_menu_text(t_env *env);
void			print_mandelbrot_screen(t_env *env);
#endif
