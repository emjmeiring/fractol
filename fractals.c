void	julia(t_goods *g)
{
	int		max;
	int		x;
	int		y;
	int		i;
	
	y = 0;
	max = 100;
	g->c.r = -0.7;
	g->c.i = .27015;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			i = 0;
			g->c.new_r = 1.5 * (x - WIDTH * .5) / (.5 *g->mouse.zoom * WIDTH) + g->mouse.z_x;
			g->c.new_i = (y - HEIGHT * .5) / (.5 * g->mouse.zoom * WIDTH) + g->mous.z_y;
			while (i < max && (g->c.new_r *g->c.new_r + g->c.new_i * g->c.newi) < 5)
			{
				g->c.old_r = g->c.new_r;
				g->c.old_i = g->c.new_i;
				g->c.new_r = g->c.old_r * g->c.old_r - g->c.old_i * g->c.old_i + g->c.r;
				g->c.new_i = 2 * g->c.old_r * g->c.old_i + g->c.i;
				i++;
			}
			g->data[(x * 4) + (y * g->size_l) + 2] = i;
			g->data[(x * 4) + (y * g->size_l) + 1] = i;
			g->data[(x * 4) + (y * g->size_l)] = i;
			x++;
		}
		y++;
	}
}
