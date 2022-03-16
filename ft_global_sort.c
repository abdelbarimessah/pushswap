/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:35:09 by amessah           #+#    #+#             */
/*   Updated: 2022/03/15 16:48:35 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init(t_stacks *s)
{
	s->tall_loop = find_biggest_loop(s->a, 1);
	s->size = list_size(s->a);
	s->grp_cont = ft_max(1, (int)(s->max / 150.0));
	s->grp_size = s->max / s->grp_cont;
}

int	distance_to_top(t_stack *a, int tag)
{
	int	i;
	int	size;

	i = 0;
	size = list_size(a);
	while (a)
	{
		if (a->index == tag)
			break ;
		a = a->next;
		i++;
	}
	if (i > size / 2)
		i -= size;
	return (i);
}

t_stack	*closet_in_group(t_stack *list, int cur_grp, int grp_size)
{
	t_stack	*closet;
	t_stack	*cur;
	int		dis;
	int		cur_dist;

	dis = 8000000;
	closet = NULL;
	cur = list;
	while (cur)
	{
		if (cur->index <= grp_size * cur_grp && !cur->keep)
		{
			cur_dist = distance_to_top(list, cur->index);
			if (abs(cur_dist) < abs(dis))
			{
				dis = cur_dist;
				closet = cur;
				if (dis == 0)
					break ;
			}
		}
		cur = cur->next;
	}
	return (closet);
}

int	distance_to_tag(int tag, int size)
{
	if (tag >= size / 2)
		tag -= size;
	return (tag);
}

void	ft_global_sort(t_stacks *s, int cur_grp)
{
	int	distance;

	ft_init(s);
	while (s->size >= s->tall_loop && cur_grp <= (s->grp_cont + 1))
	{
		s->temp = closet_in_group(s->a, cur_grp, s->grp_size);
		if (s->temp == NULL && ++cur_grp)
			continue ;
		distance = distance_to_top(s->a, s->temp->index);
		if (s->a && !s->a->keep && distance == 0)
		{
			pb(s, 1);
			(s->size)--;
		}
		else
			rr(s, 1);
	}
	populate_b(s);
}
