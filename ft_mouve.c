/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:06:24 by amessah           #+#    #+#             */
/*   Updated: 2022/03/15 16:58:43 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *b, int i)
{
	int	tmp;

	if (b == NULL || b->next == NULL)
		return ;
	tmp = b->data;
	b->data = b->next->data;
	b->next->data = tmp;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stacks *s, int i)
{
	sa(s->a, 0);
	sb(s->b, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}

void	ra(t_stack **a, int i)
{
	t_stack	*first;
	t_stack	*midle;
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	midle = *a;
	first = (*a)->next;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	midle->next = NULL;
	last->next = midle;
	*a = first;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int i)
{
	t_stack	*first;
	t_stack	*midle;
	t_stack	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	midle = *b;
	first = (*b)->next;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	midle->next = NULL;
	last->next = midle;
	*b = first;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stacks *s, int i)
{
	ra(&s->a, 0);
	rb(&s->b, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}
