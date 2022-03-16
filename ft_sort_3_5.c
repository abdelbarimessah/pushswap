/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:08:32 by amessah           #+#    #+#             */
/*   Updated: 2022/03/15 17:18:28 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stacks *stacks)
{
	t_stack	*tmp;
	int		cont;

	tmp = stacks->a;
	cont = list_size(tmp);
	if (cont <= 3)
		sort_3(stacks, cont);
	else if (cont <= 5)
		sort_5(stacks, cont);
	else
		ft_global_sort(stacks, 1);
}

int	max(t_stack *s)
{
	int	m;

	m = s->data;
	while (s)
	{
		if (s->data > m)
			m = s->data;
		s = s->next;
	}
	return (m);
}

int	min(t_stack *s)
{
	int	i;

	i = s->data;
	while (s)
	{
		if (s->data < i)
			i = s->data;
		s = s->next;
	}
	return (i);
}

void	sort_3(t_stacks *stacks, int cont)
{
	int	m;

	m = max(stacks->a);
	if (cont == 1)
		return ;
	else if (cont == 2)
	{
		if (stacks->a->data > stacks->a->next->data)
			sa(stacks->a, 1);
		return ;
	}
	else if (cont == 3)
	{
		if (stacks->a->data == m)
			ra(&stacks->a, 1);
		if (stacks->a->next->data == m)
			rra(&stacks->a, 1);
		if (stacks->a->data > stacks->a->next->data)
			sa(stacks->a, 1);
	}
}

void	sort_5(t_stacks *stacks, int cont)
{
	while (cont >= 4)
	{
		if (stacks->a->data == min(stacks->a)
			|| stacks->a->data == max(stacks->a))
		{
			pb(stacks, 1);
			cont--;
		}
		else
			ra(&stacks->a, 1);
	}
	sort_3(stacks, cont);
	pa(stacks, 1);
	pa(stacks, 1);
	if (stacks->a->data == max(stacks->a))
		ra(&stacks-> a, 1);
	else
	{
		sa(stacks->a, 1);
		ra(&stacks->a, 1);
	}
}
