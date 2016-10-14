/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   territory_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 17:30:28 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/14 18:07:45 by mdos-san         ###   ########.fr       */
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

void	territory_control(t_filler *filler)
{
	int	i;
	int	j;

	j = 0;
	ft_putstr_fd("\n", 2);
	clean(filler);
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
