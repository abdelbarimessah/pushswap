/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:31:55 by amessah           #+#    #+#             */
/*   Updated: 2022/03/15 17:21:52 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_stacks *m)
{
	int		prev;
	t_stack	*l;

	if (m->b)
		return (0);
	if (!m->a)
		return (1);
	l = m->a;
	prev = l->data;
	while (l)
	{
		if (prev > l->data)
			return (0);
		prev = l->data;
		l = l->next;
	}
	return (1);
}

void	ft_swap_list(t_stack **prevnext, t_stack *last)
{
	t_stack	*swap;

	swap = *prevnext;
	*prevnext = last->next_sort;
	swap->next_sort = last->next_sort->next_sort;
	(*prevnext)->next_sort = swap;
}

void	ft_list_sort(t_stack **begin_list)
{
	t_stack	*last;
	t_stack	*prev;

	prev = NULL;
	last = *begin_list;
	while (last && last->next_sort)
	{
		if (last->data > last->next_sort->data)
		{
			if (prev == NULL)
				ft_swap_list(begin_list, last);
			else
				ft_swap_list(&(prev->next_sort), last);
			last = *begin_list;
			prev = NULL;
		}
		else
		{
			prev = last;
			last = last->next_sort;
		}
	}
}

void	tag_list(t_stack **start, t_stacks *mem)
{
	int		i;
	t_stack	*node;

	node = (*start);
	i = 0;
	while (node)
	{
		node->index = i++;
		node = node->next_sort;
	}
	mem->max = i;
}
