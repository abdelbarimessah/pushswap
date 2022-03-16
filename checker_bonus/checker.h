/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:17:47 by amessah           #+#    #+#             */
/*   Updated: 2022/03/16 15:18:31 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 1

# include "../push_swap.h"

void	doing_mouve(char *str, t_stacks *s);
char	*get_buffer(int fd, char *str);
char	*get_line(char *s);
char	*rest(char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		check_line(char *line);
size_t	ft_strlen(const char *str);

#endif