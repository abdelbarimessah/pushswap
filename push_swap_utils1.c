/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 22:21:12 by amessah           #+#    #+#             */
/*   Updated: 2021/12/05 22:50:26 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool push(t_list *stack,int value)
{
	t_list *new = malloc(sizeof(t_list));
	if(new == NULL)
		return false;  
	new -> value = value;
	new -> next = stack;
	stack = new;
	return true;
}

int pop(t_list *stack)
{
	int res;
	t_list *tmp;
	
	if(stack == NULL)
		return STACK_EMPTY;
	res = stack -> value;
	tmp = stack;
	stack = stack -> next;
	free(tmp);
	return (res); 
}

int main()
{
	t_list 	s1 = NULL;
	t_list 	s2 = NULL;
	t_list 	s3 = NULL;
	int		t;

	push(&s1,54);
	push(&s2,64);
	push(&s2,2);
	push(&s2,0);
	push(&s3,1);
	
	while((t = pop(&s2)) != STACK_EMPTY)
	{
		printf(" t = %d\n",t);
	}
	
}

