/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:36:52 by amessah           #+#    #+#             */
/*   Updated: 2022/02/19 22:49:21 by amessah          ###   ########.fr       */
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
	while (last->next->next != NULL)
		last = last->next;
	midle = last->next;
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
	while (last->next->next != NULL)
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

t_stack	*creat(const int *buff, int count)
{
	int		i;
	t_stack	*new_list;
	t_stack	*first_element;

	i = 0;
	if (!(new_list = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	first_element = new_list;
	while (i < count)
	{
		if (i < count - 1)
		{
			if (!(new_list->next = (t_stack *)malloc(sizeof(t_stack))))
				exit(1);
		}
		new_list->data = buff[i];
		if (i == (count - 1))
			new_list->next = NULL;
		else
			new_list = new_list->next;
		i++;
	}
	return (first_element);
}

void	init(t_data *new,t_stacks *stacks)
{
	stacks->a = creat(new->a, new->cont_element);
	stacks->b = NULL;
}

void	ft_null(t_stacks *stacks, t_data *new)
{
	new->cont_element = 0;
	stacks->cont_a = 0;
	stacks->cont_b = 0;
	stacks->min = 0;
	stacks->max = 0;
	stacks->med = 0;
	stacks->a = NULL;
	stacks->b = NULL;
}

int max(t_stack *s)
{
    int m;
    m = s->data;
    while(s)
    {
        if(s->data > m)
            m = s->data;
        s = s->next;
    }
    return (m);
}

void    sort_3(t_stacks *stacks)
{
    int m;

    m = max(stacks->a);
    if(stacks->cont_a == 1)
        return ;
    else if(stacks->cont_a == 2)
    {
        if(stacks->a->data > stacks->a->next->data)
            sa(stacks->a,1);
        return ;
    }
    else if (stacks->cont_a == 3)
    {
        if (stacks->a->data == m)
			ra(&stacks->a, 1);
		if (stacks->a->next->data == m)
			rra(&stacks->a, 1);
		if (stacks->a->data > stacks->a->next->data)
			sa(stacks->a, 1);
    }
}

void	sort_5(t_stacks *stacks)
{
	while(stacks->cont_b < 2)
	{
		if(stacks->a->data == stacks->min || stacks->a->data == stacks->max)
			pb(stacks, 1);
		else
			ra(&stacks->a, 1);
	}
	sort_3(stacks);
	pa(stacks, 1);
	pa(stacks, 1);
	if(stacks->a->data == stacks->max)
		ra(&stacks->a, 1);
	else
	{
		sa(stacks->a, 1);
		ra(&stacks->a, 1);
	}
}

void	ft_valid_str(const char *str)
{
	size_t	i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (sign != 0 && nbr == 0)
				ft_error();
			nbr = 0;
			sign = 0;
		}
		else if (((str[i] == '+' || str[i] == '-') &&
				(sign == 0 && nbr == 0)) && (str[i + 1] != '\0'))
			sign++;
		else
			ft_error();
		i++;
	}
}
void	ft_number_availability(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ;
		i++;
	}
	ft_error();
}
int		ft_only_spaces(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
			i++;
		else
			return (1);
	}
	return (0);
}
int		ft_validation(int argc, char **argv)
{
	int i;
	int ret;

	ret = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_only_spaces(argv[i]))
		{
			ft_number_availability(argv[i]);
			ft_valid_str(argv[i]);
			ret = 1;
		}
		i++;
	}
	return (ret);
}

void indexing(t_stack *s,int *tab)
{
	int i;
	int k;
	int j;
	
	j = 0;
	i = 0;
	while(s)
	{
		tab[i] = s->data;
		i++;
		s = s->next;
	}
	ft_quick_sort(tab, 0, i);
	while(s)
	{
		while(tab[j])
		{
			if(s->data == tab[j])
			{
				s->index = j;
				break;
			}
			j++;	
		}
		s = s->next;
	}
}
int		ft_partition(int *array, int start, int end)
{
	int pivot;
	int i;
	int temp;
	int j;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	return (i + 1);
}
void	ft_quick_sort(int *array, int start, int end)
{
	int q;

	if (start < end)
	{
		q = ft_partition(array, start, end);
		ft_quick_sort(array, start, q - 1);
		ft_quick_sort(array, q + 1, end);
	}
}

void golbal(t_stacks *s)
{
	int *tab;
	int i;
	int med;
	
	
	indexing(s->a,tab);
	i = strlen(tab);
	med = i / 2;
	while(s->cont_a > 2)
	{
		if(s->a->index != 0 && s->a->index != i)
		{
			pb(s, 1);
			if(s->b->index < med)
				rb(&s->b, 1);
		}
		else
			ra(&s->a, 1);
	}
	if(s->a->data < s->a->next->data)
		sa(s->a, 1);
	while(s->cont_b >= 1)
	{
		pa(s, 1);
	}
	ra(&s->a, 1);
}



int	min(t_stack *a)
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
	int k;
	while(s->cont_a > 2)
	{
	
		if(s->a->data != s->min && s->a->data != s->max)
		{
			pb(s, 1);	
		}
		else
			ra(&s->a, 1);
	}
	if(s->a->data > s->a->next->data)
		sa(s->a, 1);
	while(s->cont_b >= 1)
	{
		while(s->b != NULL)
		{
			i = min(s->b);
			if(s->b->data == i)
				pa(s, 1);
			else
				rb(&s->b, 1);
		}
	}	
	j = min(s->a);
	while(s->a->data != j)
	{
		ra(&s->a, 1);	
	}
}



