/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:30:41 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/17 18:05:38 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	lst_max(t_filler *filler)
{
	double		max;
	t_list		*lst;
	t_solution	s;

	lst = filler->sol;
	max = 0;
	while (lst)
	{
		s = *(t_solution*)lst->content;
		max = (s.ratio > max) ? s.ratio : max;
		lst = lst->next;
	}
	filler->lst_max = max;
}

int		lst_count_max(t_filler *filler)
{
	double		nbr;
	t_list		*lst;
	t_solution	s;

	lst = filler->sol;
	nbr = 0;
	while (lst)
	{
		s = *(t_solution*)lst->content;
		nbr += (s.ratio == filler->lst_max) ? 1 : 0;
		lst = lst->next;
	}
	return (nbr);
}

int		lst_count_useless(t_filler *filler)
{
	double		nbr;
	t_list		*lst;
	t_solution	s;

	lst = filler->sol;
	nbr = 0;
	filler->lst_useless = 0;
	while (lst)
	{
		s = *(t_solution*)lst->content;
		if (s.ratio == filler->lst_max)
		{
			if (s.nbr_o == filler->prev_o && s.nbr_x == filler->nbr_x)
			{
				filler->lst_useless = 1;
				++nbr;
			}
		}
		lst = lst->next;
	}
	return (nbr);
}
