/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   territory_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 17:30:28 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/15 16:27:10 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	clean(t_filler *filler)
{
	int	i;
	int	j;

	j = 0;
	while (j < filler->y)
	{
		i = 0;
		while (i < filler->x)
		{
			if (filler->territory_o[j][i] == '.')
			{
				filler->territory_o[j][i] = ' ';
				filler->territory_x[j][i] = ' ';
				filler->territory_r[j][i] = ' ';
			}
			++i;
		}
		++j;
	}
}

static void	fill_y(t_filler *filler, int j, char c)
{
	int	x;
	char	a;

	x = 0;
	while (filler->territory_o[j][x])
	{
		a = filler->territory_o[j][x];
		if (a == ' ')
			filler->territory_o[j][x] = c;
		++x;
	}
}

static void	fill_x(t_filler *filler, int i, char c)
{
	int	y;
	char	a;

	y = 0;
	while (y < filler->y)
	{
		a = filler->territory_o[y][i];
		if (a == ' ')
			filler->territory_o[y][i] = c;
		++y;
	}
}

static void	control(t_filler *filler, int i, int j, char nb)
{
	int	x;
	int	y;
	char	a;
	char	c;
	char	stop;
	int	depth;

	stop = 0;
	depth = 1;
	c = (nb == 1) ? 'x' : 'o';
	while (stop == 0)
	{
		y = -depth;
		while (y <= depth && !stop)
		{
			x = -depth;
			while (x <= depth && !stop)
			{
				if (i + x >= 0 && j + y >= 0 && i + x < filler->x && j + y < filler->y)
				{
					a = (nb == 1)
						? filler->territory_o[j + y][i + x]
						: filler->territory_x[j + y][i + x];
					if (a == ' ')
					{
						(nb == 1) ? filler->territory_o[j + y][i + x] = nb + 48 : 0;
						(nb == 2) ? filler->territory_x[j + y][i + x] = nb + 48 : 0;
					}
					else if (a == c || a == c - 32)
						stop = 1;
				}
				++x;
			}
			++y;
		}
		++depth;
	}
}

static void get_result(t_filler *filler)
{
	int	x;
	int	y;
	char a;
	char b;

	y = 0;
	while (y < filler->y)
	{
		x = 0;
		while (x < filler->x)
		{
			a = filler->territory_o[y][x];
			b = filler->territory_x[y][x];
			if (a == '1' && b == '2')
				filler->territory_r[y][x] = ' ';
			else if (a == '1' && b == ' ')
				filler->territory_r[y][x] = '1';
			else if (a == ' ' && b == '2')
				filler->territory_r[y][x] = '2';
			++x;
		}
		++y;
	}
}

static void	get_territory(t_filler *filler)
{
	int	i;
	int	j;
	char	c;
	char	a;
	char	stop;

	j = 0;
	stop = 0;
	while (j < filler->y)
	{
		i = 0;
		while (i < filler->x)
		{
			a = filler->territory_o[j][i];
			if (a == 'o' || a == 'O')
				control(filler, i, j, 1);
			a = filler->territory_x[j][i];
			if (a == 'x' || a == 'X')
				control(filler, i, j, 2);
			++i;
		}
		++j;
	}
	get_result(filler);
}

void	territory_control(t_filler *filler)
{
	int	i;
	int	j;

	j = 0;
	ft_putstr_fd("\n", 2);
	clean(filler);
	get_territory(filler);
	while (j < filler->y + 2)
	{
		ft_putstr_fd("|", 2);
		i = 0;
		while (i < filler->x)
		{
			if (j == 0 || j == filler->y + 1)
				ft_putchar_fd('-', 2);
			else if (j < filler->y + 1)
			{
				ft_putstr_fd(filler->territory_r[j - 1], 2);
				break ;
			}
			++i;
		}
		ft_putstr_fd("|\n", 2);
		++j;
	}
}
