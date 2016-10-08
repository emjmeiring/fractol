#include "fractol.h"

int		quit(t_goods *g)
{
	mlx_destroy_image(g->mlx, g->img);
	exit(0);
}

int	key_press(int keycode, t_goods *g)
{
	if (keycode == ESC)
		quit(g);
	return (0);
}

int	mouse_button(int key, int x, int y, t_goods *g)
{
	if (g->set != 0)
	{
		if (key == 4)
		{
			g->mouse.z_x = (double)x * 0.001;
			g->mouse.z_y = (double)y * 0.001;
			g->mouse.zoom += .5;
		}
		else if (key == 5)
		{
			g->mouse.z_x = x;
			g->mouse.z_y = y;
			g->mouse.zoom -= 0.5;
		}
		mlx_destroy_image(g->mlx, g->img);
		draw(g);
	}
	return (0);
}

int	mouse_move(int x, int y, t_goods *g)
{
	if (g->set != 0)
	{
		g->mouse.x = (double)x * 0.001;
		g->mouse.y = (double)y * 0.001;
		mlx_destroy_image(g->mlx, g->img);
		draw(g);
	}
	return (0);
}

int expose(t_goods *g)
{
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	return (0);
}