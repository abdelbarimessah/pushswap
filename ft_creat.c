/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:28:27 by amessah           #+#    #+#             */
/*   Updated: 2022/03/15 16:34:44 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	list_contains_value(t_stack *l, int value)
{
	while (l)
	{
		if (l->data == value)
			return (1);
		l = l->next;
	}
	return (0);
}

void	push_init(t_stack **stack, int value, int tag, t_stacks *mem)
{
	t_stack	*elem;
	t_stack	*node;

	node = *stack;
	if (list_contains_value(*stack, value))
		exit_error(mem);
	elem = malloc(sizeof(t_stack));
	if (!elem)
		exit_error(mem);
	elem->next = NULL;
	elem->next_sort = NULL;
	elem->data = value;
	elem->index = tag;
	if (node == NULL)
	{
		*stack = elem;
		return ;
	}
	while (node->next)
		node = node->next;
	node->next = elem;
	node->next_sort = elem;
}

int	ft1_atoi(char *str, t_stacks *mem)
{
	int		ne;
	long	nbr;

	nbr = 0;
	ne = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			ne *= -1;
		++str;
	}
	--str;
	while (++str && ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		if ((ne == 1 && nbr > 0x7FFFFFFF) || (ne == -1 && nbr > 0x80000000))
			exit_error(mem);
	}
	return ((int)(nbr * ne));
}

void	read_args(int argc, char **argv, t_stacks *mem)
{
	int	j;
	int	i;
	int	prev_space;

	i = 1;
	prev_space = 1;
	while (i < argc)
	{
		prev_space = 1;
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] != '+' && argv[i][j] != '-' && argv[i][j] != ' '
				&& !ft_isdigit(argv[i][j]))
				exit_error(mem);
			if (prev_space == 1 && argv[i][j] != ' ')
			{
				push_init(&(mem->a), ft1_atoi(argv[i] + j, mem), -1, mem);
				prev_space = 0;
			}
			if (argv[i][j] == ' ')
				prev_space = 1;
		}
		i++;
	}
}
