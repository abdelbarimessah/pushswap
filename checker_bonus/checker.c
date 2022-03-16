/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:17:25 by amessah           #+#    #+#             */
/*   Updated: 2022/03/16 15:17:07 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	doing_mouve(char *str, t_stacks *s)
{
	if (!ft_strcmp(str, "ra\n"))
		ra(&s->a, 0);
	else if (!ft_strcmp(str, "rb\n"))
		rb(&s->b, 0);
	else if (!ft_strcmp(str, "rr\n"))
		rr(s, 0);
	else if (!ft_strcmp(str, "sa\n"))
		sa(s->a, 0);
	else if (!ft_strcmp(str, "sb\n"))
		sb(s->b, 0);
	else if (!ft_strcmp(str, "ss\n"))
		ss(s, 0);
	else if (!ft_strcmp(str, "rra\n"))
		rra(&s->a, 0);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(&s->b, 0);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(s, 0);
	else if (!ft_strcmp(str, "pa\n"))
		pa(s, 0);
	else if (!ft_strcmp(str, "pb\n"))
		pb(s, 0);
}

int	check_line(char *line)
{
	if (ft_strcmp(line, "sa\n") && ft_strcmp(line, "ra\n")
		&& ft_strcmp(line, "pa\n") && ft_strcmp(line, "rra\n")
		&& ft_strcmp(line, "sb\n") && ft_strcmp(line, "rb\n")
		&& ft_strcmp(line, "pb\n") && ft_strcmp(line, "rrb\n")
		&& ft_strcmp(line, "ss\n") && ft_strcmp(line, "rr\n")
		&& ft_strcmp(line, "rrr\n"))
		return (1);
	else
		return (0);
	puts("ddd");
}

void	write_status(t_stacks *s)
{
	if (is_ordered(s))
		ft_putstr("ok");
	else
		ft_putstr("ko");
}

int	main(int argc, char *argv[])
{
	t_stacks	s;
	char		*line;

	s.a = NULL;
	s.b = NULL;
	if (argc <= 1)
		return (0);
	read_args(argc, argv, &s);
	line = get_next_line(0);
	while (line)
	{
		if (check_line(line))
		{
			free(line);
			exit(1);
		}
		else
			doing_mouve(line, &s);
		line = get_next_line(0);
	}
	write_status(&s);
	clear_all(&s);
	return (0);
}
