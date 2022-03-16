/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouve3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:53:03 by amessah           #+#    #+#             */
/*   Updated: 2022/03/15 17:04:06 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		++str;
	}
}

void	ft_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

void	sa(t_stack *a, int i)
{
	int	tmp;

	if (a == NULL || a->next == NULL)
		return ;
	tmp = a->data;
	a->data = a->next->data;
	a->next->data = tmp;
	if (i == 1)
		write(1, "sa\n", 3);
}
