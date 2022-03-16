/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:36:52 by amessah           #+#    #+#             */
/*   Updated: 2022/03/15 16:33:58 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	mem;
	t_stack		*start_tag;

	mem.a = NULL;
	mem.b = NULL;
	if (argc <= 1)
		return (0);
	read_args(argc, argv, &mem);
	if (!is_ordered(&mem))
	{
		start_tag = mem.a;
		ft_list_sort(&start_tag);
		tag_list(&start_tag, &mem);
		ft_sort(&mem);
	}
	clear_all(&mem);
	start_tag = NULL;
	return (0);
}
