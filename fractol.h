#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

# define WIDTH 1080
# define HEIGHT 720
# define ESC 53
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20

typedef	struct	s_complex
{
	long double i;
	long double r;
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

void			julia(t_goods *g);
int				ft_strcmp(const char *s1, const char *s2);
int				quit(t_goods *g);
int				key_press(int keycode, t_goods *g);
int				mouse_button(int key, int x, int y, t_goods *g);
int				mouse_move(int x, int y, t_goods *g);
int				expose(t_goods *g);
void			draw(t_goods *g);
#endif