void	ft_sort(t_stacks *stacks)
{
	if (stacks->cont_a <= 3)
		sort_3(stacks);
	 else if (stacks->cont_a <= 5)
	 	sort_5(stacks);
	else
		ft_global_sort(stacks);
		// golbal(stacks);
		 
}
int		ft_is_sorted(t_data *new)
{
	int i;

	i = 0;
	while (i < (new->cont_element - 1))
	{
		if (new->a[i] > new->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	ft_free_stack(t_stacks *stacks)
{
	int		i;
	t_stack	*buff;

	i = 0;
	while (i < stacks->cont_a)
	{
		buff = stacks->a;
		stacks->a = stacks->a->next;
		free(buff);
		i++;
	}
	i = 0;
	while (i < stacks->cont_b)
	{
		buff = stacks->b;
		stacks->b = stacks->b->next;
		free(buff);
		i++;
	}
}

void	ft_stacking(t_data *new, int *buff, int count)
{
	int i;

	i = -1;
	while (count > ++i)
		new->a[new->cont_element + i] = buff[i];
	new->cont_element += count;
	free(buff);
}

int		ft_countword(char const *s)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			count++;
			while ((*s != ' ' && *s != '\t') && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (count);
}
int		ft_wordmalloc(char const *s, char **mass)
{
	int lenword;
	int i;

	i = 0;
	while (*s)
	{
		lenword = 0;
		if (*s != ' ' && *s != '\t')
		{
			while ((*s != ' ' && *s != '\t') && *s != '\0')
			{
				s++;
				lenword++;
			}
			if (!(mass[i++] = ((char *)malloc(sizeof(char) * (lenword + 1)))))
				return (i);
		}
		else
			s++;
	}
	return (0);
}

void	ft_rewriting(char const *s, char **mass)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			while ((*s != ' ' && *s != '\t') && *s != '\0')
				mass[i][j++] = *s++;
			mass[i++][j] = '\0';
		}
		j = 0;
		if (*s != '\0')
			s++;
	}
}
char	**ft_strsplit(char const *s, int word)
{
	char	**mass;
	int		res;

	if (!s)
		return (NULL);
	if (!(mass = (char **)malloc(sizeof(char *) * (word + 1))))
		exit(1);
	mass[word] = NULL;
	res = ft_wordmalloc(s, mass);
	if (res == 0)
		ft_rewriting(s, mass);
	else
	{
		while (res != 0)
		{
			free(mass[res]);
			mass[res--] = NULL;
		}
		free(mass);
	}
	return ((char **)mass);
}
int		ft_atoi(const char *str)
{
	int		sign;
	int		dig;
	long	res;

	sign = 1;
	dig = 0;
	res = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v'
		|| *str == ' ' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		res = res * 10 + (*str - '0');
		dig++;
		if (dig > 10 || (res * sign) > 2147483647 || (res * sign) < -2147483648)
			ft_error();
		str++;
	}
	return (int)(res * sign);
}

void	ft_array_separation(int argc, char **argv, t_data *new)
{
	int		p;
	int		i;
	int		*buff;
	char	**mass;
	int		count_element;

	i = 1;
	while (i < argc)
	{
		p = -1;
		count_element = ft_countword(argv[i]);
		mass = ft_strsplit(argv[i], count_element);
		if (!(buff = (int *)malloc(sizeof(int) * (count_element))))
			exit(1);
		while (count_element > ++p)
		{
			buff[p] = ft_atoi(mass[p]);
			free(mass[p]);
		}
		free(mass);
		ft_stacking(new, buff, count_element);
		i++;
	}
}

int		*ft_intcpy(int *dst, const int *src, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

void	ft_search_duplicate(const int *dup, int count)
{
	int i;

	i = 0;
	while (i != count)
	{
		if (dup[i] == dup[i + 1])
			ft_error();
		i++;
	}
}

void	ft_duplicate_check(t_data *new, t_stacks *stacks)
{
	int			*dup;

	if (!(dup = (int *)malloc(sizeof(int) * (new->cont_element))))
		exit(1);
	dup = ft_intcpy(dup, new->a, new->cont_element);
	ft_quick_sort(dup, 0, new->cont_element - 1);
	ft_search_duplicate(dup, new->cont_element - 1);
	stacks->cont_a = new->cont_element;
	stacks->cont_b = 0;
	stacks->min = dup[0];
	stacks->med = dup[new->cont_element / 2];
	stacks->max = dup[new->cont_element - 1];
	free(dup);
}

int		main(int argc, char **argv)
{
	t_data		*new;
	t_stacks	*stacks;

	if (argc < 2)
		exit(1);
	if (!(new = (t_data *)malloc(sizeof(t_data))))
		exit(1);
	if (!(stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		exit(1);
    ft_null(stacks, new);
	if (ft_validation(argc, argv))
	{
		ft_array_separation(argc, argv, new);
		ft_duplicate_check(new, stacks);
		if (ft_is_sorted(new))
		{
			init(new,stacks);
			ft_sort(stacks);
			// ft_affiche(stacks->a);
			ft_free_stack(stacks);
		}
	}
	free(new);
	free(stacks);
	return (0);
}
