/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:31:41 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/13 22:06:49 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_part1(t_pos *d, t_pos *pos, t_pos *inc, t_map *map)
{
	int		cumul;
	int		i;

	cumul = d->x / 2;
	i = 1;
	while (i <= d->x)
	{
		pos->x += inc->x;
		cumul += d->y;
		if (cumul >= d->x)
		{
			cumul -= d->x;
			pos->y += inc->y;
		}
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, pos->x, pos->y, map->color);
		i++;
	}
}

void	ft_part2(t_pos *d, t_pos *pos, t_pos *inc, t_map *map)
{
	int		cumul;
	int		i;

	cumul = d->y / 2;
	i = 1;
	while (i <= d->y)
	{
		pos->y += inc->y;
		cumul += d->x;
		if (cumul >= d->y)
		{
			cumul -= d->y;
			pos->x += inc->x;
		}
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, pos->x, pos->y, map->color);
		i++;
	}
}

/*
** - Fonction de tracage de droite
** - Non affichage hors champs
*/

int		ft_abs(int val)
{
	if (val < 0)
		val = -val;
	return (val);
}

void	ft_draw_line(t_pos *a, t_pos *b, t_map *map, int color)
{
	t_pos	d;
	t_pos	inc;
	t_pos	pos;

	if ((a->x < 0 || a->x > map->map_w || a->y < 0 || a->y > map->map_h)
	&& (b->x < 0 || b->x > map->map_w || b->y < 0 || b->y > map->map_h))
		if (!(a->y < 0 && b->y > map->map_h))
			if (!(b->y < 0 && a->y > map->map_h))
				if (!(a->x < 0 && b->x > map->map_h))
					if (!(b->x < 0 && a->x > map->map_h))
						return ;
	map->color = color;
	pos.x = a->x;
	pos.y = a->y;
	d.x = b->x - a->x;
	d.y = b->y - a->y;
	inc.x = (d.x > 0) ? 1 : -1;
	inc.y = (d.y > 0) ? 1 : -1;
	d.x = ft_abs(d.x);
	d.y = ft_abs(d.y);
	mlx_pixel_put(map->mlx_ptr, map->win_ptr, pos.x, pos.y, map->color);
	if (d.x > d.y)
		ft_part1(&d, &pos, &inc, map);
	else
		ft_part2(&d, &pos, &inc, map);
}
