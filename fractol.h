#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <stdio.h>

# define WIDTH 780
# define HEIGHT 680
# define ESC 53
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20

typedef	struct	s_complex
{
	long double im;
	long double rl;
	long double new_r;
	long double new_i;
	long double old_r;
	long double old_i;
}				t_complex;

typedef struct	s_mouse_specs
{
	double		x;
	double		y;
	double		z_x;
	double		z_y;
	double		zoom;
}				t_m;

typedef	struct	s_goodies
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	t_m			mouse;
	t_complex	c;
	int			bpp;
	int			size_l;
	int			endian;
	int			set;
	
}				t_goods;

#endif
