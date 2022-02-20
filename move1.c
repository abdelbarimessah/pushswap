/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:07:45 by amessah           #+#    #+#             */
/*   Updated: 2021/12/23 01:54:43 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack *a,int i)
{
	int tmp;

	if(a == NULL || a->next ==NULL)
		return ;
	tmp = a->data;
	a->data = a->next->data;
	a->next->data = tmp;
	if(i == 1)
		write(1, "sa\n", 3);
}

void    sb(t_stack *b,int i)
{
	int tmp;

	if(b == NULL || b->next ==NULL)
		return ;
	tmp = b->data;
	b->data = b->next->data;
	b->next->data = tmp;
	if(i == 1)
		write(1, "sb\n", 3);
}

void    ss(t_stacks *s,int i)
{
	sa(s->a,0);
	sb(s->b,0);
	if(i == 1)
		write(1, "ss\n",3);
}

void ra(t_stack **a,int i)
{
	t_stack *first;
	t_stack *midle;
	t_stack *last;
	
	if(*a == NULL ||(*a)->next == NULL)
		return ;
	midle = *a;
	first = (*a)->next;
	last = *a;
	while(last->next != NULL)
		last = last->next;
	midle->next = NULL;
	last->next = midle;
	*a = first;
	if( i == 1)
		write(1, "ra\n", 3);
}
void rb(t_stack **b,int i)
{
	t_stack *first;
	t_stack *midle;
	t_stack *last;
	
	if(*b == NULL ||(*b)->next == NULL)
		return ;
	midle = *b;
	first = (*b)->next;
	last = *b;
	while(last->next != NULL)
		last = last->next;
	midle->next = NULL;
	last->next = midle;
	*b = first;
	if( i == 1)
		write(1, "rb\n", 3);
}

void rr(t_stacks *s ,int i)
{
	ra(&s->a, 0);
	rb(&s->b, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}

void rra(t_stack **a, int i)
{
	t_stack *first;
	t_stack *midle;
	t_stack *last;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	midle = last ->next;
	last->next = NULL;
	midle->next = first;
	*a = midle;
	if (i == 1)
		write(1, "rra\n", 4);
}

void rrb(t_stack **b, int i)
{
	t_stack *first;
	t_stack *midle;
	t_stack *last;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	midle = last->next;
	last->next = NULL;
	midle->next = first;
	*b = midle;
	if (i == 1)
		write(1, "rrb\n", 4);
}

void rrr(t_stacks *s,int i)
{
	rra(&s->a, 0);
	rrb(&s->b, 0);
	if ( i== 1)
		write(1, "rrr\n", 4);
}

void pa(t_stacks *s, int i)
{
	t_stack *tmp;
	if(s->b == NULL)
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

void pb(t_stacks *s, int i)
{
	t_stack *tmp;
	if(s->a == NULL)
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