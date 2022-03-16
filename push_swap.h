/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:12:25 by amessah           #+#    #+#             */
/*   Updated: 2022/03/16 15:21:27 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdlib.h>
# include<string.h>
# include<stdio.h>
# include<unistd.h>
# include<limits.h>

typedef struct s_stack
{
	int				data;
	int				keep;
	int				index;
	struct s_stack	*next;
	struct s_stack	*next_sort;
}t_stack;

typedef struct s_stacks
{
	int		max;
	int		tall_loop;
	int		size;
	int		grp_cont;
	int		grp_size;
	int		cont_a;
	int		cont_b;
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp;
}t_stacks;

t_stack	*get_last(t_stack *l);
t_stack	*closet_in_group(t_stack *list, int cur_grp, int grp_size);
void	clear_all(t_stacks *mem);
void	ft_free_list(t_stack **list);
void	ft_index(t_stack **start, t_stacks *s);
void	swap_list(t_stack **s, t_stack *last);
void	sort_stack(t_stack **s);
void	ft_init(t_stacks *s);
void	calculate_b_rotation(t_stacks *m, int max_dist, int *rot_a, int *rot_b);
void	double_rotate(t_stacks *mem, int *rot_a, int *rot_b);
void	rotate(t_stacks *mem, int rot_a, int rot_b);
void	populate_b(t_stacks *m);
void	ft_global_sort(t_stacks *s, int cur_grp);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	exit_error(t_stacks *mem);
void	ft_puterr(char *str);
void	sa(t_stack *a, int i);
void	sb(t_stack *b, int i);
void	ss(t_stacks *s, int i);
void	ra(t_stack **a, int i);
void	rb(t_stack **b, int i);
void	rr(t_stacks *s, int i);
void	rra(t_stack **a, int i);
void	rrb(t_stack **b, int i);
void	rrr(t_stacks *s, int i);
void	pa(t_stacks *s, int i);
void	pb(t_stacks *s, int i);
void	ft_sort(t_stacks *stacks);
void	sort_3(t_stacks *stacks, int cont);
void	sort_5(t_stacks *stacks, int cont);
void	ft_swap_list(t_stack **prevnext, t_stack *last);
void	ft_list_sort(t_stack **begin_list);
void	tag_list(t_stack **start, t_stacks *mem);
void	read_args(int argc, char **argv, t_stacks *mem);
void	ft_error(void);
int		loop_list(t_stack *list, t_stack *start, int set);
int		find_biggest_loop(t_stack *start, int set);
int		list_size(t_stack *a);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		distance_to_top(t_stack *a, int tag);
int		abs(int x);
int		can_swap(t_stack *list);
int		distance_to_tag(int tag, int size);
int		insert_distance(t_stack *list, int t, int size);
int		max(t_stack *s);
int		min(t_stack *s);
int		is_ordered(t_stacks *m);

#endif