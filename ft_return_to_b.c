/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:37:25 by amessah           #+#    #+#             */
/*   Updated: 2022/03/15 17:04:47 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_rotate(t_stacks *mem, int *rot_a, int *rot_b)
{
	while (*rot_a > 0 && *rot_b > 0)
	{
		(*rot_a)--;
		(*rot_b)--;
		rr(mem, 1);
	}
	while (*rot_a < 0 && *rot_b < 0)
	{
		(*rot_a)++;
		(*rot_b)++;
		rrr(mem, 1);
	}
}

void	rotate(t_stacks *mem, int rot_a, int rot_b)
{
	double_rotate(mem, &rot_a, &rot_b);
	while (rot_a > 0)
	{
		rot_a--;
		ra(&mem->a, 1);
	}
	while (rot_a < 0)
	{
		rot_a++;
		rra(&mem->a, 1);
	}
	while (rot_b > 0)
	{
		rot_b--;
		rb(&mem->b, 1);
	}
	while (rot_b < 0)
	{
		rot_b++;
		rrb(&mem->b, 1);
	}
}

int	insert_distance(t_stack *list, int t, int size)
{
	t_stack	*p;
	t_stack	*c;
	int		i;
	int		moves[2];

	i = 0;
	p = get_last(list);
	c = list;
	moves[1] = 8000000;
	while (c)
	{
		if ((p->index > c->index && (t < c->index || t > p->index))
			|| (t > p->index && t < c->index))
		{
			moves[0] = i;
			if (moves[0] > size / 2)
				moves[0] = moves[0] - size;
			if (abs(moves[0]) < moves[1])
				moves[1] = moves[0];
		}
		p = c;
		c = c->next;
		i++;
	}
	return (moves[1]);
}

void	calculate_b_rotation(t_stacks *m, int max_dist, int *rot_a, int *rot_b)
{
	int	dist_total;
	int	insert;
	int	distance_b;
	int	i;

	i = 0;
	m->temp = m->b;
	while (m->temp)
	{
		distance_b = distance_to_tag(i++, m->max - m->size);
		insert = insert_distance(m->a, m->temp->index, m->size);
		dist_total = abs(insert) + abs(distance_b);
		if (insert > 0 && distance_b > 0)
			dist_total = dist_total - ft_min(distance_b, insert);
		if (insert < 0 && distance_b < 0)
			dist_total = dist_total + ft_max(distance_b, insert);
		if (dist_total < max_dist)
		{
			max_dist = dist_total;
			*rot_a = insert;
			*rot_b = distance_b;
		}
		m->temp = m->temp->next;
	}
}

void	populate_b(t_stacks *m)
{
	int	rot_a;
	int	rot_b;

	while (m->b)
	{
		calculate_b_rotation(m, 8000000, &rot_a, &rot_b);
		rotate(m, rot_a, rot_b);
		pa(m, 1);
		(m->size)++;
	}
	rotate(m, distance_to_top(m->a, 0), 0);
}
