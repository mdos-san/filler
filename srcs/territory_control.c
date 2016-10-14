/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   territory_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 17:30:28 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/14 19:28:43 by mdos-san         ###   ########.fr       */
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
			if (filler->territory[j][i] == '.')
				filler->territory[j][i] = ' ';
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
	while (filler->territory[j][x])
	{
		a = filler->territory[j][x];
		if (a == ' ')
			filler->territory[j][x] = c;
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
		a = filler->territory[y][i];
		if (a == ' ')
			filler->territory[y][i] = c;
		++y;
	}
}

static void	get_territory(t_filler *filler)
{
	int	i;
	int	j;
	char	c;
	char	a;

	j = 0;
	while (j < filler->y)
	{
		i = 0;
		while (i < filler->x)
		{
			a = filler->territory[j][i];
			if (a != ' ' && a != '1' && a != '2')
			{
				c = (a == 'o' || a == 'O' || a == '1') ? '1' : '2';
				fill_y(filler, j, c);
				fill_x(filler, i, c);
			}
			++i;
		}
		++j;
	}
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
				ft_putstr_fd(filler->territory[j - 1], 2);
				break ;
			}
			++i;
		}
		ft_putstr_fd("|\n", 2);
		++j;
	}
}
