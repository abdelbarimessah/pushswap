/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:12:25 by amessah           #+#    #+#             */
/*   Updated: 2022/02/19 21:21:47 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<limits.h>

typedef struct s_data
{
	int a[10000];
	int cont_element;	
}t_data;

typedef struct		s_steps
{
	int				count_a;
	int				count_b;
	int				dest_a;
	int				dest_b;
}t_steps;


typedef struct s_stack
{
	int	data;
	int step;
	int rotate;
	int index;
	struct s_stack *next;
}t_stack;

typedef struct s_stacks
{
	int cont_a;
	int cont_b;
	int min;
	int max;
	int med;
	t_stack *a;
	t_stack *b;
}t_stacks;


#endif