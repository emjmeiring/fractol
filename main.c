#include "fractol.h"

void	init_goods(t_goods *g)
{
	g->mouse.x = 0;
	g->mouse.y = 0;
	g->mouse.z_x = 0;
	g->mouse.z_y = 0;
	g->mouse.zoom = 1;
	g->c.r = 0;
	g->c.i = 0;
	g->c.new_r = 0;
	g->c.new_i = 0;
	g->c.old_r = 0;
	g->c.old_i = 0;
	g->set = 0;
}

void	draw(t_goods *g)
{
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->data = mlx_get_data_addr(g->img, &g->bpp, &g->size_l, &g->endian);
	if (g->set == 1)
	{
		julia(g);
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
}

int		main(int argc, char **argv)
{
	t_goods g;

	init_goods(&g);
	if (argc == 2)
	{
		g.mlx = mlx_init();
		g.win = mlx_new_window(g.mlx, WIDTH, HEIGHT, "Fractal");
		if (ft_strcmp(argv[1],"1") == 0)
		{
			g.set = 1;
			draw(&g);
		}
		else if (ft_strcmp(argv[1],"2") == 0)
		{
			g.set = 2;
			draw(&g);
		}
	}
	else
	{
		write(1, "pass '1' as argumanet for the ", 30);
		write(1, "julia set\n", 10);
		write(1, "or '2' for mandelbrot\n", 20);
		return(0);
	}
	mlx_key_hook(g.win, &key_press, &g);
	mlx_mouse_hook(g.win, &mouse_button, &g);
	mlx_hook(g.win, 6, (1L << 6), &mouse_move, &g);
	mlx_hook(g.win, 17, 0L, &quit, &g);
	mlx_expose_hook(g.win, &expose, &g);
	mlx_loop(g.mlx);
	return (0);
}
