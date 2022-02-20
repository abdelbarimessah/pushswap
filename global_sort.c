/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:45:31 by amessah           #+#    #+#             */
/*   Updated: 2022/02/11 15:57:03 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void min(t_stack *a)
{
	int i;
	
	i = a->data;
	while(a)
	{
		if(a->data < i)
			i = a->data;
		a = a->next;		
	}
	return (i);
}
void	ft_global_sort(t_stacks *s)
{
	int i;
	int j;
	
	
	while(s->cont_a > 2)
	{
		if(s->a->data != s->min || s->a->data != s->max)
		{
			pb(s, 1);	
		}
		else
			ra(&s->a, 1);
	}
	if(s->a->data > s->a->data)
		sa(s->a, 1);
	while(s->cont_b >= 1)
	{
		i = min(s->b);
		while(s->b)
		{
			if(s->b->data != i)
				rb(&s->b, 1);
			else if(s->b->data == i)
				pa(s, 1);
			s->b = s->b->next;
		}
	}
	j = min(s->a);
	while(s->a->data != j)
	{
		ra(&s->a, 1);	
	}
}
