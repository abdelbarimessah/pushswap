/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouve2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:50:01 by amessah           #+#    #+#             */
/*   Updated: 2022/03/15 17:03:15 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int i)
{
	t_stack	*first;
	t_stack	*midle;
	t_stack	*last;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	last = *a;
	while (last->next->next != NULL)
		last = last->next;
	midle = last->next;
	last->next = NULL;
	midle->next = first;
	*a = midle;
	if (i == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int i)
{
	t_stack	*first;
	t_stack	*midle;
	t_stack	*last;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	last = *b;
	while (last->next->next != NULL)
		last = last->next;
	midle = last->next;
	last->next = NULL;
	midle->next = first;
	*b = midle;
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stacks *s, int i)
{
	rra(&s->a, 0);
	rrb(&s->b, 0);
	if (i == 1)
		write(1, "rrr\n", 4);
}

void	pa(t_stacks *s, int i)
{
	t_stack	*tmp;

	if (s->b == NULL)
		return ;
	s->cont_a += 1;
	s->cont_b -= 1;
	tmp = s->b;
	s->b = s->b->next;
	tmp->next = s->a;
	s->a = tmp;
	if (i == 1)
		write (1, "pa\n", 3);
}

void	pb(t_stacks *s, int i)
{
	t_stack	*tmp;

	if (s->a == NULL)
		return ;
	s->cont_b += 1;
	s->cont_a -= 1;
	tmp = s->a;
	s->a = s->a->next;
	tmp->next = s->b;
	s->b = tmp;
	if (i == 1)
		write (1, "pb\n", 3);
}
