/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:39:48 by amessah           #+#    #+#             */
/*   Updated: 2022/03/15 17:21:08 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_list(t_stack **s, t_stack *last)
{
	t_stack	*tmp;

	tmp = *s;
	*s = last->next_sort;
	tmp->next_sort = last->next_sort->next_sort;
	(*s)->next_sort = tmp;
}

void	sort_stack(t_stack **s)
{
	t_stack	*last;
	t_stack	*prev;

	prev = NULL;
	last = *s;
	while (last && last->next_sort)
	{
		if (last->data > last->next_sort->data)
		{
			if (prev == NULL)
				swap_list(s, last);
			else
				swap_list(&(prev->next_sort), last);
			last = *s;
			prev = NULL;
		}
		else
		{
			prev = last;
			last = last->next_sort;
		}
	}
}

int	loop_list(t_stack *list, t_stack *start, int set)
{
	t_stack	*loop;
	int		max_tag;
	int		count;

	max_tag = -1;
	count = 0;
	loop = start;
	while (loop)
	{
		if (set)
			loop->keep = 0;
		if (loop->index > max_tag)
		{
			max_tag = loop->index;
			count++;
			if (set)
				loop->keep = 1;
		}
		loop = loop->next;
		if (loop == NULL)
			loop = list;
		if (loop == start)
			break ;
	}
	return (count);
}

int	find_biggest_loop(t_stack *start, int set)
{
	t_stack	*t;
	t_stack	*max_keeep;
	int		max;
	int		cont;

	max = 0;
	t = start;
	while (t)
	{
		cont = loop_list(start, t, 0);
		if (cont > max)
		{
			max = cont;
			max_keeep = t;
		}
		t = t->next;
	}
	if (set)
		loop_list(start, max_keeep, 1);
	return (max);
}

t_stack	*get_last(t_stack *l)
{
	if (l == NULL)
		return (NULL);
	while (l->next)
	{
		l = l->next;
	}
	return (l);
}
